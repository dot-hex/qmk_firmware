"""Used by the make system to generate info_config.h from info.json.
"""
from pathlib import Path
from dotty_dict import dotty

from argcomplete.completers import FilesCompleter
from milc import cli

from qmk.info import info_json
<<<<<<< HEAD
from qmk.json_schema import json_load, validate
from qmk.keyboard import keyboard_completer, keyboard_folder
from qmk.keymap import locate_keymap
from qmk.path import normpath
=======
from qmk.json_schema import json_load
from qmk.keyboard import keyboard_completer, keyboard_folder
from qmk.commands import dump_lines, parse_configurator_json
from qmk.path import normpath, FileType
from qmk.constants import GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE


def generate_define(define, value=None):
    is_keymap = cli.args.filename
    value = f' {value}' if value is not None else ''
    if is_keymap:
        return f"""
#undef {define}
#define {define}{value}"""
    return f"""
#ifndef {define}
#    define {define}{value}
#endif // {define}"""
>>>>>>> upstream/master


def direct_pins(direct_pins, postfix):
    """Return the config.h lines that set the direct pins.
    """
    rows = []

    for row in direct_pins:
        cols = ','.join(map(str, [col or 'NO_PIN' for col in row]))
        rows.append('{' + cols + '}')

<<<<<<< HEAD
    return f"""
#ifndef DIRECT_PINS{postfix}
#   define DIRECT_PINS{postfix} {{ {", ".join(rows)} }}
#endif // DIRECT_PINS{postfix}
"""
=======
    return generate_define(f'DIRECT_PINS{postfix}', f'{{ {", ".join(rows)} }}')
>>>>>>> upstream/master


def pin_array(define, pins, postfix):
    """Return the config.h lines that set a pin array.
    """
    pin_array = ', '.join(map(str, [pin or 'NO_PIN' for pin in pins]))

<<<<<<< HEAD
    return f"""
#ifndef {define}_PINS{postfix}
#   define {define}_PINS{postfix} {{ {pin_array} }}
#endif // {define}_PINS{postfix}
"""
=======
    return generate_define(f'{define}_PINS{postfix}', f'{{ {pin_array} }}')
>>>>>>> upstream/master


def matrix_pins(matrix_pins, postfix=''):
    """Add the matrix config to the config.h.
    """
    pins = []

    if 'direct' in matrix_pins:
        pins.append(direct_pins(matrix_pins['direct'], postfix))

    if 'cols' in matrix_pins:
        pins.append(pin_array('MATRIX_COL', matrix_pins['cols'], postfix))

    if 'rows' in matrix_pins:
        pins.append(pin_array('MATRIX_ROW', matrix_pins['rows'], postfix))

    return '\n'.join(pins)


def generate_matrix_size(kb_info_json, config_h_lines):
    """Add the matrix size to the config.h.
    """
<<<<<<< HEAD
    if 'matrix_pins' in kb_info_json:
        col_count = kb_info_json['matrix_size']['cols']
        row_count = kb_info_json['matrix_size']['rows']

        config_h_lines.append(f"""
#ifndef MATRIX_COLS
#   define MATRIX_COLS {col_count}
#endif // MATRIX_COLS

#ifndef MATRIX_ROWS
#   define MATRIX_ROWS {row_count}
#endif // MATRIX_ROWS
""")


def generate_config_items(kb_info_json, config_h_lines):
    """Iterate through the info_config map to generate basic config values.
    """
    info_config_map = json_load(Path('data/mappings/info_config.json'))

=======
    if 'matrix_size' in kb_info_json:
        config_h_lines.append(generate_define('MATRIX_COLS', kb_info_json['matrix_size']['cols']))
        config_h_lines.append(generate_define('MATRIX_ROWS', kb_info_json['matrix_size']['rows']))


def generate_matrix_masked(kb_info_json, config_h_lines):
    """"Enable matrix mask if required"""
    mask_required = False

    if 'matrix_grid' in kb_info_json.get('dip_switch', {}):
        mask_required = True
    if 'matrix_grid' in kb_info_json.get('split', {}).get('handedness', {}):
        mask_required = True

    if mask_required:
        config_h_lines.append(generate_define('MATRIX_MASKED'))


def generate_config_items(kb_info_json, config_h_lines):
    """Iterate through the info_config map to generate basic config values.
    """
    info_config_map = json_load(Path('data/mappings/info_config.hjson'))

>>>>>>> upstream/master
    for config_key, info_dict in info_config_map.items():
        info_key = info_dict['info_key']
        key_type = info_dict.get('value_type', 'raw')
        to_c = info_dict.get('to_c', True)

        if not to_c:
            continue

        try:
            config_value = kb_info_json[info_key]
        except KeyError:
            continue

        if key_type.startswith('array.array'):
            config_h_lines.append(generate_define(config_key, f'{{ {", ".join(["{" + ",".join(list(map(str, x))) + "}" for x in config_value])} }}'))
        elif key_type.startswith('array'):
            config_h_lines.append(generate_define(config_key, f'{{ {", ".join(map(str, config_value))} }}'))
        elif key_type == 'bool':
            config_h_lines.append(generate_define(config_key, 'true' if config_value else 'false'))
        elif key_type == 'flag':
            if config_value:
                config_h_lines.append(generate_define(config_key))
        elif key_type == 'mapping':
            for key, value in config_value.items():
