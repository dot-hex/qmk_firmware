"""Used by the make system to generate version.h for use in code.
"""
<<<<<<< HEAD
from milc import cli

from qmk.commands import create_version_h
from qmk.path import normpath
=======
from time import strftime

from milc import cli

from qmk.path import normpath
from qmk.commands import dump_lines
from qmk.git import git_get_qmk_hash, git_get_version, git_is_dirty
from qmk.constants import GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE

TIME_FMT = '%Y-%m-%d-%H:%M:%S'
>>>>>>> upstream/master


@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('--skip-git', arg_only=True, action='store_true', help='Skip Git operations')
@cli.argument('--skip-all', arg_only=True, action='store_true', help='Use placeholder values for all defines (implies --skip-git)')
@cli.subcommand('Used by the make system to generate version.h for use in code', hidden=True)
def generate_version_h(cli):
    """Generates the version.h file.
    """
    if cli.args.skip_all:
        cli.args.skip_git = True

<<<<<<< HEAD
    version_h = create_version_h(cli.args.skip_git, cli.args.skip_all)

    if cli.args.output:
        cli.args.output.parent.mkdir(parents=True, exist_ok=True)
        if cli.args.output.exists():
            cli.args.output.replace(cli.args.output.parent / (cli.args.output.name + '.bak'))
        cli.args.output.write_text(version_h)

        if not cli.args.quiet:
            cli.log.info('Wrote version.h to %s.', cli.args.output)
    else:
        print(version_h)
=======
    if cli.args.skip_all:
        current_time = "1970-01-01-00:00:00"
    else:
        current_time = strftime(TIME_FMT)

    if cli.args.skip_git:
        git_dirty = False
        git_version = "NA"
        git_qmk_hash = "NA"
        chibios_version = "NA"
        chibios_contrib_version = "NA"
    else:
        git_dirty = git_is_dirty()
        git_version = git_get_version() or current_time
        git_qmk_hash = git_get_qmk_hash() or "Unknown"
        chibios_version = git_get_version("chibios", "os") or current_time
        chibios_contrib_version = git_get_version("chibios-contrib", "os") or current_time

    # Build the version.h file.
    version_h_lines = [GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE, '#pragma once']

    version_h_lines.append(
        f"""
#define QMK_VERSION "{git_version}"
#define QMK_BUILDDATE "{current_time}"
#define QMK_GIT_HASH  "{git_qmk_hash}{'*' if git_dirty else ''}"
#define CHIBIOS_VERSION "{chibios_version}"
#define CHIBIOS_CONTRIB_VERSION "{chibios_contrib_version}"
"""
    )

    # Show the results
    dump_lines(cli.args.output, version_h_lines, cli.args.quiet)
>>>>>>> upstream/master
