# Simple Operating System

The simulation of major components in a simple operating system, for example, scheduler synchronization, related operations of physical memory and virtual memory.

Visit my [documentation](https://ngyngcphu.github.io/Simple-Operating-System/) for more details.

## Prerequisites

- `Ubuntu` 22.04 LTS

## Commands

- `make all`: compile the whole source code.
- `./os [path to configure file] [path to output file]`: run simulation  
`[path to configure file]` in folder **input** and `[path to output file]` is name of output file which you want to set in folder **output**, example:
```sh
make all
./os os_0_mlq_paging os_0_mlq_paging.output
```

## Project structure

```py
 ┣ 📂docs           # Documentation for this repo.
 ┣ 📂include        # Header files.
 ┣ 📂input          # Samples input used for verification.
 ┣ 📂obj            # Include objects file after run make all.
 ┣ 📂output         # Samples output of the operating system.
 ┣ 📂src            # Source files.
 ┣ 📜Makefile       # Include scripts to compile source code. 
```

## Git working culture

- For every updates, DO NOT push directly to `master` branch. Create a new branch, commit, publish branch and create a pull request (PR) instead.
- A branch should have prefix `features/` for a feature update, prefix `hotfixes/` for a hotfix, `improvs/` for an improvement ...
- A PR should be small enough to review. To split a large PR, use [stacked PRs](https://blog.logrocket.com/using-stacked-pull-requests-in-github/).