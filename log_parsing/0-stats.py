#!/usr/bin/python3

"""
Log parsing script that reads stdin line by line and computes metrics.
"""

import sys


def print_stats(total_size, status_counts):
    """
    Print current statistics for file size and status codes.
    """

    print("File size: {}".format(total_size))

    for code in [200, 301, 400, 401, 403, 404, 405, 500]:
        if code in status_counts:
            print("{}: {}".format(code, status_counts[code]))


def parse_line(line):
    """
    Parse a log line and extract status code and file size.
    """

    try:
        parts = line.split()

        if len(parts) < 7:
            return None, None

        status_code = int(parts[-2])
        file_size = int(parts[-1])

        if '"GET' in line and '/projects/260' in line and 'HTTP/1.1"' in line:
            return status_code, file_size

        return None, None

    except (ValueError, IndexError):
        return None, None


if __name__ == "__main__":
    total_size = 0
    status_counts = {}
    line_count = 0
    valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]

    try:
        for line in sys.stdin:
            status_code, file_size = parse_line(line)

            if status_code is None:
                continue

            total_size += file_size
            line_count += 1

            if status_code in valid_codes:
                if status_code in status_counts:
                    status_counts[status_code] += 1
                else:
                    status_counts[status_code] = 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
