import sys
import re

import numpy as np

import cppyy

cppyy.include("src/logicle.hpp")
cppyy.load_library("liblogicle.so")

from cppyy.gbl import Logicle, FastLogicle

import fcsparser
import matplotlib.pyplot as plt


def name_to_index(meta, name):
    re_name = re.compile(r"\$P(\d+)S")
    names = {int(k[1]): k[0] for k in [re_name.match(k) for k in meta] if k}
    for i, key in names.items():
        if meta[key] == name:
            return i


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


def transform(data, lgc, col):
    """Transform data column using provided logicle object."""
    scaler = np.vectorize(lgc.scale)
    return scaler(data[col].values)


def transform_logicle(data):
    """Transform all channels that are not explicitly linear"""
    pass


lg = Logicle(262144.0, 0.5)
flg = FastLogicle(262144.0, 0.5)

meta, data = fcsparser.parse("../fcsparser/test.lmd", linearize=True)

cd45_trans = estimate_logicle(data, meta, "CD45-KrOr")
tf_data = transform(data, cd45_trans, "CD45-KrOr")

plt.figure()
plt.scatter(tf_data, data["SS INT LIN"])
plt.show()
plt.close()
