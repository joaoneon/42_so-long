<h1 align="center">
  42_so-long
</h1>
<p align="center">
  <img src="https://github.com/joaoneon/42_so-long/assets/6489188/334f60db-c9ab-4bcf-92e5-e97790bcb1bb">
</p>

<h3 align="left">
About the project:
</h3>
<p>
This repository contains the entire codebase for the so_long project, encompassing both the mandatory section and a portion of the bonus section. To build the code into a program named so_long, you can utilize the provided Makefile.
</p>

<h3 align="left">
    Technology used:
  </h3>
   <table>
       <td align="center">
            <img src="https://skillicons.dev/icons?i=c" width="65px" alt="C icon" /><br>
            <sub>
                <b>
                    <pre>C language</pre>
                </b>
            </sub>
        </td>
  </table>
  <h3 align=>
  Win animation  
</h3>

   <img src="https://github.com/joaoneon/42_so-long/assets/6489188/33380257-8135-48b3-b941-f497ffbe7601" /><br>   
  <h3 align=>

  Death animation  
</h3>
 <img src="https://github.com/joaoneon/42_so-long/assets/6489188/070c2d4a-ba91-474a-8936-9d396fa20e74" /><br>

 
  <h3 align=>

  Mandatory Part  
</h3>

  <ul>
  <li>
  Develop a 2D game where the protagonist must gather all necessary items before successfully escaping the map.
  </ul>
  </li>

  <ul>
  <li>
  Use Minilibx to create your game.
  </ul>
  </li>
  
  <ul>
  <li>
  Your project must not relink.
  </ul>
  </li>

  <ul>
  <li>
 The game must be in 2D view.
  </ul>
  </li>
    <ul>
  <li>
  Your character can move with WASD or arrow keys.
  </ul>
  </li>
    <ul>
  <li>
  Your character must move on 4 directions: up, down, left and right.
  </ul>
  </li>
    <ul>
  <li>
  Your character can't go trought walls (colision).
  </ul>
  </li>
    <ul>
  <li>
  Your project must displayer the character movement in the terminal.
  </ul>
  </li>
    <ul>
  <li>
  Your character must collect all itens before going through the exit.
  </ul>
  </li>
    <ul>
  <li>
 Your game must run in a window, created with the size of the map.
  </ul>
  </li>
    <ul>
  <li>
  Your game must close when pressing ESC or pressing the 'x' on the window.
  </ul>
  </li>

   <h3 align=>
 Map 
</h3>
  <ul>
  <li>
 The map should feature a single exit point.
  </ul>
  </li>
    <ul>
  <li>
 The map should feature a single player.
  </ul>
  </li>
    <ul>
  <li>
 The map should feature at least 1 collectable.
  </ul>
  </li>
    <ul>
  <li>
 The map must be rectangular.
  </ul>
  </li>
    <ul>
  <li>
 The map should be surrounded by walls.
  </ul>
  </li>
    <ul>
  <li>
The map should have an exit path collecting all collectables.
  </ul>
  </li>
      <ul>
  <li>
The map should be a "*.ber" file.
  </ul>
  </li>

   <h3 align=>
  Characters and sprites
</h3>
  <table align>
  <tr>
    <td>Character</td>
    <td>Description</td>
  </tr>
  <tr>
    <td>P</td>
    <td>Player sprite</td>
  </tr>
    <tr>
    <td>0</td>
    <td>Floor sprite</td>
  </tr>
    <tr>
    <td>1</td>
    <td>Wall sprite</td>
  </tr>
    <tr>
    <td>C</td>
    <td>Collectable sprite</td>
  </table>
  <h3 align=>
 Bonus
</h3>
  <ul>
  <li>
There must be a movement counter on the game window.
  </ul>
  </li>
      <ul>
  <li>
Make some animations for the game.
  </ul>
  </li>
    <ul>
  <li>
There must be enemys.
  </ul>
  </li>
    <ul>
  <li>
The player must die, and the game needs to be finished when coliding with an enemy.
  </ul>
  </li>
   <h3 align=>
  Bonus character and sprite
</h3>
  <table align>
  <tr>
    <td>Character</td>
    <td>Description</td>
  </tr>
  <tr>
    <td>X</td>
    <td>Enemy sprite</td>
  </tr>
  </table>
  <br>

 <h3 align="left">
   Final score  
</h3>
<p align="left">
  <img src="https://github.com/joaoneon/42_so-long/assets/6489188/0f04a2e3-aca7-445c-bfdd-49a9f4160938">
</p>

   <h3 align=>
  Instructions to use
</h3>
 <p>
To use this project, you <b>must</b> install the Minilibx
  </p>
  <p>
  In order to utilize this project, you must initially clone the repository onto your local machine by employing a terminal:
  </p>
  <ul>
  <li>
  - $> git clone https://github.com/joaoneon/42_so-long.git [folder]
  </ul>
  </li>
  
  <p>
  Once you have cloned the project into your local repository, you can execute various commands listed in the Makefile.
  </p>
  <ul>
  <li>
  - $> By executing the command <b>"make all"</b> or simply <b>"make"</b>, you can compile the project.
  </ul>
    <ul>
  <li>
  - $> To delete the object files created during compilation, you can use the command <b>"make clean"</b>.
  </ul>
  </li>
    <ul>
  <li>
  - $> Execute the clean command and delete the so_long file and the object files, you can use the command <b>"make fclean"</b>.
  </ul>
  </li>
    <ul>
  <li>
  - $>  The command <b>"make re"</b> executes the "fclean" command followed by the "all" command. It cleans the project by deleting object files, and then recompiles the entire project.
  </ul>
  </li>
