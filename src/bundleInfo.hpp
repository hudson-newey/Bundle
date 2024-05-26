#pragma once

// the bundle version is increased every time a breaking change is made
#define BUNDLE_VERSION "1.2"
#define BUNDLE_HELP_DOCS "Bundle is a program to easily run, and distribute projects / templates.\n\n\tUsage:\n\t\tbundle [command] [options]\n\n\tCommands:\n\t\trun, r          Run the project\n\t\tcheck, c        Check all dependencies are installed\n\t\tinstall, i      Install all dependencies\n\t\tnew, n          Create a new project from a template\n\t\tram             Load/Unload a file into/from ram\n\n\tFlags:\n\t\t-h, --help      Show this help message\n\t\t-v, --version   Show the version of bundle\n"

#define BUNDLE_ENV_ROOT "/.local/share/bundle/env"

// Todo: This is a hack so that I can change the target bundle at runtime
std::string BUNDLE_FILE = "bundle.yaml";

std::string ramDiskPartition = "/mnt/ram";
