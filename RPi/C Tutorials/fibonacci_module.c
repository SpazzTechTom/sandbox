#include </usr/include/python3.2/Python.h>

int cFibonacci(int n)
{
	if(n<2)
	{
		return n;
	}else
	{
		return cFibonacci(n-1) + cFibonacci(n-2);
	}
}

static PyObject* fibonacci(PyObject* self, PyObject* args)
{
	int n;
	
	if(!PyArg_ParseTuple(args, "i", &n))
	{
		return NULL;
	}
	
	return Py_BuildValue("i", cFibonacci(n));
}

static PyObject* version(PyObject* self)
{
	return Py_BuildValue("s", "Version 1.0");
}

static PyMethodDef fibonacci_Methods[] = {
	{"fibonacci", fibonacci, METH_VARARGS, "Calculates the Fibonacci number."},
	{"version", (PyCFunction)version, METH_NOARGS, "Returns the version."},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initfibonacci_module(void)
{
	(void)Py_InitModule("fibonacci_module", fibonacci_Methods);
}
