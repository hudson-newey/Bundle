# Bundler

A program to easily run, and distribute projects / templates

To fix name conflicts with ruby's [bundler](https://bundler.io), I suggest that you alias the hudson-newey/Bundler executable to `b`.

eg. Add the following line to your `~/.bashrc` or `~/.zshrc`

```sh
alias b=~/.local/bin/hudson-newey/Bundler/build/bundler;
```

To build from source, see [building.md](BUILDING.md)

## Inbuilt Commands

Alternatives / Shorthands are listed as sub items

- `bundler run`
  - `bundler r <templateName>`
  - `bundler r` (defaults to current directory bundle.yaml file)
  - `bundler` (defaults to current directory bundle.yaml file)
- `bundler list`
  - `bundler ls`
  - `bundler l`
- `bundler view <manifestName>`
  - `bundler v`
- `bundler install`
  - `bundler i`
- `bundler check`
  - `bundler c`
- `bundler new <templateName>`
  - `bundler n`
  - `bundler init` (same as `bundler new init`)
- `bundler ram <load|unload> <filePath>`
- `bundler commit`

### bundler run / bundler

Bundler run will run your projects "scripts", as specified within your bundle.yaml file

### bundler list

Lists out all avaliable manifests and templates that can be used with `bundler new` and `bundler run`

### bundler view

Prints the contents of a manifest file (a .yaml file located in the `~/.local/templates/` directory)

### bundler install

Runs install scripts in bundle

### bundler check

Checks that system dependencies are satisfied

### bundler new

Copies a template from _~./local/templates/templateName/_

### bundler ram load

Loads a file directory into RAM-disk for sub-millisecond read/write

## Example Addons

### bundler commit

A sample Bundler addon for `git`. This will add, commit and push your HEAD branch to origin.

---

**Footer Notes:**

I will only increment the bundler version when there is a breaking change to the bundle.yaml.

This includes:

- Additional features to the bundle.yaml spec
- Renaming of bundle.yaml keys
- Removal of bundle.yaml keys

This does **not** include:

- Bug fixes
- Changes to compiler support
- Additional features to the bundler cli