<<<<<<< HEAD
                config_h_lines.append('')
                config_h_lines.append(f'#ifndef {key}')
                config_h_lines.append(f'#   define {key} {value}')
                config_h_lines.append(f'#endif // {key}')
        elif key_type == 'bcd_version':
            (major, minor, revision) = config_value.split('.')
            config_h_lines.append('')
            config_h_lines.append(f'#ifndef {config_key}')
            config_h_lines.append(f'#   define {config_key} 0x{major.zfill(2)}{minor}{revision}')
            config_h_lines.append(f'#endif // {config_key}')
=======
                config_h_lines.append(generate_define(key, value))
        elif key_type == 'str':
            escaped_str = config_value.replace('\\', '\\\\').replace('"', '\\"')
            config_h_lines.append(generate_define(config_key, f'"{escaped_str}"'))
        elif key_type == 'bcd_version':
            (major, minor, revision) = config_value.split('.')
            config_h_lines.append(generate_define(config_key, f'0x{major.zfill(2)}{minor}{revision}'))
>>>>>>> upstream/master
        else:
            config_h_lines.append(generate_define(config_key, config_value))


def generate_encoder_config(encoder_json, config_h_lines, postfix=''):
    """Generate the config.h lines for encoders."""
    a_pads = []
    b_pads = []
    resolutions = []
    for encoder in encoder_json.get("rotary", []):
        a_pads.append(encoder["pin_a"])
        b_pads.append(encoder["pin_b"])
        resolutions.append(encoder.get("resolution", None))

    config_h_lines.append(generate_define(f'ENCODER_A_PINS{postfix}', f'{{ {", ".join(a_pads)} }}'))
    config_h_lines.append(generate_define(f'ENCODER_B_PINS{postfix}', f'{{ {", ".join(b_pads)} }}'))

    if None in resolutions:
        cli.log.debug(f"Unable to generate ENCODER_RESOLUTION{postfix} configuration")
    elif len(resolutions) == 0:
        cli.log.debug(f"Skipping ENCODER_RESOLUTION{postfix} configuration")
    elif len(set(resolutions)) == 1:
        config_h_lines.append(generate_define(f'ENCODER_RESOLUTION{postfix}', resolutions[0]))
    else:
        config_h_lines.append(generate_define(f'ENCODER_RESOLUTIONS{postfix}', f'{{ {", ".join(map(str,resolutions))} }}'))


def generate_split_config(kb_info_json, config_h_lines):
    """Generate the config.h lines for split boards."""
    if 'handedness' in kb_info_json['split']:
        # TODO: change SPLIT_HAND_MATRIX_GRID to require brackets
        handedness = kb_info_json['split']['handedness']
        if 'matrix_grid' in handedness:
            config_h_lines.append(generate_define('SPLIT_HAND_MATRIX_GRID', ', '.join(handedness['matrix_grid'])))

    if 'protocol' in kb_info_json['split'].get('transport', {}):
        if kb_info_json['split']['transport']['protocol'] == 'i2c':
            config_h_lines.append(generate_define('USE_I2C'))

    if 'right' in kb_info_json['split'].get('matrix_pins', {}):
        config_h_lines.append(matrix_pins(kb_info_json['split']['matrix_pins']['right'], '_RIGHT'))

    if 'right' in kb_info_json['split'].get('encoder', {}):
        generate_encoder_config(kb_info_json['split']['encoder']['right'], config_h_lines, '_RIGHT')


def generate_led_animations_config(feature, led_feature_json, config_h_lines, enable_prefix, animation_prefix):
    if 'animation' in led_feature_json.get('default', {}):
        config_h_lines.append(generate_define(f'{feature.upper()}_DEFAULT_MODE', f'{animation_prefix}{led_feature_json["default"]["animation"].upper()}'))

    for animation in led_feature_json.get('animations', {}):
        if led_feature_json['animations'][animation]:
            config_h_lines.append(generate_define(f'{enable_prefix}{animation.upper()}'))


@cli.argument('filename', nargs='?', arg_only=True, type=FileType('r'), completer=FilesCompleter('.json'), help='A configurator export JSON to be compiled and flashed or a pre-compiled binary firmware file (bin/hex) to be flashed.')
@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('-kb', '--keyboard', arg_only=True, type=keyboard_folder, completer=keyboard_completer, help='Keyboard to generate config.h for.')
@cli.subcommand('Used by the make system to generate info_config.h from info.json', hidden=True)
def generate_config_h(cli):
    """Generates the info_config.h file.
    """
    # Determine our keyboard/keymap
    if cli.args.filename:
        user_keymap = parse_configurator_json(cli.args.filename)
        kb_info_json = dotty(user_keymap.get('config', {}))
    elif cli.args.keyboard:
        kb_info_json = dotty(info_json(cli.args.keyboard))
    else:
        cli.log.error('You must supply a configurator export or `--keyboard`.')
        cli.subcommands['generate-config-h'].print_help()
        return False

    # Build the info_config.h file.
    config_h_lines = [GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE, '#pragma once']

    generate_config_items(kb_info_json, config_h_lines)

    generate_matrix_size(kb_info_json, config_h_lines)

    generate_matrix_masked(kb_info_json, config_h_lines)


