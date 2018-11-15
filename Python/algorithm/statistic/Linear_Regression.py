# -*- coding: utf-8 -*-
"""
Created on Wed Nov  7 18:22:06 2018

@author: melissa
"""
class LinearRegression():
    def __init__(self, response, predictor):
        self.X = predictor.astype(np.float)
        self.Y = response.astype(np.float)

    def lm(self, use_intercept=True):
        if use_intercept:
            self.X = np.column_stack( (np.ones((self.X.shape[0],1)), self.X) );
        XT = self.X.T
        self.coefs = np.linalg.inv( XT @ self.X ) @ XT @ self.Y
        return self.coefs
    
    def coefficients(self):
        return self.coefs
    
    def predict(self, X_test=None):
        if X_test == None:
            return self.X @ self.coefs
        else:
            return X_test @ self.coefs
    
    def residual(self):
        self.residual = np.mean( (self.Y - self.X @ self.coefs)**2 )
        return self.residual
        
import numpy as np
import pandas as pd
# Create dataframe
url = r"http://www.stat.nthu.edu.tw/~swcheng/Teaching/stat5410/data/wrinkle.txt"
df = pd.read_csv(url)
header = df.columns.tolist()[0].split()
table = [ df.values.tolist()[idx][0].split() for idx in range(len(df))]

# Complete Dataframe
df = pd.DataFrame(table, columns=header)

# prepare model
resp_col = "press"
pred_col = ['HCHO', 'catalyst', 'temp', 'time']

resp = df[resp_col].values
pred = df[pred_col].values

model = LinearRegression(resp, pred)
model.lm()

fig, ax = plt.subplots(ncols=2, sharey=True)
ax[0].scatter(range(30), model.predict())
ax[1].scatter(range(30), resp)