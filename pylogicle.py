import cppyy

cppyy.include("src/logicle.hpp")
cppyy.load_library("liblogicle.so")

from cppyy.gbl import Logicle, FastLogicle

lg = Logicle(262144.0, 0.5)
flg = FastLogicle(262144.0, 0.5)
