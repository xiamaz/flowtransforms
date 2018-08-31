from flowtransforms import log as ft

import fcsparser
import matplotlib.pyplot as plt


def log_equal():
    """Assert that linearized and log transformed data can be made equal to
    original data."""
    non_lin = fcsparser.parse("../fcsparser/test.lmd", linearize=False)
    lin = fcsparser.parse("../fcsparser/test.lmd", linearize=True)

    cd45_org = non_lin[1]["CD45-KrOr"]

    transformed = ft.transform_log(
        lin, "CD45-KrOr", scale_max=1024.0, scale_min=0.1024
    )

    cd45_trans = transformed[1]["CD45-KrOr"]



def plot_simple_result():
    meta, data = fcsparser.parse("../fcsparser/test.lmd", linearize=True)

    cd45_trans = ft.estimate_logicle(data, meta, "CD45-KrOr")
    tf_data = ft.transform(data, cd45_trans, "CD45-KrOr")

    plt.figure()
    plt.scatter(tf_data, data["SS INT LIN"])
    plt.show()
    plt.close()


if __name__ == "__main__":
    plot_simple_result()
