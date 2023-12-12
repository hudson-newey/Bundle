#pragma once

// the bundler version is increased every time a breaking change is made
#define BUNDLER_VERSION "1.0"
#define BUNDLER_FILE "bundle.yaml"

#define BUNDLER_HELP_DOCS "Bundler is a program to easily run, and distribute projects / templates.\n\n\tUsage:\n\t\tbundler [command] [options]\n\n\tCommands:\n\t\trun, r          Run the project\n\t\tcheck, c        Check all dependencies are installed\n\t\tinstall, i      Install all dependencies\n\t\tnew, n          Create a new project from a template\n\t\tram             Load/Unload a file into/from ram\n\n\tFlags:\n\t\t-h, --help      Show this help message\n\t\t-v, --version   Show the version of bundler\n\n"
