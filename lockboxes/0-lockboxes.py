#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened.
    Prototype: def canUnlockAll(boxes) boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    There can be keys that do not have boxes
    The first box boxes[0] is unlocked

    Return True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):

    if not boxes:
        return False

    opened_boxes = {0}
    keys = boxes[0]

    while keys:
        key = keys.pop()
        if key in opened_boxes:
            continue
        if key >= len(boxes):
            continue
        opened_boxes.add(key)
        keys += boxes[key]

    return len(opened_boxes) == len(boxes)