def generate_split_config(kb_info_json, config_h_lines):
    """Generate the config.h lines for split boards."""
    if 'primary' in kb_info_json['split']:
        if kb_info_json['split']['primary'] in ('left', 'right'):
            config_h_lines.append('')
            config_h_lines.append('#ifndef MASTER_LEFT')
            config_h_lines.append('#   ifndef MASTER_RIGHT')
            if kb_info_json['split']['primary'] == 'left':
                config_h_lines.append('#       define MASTER_LEFT')
            elif kb_info_json['split']['primary'] == 'right':
                config_h_lines.append('#       define MASTER_RIGHT')
            config_h_lines.append('#   endif // MASTER_RIGHT')
            config_h_lines.append('#endif // MASTER_LEFT')
        elif kb_info_json['split']['primary'] == 'pin':
            config_h_lines.append('')
            config_h_lines.append('#ifndef SPLIT_HAND_PIN')
            config_h_lines.append('#   define SPLIT_HAND_PIN')
            config_h_lines.append('#endif // SPLIT_HAND_PIN')
        elif kb_info_json['split']['primary'] == 'matrix_grid':
            config_h_lines.append('')
            config_h_lines.append('#ifndef SPLIT_HAND_MATRIX_GRID')
            config_h_lines.append('#   define SPLIT_HAND_MATRIX_GRID {%s}' % (','.join(kb_info_json["split"]["matrix_grid"],)))
            config_h_lines.append('#endif // SPLIT_HAND_MATRIX_GRID')
        elif kb_info_json['split']['primary'] == 'eeprom':
            config_h_lines.append('')
            config_h_lines.append('#ifndef EE_HANDS')
            config_h_lines.append('#   define EE_HANDS')
            config_h_lines.append('#endif // EE_HANDS')

    if 'protocol' in kb_info_json['split'].get('transport', {}):
        if kb_info_json['split']['transport']['protocol'] == 'i2c':
            config_h_lines.append('')
            config_h_lines.append('#ifndef USE_I2C')
            config_h_lines.append('#   define USE_I2C')
            config_h_lines.append('#endif // USE_I2C')

    if 'right' in kb_info_json['split'].get('matrix_pins', {}):
        config_h_lines.append(matrix_pins(kb_info_json['split']['matrix_pins']['right'], '_RIGHT'))


@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('-kb', '--keyboard', arg_only=True, type=keyboard_folder, completer=keyboard_completer, required=True, help='Keyboard to generate config.h for.')
@cli.argument('-km', '--keymap', arg_only=True, help='Keymap to generate config.h for.')
@cli.subcommand('Used by the make system to generate info_config.h from info.json', hidden=True)
def generate_config_h(cli):
    """Generates the info_config.h file.
    """
    # Determine our keyboard/keymap
    if cli.args.keymap:
        km = locate_keymap(cli.args.keyboard, cli.args.keymap)
        km_json = json_load(km)
        validate(km_json, 'qmk.keymap.v1')
        kb_info_json = dotty(km_json.get('config', {}))
    else:
        kb_info_json = dotty(info_json(cli.args.keyboard))

    # Build the info_config.h file.
    config_h_lines = ['/* This file was generated by `qmk generate-config-h`. Do not edit or copy.', ' */', '', '#pragma once']

    generate_config_items(kb_info_json, config_h_lines)

    generate_matrix_size(kb_info_json, config_h_lines)

    if 'matrix_pins' in kb_info_json:
        config_h_lines.append(matrix_pins(kb_info_json['matrix_pins']))

<<<<<<< HEAD
    if 'split' in kb_info_json:
        generate_split_config(kb_info_json, config_h_lines)

    # Show the results
    config_h = '\n'.join(config_h_lines)
=======
    if 'encoder' in kb_info_json:
        generate_encoder_config(kb_info_json['encoder'], config_h_lines)
>>>>>>> upstream/master

    if 'split' in kb_info_json:
        generate_split_config(kb_info_json, config_h_lines)

    if 'led_matrix' in kb_info_json:
        generate_led_animations_config('led_matrix', kb_info_json['led_matrix'], config_h_lines, 'ENABLE_LED_MATRIX_', 'LED_MATRIX_')

    if 'rgb_matrix' in kb_info_json:
        generate_led_animations_config('rgb_matrix', kb_info_json['rgb_matrix'], config_h_lines, 'ENABLE_RGB_MATRIX_', 'RGB_MATRIX_')

    if 'rgblight' in kb_info_json:
        generate_led_animations_config('rgblight', kb_info_json['rgblight'], config_h_lines, 'RGBLIGHT_EFFECT_', 'RGBLIGHT_MODE_')

    # Show the results
    dump_lines(cli.args.output, config_h_lines, cli.args.quiet)
