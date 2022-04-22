import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report,confusion_matrix,accuracy_score

dataset=pd.read_csv("bill_authentication.csv")
print(dataset)
X=dataset.iloc[:,0:4].values
Y=dataset.iloc[:,4].values
print(dataset.iloc[:,0:1])
X_train,X_test,Y_train,Y_test=train_test_split(X,Y, test_size=0.2, random_state=0)
print("--->X TEST",X_test)
print("--->Y TEST",Y_test)
sc=StandardScaler()
X_train=sc.fit_transform(X_train)
X_test=sc.fit_transform(X_test)
classifier=RandomForestClassifier(n_estimators=20,random_state=0)
classifier.fit(X_train,Y_train)
Y_pred=classifier.predict(X_test)
print("---->Y PRED",Y_pred)
print(confusion_matrix(Y_test,Y_pred))
print(classification_report(Y_test,Y_pred))
print(accuracy_score(Y_test,Y_pred))