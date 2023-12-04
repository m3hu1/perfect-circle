# Perfect Circle on https://neal.fun/perfect-circle/

Inspired from Michael Bill's perfect-circle exploit; Written in C++.

## Compiling
```
g++ -o run.out draw.cpp -framework ApplicationServices
```
Make sure to use `-framework ApplicationServices` while compiling otherwise you'll get errors.

## Run
Place your cursor in the middle of the white circle.
```
./run
```
If you want to speicify executing parameters, use this instead: 
```
./run.out -wait 5000 -steps 40 -sleep 60 -r 250
```
Values of `wait`, `steps`, `sleep` and `r` can be changed accordingly.

>`wait(ms) - wait time before the program starts to draw the circle`  
>`steps(n) - the circle is drawn in n steps`  
>`sleep(ms) - each step takes this amount of ms to run`  
>`r(px) - radius in px`

Check out Michael's perfect-circle exploit : https://github.com/michael-bill/perfect-circle/
