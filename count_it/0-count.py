#!/usr/bin/python3
"""
This script retrieves and counts the occurrences of specific words
from post titles in a subreddit
"""

import pprint
import re
import requests


# Reddit API base URL for accessing a subreddit's hot posts
BASE_URL = 'http://reddit.com/r/{}/hot.json'


def count_words(subreddit, word_list, hot_list=[], after=None):
    """
    Recursively fetch posts from a subreddit and counts how many times
    words from 'word_list' appear in titles

    Args:
    - subreddit (str): the name of the subreddit to scan
    - word_list (list): the words to count in the post titles
    - hot_list (list): the accumulator for titles containing the words
    - after (str): Reddit's pagination token for fetching the next set of posts

    Returns:
    - Recursive call to itself until all pages are fetched, then calls
      'print_results' to output the counts
    """

    headers = {'User-agent': 'Unix:0-subs:v1'}
    params = {'limit': 100}

    if isinstance(after, str):
        if after != "STOP":
            params['after'] = after
        else:
            return print_results(word_list, hot_list)

    response = requests.get(BASE_URL.format(subreddit),
                            headers=headers, params=params)

    if response.status_code != 200:
        return None

    data = response.json().get('data', {})
    after = data.get('after', 'STOP')

    if not after:
        after = "STOP"
    hot_list = hot_list + [post.get('data', {}).get('title')
                           for post in data.get('children', [])]

    return count_words(subreddit, word_list, hot_list, after)


def print_results(word_list, hot_list):
    """
    Print the count of each word in 'word_list' that appears in 'hot_list'

    Args:
    - word_list (list): the list of words to be counted
    - hot_list (list): the titles of posts collected to count the words from

    Outputs:
    - the number of occurrences of each word in descending order
    """
    count = {}

    for word in word_list:
        count[word] = 0

    for title in hot_list:
        for word in word_list:
            for title_word in title.lower().split():
                if title_word == word.lower():
                    count[word] += 1

    count = {k: v for k, v in count.items() if v > 0}
    words = list(count.keys())

    for word in sorted(words,
                       reverse=True, key=lambda k: count[k]):
        print("{}: {}".format(word, count[word]))
