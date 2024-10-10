# Desync's Keymap
![Layout](images/layout.png?raw=true)

<img src="./images/left.gif" height="225"> <img src="./images/right.jpg" height="225"> <img src="./images/base display.png" height="225"> <img src="./images/edit display.png" height="225"> <img src="./images/waves.png" height="225"> <img src="./images/four-byte-burger.png" height="225">

---
# Features

- Base layer is a magic modded [graphite](https://github.com/rdavison/graphite-layout)/[gallium](https://github.com/GalileoBlues/Gallium) layout.
- Many common symbols and punctuation are accessible through combos.
- Home block mods on main layer.
- [Achordion](https://getreuer.info/posts/keyboards/achordion/index.html) enabled with opposite hand triggers and typing streak detection for home block mod and `Repeat`/`Magic` layer-tap safety.
- Control key overrides for easier left-hand only use; overrides disabled on home block mods.
- Mouse emulation accessible on pinky key combo; movement keys in same position as arrow keys on navigation layer, scrolling underneath in vim layout.
- Numpad and Steno (GeminiPR) layers accessible through combos.



## Dynamic Keys

![Base](images/base.png?raw=true)

`Repeat` and `Magic` are dynamic keys that return different outputs depending on the previous key.

As the name suggests, the Repeat key (generally) repeats the last key pressed; the Magic key (generally) swaps the first and second rows, along with various keys on the index columns. This eliminates many SFBs and double-taps, turning them into alternations and rolls.

The most common use-case for the swapping-rows behaviour is for the vowel block on the right side, turning the `OE`, `EO`, `IU`, and `UI` SFBs into rolls and alternations; as well as elimination various index finger SFBs on both sides (i.e., in the words `T[YP]E`, `[SC]IENCE`, `[HY][PH]EN`, etc.).

Letters that are not commonly repeated (i.e. `I`, `U`, `A`, `Q`) are overridden and instead return common n-grams.



### Magic Key

Left hand keys:
|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `Z` | `L` | `D` | `C` | `B` | `N`  | `R` | `T`   | `S` | `G` | `Q` | `X` | `M`   | `W` | `V` |
| Magic | `N` | `R` | `T` | `S` | `S` | `'T` | `L` | `ION` | `C` | `S` | `U` | `C` | `ENT` | `S` | `S` |

Right hand overrides:
|     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `J`   | `O` | `U` | `Y` | `H`   | `E` | `I`  | `K`  | `P` |
| Magic | `ECT` | `E` | `I` | `P` | `ERE` | `O` | `ON` | `EY` | `H` |

(Other right hand keys are repeated.)

Other:
|     |     |     |     |     |
| --- | --- | --- | --- | --- |
| `Non-alpha` | `⎵`         | `,`     | `.`   | `'`   |
| `OSM Shift` | `OSM Shift` | `⎵AND⎵` | `COM` | `LL⎵` |

### Repeat Key

Right hand keys:
|     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev   | `J`   | `F` | `O` | `U` | `Y` | `H` | `E` | `I` | `A` | `K` | `P` |
| Repeat | `UST` | `Y` | `O` | `I` | `P` | `Y` | `E` | `U` | `A` | `Y` | `P` |

Left hand overrides:
|     |     |     |     |
| --- | --- | --- | --- |
| Prev   | `Q`  | `V`  | `W`   |
| Repeat | `UI` | `ER` | `ITH` |

(Other left hand keys are repeated.)

Other:
|     |     |     |     |     |
| --- | --- | --- | --- | --- |
| `Non-alpha` | `⎵`   | `,`     | `.`   | `'`   |
| `THE`       | `THE` | `⎵BUT⎵` | `COM` | `RE⎵` |

---
### Details

Only the keys listed above are tracked (including those from combos); any other key is ignored:

> `a 1 [Rep]` produces `a 1 a`.

Modifiers are not tracked (but the dynamic keys may be modified):

> `[Shift] a [Release shift] [Magic]` produces `A a`;
>
>` a [Shift] [Magic] [Release shift] ` produces `a A`.

Any keys pressed while the control modifier is active are not tracked:

> `a [CTRL] b [Release CTRL] [Magic]` produces `a ^b a`.

`Backspace` reverts the tracked key to the previous key:

> `a b c [Rep]` produces `a b c c` (`Rep` returns `c`);
>
> `a b c [BSPC] [Rep]` produces `a b b` (`Rep` returns previous tracked key `b`).

Note that this feature only tracks two keys into the past.

For longer dynamic outputs, (e.g. `W -> WITH`) there is also a short window (default 500ms) in which `Backspace` will delete the entire magic output (i.e. `WITH -> W` rather than `WITH -> WIT`). Pressing any other key will instantly close this window.

After a short duration (default 1000ms) of no keyboard input, both dynamic keys will reset to the `Non-alpha` state, i.e., `OSM Shift`/`THE`.

After longer `Magic` outputs and those that output `S` (i.e. outputs that commonly end words), the `Rep` key will output `Space` to avoid SFBs on the left thumb for word breaks.

On QWERTY and Basic modes, both dynamic keys are overridden to only have repeat functionality.

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
- `New` combo presses `DOT`, `SPC`, then sets a one shot shift (same as `Newsent` key);
- `Del` combo deletes the current word;
- `<<` combo presses `M4` (`Back`); `>>` combo presses `M5` (`Forward`);
- `Join` combo joins current line to following line with space between; does not add space if shifted;
- `Line` combos adds new lines above/below the current position.



# Layers
### Base
![Base](images/base.png?raw=true)
Base layer alphas is a slightly modified graphite layout, with home block mods, and magic/repeat keys on middle thumb keys.

I find it difficult to press upper row keys with my pinkies and end up alt fingering them with my ring fingers, which introduces some SFBs (`BL`, `BR`) with the default Graphite layout. So, `J` and `B` have been moved off the outer top row; `B` has also been placed next to `C` to make the common `B_C` string not a skipgram. Also, I don't like `E` on the ring finger, so `HEIA` is used over `HAEI`.

> ℹ️ Note that this keymap internally uses a QWERTY layer (specifically, the `_BASIC` layer) for combos, so this Base layer can be modified easily without needing any changes to combo code. 
> 
> ⚠️ However, per-key mod-tap settings and Achordion will still need to be handled separately if home block mods are changed.

`Comma`, `Dot`, `Scln`, `Colon`, `Dash`, and `Exlm` are compressed together or omitted, as they accessible from combos near or on the home row. (These combos are accessible on almost every layer.) `Hash` is also included on base layer as I use it as a (La)TeX [snippet trigger]((https://gist.github.com/DesyncTheThird/0c7a18dc6bedaf27e2627c07f0c53e17))/(reverse) leader key.

`Tab` is on right hand to reduce left hand contortions and to keep it on home row. `Tab` key also functions as `RShift` when held. `New Sentence` macro sends a dot, a space, then sets a one shot shift.

The `LCTL` key also sets a weak one shot `ctrl` modifier for the `Backspace` key only to allow for faster usage while typing. The one shot modifier lingers for 500ms and is removed on any other keypress (without being applied).

### Data
![Data](images/data.png?raw=true)
Number grid with `1`, `2`, and `3` on right hand home row, along with arithmetic and numerical symbols on left hand, sharing locations from `Symbol` and `Program` layers.

Function keys also available for left hand only usage.



### Edit
![Edit](images/edit.png?raw=true)
Navigation/editing keys on left hand and paired delimiters and common symbol combinations on right hand.

Many common strings are inward rolls on right hand, e.g.; `[]`, `()`, `{}`, `^{}`, `_{}`, `!()`, `?()`; right hand also duplicated on Symbol and Program layers.

`Select` macro by [Getreuer](https://getreuer.info/posts/keyboards/select-word/index.html) selects the current word and extends selection by one word per subsequent press; holding shift selects/extends selection by lines instead.



### Symbol
![Symbol](images/symbol.png?raw=true)
Symbol layout optimised for (La)TeX editing with many common strings as inward rolls on left hand, e.g.; `<-`, `<=`, `->`, `>=`, `|->`, `<-`, `~>`, `:-`, `&=`, etc. (Intended to be used with [snippet extensions](https://gist.github.com/DesyncTheThird/0c7a18dc6bedaf27e2627c07f0c53e17).) Brackets on right hand as above.



### Program
![Program](images/program.png?raw=true)
Program layer optimised for c programming, with comparison operators as inward rolls, logical/bitwise operators symbols grouped on index finger, etc. Brackets on right hand as above.



### Utility
![Utility](images/utility.png?raw=true)
Utility layer containing media control, RGB controls, OLED controls, function keys, and debug functions. Layer is accessible using either outer thumb key (XOR).

The `Mute` thumb keys only activate on the hand opposite to the one holding the layer key to avoid accidental activations.

`Base` swaps default layer to QWERTY layout; `Basic` swaps default layer to QWERTY layout with home block mods and `Space` layer-tap disabled (useful for games).

`Clock` keys set the OLED clock. `OLED Static` disables animations and changes OLEDs to static images. `OLED Menu` toggles between layer stack view and layout display on right OLED.

`Alt Tab` key holds `LAlt` and taps `Tab` on first press; taps `Tab` on subsequent presses; `LAlt` is released when layer key is released.

Tap the `Reboot` key to reboot keyboard; hold for one second to enter bootloader.



### Mouse
![Mouse](images/mouse.png?raw=true)
Mouse emulation accessible on pinky key combo to allow mouse movement without moving from home row. Override cursor/scroll speed with right thumb keys.



### Control
![Control](images/control.png?raw=true)
Control key overrides with QWERTY-esque layout for easier left-hand only use. (I usually don't remember which *letter* does what command, only which key *position*.)

Overrides activate only from left hand control key; home block mods are unaffected, so intentional letter controls can be used in two-hand usage.



# Alt Base Layer
### QWERTY
![QWERTY](images/qwerty.png?raw=true)

Accessible with `Base` key on Utility layer, or `Basic` to also disable home block mods and `Space` layer-tap (for games).

> ⚠️ Modifying the _BASIC layer will also require changing mod-tap and combo code.



# Building

1. Set up a [local installation of QMK](https://docs.qmk.fm/newbs).

2. Clone this repository into `qmk_firmware\keyboards\crkbd\keymaps`.

   ```sh
   git clone https://github.com/DesyncTheThird/corne-keymap qmk_firmware\keyboards\crkbd\keymaps\desync
   ```

3. Install the `achordion` feature as per step 4 in [these instructions](https://getreuer.info/posts/keyboards/achordion/index.html#add-achordion-to-your-keymap).

   That is, in the cloned directory (i.e. the one containing `keymap.c`), add an new subdirectory called `features`, and copy [achordion.h](https://raw.githubusercontent.com/getreuer/qmk-keymap/main/features/achordion.h) and [achordion.c](https://raw.githubusercontent.com/getreuer/qmk-keymap/main/features/achordion.c) there.

4. Build the keymap from the [QMK CLI](https://docs.qmk.fm/cli#qmk-cli) with:

   ```sh
   qmk compile -c -kb crkbd -km desync
   ```

   Note, however:

> ⚠️ Unmodified, this keymap will not fit on most AVR MCUs (and in fact may fail to compile in some cases due to overflowing 8-bit integers).

For reference, my compiled uf2 file is 212kB (accurate as of commit [`4454bdd`](https://github.com/DesyncTheThird/corne-keymap/tree/4454bddad15e8470a2e288703569bdf98fe6e41c)), though you should be able to save a significant amount of space by removing various OLED animations, deleting unused layers (along with the associated OLED layout `PROGMEM`), and disabling additional RGB animations (the `CS_RGBN` key will need to be updated in this case).

See [here](https://docs.qmk.fm/squeezing_avr) for more ways to save space. (Most space-saving `rules.mk` and `config.h` options have already been enabled; only modify those files if you have disabled additional features in `keymap.c`.)

> ℹ️ I recommend using an RP2040 or another ARM MCU with more space. (Plus, they're generally cheaper and faster than AVR pro-micros.)

5. To use a drop-in replacement controller, additionally use a [converter](https://docs.qmk.fm/feature_converters#supported-converters) flag: `-e CONVERT_TO=<converter>`.

   For instance, I use a (non-Sparkfun) RP2040 controller, so my full build command is:

   ```sh
   qmk compile -c -kb crkbd -km desync -e CONVERT_TO=rp2040_ce
   ```
