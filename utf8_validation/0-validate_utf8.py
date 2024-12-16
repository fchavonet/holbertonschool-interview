#!/usr/bin/python3

"""
Module that validate if a list of integers represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Validate if a list of integers represents a valid UTF-8 encoding.

    Args:
        data (list): list of integers representing bytes (0-255).

    Returns:
        bool: True if the data is valid UTF-8 encoding, False otherwise.
    """

    num_bytes = 0

    for byte in data:
        # Mask the byte to ensure it's 8 bits (0-255).
        byte = byte & 0xFF

        # Check if we are starting a new UTF-8 character.
        if num_bytes == 0:
            # 1-byte character (ASCII): starts with '0'.
            if (byte >> 7) == 0:
                continue
            # 2-byte character: starts with '110'.
            elif (byte >> 5) == 0b110:
                num_bytes = 1
            # 3-byte character: starts with '1110'.
            elif (byte >> 4) == 0b1110:
                num_bytes = 2
            # 4-byte character: starts with '11110'.
            elif (byte >> 3) == 0b11110:
                num_bytes = 3
            else:
                # Invalid starting byte for UTF-8.
                return False
        else:
            # Continuation bytes must start with '10'.
            if (byte >> 6) != 0b10:
                return False
            # Decrement the count of remaining continuation bytes.
            num_bytes -= 1

    # If all characters are complete, num_bytes should be 0.
    return num_bytes == 0
