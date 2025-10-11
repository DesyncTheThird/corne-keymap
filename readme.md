# Desync's Keymap
![Layout](images/dark_layout.png?raw=true)

<img src="./images/left.gif" width="110"> <img src="./images/right.jpg" width="113"> <img src="./images/base display.png" width="110"> <img src="./images/edit display.png" width="110"> <img src="./images/waves.png" width="180"> <img src="./images/pro_micro.png" width="180">

See also [here](https://github.com/DesyncTheThird/OLED-art) for more OLED art.

---

# Overview

- [Base layer](#base) is a [magic](#dynamic-keys) modded [graphite](https://github.com/rdavison/graphite-layout)/[gallium](https://github.com/GalileoBlues/Gallium) layout. ([Alternative base layers](#alt-base-layer) available.)
- Many common symbols and punctuation are accessible through [combos](#combos).
- Home row mods selectively available on most layers.
- [Chordal Hold](https://docs.qmk.fm/tap_hold#chordal-hold) enabled with opposite hand triggers for home row mod and `Repeat`/`Magic` layer-tap safety.
- [Rollback feature](#rollbacks) for magic outputs and macros.
- [Case Lock](#case-lock) for easy `snake_case`, `kebab-case`, `camelCase`, etc.
- [Mouse emulation](#mouse) accessible on pinky key combo; movement keys in same position as arrow keys on navigation layer, scrolling underneath in vim arrow layout.
- Media control on [Utility layer](#utility).
- [Control key overrides](#control-overlay) for easier left-hand only use; overrides disabled on home row mods.
- Locking numpad and Steno (GeminiPR) layers accessible through combos.

### [⬇️ Download compiled binaries (for RP2040-CE)](/compiled/)



# Features
## Dynamic Keys

![Base](images/base.png?raw=true)

This keymap features four *dynamic keys* that emit different characters depending on the surrounding context. Two are on the home thumb keys, and two are under the vowel cluster on the right hand.

---

The `Repeat` key generally repeats the last key pressed, while the `Magic` key generally swaps the first and second rows, along with various keys on the index columns (with some exceptions, listed below). This eliminates many SFBs and double-taps, turning them into alternations and rolls.

The most common use-case for the swapping-rows behaviour is for the vowel block on the right side, turning the `OE`, `EO`, `IU`, and `UI` SFBs into rolls and alternations, as well as eliminating various index finger SFBs on both sides (i.e., in the words `T[YP]E`, `[SC]IENCE`, `[HYP]HEN`, etc.).

Letters that are not commonly repeated (i.e. `I`, `U`, `A`) are overridden and instead return common n-grams. (Some letters uncommonly repeated in prose are still common in LaTeX commands and have not been overridden.)



### Magic Key

Left hand keys:
|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `Z` | `L` | `D` | `C` | `B`       | `N`  | `R` | `T`    | `S` | `G` | `Q` | `X` | `M`   | `W` | `V` |
| Magic | `N` | `R` | `G` | `S` | `ECAUSE⎵` | `'T` | `L` | `MENT` | `C` | `S` | `U` | `C` | `ENT` | `S` | `S` |

Right hand overrides:
|     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `J`   | `O` | `U` | `Y` | `H`   | `E` | `I`  | `A`   | `K`   |
| Magic | `ECT` | `E` | `I` | `P` | `ERE` | `O` | `ON` | `ND⎵` | `NOW` |

(Other right hand keys are repeated.)

Other:
|     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- |
| `Non-alpha` | `Undo` | `Redo` | `⎵`         | `,`     | `.`             | `'`   |
| `OSM Shift` | `Redo` | `Undo` | `OSM Shift` | `⎵AND⎵` | `⎵`+`OSM Shift` | `VE⎵` |

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
|     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- |
| `Non-alpha` | `Undo` | `Redo` | `⎵`   | `,`     | `.`   | `'`   |
| `THE`       | `Undo` | `Redo` | `THE` | `⎵BUT⎵` | `COM` | `RE⎵` |

> [!NOTE]
> These outputs can be adjusted in the `process_magic` function.



---

### Details

Only the keys listed above are tracked (including those from combos). Pressing any other key resets the key to the default `Non-alpha` state (i.e. `OSM Shift`/`THE`).

> `a 1 [Rep]` produces `a 1 the`.

Modifiers are not tracked (but the dynamic keys may be modified):

> `[Shift] a [Release shift] [Magic]` produces `A a`;
>
>` a [Shift] [Magic] [Release shift] ` produces `a A`.

Any keys pressed while the control modifier is active are not tracked. This does not reset key tracking:

> `a [Ctrl] b [Release Ctrl] [Magic]` produces `a ^b a`.

`Backspace` reverts the tracked key to the previous key:

> `a b c [Rep]` produces `a b c c` (`Rep` returns `c`);
>
> `a b c [BSPC] [Rep]` produces `a b b` (`Rep` returns previous tracked key `b`).

Note that this feature only tracks two keys into the past.

After a short duration (default 1000ms) of no keyboard input, both dynamic keys will reset to the `Non-alpha` state.

Punctuation following a dynamic output that ends with a space will remove the space within the timeout duration.

> [!NOTE]
> In QWERTY and Basic modes, both dynamic keys are overridden to only have repeat functionality. This behaviour can also be changed in `process_magic`, though the default output tables as above will not make much sense for QWERTY layouts.

---



### Magic Punctuation

The two punctuation keys beneath the vowel cluster emit different outputs depending on both the previous *and* following keys:

| Key    | Previous   | Next       | Output          |
| ------ | ---------- | ---------- | --------------- |
| Either | `N`        | `T`        | `[n]'t⎵`        |
| Either | `N`        | `B`        | `[n].b.`        |
| Left   | `I`        | `E`        | `[i].e.`        |
| Left   | `A`        | `M`        | `[a].m.`        |
| Either | `P`        | `M`        | `[p].m.`        |
| Right  | `⎵`        | Immediate  | `[⎵]-`          |
| Right  | `E`        | `G`        | `[e].g.`        |
| Either | Any Key    | `Enter`    | `[-];`+`Enter`  |
| Left   | `S`        | `⎵`        | `[s]'⎵`         |
| Either | Any Letter | `⎵`        | `[-],⎵`         |
| Either | Any Letter | `D`        | `[-]'d⎵`        |
| Either | Any Letter | `L`        | `[-]'ll⎵`       |
| Either | Any Letter | `V`        | `[-]'ve⎵`       |
| Either | Any Letter | `M`        | `[-]'m⎵`        |
| Either | Any Letter | `S`        | `[-]'s⎵`        |
| Either | Any Letter | `R`        | `[-]'re⎵`       |
| Left   | Either     | Immediate  | `''`            |
| Right  | Either     | Immediate  | `,`             |

Immediate rules eagerly trigger on magic-key-down if matched; other rules trigger on next-key-down.

The rules have been set up such that pressing whichever punctuation key is more comfortable while typing (i.e. sequences that aren't SFBs) will generally produce contextually sensible punctuation.

> [!NOTE]
> New rules can be added to the `keymatch_rule_t match_rules[]` table. The rules are matched greedily top down, so more general rules should go lower in the table and specific rules higher up.
>
> For example, `S`+`Left`+`Spc` will return `s'⎵` rather than `s,⎵`, because the specific rule `Either`+`S`+`⎵` is above the general rule `Either`+`Any`+`⎵`. If the rules were reversed, the latter would never be matched as a subset of the former.

> [!WARNING]
> Immediate rules should always return true in the `track_t` attribute despite not having a following key to consume, or else other tracking systems will not function.

If your language uses dicritics, more rules can be added to these keys to support these outputs.

The following key must be pressed within 500ms for the dynamic output to activate; otherwise, the keys will default to emitting `'` (left) or `,` (right) after the timer expires. If a following key is pressed, but no rules are matched, the timer will immediately resolve, and `'` or `,` will be placed immediately before the next key's output.

> [!NOTE]
> In these fallthrough cases, the `Magic` and `Repeat` keys will track these punctuation keys as `'` and `,`, e.g. pressing `Right`+`Repeat` will emit `,⎵but⎵`.

When shifted, the left magic key always outputs `@`, and the right magic key always outputs `~`.



## Rollbacks

For longer dynamic key outputs (e.g. `W -> WITH`), there is a short window (default 500ms) in which `Backspace` will delete ("rollback") the entire magic output (i.e. `WITH -> W` rather than `WITH -> WIT`).

Pressing any other key will instantly close this window.

This feature is also reused to rollback various macro outputs in a single keypress.

> [!NOTE]
> You can hook into this feature with the `process_key_tracking` and `rollback_last_key` functions.



## Case Lock
Tapping the `Case Lock` key will prime the feature, capturing the next key pressed to be used as a separator. Then, the `Space` key will emit the captured separator instead of a space.

By default, the only keys that can be captured are:
- `_` (snake_case),
- `-` (kebab-case),
- `.` (dot.case),
- `/` (unix/file/path),
- `\` (win\file\path) [activated by `Magic`],
- `LSFT` (camelCase),
- `RSFT` (Title Case),
- `Case Lock` (enables `Caps Lock`).

Pressing any other key activates snake_case by default.

> [!NOTE]
> This can be customised in the `process_case_lock` and `process_case_capture` functions.

The capture will time out after a short duration of no input (default 1000ms), cancelling the capture. Case Lock will also time out after a short duration of no input (default 2000ms).

Tapping the `Space` key again after a separator will delete the separator, disable Case Lock, and output a space.

While Case Lock is active, `Ctrl`+`BSPC` will instead delete to the previous separator rather than deleting the entire word.

To indicate that the feature is active, the per-key LEDs will glow green while the feature is primed, and red while active.



## Combos
![Combos](images/combos.png?raw=true)

(Press `Esc`, `;`, and `#` to access Touhou layer and to see funky Cirno fumo on right OLED.)

---

Pressing `Space` plus a key on the left hand top row will output the function keys `F1` to `F5` for left-hand-only usage. (Not shown on image due to reduce clutter.)

Common punctuation is accessible from combos on or near home row. Mouse emulation layer is accessible on pinky key combos to allow mouse control without moving from home row. Uncommon locking layers (numpad/steno) are also accessible from large combos.

- `New` combo emits `Dot`, `Space`, then sets a one shot shift;
- `⇄` thumb combo transposes the previous two characters.
- `«` thumb combo emits `Ctrl`+`Bspc`;

The Caps Word feature shifts letter keys (including `Magic` and `Repeat` outputs) and is automatically disabled at the end of the word. The shift modifier will also be retained between separators while the [Case Lock](#case-lock) feature is active.



## 128x64 OLEDs

<img src="./images/left.gif" width="110"> <img src="./images/right.jpg" width="113"> <img src="./images/base display.png" width="110"> <img src="./images/edit display.png" width="110"> <img src="./images/waves.png" width="180"> <img src="./images/pro_micro.png" width="180">

See also [here](https://github.com/DesyncTheThird/OLED-art) for more OLED art.

### Left:
- Cycles between text and logo with cyberpunk glitch aesthetic animation (based on [this code](https://gist.github.com/aleksbrgt/48a8eb932dc1b6aa8f4b36ecd7c380d0));
- Logo displays WPM and current session time.

### Right:
- Default layer and layer stack display;
- `Menu` key on [`Utility` layer](#utility) swaps layer stack to layout display;
- Clock — time is set manually using keys on `Utility` layer and doesn't require software on host (persists through sleep events);
- Custom locking key, modifier, and mute state indicators.
- `OLED Static` key on `Utility` layer swaps both OLEDs to static images.

> [!NOTE]
> You can change the static images by updating `static_left` and `static_right` in `menu.c`.



# ⚠️ Experimental Features
Various additional experimental features that have not yet been incorporated into the main keymap may be found on various branches. Current features in development:

### [Steno-lite](https://github.com/DesyncTheThird/corne-keymap/tree/steno-lite)
This feature adds a selection of combos that output common words or word fragments.

These combos can be triggered by pressing `Magic` or `Repeat`, along with the specified combo keys listed below. Most of these combos agree with magic/repeat outputs.

Magic:
|     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Combo  | `B`        | `T`      | `TH`    | `TI`    | `S`     | `M`     | `W`     | `WH`    |
| Output | `because⎵` | `tment⎵` | `that⎵` | `this⎵` | `some⎵` | `ment⎵` | `with⎵` | `what⎵` |

|     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Combo  | `WI`     | `J`     | `F`     | `Y`       | `H`     | `E`      |`I`     | `A`     |
| Output | `which⎵` | `ject⎵` | `from⎵` | `you've⎵` | `here⎵` | `every⎵` | `ion⎵` |`about⎵` |

Repeat:
|     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Combo  | `B`    | `T`   | `TH`   | `TI`   | `S`    | `M`    | `W`    | `WH`   |
| Output | `but⎵` | `the` | `that` | `this` | `some` | `ment` | `with` | `what` |

|     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Combo  | `WI`    | `J`    | `F`    | `Y`       | `H`    | `E`     |`I`     | `A`  |
| Output | `which` | `just` | `from` | `you're⎵` | `have` | `every` | `ing⎵` |`and` |



### [Arrow Layout Toggle](https://github.com/DesyncTheThird/corne-keymap/tree/edit-mode-toggle)
This feature allows you to swap the arrow keys on the `Edit` layer between an inverted-T and line (vim-like) layout.

<img src="./images/line arrow layout.png" width="49%"> <img src="./images/inverted-T arrow layout.png" width="49%">

Pressing the pinky key (line left) while in inverted-T swaps to line mode, and pressing the upper middle key (inverted-T up) while in line mode swaps to inverted-T.



### [Quadrant-based mouse keys](https://github.com/DesyncTheThird/corne-keymap/tree/quad-mousekeys)
Based on qmk/qmk_firmware#24760, this feature uses the digitiser support to move the mouse pointer to absolute positions rather than relative ones as per the built-in mouse keys feature as follows: the screen is divided up into a quadrants; pressing one of the directional keys snaps the pointer to the centre of that quadrant, and then the grid is rescaled to the quadrant; then, movement can be repeated within the quadrant.

The original thread uses 8 directional keys and shrinks the grid uniformly in every direction, but I found the diagonal keys difficult to use. This version instead only allows four directional keys, and tracks the vertical and horizontal scales separately; pressing up will snap the pointer upwards and reduce the vertical scale, but leave the horizontal scale unchanged, and vice versa; moving along the same axis twice will reduce the scale in both directions. I find this version more intuitive to use as it more closely matches the standard inverted-T key layout, where you press (or alternate between) multiple direction keys to move diagonally.

Due to the digitiser feature mapping outputs to the whole virtual desktop, it does not interact well with multiple monitors, as the minimum step size becomes much too large; furthermore, the digitiser feature can also attempt to place the cursor offscreen if the virtual desktop is not a rectangle, which is especially prominent if the monitors have different orientations or unusual positionings. However, on single monitors, this feature has the potential to be much faster than using standard mouse keys.



### [Number Case](https://github.com/DesyncTheThird/corne-keymap/tree/numcase)
This feature adds a toggle on the `Data` layer(s) that replaces the number keys with Roman numerals when active. Useful for some LaTeX editing. Could easily be extended to multiple cases by adding more cases to the switch statement in `process_number_case`, e.g. binary/octal/hexadecimal, Base64, ordinals (`1st`, `2nd`, `3rd`), parenthesised (`(1)`, `(2)`, `(3)`), prefixed/suffixed (`1.`, `2.`, `3.` / `1)`, `2)`, `3)`), words (`one`, `two`, `three`), etc.



# Layers
### Base
![Base](images/base.png?raw=true)
Base layer alphas is a modified graphite layout, with home row mods, [magic/repeat keys](#dynamic-keys) on home thumb keys, and [magic punctuation keys](#magic-punctuation) under the right hand vowel cluster.

I find it difficult to press upper row keys with my pinkies and end up alt fingering them with my ring fingers, which introduces some SFBs (`BL`, `BR`) with the default graphite layout. I also find the upper inner index column keys much easier to press, so I have swapped the less common keys placed there with these pinky keys. The `C` and `W` keys have also been swapped to place `C` next to `B` to make the common `B_C` string not a skipgram. Also, I don't like `E` on the ring finger, so `HEIA` is used over `HAEI`.

> [!NOTE]
> The keymap internally uses a QWERTY layer (specifically, the `_BASIC` layer) for combo tracking, so this `Base` layer can be modified easily without needing any changes to combo code.

> [!WARNING]
> However, per-key mod-tap settings and Chordal Hold config will still need to be handled separately if home row mods are changed.

Many punctuation marks common in prose are accessible through [combos](#combos) near or on the home row. (These combos are accessible on almost every layer.) `Hash` is also included on base layer as I use it as a LaTeX [snippet trigger]((https://gist.github.com/DesyncTheThird/0c7a18dc6bedaf27e2627c07f0c53e17))/(reverse) leader key.

A copy of `Tab` is placed on the right hand to reduce left hand contortions. The two `Tab` keys also function as `LShift` and `RShift` when held. The shift modifiers are applied eagerly on keydown to improve interaction with pointing devices; these eager shift modifiers do not overwrite home row mods, so you can still shift-tab with one hand.

The `LCTL` key also sets a weak one shot `Ctrl` modifier for the `Backspace` key only to allow for faster usage while typing. The one shot modifier lingers for 500ms and is removed on any other keypress (without being applied).



## Data
![Data](images/data.png?raw=true)
Number grid with `1`, `2`, and `3` on right hand home row, along with common numerical separators on left hand home row, sharing similar layout to `Symbol` and `Program` layers.

The inner column on the right hand has *cycling macros* which cycle between different outputs on repeated presses:
- `Misc`: `%` -> `@` -> `£` -> `` -> ...
- `Bracket`: `()` -> `{}` -> `[]` -> `()` -> ...

  This macro places the cursor between the two brackets with each press.

- `Comp`: `>` -> `<` -> `=` -> `>` -> ...

These macros interoperate with the rollback feature.

Activating both `Data` and `Program` layers will also activate the `Edit` layer on top to allow for quick navigation during numerical input. This is implemented via the tri-layer feature, so the layer keys may be released in any order without issue.



## Edit
![Edit](images/edit.png?raw=true)
Navigation/editing keys on left hand and paired delimiters and common symbol combinations on right hand. I prefer the navigation cluster on the left hand to allow usage with the mouse.

Many common strings are inward rolls on right hand, e.g.; `[]`, `()`, `{}`, `^{}`, `_{}`, `?()`; right hand also duplicated on `Symbol` and `Program` layers.

The bottom row of the [`Control Overlay`](#control-overlay) can also be activated with home row mods on this layer.

### Macros

The `Lock` key activates the [Layer Lock](https://docs.qmk.fm/features/layer_lock) feature, for extended navigation.

The left hand bracket macro surrounds the current word with brackets, and cycles the bracket type on subsequent presses:
- `⟦⟳⟧`: `(-)` -> `{-}` -> `[-]` -> `(-)` -> ...

In place of the bracket macro as on the `Data` layer, there is an enumeration macro:
- The `++` macro outputs `1` on first press and increments on subsequent presses, rolling over to `0` after `9`, and resetting to `1` when the `Edit` layer is released.

The two directional `Select` macros select in the indicated directions from the current cursor position. Pressing/holding the keys will extend the selection one word at a time; activating the opposite macro will retract the selection instead.

The `Select` macro selects the current word; pressing it again within 200ms will cut (`Ctrl`+`X`) the selection. Pressing `Select` within 500ms of either of the other two directional `Select` macros will also immediately cut the selection.

Pressing the `Select Right` key within 200ms of the `Select` key will copy (`Ctrl`+`C`) the selection; pressing `Select Left` will delete the selection; and pressing `Enter` will paste over the selection.

After cutting with `Select`, copying with `Select Right`, or deleting with `Select Left`, the `Enter` key on this layer will act as paste, resetting after the first use or if the `Edit` layer is disabled.

The right thumb keys also have additional layering actions:
- Activating both `Edit` and `Program` layers will activate the [`Edit Overlay`](#edit-overlay), which contains macros useful for editing, and also hold the `LCTL` or `LSFT` modifier for various keys on the left hand.
- Activating both `Edit` and `Symbol` layers will replace the right hand with a copy of the `Data` layer (with `_` replaced by `0`, since the thumb keys are not accessible in this configuration).

These are both implemented via the tri-layer feature, so the layer keys may be released in any order without issue.

### Arrows

If an arrow key is held on the `Edit` layer while the `Edit Overlay` is activated, the arrow key will be retriggered with a persistent `Ctrl` modifier, allowing quick horizontal navigation/vertical scrolling without having to manually re-press the arrow key after holding a modifier. If the modifier has been lost, retriggering on layer-off is disabled, avoiding pauses in motion.

The modifier will be disabled if no arrow key is pressed for 1000ms; if an arrow key is double-tapped within 150ms, or if any other key is pressed.

The `Ctrl` key will also become sticky for arrow keys while the overlay is active, reactivating the persistent modifier. Home row mods will also automatically retrigger arrow keys on the `Edit` layer.

> [!NOTE]
> You can modify these features in the `process_arrow_retrigger` function.



## Symbol
![Symbol](images/symbol.png?raw=true)
Symbol layout optimised for (La)TeX editing with many common strings as inward rolls on left hand, e.g.; `<-`, `<=`, `->`, `>=`, `|->`, `<-`, `|>`, `:=`, `:-`, `&=`, etc. (Intended to be used with [snippet extensions](https://gist.github.com/DesyncTheThird/0c7a18dc6bedaf27e2627c07f0c53e17).) Brackets on right hand as above.



## Program
![Program](images/program.png?raw=true)
`Program` layer optimised for programming in mostly C and Python. Inward rolls include:
- Comparison operators: `!=`, `>=`, `<=` on home row;
- Arithmetic assignment operators: `^=`, `+=`, `-=`, `*=`, `/=` above and below home row.
Bitwise operator symbols are grouped on the inner index column.

Holding shift while pressing `&` or `|` will send the respective symbol twice, i.e. as logical operators, and holding control will add spaces.

Brackets on right hand as above.



## Utility
![Utility](images/utility.png?raw=true)
`Utility` layer containing media control, RGB controls, OLED controls, function keys, and debug functions. Layer is accessible using either outer thumb key.

The `Mute` thumb keys only activate on the hand opposite to the one holding the layer key to avoid accidental activations. The `Volume Up/Down` keys are macros that rapidly and repeatedly send the volume control keycodes for smooth volume control; holding shift sends the keycodes only once for finer control.

`Base` swaps default layer to QWERTY layout; `Basic` swaps default layer to QWERTY layout with home row mods and `Space` layer-tap disabled (right hand `Data` layer is still accessible by simultaneously activating `Edit` and `Symbol` layers).

`Clock` keys set the OLED clock. `OLED Static` disables animations and changes OLEDs to static images. `OLED Menu` toggles between layer stack view and layout display on right OLED.

`Alt Tab` key holds `LAlt` and taps `Tab` on first press; taps `Tab` on subsequent presses; `LAlt` is released when layer key is released.

Tap the `Reboot` key to reboot keyboard; hold for one second to enter bootloader.



## Mouse
![Mouse](images/mouse.png?raw=true)
Mouse emulation accessible on pinky key combo to allow mouse movement without moving from home row. A mirrored left hand combo is also available, intended to be used with the layer lock feature.

Cursor/scroll speed may be overridden with right thumb keys for higher speed or finer control.



# Overlay Layers

## Control Overlay
![Control](images/control.png?raw=true)
Control key overrides with QWERTY-esque layout for easier left-hand only use. (I usually don't remember which *letter* does what command, only which key *position*, particularly for graphical and editing software.)

Overrides activate only from left hand control key on a base layer; home row mods are unaffected, so intentional letter controls can be used in two-hand usage.

Holding `LCTL` on any layer (including non-base layers) covers the left hand bottom row with: `Redo`, `Undo`, `Cut`, `Copy`, and `Paste` shortcuts (i.e. overlays only the bottom row of this layer).



## Edit Overlay
![Edit Overlay](images/edit_overlay.png?raw=true)
Activating the `Program` and `Edit` layers simultaneously will activate the `Edit Overlay` layer on top (of the `Edit` layer). This is implemented via the tri-layer feature, so the layer keys may be released in any order without issue.

The right hand is replaced with macros useful for editing:
- The directional `Delete` macros delete in the indicated directions from the current cursor position to the beginning/end of the current line.
- The `Line` macros add new lines above/below the current line; deletes left/right instead if `Shift` or `Ctrl` is active.
- The `Join` macro joins current line to following line with space between; omits the space if `Shift` or `Ctrl` is active.
- The three bracket macros enclose the current word with the listed brackets. These macros also interoperate with the rollback feature.



# Alt Base Layer
## QWERTY
![QWERTY](images/qwerty.png?raw=true)

Accessible with `Base` key on `Utility` layer, or `Basic` to also disable home row mods and `Space` layer-tap (for games).

> [!WARNING]
> Modifying the _BASIC layer will also require changing mod-tap and combo code.



# Some notes on implementation

### CS_XXXX Keycodes
I've had problems in the past with rolling built-in shifted keycodes. For instance, `&=` is a very common inward roll (in LaTeX), but the shift from the ampersand would often persist through to the equals symbol, outputting `&+` instead. (And similar problems with other rolls.)

The `CS_XXXX` keycodes explicitly reset shift modifiers before sending the intended keycode, fixing this issue. They also rename the keycodes to their ISO counterparts. These keycodes also can't be shifted manually: this is intended -- every symbol should be accessible on some layer without needing the shift key at all -- shift should only be needed for normal letters.

This has probably been fixed in the years since I first encountered this issue, but there's little reason to swap back to ordinary keycodes as; the keycode renaming is convenient for maintenance; the shift-disabling behaviour is desired; and it works as-is.

I also don't use key overrides for this purpose, because they override all matching instances of inputs when active, and sometimes I do want to manually send strange combinations of modifiers and keycodes.

By the way, `CS` originally stood for `Custom Symbol`, but I've ended up using the prefix for any custom key I implement, mostly because it's easy to search/regex for.

### Layers
You may notice that this keymap has a lot of layers defined. In practice however, you'll only really be using 6 or so layers: the `Base` layer, `Edit`, `Data`, `Symbol`, `Program`, and `Utility`. The other 10 are either persistent locking layers (different base layers/numpad/steno, etc.), or are there to make the internal layer switching implementation simpler (including "overlay" layers).

Because layers are arranged in a stack that is scanned top-down, there isn't an easy way to move from a higher layer to a lower layer momentarily. I've done some implementations of this before, but they are often error-prone to work with, difficult to maintain and troubleshoot, and often don't interact well with other features. Alternatively, I could make every key on every layer that needs this behaviour a custom key that performs different actions depending on the currently held keys, but this is even worse for maintenance, even if it is slightly more memory efficient. To save myself the trouble, I just stack extra layers on top wherever I need them.

### Repeat Key
I am aware that there is a built-in QMK implementation of the repeat/magic key. However, my original implementation predates the repeat key being merged into the main branch. Furthermore, I've customised my dynamic keys so much at this point that it's easier to keep using my own implementation as I keep all of the functions exposed and can hook into it anywhere. In particular, the rollback feature and various dynamic macros do this extensively.

### Other
If there's anything else in the keymap that looks inefficient or badly implemented, that's probably because it's very old and I didn't want to look into it too deeply when refactoring, and/or I didn't put much thought into it when I was first making it.

If you find a way to clean up some of my code or fix some bugs, that's lovely, and a PR would be appreciated. However, this is my personal keymap, so I will not be accepting any PRs that change functionality meaningfully; please make a fork if you would like to experiment on your own copy.



# Building

Precompiled binaries for RP2040 controllers can be found [here](/compiled/). Otherwise:

1. Set up a [local installation of QMK](https://docs.qmk.fm/newbs).

2. Clone this repository into `qmk_firmware\keyboards\crkbd\keymaps`.

   ```sh
   git clone https://github.com/DesyncTheThird/corne-keymap qmk_firmware\keyboards\crkbd\keymaps\desync
   ```

3. Build the keymap from the [QMK CLI](https://docs.qmk.fm/cli#qmk-cli) with:

   ```sh
   qmk compile -c -kb crkbd -km desync
   ```

   Note, however:

> [!CAUTION]
> Unmodified, this keymap will not fit on most AVR MCUs (and in fact may fail to compile in some cases due to overflowing 8-bit integers).

For reference, my compiled uf2 file is 220kB (accurate as of commit [`dd59929`](https://github.com/DesyncTheThird/corne-keymap/tree/dd599294d9cbd42c863b7d2914a1f687b2181fc3)), though you should be able to save a significant amount of space by removing various OLED animations, deleting unused layers (along with the associated OLED layout `PROGMEM`), and disabling additional RGB animations (the `CS_RGBN` key will need to be updated in this case).

See [here](https://docs.qmk.fm/squeezing_avr) for more ways to save space. (Most space-saving `rules.mk` and `config.h` options have already been enabled; only modify those files if you have disabled additional features in `keymap.c`.)

> [!TIP]
> I recommend using an RP2040 or another ARM MCU with more space. (Plus, they're generally cheaper and faster than AVR pro-micros.)

4. To use a drop-in replacement controller, additionally use a [converter](https://docs.qmk.fm/feature_converters#supported-converters) flag: `-e CONVERT_TO=<converter>`.

   For instance, I use a (non-Sparkfun) RP2040 controller, so my full build command is:
   ```sh
   qmk compile -c -kb crkbd -km desync -e CONVERT_TO=rp2040_ce
   ```

5. By default, the keymap is set up to use `EE_HANDS`. To enable this on RP2040 controllers, you need to flash each side using different commands as follows:
   ```sh
   qmk flash -c -kb crkbd -km desync -e CONVERT_TO=rp2040_ce -bl uf2-split-right
   ```
   and
   ```sh
   qmk flash -c -kb crkbd -km desync -e CONVERT_TO=rp2040_ce -bl uf2-split-left
   ```

> [!WARNING]
> The `-bl` flag does not work with the `qmk compile` command, only `qmk flash`.

6. OS Setup:
   - Regional layout: English (United Kingdom)
