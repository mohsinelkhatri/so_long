<h1 align="center">🎮 so_long – 2D Mini-Game Project (42 / 1337 School)</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Library-MiniLibX-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-No%20Bonus-orange?style=for-the-badge">
</p>

<p style="font-size:16px;">
The <strong>so_long</strong> project is a small 2D game built using the MiniLibX graphics library.  
The goal is to read a map file, validate it, load textures, and allow the player to move around, collect items, and reach the exit.
This README covers the mandatory part only (no bonus).
</p>

<hr>

<h2 align="center">📌 Project Overview</h2>

<p>
You must create a simple top-down game where:
</p>

<ul>
  <li>🧍 The player moves with WASD/arrow keys</li>
  <li>💰 The player must collect all collectibles</li>
  <li>🚪 The exit only works after collecting everything</li>
  <li>🟩 The map is loaded from <code>.ber</code> file</li>
  <li>🖼 All graphics use MiniLibX textures</li>
</ul>

<hr>

<h2 align="center">📁 Repository Structure (Your Project)</h2>

<pre style="background:#1e1e1e; color:#00e676; padding:15px; border-radius:8px;">
so_long/
│
├── libs/
│   ├── ft_printf/
│   └── get_next_line/
│
├── map/
│   └── map.ber
│
├── start_game/
│   ├── events.c
│   ├── fill_textures.c
│   └── start_game.c
│
├── textures/
│   ├── 0.xpm
│   ├── 1.xpm
│   ├── c.xpm
│   ├── e.xpm
│   ├── pd.xpm
│   ├── pl.xpm
│   ├── pr.xpm
│   └── pu.xpm
│
├── utils/
│   ├── error.c
│   ├── find_coords.c
│   ├── free_map.c
│   ├── ft_atoi.c
│   ├── ft_split.c
│   ├── is_all_collected.c
│   ├── map_height.c
│   ├── map_width.c
│   └── freall.c
│
├── validate_map/
│   ├── check_border.c
│   ├── check_characters.c
│   ├── check_shape.c
│   ├── check_way.c
│   └── validate_map.c
│
├── main.c
├── parse_map.c
├── so_long.h
└── Makefile
</pre>

<hr>

<h2 align="center">🗺 Map Rules (Mandatory Part)</h2>

<p>Your <code>.ber</code> map must follow strict rules:</p>

<ul>
  <li>Map must be rectangular (same width for all rows)</li>
  <li>Map must be surrounded by walls (<strong>1</strong>)</li>
  <li>Characters allowed:
    <ul>
      <li><strong>0</strong> → empty floor</li>
      <li><strong>1</strong> → wall</li>
      <li><strong>C</strong> → collectible</li>
      <li><strong>E</strong> → exit</li>
      <li><strong>P</strong> → player</li>
    </ul>
  </li>
  <li>Must contain:
    <ul>
      <li>1x player (P)</li>
      <li>1x exit (E)</li>
      <li>At least 1 collectible (C)</li>
    </ul>
  </li>
  <li>Map must be solvable → player can reach all Cs and E</li>
</ul>

<hr>

<h2 align="center">🧪 Map Validation (Your validate_map Folder)</h2>

<p>The following files validate all mandatory rules:</p>

<ul>
  <li><strong>check_border.c</strong> – verifies map is surrounded by walls</li>
  <li><strong>check_characters.c</strong> – allowed characters & required counts</li>
  <li><strong>check_shape.c</strong> – checks if map is rectangular</li>
  <li><strong>check_way.c</strong> – flood-fill to verify solvability</li>
  <li><strong>validate_map.c</strong> – main validation function</li>
</ul>

<hr>

<h2 align="center">🎮 Game Engine (Your start_game Folder)</h2>

<p>These files initialize the game window and handle gameplay:</p>

<ul>
  <li><strong>start_game.c</strong> – sets up MLX, loads map, starts game</li>
  <li><strong>fill_textures.c</strong> – loads all .xpm textures into MLX</li>
  <li><strong>events.c</strong> – handles keypresses, movement, and exit</li>
</ul>

<hr>

<h2 align="center">🖼 Textures (XPM Files)</h2>

<p>All game graphics are stored in <code>textures/</code>:</p>

<ul>
  <li>0.xpm → floor</li>
  <li>1.xpm → wall</li>
  <li>c.xpm → collectible</li>
  <li>e.xpm → exit</li>
  <li>pd.xpm / pl.xpm / pr.xpm / pu.xpm → player sprites</li>
</ul>

<hr>

<h2 align="center">🔧 Utility Functions (Your utils Folder)</h2>

<ul>
  <li><strong>ft_split.c</strong> – splits map file into 2D array</li>
  <li><strong>map_width.c / map_height.c</strong></li>
  <li><strong>find_coords.c</strong> – get player or exit coordinates</li>
  <li><strong>is_all_collected.c</strong></li>
  <li><strong>free_map.c / freall.c</strong></li>
  <li><strong>error.c</strong> – error messages + exit</li>
  <li><strong>ft_atoi.c</strong> – custom atoi for safety</li>
</ul>

<hr>

<h2 align="center">🚀 Game Flow</h2>

<ol>
  <li>Load <code>.ber</code> file</li>
  <li>Validate map structure</li>
  <li>Extract player coordinates</li>
  <li>Load window via MiniLibX</li>
  <li>Render all textures</li>
  <li>Handle input:
    <ul>
      <li>W / ↑ → move up</li>
      <li>A / ← → move left</li>
      <li>S / ↓ → move down</li>
      <li>D / → → move right</li>
    </ul>
  </li>
  <li>Player collects all Cs</li>
  <li>Exit becomes active</li>
  <li>Player reaches E → game ends</li>
</ol>

<hr>

<h2 align="center">🛠 Compilation & Execution</h2>

<pre style="background:#1e1e1e; color:white; padding:14px; border-radius:8px;">
make
./so_long map/map.ber
</pre>

<hr>

<h2 align="center">❗ Error Handling</h2>

<p>The program must exit with an error message if:</p>

<ul>
  <li>Invalid file extension</li>
  <li>Map is not valid</li>
  <li>Multiple Ps or Es</li>
  <li>No collectibles</li>
  <li>Map is not solvable</li>
  <li>Map is not rectangular</li>
</ul>

<hr>

<h2 align="center">📜 License</h2>

<p style="font-size:16px;">
This project README is designed for students of <strong>42 Network / 1337 School</strong>.  
You may use and modify it for learning and documentation purposes.
</p>

<hr>

<h1 align="center">🎉 Good luck and have fun coding so_long! 🎉</h1>
