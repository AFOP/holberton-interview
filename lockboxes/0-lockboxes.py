#!/usr/bin/python3


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
        print(keys)
        print(opened_boxes)
        print(key)

    return len(opened_boxes) == len(boxes)
