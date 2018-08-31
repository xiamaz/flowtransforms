"""Utility functions for metadata access and convenience functions."""
import re
import numpy as np

RE_NAME = re.compile(r"\$P(\d+)S")
RE_TRANSFORM = re.compile(r"fcsparser_(\d+)_transform")


def name_to_index(meta, name):
    """Match column names to their index in the metadata dict.
    Params:
        meta - Metadata dictionary from fcsparser.
        name - Column name in dataframe to be searched. Should match the $PnS
            field.
    Returns:
        Integer index of the found field. FCS header numbers start from 1,
        or return None if no result has been found.
    """
    names = {int(k[1]): k[0] for k in [RE_NAME.match(k) for k in meta] if k}
    for i, key in names.items():
        if meta[key] == name:
            return i
    return None
