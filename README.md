# Bundler

A framework to easily run, distribute and edit your projects

To fix name conflicts with ruby's [bundler](https://bundler.io), I suggest that you alias the hudson-newey/Bundler executable to `b`.

eg. Add the following line to your `~/.bashrc` or `~/.zshrc`

```sh
alias b=~/.local/bin/hudson-newey/Bundler/build/bundler;
```

To build from source, see [building.md](BUILDING.md)

## Inbuilt Commands

Alternatives / Shorthands are listed as sub items

- `bundler run`
  - `bundler r`
  - `bundler`
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
