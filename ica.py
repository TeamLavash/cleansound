import numpy as np
from scipy import signal
from sklearn.decomposition import FastICA

np.random.seed(0)
n_samples = 2000
time = np.linspace(0, 8, n_samples)

s1t = np.sin(2 * time)  # Signal 1 : sinusoidal signal
s2t = np.sign(np.sin(3 * time))  # Signal 2 : square signal

s1t.tofile("~temp_a.bin", sep=' ')
s2t.tofile("~temp_b.bin", sep=' ')

# s1 = np.fromfile("~temp_a.bin", dtype=np.int32, sep=' ')
# s2 = np.fromfile("~temp_b.bin", dtype=np.int32, sep=' ')
s1 = np.fromfile("~temp_a.bin", dtype=np.float, sep=' ')
s2 = np.fromfile("~temp_b.bin", dtype=np.float, sep=' ')

S = np.c_[s1, s2]
ica = FastICA(n_components=2)
S_ = ica.fit_transform(S)  # Reconstruct signals
res = np.transpose(S_)
res[0].tofile("~temp_res_a.bin", sep=' ')
res[1].tofile("~temp_res_b.bin", sep=' ')