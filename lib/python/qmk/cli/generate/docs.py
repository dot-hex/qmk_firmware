"""Build QMK documentation locally
"""
import shutil
<<<<<<< HEAD
from pathlib import Path
from subprocess import DEVNULL

from milc import cli

DOCS_PATH = Path('docs/')
BUILD_PATH = Path('.build/')
BUILD_DOCS_PATH = BUILD_PATH / 'docs'
DOXYGEN_PATH = BUILD_PATH / 'doxygen'

=======
from qmk.docs import prepare_docs_build_area, run_docs_command, BUILD_DOCS_PATH

from milc import cli

>>>>>>> upstream/master

@cli.argument('-s', '--serve', arg_only=True, action='store_true', help="Serves the generated docs once built.")
@cli.subcommand('Build QMK documentation.', hidden=False if cli.config.user.developer else True)
def generate_docs(cli):
    """Invoke the docs generation process

    TODO(unclaimed):
        * [ ] Add a real build step... something static docs
    """

<<<<<<< HEAD
    if BUILD_DOCS_PATH.exists():
        shutil.rmtree(BUILD_DOCS_PATH)
    if DOXYGEN_PATH.exists():
        shutil.rmtree(DOXYGEN_PATH)

    shutil.copytree(DOCS_PATH, BUILD_DOCS_PATH)

    # When not verbose we want to hide all output
    args = {
        'capture_output': False if cli.config.general.verbose else True,
        'check': True,
        'stdin': DEVNULL,
    }
=======
    if not shutil.which('doxygen'):
        cli.log.error('doxygen is not installed. Please install it and try again.')
        return

    if not shutil.which('yarn'):
        cli.log.error('yarn is not installed. Please install it and try again.')
        return
>>>>>>> upstream/master

    if not prepare_docs_build_area(is_production=True):
        return False

<<<<<<< HEAD
    # Generate internal docs
    cli.run(['doxygen', 'Doxyfile'], **args)
    cli.run(['moxygen', '-q', '-g', '-o', BUILD_DOCS_PATH / 'internals_%s.md', DOXYGEN_PATH / 'xml'], **args)

    cli.log.info('Successfully generated internal docs to %s.', BUILD_DOCS_PATH)
=======
    cli.log.info('Building vitepress docs')
    run_docs_command('run', 'docs:build')
    cli.log.info('Successfully generated docs to %s.', BUILD_DOCS_PATH)

    if cli.args.serve:
        if not cli.config.general.verbose:
            cli.log.info('Serving docs at http://localhost:4173/ (Ctrl+C to stop)')
        run_docs_command('run', 'docs:preview')
>>>>>>> upstream/master
