# Bundler

A framework to easily run, distribute and edit your projects

## Inbuilt Commands

* `bundler run`
* `bundler` (same as `bundler run`)
* `bundler install`
* `bundler check`
* `bundler init` (same as `bundler new init`)
* `bundler commit`
* `bundler new <templateName>`
* `bundler ram <load|unload> <filePath>`

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

## Addons:

### bundler commit

A sample Bundler addon for `git`. This will add, commit and push your HEAD branch to origin
