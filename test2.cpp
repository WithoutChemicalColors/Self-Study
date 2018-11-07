#include <Python.h>
#include <iostream>

static PyObject *_slow_calc (PyObject *self, PyObject *args, PyObject *kwargs) {
// 參數值
  int x, a = 0, b = 0;
  // kwlist 裡存放 keyword 的名字，以 NULL 結束
  static char *kwlist[] = {"x", "a", "b", NULL};
  // 回傳值
  int res;
  // PyArg_ParseTupleAndKeywords 會嘗試把接收的 args 及 kwargs
  // 包成我們要的 format，也就是 "i|ii"
  // i 即 int，non-optional 和 optional arguments 以 | 區隔
  // 成功包好的值存在 x，a，b 中，打包失敗則整個 function 回傳 NULL，不再繼續
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "i|ii", kwlist, &x, &a, &b)) {
    return NULL;
  }
  // 呼叫原 function，傳入包好的值
  res = slow_calc(x, a, b);
  // 把回傳值用 Py_BuildValue 包成 PyObject 以回送給 Python
  return Py_BuildValue("i", res);
}
