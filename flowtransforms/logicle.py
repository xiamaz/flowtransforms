import sys
import numpy as np

import cppyy

cppyy.include("src/logicle.hpp")
cppyy.load_library("liblogicle.so")

from cppyy.gbl import Logicle, FastLogicle

from .utils import name_to_index


def estimate_logicle(data, meta, col):
    """Estimate values for logicle function."""
    t = meta[f"$P{name_to_index(meta, col)}R"]
    m = 4.5
    negative_data = data.loc[data[col] < 0, col]
    if not negative_data.empty:
        r = sys.float_info.epsilon / data[col].quantile(0.05)
        w = (m - np.log10(t / abs(r))) / 2
    else:
        w = 0
    return FastLogicle(float(t), float(w), float(m), 0.0)


def transform_logicle(fcsdata, channel, lgc):
    """Transform data column using provided logicle object."""
    meta, data = fcsdata
    scaler = np.vectorize(lgc.scale)
    data.loc[:, channel] = scaler(data.loc[:, channel].values)
    return meta, data
