#include <Python.h>
#include <iostream>

static PyObject *_slow_calc (PyObject *self, PyObject *args, PyObject *kwargs) {
// �Ѽƭ�
  int x, a = 0, b = 0;
  // kwlist �̦s�� keyword ���W�r�A�H NULL ����
  static char *kwlist[] = {"x", "a", "b", NULL};
  // �^�ǭ�
  int res;
  // PyArg_ParseTupleAndKeywords �|���էⱵ���� args �� kwargs
  // �]���ڭ̭n�� format�A�]�N�O "i|ii"
  // i �Y int�Anon-optional �M optional arguments �H | �Ϲj
  // ���\�]�n���Ȧs�b x�Aa�Ab ���A���]���ѫh��� function �^�� NULL�A���A�~��
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "i|ii", kwlist, &x, &a, &b)) {
    return NULL;
  }
  // �I�s�� function�A�ǤJ�]�n����
  res = slow_calc(x, a, b);
  // ��^�ǭȥ� Py_BuildValue �]�� PyObject �H�^�e�� Python
  return Py_BuildValue("i", res);
}
