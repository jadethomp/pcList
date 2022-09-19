# pcList
This program was the first offical project for my Data Structures course (CSE 2383) at MSU.
It is intended to manage a list of playable characters (from a video game) and their stats.
It utilizes a basic linked list and a modified Node class to do this, as well as the processText
function (adapted from my professor, Aubrey Knight). I also use a tokenizer to read user input.
Users can use several commands to edit the list in various ways.

*note: the <> symbols should not be included in actual execution
SUPPORTED COMMANDS:
  exit
  load <filename>
  add <charactername>
  remove <charactername>
  set <charactername> <stat> <value>
    supported stats are level, job, race, physical, social, and mental.
    job and race take strings as values, all other stats are numerical values (int)
    *note: stat default values are all 1, except for job and race (default to villager and PC)
  search <stat> <value>
  display
