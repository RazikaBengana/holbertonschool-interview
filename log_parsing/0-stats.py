#!/usr/bin/python3
"""
Module to process log entries from standard input and report summary statistics,
including the total file size and count of each HTTP status code received
after every 10 lines of input or at the end of the input
"""


if __name__ == '__main__':

    import sys

    def print_results(statusCodes, fileSize):
        """
        Print the accumulated file size and the count of each status code encountered

        Args:
            statusCodes (dict): a dictionary mapping HTTP status codes (as strings)
                                to their counts (as integers)
            fileSize (int): the total size of files processed, accumulated from the
                            input data
        """
        print("File size: {:d}".format(fileSize))

        for statusCode, times in sorted(statusCodes.items()):
            if times:
                print("{:s}: {:d}".format(statusCode, times))

    statusCodes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

    fileSize = 0
    n_lines = 0

    try:
        for line in sys.stdin:
            if n_lines != 0 and n_lines % 10 == 0:
                print_results(statusCodes, fileSize)

            n_lines += 1
            data = line.split()

            try:
                statusCode = data[-2]
                if statusCode in statusCodes:
                    statusCodes[statusCode] += 1
                fileSize += int(data[-1])

            except Exception:
                pass

        print_results(statusCodes, fileSize)

    except KeyboardInterrupt:
        print_results(statusCodes, fileSize)
        raise
