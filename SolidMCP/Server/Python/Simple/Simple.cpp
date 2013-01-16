
///////////////////////////////////////////////////////////////////////////////
// \file Simple
// \brief Implementation of Simple python module
//
// It's customized Simple module built on raw python api.
///////////////////////////////////////////////////////////////////////////////

// Python
#include<Python.h>

#include<windows.h>
#include<string>

#if defined( _WIN32 )
#define EXPORT_SYMBOL __declspec( dllexport )
#else
#define EXPORT_SYMBOL
#endif


// ----------------------------------------------------------------------------
// Methods
// ----------------------------------------------------------------------------

static std::string querySexInternal(const std::string& name)
{
    if(name == "Piaoger") {
        return "Man!!";
    } else if(name == "Feng Jie") {
        return "Who Cares ?";
    }
    return "Who knows !";
}

static PyObject* querySex(PyObject *self, PyObject *args)
{
    // Parse Arguments
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    // Internal implementation
    std::string sex = querySexInternal(name);

    // Return Sex Value in string format.
    return Py_BuildValue("s", sex.c_str() );
}

// ----------------------------------------------------------------------------
// Registering functions and initializing modules
// ----------------------------------------------------------------------------
// Build Mapping for all methods of Simple Module
static PyMethodDef sAllMyMethods[] =
{
    // QuerySex
    {"querySex", querySex, METH_VARARGS, "Query sex for specified user"},
    {NULL, NULL, 0, NULL}
};

// Export for Simple module in Release build
extern "C" EXPORT_SYMBOL void initSimple()
{
    // PythonDoc for Simple Module
    const char* pyDoc = "A Simple module to query sex from name.";
    Py_InitModule3("Simple", sAllMyMethods, pyDoc);
}

// Export for Simple module in Debug build
extern "C" EXPORT_SYMBOL void initSimple_d()
{
    initSimple();
}