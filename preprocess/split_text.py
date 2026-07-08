import re
import sys

# /**
#  * ash = |
#  * eth = ~
#  * thorn = }
#  */

with open(sys.argv[1]) as f:
    text = f.read()
    trans = text.translate(str.maketrans(
        {
            # "\n": " ",
            # "\r": None,
            "æ": "|",
            "Æ": "|",
            "ð": "~",
            "Ð": "~",
            "þ" :"}",
            "Þ" :"}",
        }
    ))
    trans = trans.replace("\n", " ")
    trans = re.sub(r"(\S+) ", r'"\1", ', trans)

with open(sys.argv[2], 'w') as f:
    f.write(trans)