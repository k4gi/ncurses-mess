# No NCurses, no C, just late night wakefulness

class Room:
    def __init__(self, t="", d="", l=0):
        self.title = t
        self.description = d
        self.lights = l
        self.risen = 1
        self.checkphone = 1
    def interpret(self, i):
        if i == "turn on lights":
            print("You reach over to the bedside table and turn on the lights.")
            self.lights = 0
            return 0
        elif i == "get up":
            if self.lights == 0:
                if self.checkphone == 0:
                    print("You are ready to meet the day. You slip out from under the covers and stand up.")
                    self.risen = 0
                else:
                    print("You'd like to get out of bed, but are you really emotionally prepared? Maybe a dose of the internet will set you right.")
            else:
                print("It's too dark to get out of bed...")
            return 0
        elif i == "check phone":
            print("You scroll through social media and catch up on the biggest world news. Fighting in the Middle East! Who would've guessed?")
            self.checkphone = 0
            return 0
        elif i == "help":
            print("'check phone' 'get up' 'turn on lights'")
            return 0
        else:
            return 1

print("Hello and welcome to explore.py")

str_input = ""
room_index = 0
rooms = [
    Room(
        "Bedroom", 
        "This room is cluttered and small, crammed with as much furniture as can fit, and then some. Various clothes have been shoved into the shelves between books and magazines. The computer desk is piled high with papers. On the bedside table rests a large collection of empty medicine boxes.",
        1)
]

# first room
print("You find yourself in a dark room. Sunshine is reaching its fingers in behind a venitian blind, allowing you to just about make out a few items of furniture: a desk, a shelf, a clothes horse. You realise you are on your back, in bed.")

while str_input != "quit" and str_input != "exit":
    #loop goes here or w/e
    print(rooms[room_index].title)
    if rooms[room_index].lights == 0:
        print(rooms[room_index].description)
    else:
        print("It's too dark to see.")
    str_input = input("  > ")
    print()

    if(rooms[room_index].interpret(str_input) == 1):
        print("ERROR: Invalid command")
    print()

print("Bye!")
