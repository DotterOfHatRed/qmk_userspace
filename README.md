# QMK Userspace

This is an experimental repository which allows for an external set of QMK keymaps to be defined and compiled. This is useful for users who want to maintain their own keymaps without having to fork the main QMK repository.

**By default, the keymap name used is the GitHub username.**

## Howto build with GitHub

1. Fork this repository
2. Add your keymap to the `keyboards` directory, in the same location that would normally be used in the main QMK repository. For example, if you wanted to add a keymap for the Planck, you would add it to `keyboards/planck/keymaps/<your keymap name>/keymap.c` or `keyboards/planck/keymaps/<your keymap name>/keymap.json`, depending on the type of keymap you have.
3. Commit your changes
4. Look at the GitHub Actions for a new actions run
5. Wait for the actions run to complete
6. Inspect the Releases tab on your repository for the latest firmware build

## Howto build locally

**For the moment, this procedure will only work if you've got the `qmk-userspace` branch of `qmk_firmware` checked out. Once merged to `master`, this becomes generally available.**

1. Run the normal `qmk setup` procedure if you haven't already done so
2. Fork this repository
3. Clone your fork
4. `cd` into this repository
5. (Optional) set global userspace path: `qmk config user.overlay_dir=$(realpath .)` -- you MUST be located in the cloned userspace location for this to work correctly
6. Add your keymap to the `keyboards` directory, in the same location that would normally be used in the main QMK repository. For example, if you wanted to add a keymap for the Planck, you would add it to `keyboards/planck/keymaps/<your keymap name>/keymap.c` or `keyboards/planck/keymaps/<your keymap name>/keymap.json`, depending on the type of keymap you have.
7. Compile normally: `qmk compile -kb your_keyboard -km your_keymap` or `make your_keyboard:your_keymap`

## Extra info

If you wish to point GitHub actions to a different repository, a different branch, or even a different keymap name, you can modify `.github/workflows/build_binaries.yml` to suit your needs.

To override the `build` job, you can change the following parameters to use a different target/branch/keymap:
```
    with:
      qmk_repo: qmk/qmk_firmware
      qmk_ref: master
      qmk_keymap: my_keymap
```

If you wish to manually manage `qmk_firmware` using git within the userspace repository, you can add `qmk_firmware` as a submodule in the userspace directory. GitHub Actions will automatically use the submodule at the pinned revision if it exists, otherwise it will use the default latest revision of `qmk_firmware` from the main repository.

This can also be used to control which fork is used, though only upstream `qmk_firmware` will have support for external userspace until other manufacturers update their forks.

1. (First time only) `git submodule add https://github.com/qmk/qmk_firmware.git`
2. (To update) `git submodule update --init --recursive`
3. Commit your changes to the userspace repository