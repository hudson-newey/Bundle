# Bundle

A program to easily run, and distribute projects / templates

To build from source, see [building.md](BUILDING.md)

## Inbuilt Commands

Alternatives / Shorthands are listed as sub items

- `bundle run`
  - `bundle r <template-name>`
  - `bundle r` (defaults to current directory bundle.yaml file)
  - `bundle` (defaults to current directory bundle.yaml file)
- `bundle list`
  - `bundle ls`
  - `bundle l`
- `bundle view <manifest-name>`
  - `bundle v`
- `bundle install`
  - `bundle i`
- `bundle check`
  - `bundle c`
- `bundle new <template-name>`
  - `bundle n`
  - `bundle init` (same as `bundle new init`)
- `bundle save <path> [template-name]`
  - `bundle s`
- `bundle delete <template-name>`
  - `bundle del`
  - `bundle d`
- `bundle ram <load|unload> <file-path>`
- `bundle commit`

### bundle run / bundle

Bundle run will run your projects "scripts", as specified within your bundle.yaml file

### bundle list

Lists out all avaliable manifests and templates that can be used with `bundle new` and `bundle run`

### bundle view

Prints the contents of a manifest file (a .yaml file located in the `~/.local/templates/` directory)

### bundle install

Runs install scripts in bundle

### bundle check

Checks that system dependencies are satisfied

### bundle new

Copies a template from _~./local/templates/template-name/_

### bundle save

Saves a directory of file as a template or manifest to be used with `bundle new` or `bundle run`

### bundle delete

Deletes a template or manifest

### bundle ram load

Loads a file directory into RAM-disk for sub-millisecond read/write
