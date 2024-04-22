# Bundle

A program to easily run, and distribute projects / templates

To build from source, see [building.md](BUILDING.md)

## Inbuilt Commands

Alternatives / Shorthands are listed as sub items

- `bundle run`
  - `bundle r <templateName>`
  - `bundle r` (defaults to current directory bundle.yaml file)
  - `bundle` (defaults to current directory bundle.yaml file)
- `bundle list`
  - `bundle ls`
  - `bundle l`
- `bundle view <manifestName>`
  - `bundle v`
- `bundle install`
  - `bundle i`
- `bundle check`
  - `bundle c`
- `bundle new <templateName>`
  - `bundle n`
  - `bundle init` (same as `bundle new init`)
- `bundle ram <load|unload> <filePath>`
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

Copies a template from _~./local/templates/templateName/_

### bundle ram load

Loads a file directory into RAM-disk for sub-millisecond read/write

## Example Addons

### bundle commit

A sample bundle addon for `git`. This will add, commit and push your HEAD branch to origin.

---

**Footer Notes:**

I will only increment the bundle version when there is a breaking change to the bundle.yaml.

This includes:

- Additional features to the bundle.yaml spec
- Renaming of bundle.yaml keys
- Removal of bundle.yaml keys

This does **not** include:

- Bug fixes
- Changes to compiler support
- Additional features to the bundle cli
