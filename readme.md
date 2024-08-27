# Desync's Keymap
![Layout](images/layout.png?raw=true)


<img src="./images/left.gif" height="225"> <img src="./images/right.jpg" height="225"> <img src="./images/base display.png" height="225"> <img src="./images/edit display.png" height="225"> <img src="./images/waves.png" height="225"> <img src="./images/four-byte-burger.png" height="225">

---
# Features
- Common symbols and punctuation accessible through combos with many duplicated on both sides; combos trigger through most layers.
- Repeat key on right thumb, magic key on left thumb.
- Home block mods on main layer (toggle-able).
- Control key overrides for easier left-hand only use; overrides disabled on home block mods.
- Brackets/paired delimiters accessible on Edit layer with many common strings as inward rolls, e.g.; `[]`, `()`, `{}`, `^{}`, `_{}`, `!()`, `?()`; also duplicated on Symbol and Program layers.
- Symbol layer optimised for (La)TeX editing, with brackets and many common strings as inward rolls, e.g.; `<-`, `<=`, `->`, `>=`, `|->`, `<-`, `~>`, `:-`, `&=`, etc. (Intended to be used with snippet extensions.) Backslash also on main thumb key on this layer.
- Program layer optimised for c programming, with comparison operators as inward rolls, logical/bitwise operators symbols grouped on index finger, etc.
- Number layer with number grid on right hand with [1,2,3] on home row and common numerical punctuation on left hand.
- Function layer on right hand, F1-F5 duplicated on left side for left-hand only usage.
- Mouse emulation accessible on pinky key combo; movement same position as arrow keys on navigation layer, scrolling underneath in vim layout.
- Steno layer (using GeminiPR) accessible through combo.

### Magic Key

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `A` | `B`  | `C` | `D` | `E` | `F` | `G` | `H` | `I` | `J`   | `K` | `L` | `M`   | 
| Magic | `U` | `S`  | `S` | `T` | `O` | `Y` | `S` | `Y` | `U` | `UST` | `Y` | `R` | `ENT` |

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `N`   | `O` | `P` | `Q` | `R` | `S` | `T`   | `U` | `V`  | `W` | `X` | `Y` | `Z` |
| Magic | `ION` | `E` | `H` | `U` | `L` | `C` | `ION` | `I` | `ER` | `S` | --  | `P` | --  |

### Repeat Key Overrides

|     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev   | `A`  | `H`   | `I`  | `J`   | `K`  | `Q` | `V`  | `W`   | `Y`  |
| Repeat | `ND` | `ERE` | `NG` | `ECT` | `EY` | `U` | `ER` | `ITH` | `OU` |

`Repeat` key just repeats any other key; these overrides are on letters that are not commonly repeated.

`Backspace` reverts the tracked key to the previous distinct key:

> `a b c [Rep]` produces `a b c c` (`Rep` returns `c`);
>
> `a b c [BSPC] [Rep]` produces `a b b` (`Rep` returns previous tracked key `b`);

Duplicated keys are not tracked:

> `a b c c c c [BSPC] [Rep]` produces `a b c c c b` (`Rep` returns previous distinct tracked key `b`);

Repeat/magic key outputs are not tracked:

> `a [Rep] [Rep]` produces `a n d a` (`Rep` ignores `Rep` output and returns `a`, not `d`);
> 
> `b [Magic] [Rep]` produces `b s b` (`Rep` ignores `Magic` output and returns `b`, not `s`);
> 
> `b [Magic] [Magic]` produces `b s s` (`Magic` ignores `Magic` output and returns `s`, not `c`);


## OLEDs
(128x64 OLEDs)
### Right:
- Default layer and layer stack display;
- Menu key swaps layer stack to layout display;
- Clock -- time is set manually using keys on utility layer and doesn't require software on host (persists through sleep events);
- Custom locking key, modifier, and mute state indicators.

### Left:
- Cycles between text and logo with cyberpunk glich aesthetic animation;
- Logo displays WPM and current session time.

Key on utility layer available to change both OLEDs to static images.

# Combos

![Combos](images/combos.png?raw=true)

# Layers
![Base](images/base.png?raw=true)

![Data](images/data.png?raw=true)

![Edit](images/edit.png?raw=true)

![Symbol](images/symbol.png?raw=true)

![Program](images/program.png?raw=true)

![Utility](images/utility.png?raw=true)

![Mouse](images/mouse.png?raw=true)

![Control](images/control.png?raw=true)


# Alt Base Layer

![QWERTY](images/qwerty.png?raw=true)


