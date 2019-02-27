# DZ60 layout for Dyon :D

Pull the QMK repo.
Pull repo to `keyboards/gh60`

Run the docker command
```
docker run -e keymap=gh60-dyon -e subproject="" -e keyboard=gh60 --rm -v PATH_TO_QMK_FIRMWARE:/qmk:rw edasque/qmk_firmware
```

Flash resulting hex

## Layout
```
Hold ESC to toggle layer
Layer + WASD = Move mouse
Layer + O = Media play/pause
Layer + I = Increase volume
Layer + U = Decrease volume
Layer + Y = Next song
Layer + T = Previous song
Layer + H = Arrow Left
Layer + J = Arrow Down
Layer + K = Arrow Up
Layer + L = Arrow Right
Layer + Shift + H = Home
Layer + Shift + J = Page Down
Layer + Shift + K = Page Up
Layer + Shift + L = End

Keymap _BL: (Base Layer) Default Layer
,-----------------------------------------------------------.
|~   | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
|-----------------------------------------------------------|
|Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
|-----------------------------------------------------------|
|Esc    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
|-----------------------------------------------------------|
|Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
|-----------------------------------------------------------|
|Ctrl|Alt |Gui |      Space            |Left|Down|Up |Right |
`-----------------------------------------------------------'

Keymap _FL: Function Layer
,-----------------------------------------------------------.
|     |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12| Del |
|-----------------------------------------------------------|
|S Ins|   |Mup|   |   |Prv|Nxt|Vdn|Vup|Ply|   |   |   |     |
|-----------------------------------------------------------|
|      |Mle|Mdo|Mri|   |   |Left|Down| Up |Right|    |      |
|-----------------------------------------------------------|
|        |   |   |   |   |   |   |   |   |   |     |        |
|-----------------------------------------------------------|
|    |    |    |      Mouse left   |    |      |        |   |
`-----------------------------------------------------------'

Keymap _SF: Shifted Function Layer
,-----------------------------------------------------------.
|     |   |   |   |   |   |   |   |   |   |   |   |   |     |
|-----------------------------------------------------------|
|     |   |   |   |   |   |    |    |      |    |    | |  | |
|-----------------------------------------------------------|
|      |   |   |   |   |   |Home|PgDn|PgUp|End|    |        |
|-----------------------------------------------------------|
|        |   |   |   |   |   |   |   |   |   |     |        |
|-----------------------------------------------------------|
|    |    |    |                       |    |    |   |      |
`-----------------------------------------------------------'
```
