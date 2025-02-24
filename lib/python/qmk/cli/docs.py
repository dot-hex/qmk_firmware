"""Serve QMK documentation locally
"""
<<<<<<< HEAD
import http.server
import os
import shutil
import webbrowser
=======
import shutil
from qmk.docs import prepare_docs_build_area, run_docs_command
>>>>>>> upstream/master

from milc import cli


<<<<<<< HEAD
@cli.argument('-p', '--port', default=8936, type=int, help='Port number to use.')
@cli.argument('-b', '--browser', action='store_true', help='Open the docs in the default browser.')
=======
>>>>>>> upstream/master
@cli.subcommand('Run a local webserver for QMK documentation.', hidden=False if cli.config.user.developer else True)
def docs(cli):
    """Spin up a local HTTP server for the QMK docs.
    """

<<<<<<< HEAD
    # If docsify-cli is installed, run that instead so we get live reload
    if shutil.which('docsify'):
        command = ['docsify', 'serve', '--port', f'{cli.config.docs.port}', '--open' if cli.config.docs.browser else '']

        cli.log.info(f"Running {{fg_cyan}}{str.join(' ', command)}{{fg_reset}}")
        cli.log.info("Press Control+C to exit.")

        try:
            cli.run(command, capture_output=False)
        except KeyboardInterrupt:
            cli.log.info("Stopping HTTP server...")
    else:
        # Fall back to Python HTTPServer
        with http.server.HTTPServer(('', cli.config.docs.port), http.server.SimpleHTTPRequestHandler) as httpd:
            cli.log.info(f"Serving QMK docs at http://localhost:{cli.config.docs.port}/")
            cli.log.info("Press Control+C to exit.")

            if cli.config.docs.browser:
                webbrowser.open(f'http://localhost:{cli.config.docs.port}')

            try:
                httpd.serve_forever()
            except KeyboardInterrupt:
                cli.log.info("Stopping HTTP server...")
            finally:
                httpd.shutdown()
=======
    if not shutil.which('doxygen'):
        cli.log.error('doxygen is not installed. Please install it and try again.')
        return

    if not shutil.which('yarn'):
        cli.log.error('yarn is not installed. Please install it and try again.')
        return

    if not prepare_docs_build_area(is_production=False):
        return False

    if not cli.config.general.verbose:
        cli.log.info('Serving docs at http://localhost:5173/ (Ctrl+C to stop)')
    run_docs_command('run', 'docs:dev')
>>>>>>> upstream/master
