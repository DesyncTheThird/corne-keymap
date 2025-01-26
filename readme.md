# Desync's Keymap
![Layout](images/layout.png?raw=true)

<img src="./images/left.gif" height="225"> <img src="./images/right.jpg" height="225"> <img src="./images/base display.png" height="225"> <img src="./images/edit display.png" height="225"> <img src="./images/waves.png" height="225"> <img src="./images/four-byte-burger.png" height="225">

---

# Overview

- [Base layer](#base) is a [magic](#dynamic-keys) modded [graphite](https://github.com/rdavison/graphite-layout)/[gallium](https://github.com/GalileoBlues/Gallium) layout. ([Alternative base layers](#alt-base-layer) available.)
- Many common symbols and punctuation are accessible through [combos](#combos).
- Home row mods selectively available on most layers.
- [Achordion](https://getreuer.info/posts/keyboards/achordion/index.html) enabled with opposite hand triggers and typing streak detection for home row mod and `Repeat`/`Magic` layer-tap safety.
- [Rollback feature](#rollbacks) for magic outputs and macros.
- [Mouse emulation](#mouse) accessible on pinky key combo; movement keys in same position as arrow keys on navigation layer, scrolling underneath in vim arrow layout.
- Media control on [Utility layer](#utility).
- [Control key overrides](#control-overlay) for easier left-hand only use; overrides disabled on home row mods.
- Locking numpad and Steno (GeminiPR) layers accessible through combos.



# Features
## Dynamic Keys

![Base](images/base.png?raw=true)

`Repeat` and `Magic` are dynamic keys that return different outputs depending on the previous key.

As the name suggests, the Repeat key repeats the last key pressed; while the Magic key swaps the first and second rows, along with various keys on the index columns (with some exceptions, listed below). This eliminates many SFBs and double-taps, turning them into alternations and rolls.

The most common use-case for the swapping-rows behaviour is for the vowel block on the right side, turning the `OE`, `EO`, `IU`, and `UI` SFBs into rolls and alternations; as well as eliminating various index finger SFBs on both sides (i.e., in the words `T[YP]E`, `[SC]IENCE`, `[HYP]HEN`, etc.).

Letters that are not commonly repeated (i.e. `I`, `U`, `A`) are overridden and instead return common n-grams. (Some letters uncommonly repeated in prose are still common in LaTeX commands and have not been overridden.)



### Magic Key

Left hand keys:
|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `Z` | `L` | `D` | `C` | `B`       | `N`  | `R` | `T`    | `S` | `G` | `Q` | `X` | `M`   | `W` | `V` |
| Magic | `N` | `R` | `T` | `S` | `ECAUSE⎵` | `'T` | `L` | `MENT` | `C` | `S` | `U` | `C` | `ENT` | `S` | `S` |

Right hand overrides:
|     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `J`   | `O` | `U` | `Y` | `H`   | `E` | `I`  | `A`   |
| Magic | `ECT` | `E` | `I` | `P` | `ERE` | `O` | `ON` | `ND⎵` |

(Other right hand keys are repeated.)

Other:
|     |     |     |     |     |
| --- | --- | --- | --- | --- |
| `Non-alpha` | `⎵`         | `,`     | `.`             | `'`   |
| `OSM Shift` | `OSM Shift` | `⎵AND⎵` | `⎵`+`OSM Shift` | `VE⎵` |

### Repeat Key

Right hand keys:
|     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev   | `J`   | `F` | `O` | `U` | `Y` | `H` | `E` | `I` | `A`   | `K` | `P` |
| Repeat | `UST` | `Y` | `O` | `I` | `P` | `Y` | `E` | `U` | `ND⎵` | `Y` | `H` |

Left hand overrides:
|     |     |     |     |
| --- | --- | --- | --- |
| Prev   | `X`  | `V`  | `W`   |
| Repeat | `ES` | `ER` | `ITH` |

(Other left hand keys are repeated.)

Other:
|     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- |
| `Magic`* | `Non-alpha` | `⎵`   | `,`     | `.`   | `'`   |
| `⎵`      | `THE`       | `THE` | `⎵BUT⎵` | `COM` | `RE⎵` |

*Unless the previous magic output already ended with a space, in which case the repeat key will default to the `Non-alpha` state; or if the previous magic output was a basic repeat (`F`, `K`, and `P`), in which case the repeat key will treat the magic key as an ordinary alpha key.

---
### Details

Only the keys listed above are tracked (including those from combos). Pressing any other key resets the key to the default `Non-alpha` state (i.e. `OSM Shift`/`THE`).

> `a 1 [Rep]` produces `a 1 the`.

Modifiers are not tracked (but the dynamic keys may be modified):

> `[Shift] a [Release shift] [Magic]` produces `A a`;
>
>` a [Shift] [Magic] [Release shift] ` produces `a A`.

Any keys pressed while the control modifier is active are not tracked. This does not reset key tracking:

> `a [CTRL] b [Release CTRL] [Magic]` produces `a ^b a`.

`Backspace` reverts the tracked key to the previous key:

> `a b c [Rep]` produces `a b c c` (`Rep` returns `c`);
>
> `a b c [BSPC] [Rep]` produces `a b b` (`Rep` returns previous tracked key `b`).

Note that this feature only tracks two keys into the past.

After a short duration (default 1000ms) of no keyboard input, both dynamic keys will reset to the `Non-alpha` state.

In QWERTY and Basic modes, both dynamic keys are overridden to only have repeat functionality.



## Rollbacks

For longer dynamic key outputs (e.g. `W -> WITH`), there is a short window (default 500ms) in which `Backspace` will delete ("rollback") the entire magic output (i.e. `WITH -> W` rather than `WITH -> WIT`).

Pressing any other key will instantly close this window.

This feature is also reused to rollback various macro outputs in a single keypress.

> ℹ️ You can hook into this feature with the `process_key_tracking` and `rollback_last_key` functions.



## OLEDs
(128x64 OLEDs)
### Right:
- Default layer and layer stack display;
- Menu key swaps layer stack to layout display;
- Clock — time is set manually using keys on utility layer and doesn't require software on host (persists through sleep events);
- Custom locking key, modifier, and mute state indicators.

### Left:
- Cycles between text and logo with cyberpunk glich aesthetic animation (based on [this code](https://gist.github.com/aleksbrgt/48a8eb932dc1b6aa8f4b36ecd7c380d0));
- Logo displays WPM and current session time.

Key on utility layer available to change both OLEDs to static images.



# Combos
![Combos](images/combos.png?raw=true)

(Press `Esc`, `;`, and `#` to access Touhou layer and to see funky Cirno fumo on right OLED.)

---
- Common punctuation is accessible from combos on or near home row;
- Mouse emulation layer accessible on pinky key combos to allow mouse control without moving from home row.
- Uncommon locking layers (numpad/steno) also accessible from large combos;
- `New` combo presses `DOT`, `SPC`, then sets a one shot shift;
- `Del` combo deletes the current word;
- `<<` combo presses `M4` (`Back`); `>>` combo presses `M5` (`Forward`);
- `Join` combo joins current line to following line with space between; does not add space if shifted;
- `Line` combos adds new lines above/below the current position.



# ⚠️ Experimental Features
Various additional experimental features that have not yet been incorporated into the main keymap may be found on various branches. Current features in development:

### [Steno-lite](https://github.com/DesyncTheThird/corne-keymap/tree/steno-lite)
This feature adds a selection of combos that output common words or word fragments.

Any of these combos can be triggered by pressing `Magic` *or* `Repeat`, along with the specified combo keys listed below:

|     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Combo  | `T`   | `A`   | `TH`   | `TI`   | `H`    | `HA`   | `W`    | `Y`   | `S`    |
| Output | `the` | `and` | `that` | `this` | `here` | `have` | `with` | `you` | `some` |

|     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Combo  | `WH`   | `B`   | `WI`    | `J`    | `M`    | `I`   | `E`    | `F`    |
| Output | `what` | `but` | `which` | `just` | `ment` | `ing` | `ever` | `from` |

### [Quadrant-based mouse keys](https://github.com/DesyncTheThird/corne-keymap/tree/quad-mousekeys)
Based on qmk/qmk_firmware#24760, this feature uses the digitiser support to move the mouse pointer to absolute positions rather than relative ones as per the built-in mouse keys feature as follows: the screen is divided up into a quadrants; pressing one of the directional keys snaps the pointer to the centre of that quadrant, and then the grid is rescaled to the quadrant; then, movement can be repeated within the quadrant.

The original thread uses 8 directional keys and shrinks the grid uniformly in every direction, but I found the diagonal keys difficult to use. This version instead only allows four directional keys, and tracks the vertical and horizontal scales separately; pressing up will snap the pointer upwards and reduce the vertical scale, but leave the horizontal scale unchanged, and vice versa; moving along the same axis twice will reduce the scale in both directions. I find this version more intuitive to use as it more closely matches the standard inverted-T key layout, where you press (or alternate between) multiple direction keys to move diagonally.

Due to the digitiser feature mapping outputs to the whole virtual desktop, it does not interact well with multiple monitors, as the minimum step size becomes much too large; furthermore, the digitiser feature can also attempt to place the cursor offscreen if the virtual desktop is not a rectangle, which is especially prominent if the monitors have different orientations or unusual positionings. However, on single monitors, this feature has the potential to be much faster than using standard mouse keys.

I currently keep a copy of this fork on my offside half, so I can swap to it when not at my desktop by plugging in the other side of the split. In the future, I may add the ability to toggle between the two modes in the main keymap.



# Layers
### Base
![Base](images/base.png?raw=true)
Base layer alphas is a slightly modified graphite layout, with home row mods, and magic/repeat keys on middle thumb keys.

I find it difficult to press upper row keys with my pinkies and end up alt fingering them with my ring fingers, which introduces some SFBs (`BL`, `BR`) with the default Graphite layout. So, `J` and `B` have been moved off the outer top row; `B` has also been placed next to `C` to make the common `B_C` string not a skipgram. Also, I don't like `E` on the ring finger, so `HEIA` is used over `HAEI`.

> ℹ️ Note that this keymap internally uses a QWERTY layer (specifically, the `_BASIC` layer) for combos, so this Base layer can be modified easily without needing any changes to combo code. 
> 
> ⚠️ However, per-key mod-tap settings and Achordion will still need to be handled separately if home row mods are changed.

`Comma`, `Dot`, `Scln`, `Colon`, `Dash`, and `Exlm` are compressed together or omitted, as they accessible from combos near or on the home row. (These combos are accessible on almost every layer.) `Hash` is also included on base layer as I use it as a LaTeX [snippet trigger]((https://gist.github.com/DesyncTheThird/0c7a18dc6bedaf27e2627c07f0c53e17))/(reverse) leader key.

A copy of `Tab` is placed on the right hand to reduce left hand contortions. The two `Tab` keys also function as `LShift` and `RShift` when held. The shift modifiers are applied eagerly on keydown to improve interaction with pointing devices; these eager shift modifiers do not overwrite home row mods, so you can still shift-tab with one hand.

The `LCTL` key also sets a weak one shot `ctrl` modifier for the `Backspace` key only to allow for faster usage while typing. The one shot modifier lingers for 500ms and is removed on any other keypress (without being applied).

### Data
![Data](images/data.png?raw=true)
Number grid with `1`, `2`, and `3` on right hand home row, along with common numerical separators on left hand, sharing similar layout to `Symbol` and `Program` layers.

Arithmetic symbols on right hand share positions with combos, `-` not included as it is a home row combo; `@` is also available on this layer as many email handles end with numbers, and also because I use it as a leader key for LaTeX commands; and `~` is available for git commands.

The bracket macros `(-)` and `[-]` sends the listed brackets, then taps `Left`, placing the cursor between the two brackets. The `[-]` macro is shiftable. These macros also interact properly with the rollback feature.

Function keys also available for left hand only usage.



### Edit
![Edit](images/edit.png?raw=true)
Navigation/editing keys on left hand and paired delimiters and common symbol combinations on right hand.

Many common strings are inward rolls on right hand, e.g.; `[]`, `()`, `{}`, `^{}`, `_{}`, `!()`, `?()`; right hand also duplicated on Symbol and Program layers.

Activating both `Data` and `Program` layers will activate the `Edit` layer on top to allow for quick navigation. This is implemented via the tri-layer feature, so the layer keys may be released in any order without issue.

See also the [Edit Overlay](#edit-overlay).



### Symbol
![Symbol](images/symbol.png?raw=true)
Symbol layout optimised for (La)TeX editing with many common strings as inward rolls on left hand, e.g.; `<-`, `<=`, `->`, `>=`, `|->`, `<-`, `~>`, `|>`, `:=`, `:-`, `&=`, etc. (Intended to be used with [snippet extensions](https://gist.github.com/DesyncTheThird/0c7a18dc6bedaf27e2627c07f0c53e17).) Brackets on right hand as above.



### Program
![Program](images/program.png?raw=true)
Program layer optimised for programming (mostly C and Python). Inward rolls include:
- comparison operators: `!=`, `>=`, `<=` on home row;
- arithmetic assignment operators: `^=`, `+=`, `-=`, `*=`, `/=` above and below home row.
Bitwise operator symbols are grouped on the inner index column. Holding shift while pressing `&` or `|` will send the respective symbol twice, i.e. as logical operators.

Brackets on right hand as above.



### Utility
![Utility](images/utility.png?raw=true)
Utility layer containing media control, RGB controls, OLED controls, function keys, and debug functions. Layer is accessible using either outer thumb key (XOR).

The `Mute` thumb keys only activate on the hand opposite to the one holding the layer key to avoid accidental activations. The `Volume Up/Down` keys are macros that rapidly and repeatedly send the volume control keycodes for smooth volume control; holding shift sends the keycodes only once for finer control.

`Base` swaps default layer to QWERTY layout; `Basic` swaps default layer to QWERTY layout with home row mods and `Space` layer-tap disabled (useful for games).

`Clock` keys set the OLED clock. `OLED Static` disables animations and changes OLEDs to static images. `OLED Menu` toggles between layer stack view and layout display on right OLED.

`Alt Tab` key holds `LAlt` and taps `Tab` on first press; taps `Tab` on subsequent presses; `LAlt` is released when layer key is released.

Tap the `Reboot` key to reboot keyboard; hold for one second to enter bootloader.



### Mouse
![Mouse](images/mouse.png?raw=true)
Mouse emulation accessible on pinky key combo to allow mouse movement without moving from home row. A mirrored left hand combo is also available, intended to be used with the layer lock feature.

Cursor/scroll speed may be overridden with right thumb keys for higher speed or finer control.



# Overlay Layers

### Control Overlay
![Control](images/control.png?raw=true)
Control key overrides with QWERTY-esque layout for easier left-hand only use. (I usually don't remember which *letter* does what command, only which key *position*, particularly for graphical and editing software)

Overrides activate only from left hand control key; home row mods are unaffected, so ntentional letter controls can be used in two-hand usage.



### Edit Overlay
![Edit Overlay](images/edit_overlay.png?raw=true)
Activating the `Program` layer while on the `Edit` layer will activate the `Edit Overlay` layer on top (of the `Edit` layer). This is implemented via the tri-layer feature, so the layer keys may be released in any order without issue. 

This layer contains macros useful for text selection and deletion:
- The three macros at the top enclose the current word with the listed brackets. These macros also interoperate with the rollback feature.
- The `< Del` and `Del >` macros delete the previous and forward characters in current word, respectively.
- `Select` macro selects the current word, or select the current line if shifted.

The `LCTL` modifier is also held for the keys listed on the left while this layer is active, apart from the `Home` and `End` keys, for which the `LSFT` modifier is held instead.



# Alt Base Layer
### QWERTY
![QWERTY](images/qwerty.png?raw=true)

Accessible with `Base` key on Utility layer, or `Basic` to also disable home row mods and `Space` layer-tap (for games).

> ⚠️ Modifying the _BASIC layer will also require changing mod-tap and combo code.



# Building

1. Set up a [local installation of QMK](https://docs.qmk.fm/newbs).

2. Clone this repository into `qmk_firmware\keyboards\crkbd\keymaps`.

   ```sh
   git clone https://github.com/DesyncTheThird/corne-keymap qmk_firmware\keyboards\crkbd\keymaps\desync
   ```

3. Install the `achordion` feature as per step 4 in [these instructions](https://getreuer.info/posts/keyboards/achordion/index.html#add-achordion-to-your-keymap).

   That is, in the cloned directory (i.e. the one containing `keymap.c`), add a new subdirectory called `features`, and copy [achordion.h](https://raw.githubusercontent.com/getreuer/qmk-keymap/main/features/achordion.h) and [achordion.c](https://raw.githubusercontent.com/getreuer/qmk-keymap/main/features/achordion.c) there.

4. Build the keymap from the [QMK CLI](https://docs.qmk.fm/cli#qmk-cli) with:

   ```sh
   qmk compile -c -kb crkbd -km desync
   ```

   Note, however:

> ⚠️ Unmodified, this keymap will not fit on most AVR MCUs (and in fact may fail to compile in some cases due to overflowing 8-bit integers).

For reference, my compiled uf2 file is 218kB (accurate as of commit [`972be81`](https://github.com/DesyncTheThird/corne-keymap/tree/972be8199a39604a71828d9c83535090095b7b2f)), though you should be able to save a significant amount of space by removing various OLED animations, deleting unused layers (along with the associated OLED layout `PROGMEM`), and disabling additional RGB animations (the `CS_RGBN` key will need to be updated in this case).

See [here](https://docs.qmk.fm/squeezing_avr) for more ways to save space. (Most space-saving `rules.mk` and `config.h` options have already been enabled; only modify those files if you have disabled additional features in `keymap.c`.)

> ℹ️ I recommend using an RP2040 or another ARM MCU with more space. (Plus, they're generally cheaper and faster than AVR pro-micros.)

5. To use a drop-in replacement controller, additionally use a [converter](https://docs.qmk.fm/feature_converters#supported-converters) flag: `-e CONVERT_TO=<converter>`.

   For instance, I use a (non-Sparkfun) RP2040 controller, so my full build command is:

   ```sh
   qmk compile -c -kb crkbd -km desync -e CONVERT_TO=rp2040_ce
   ```

6. OS Setup:
   - Regional layout: English (United Kingdom)
