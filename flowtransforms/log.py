"""Apply log transformation to provided data with metadata."""
import numpy as np
from .utils import name_to_index, RE_TRANSFORM


def inverse_linearize(fcsdata):
    """Revert linearization of fcsdata by fcsparser."""
    meta, data = fcsdata

    indices = np.array([
        int(RE_TRANSFORM.match(k)[1])
        for k, v in meta.items() if v == "linearize"
    ])

    min_vals = np.array([meta[f"fcsparser_$P{i}R_min"] for i in indices])
    max_vals = np.array([meta[f"fcsparser_$P{i}R_max"] for i in indices])
    decades = np.array([meta[f"fcsparser_{i}_log_decades"] for i in indices])

    data.iloc[:, indices - 1] = np.log10(
        data.iloc[:, indices - 1] / min_vals) * max_vals / decades
    return meta, data


def transform_log(
        fcsdata, channel, scale_max=1023.0, decades=4.0, scale_min=0.1023
):
    """Transform channels using logarithmic transform."""
    scale_max = 1023.0
    decades = 4.0

    meta, data = fcsdata

    data.loc[:, channel] = np.log10(
        data.loc[:, channel] / scale_min) * scale_max / decades

    return meta, data
