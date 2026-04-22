mkdir -p maps/valid maps/invalid

# VALID MAPS
cat > maps/valid/valid1.ber << EOF
11111
1P0C1
10001
1C0E1
11111
EOF

cat > maps/valid/valid2.ber << EOF
1111111
1P00001
1111101
1C00001
1011111
1C000E1
1111111
EOF

cat > maps/valid/valid3.ber << EOF
11111
1PE01
1C001
11111
EOF

# INVALID MAPS
cat > maps/invalid/invalid_no_exit.ber << EOF
11111
1P0C1
10001
1C001
11111
EOF

cat > maps/invalid/invalid_unreachable_exit.ber << EOF
11111
1P0C1
111E1
1C001
11111
EOF

cat > maps/invalid/invalid_unreachable_collectible.ber << EOF
11111
1P0C1
11101
1C0E1
11111
EOF

cat > maps/invalid/invalid_multiple_players.ber << EOF
11111
1P0C1
1P001
1C0E1
11111
EOF

cat > maps/invalid/invalid_open_wall.ber << EOF
11111
1P0C1
10001
1C0E0
11111
EOF

cat > maps/invalid/invalid_with_space.ber << EOF
11111
1P0 C1
10001
1C0E1
11111
EOF