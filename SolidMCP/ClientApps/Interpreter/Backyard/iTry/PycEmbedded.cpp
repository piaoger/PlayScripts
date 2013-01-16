
// References:
// http://www.codesampler.com/python.htm
// 
// Note:
//   The borrower of a reference should not call Py_DECREF()
//   In below test cases, you can see a couple of Py_DECREF are commented out.
//   For more information about reference count in Python, see following page:
//      http://docs.python.org/release/2.5.2/ext/refcountsInPython.html


#include "PycEmbedded.h"

// Python
#include <Python.h>
#include <graminit.h>

// Std
#include <iostream>

namespace PycEmbeddedCases
{

    void testRunSimpleString( void )
    {
        // Initialize Python
        Py_Initialize();

        // Execute a Python script one line at a time.
        // >>> import string
        // >>> print string.uppercase
        // ABCDEFGHIJKLMNOPQRSTUVWXYZ
        // >>> x = string.uppercase
        // >>> print string.lower(x)
        // abcdefghijklmnopqrstuvwxyz

        PyRun_SimpleString("import string");
        PyRun_SimpleString("print string.uppercase");
        PyRun_SimpleString("x = string.uppercase");
        PyRun_SimpleString("print string.lower(x)");

        Py_Finalize();
    }


    void testRunString( void )
    {
        Py_Initialize();

        // Get the "string" module
        // import string
        PyObject* stringModule = PyImport_ImportModule("string");

        // Execute its "uppercase" method, which is stored in its dictionary object.
        // The result will be returned as a pointer to a PyObject.
        // string.uppercase()
        PyObject* dictionary = PyModule_GetDict(stringModule);
        PyObject* uppercaseResult = PyRun_String("uppercase", eval_input, dictionary, dictionary );

        // Parsing out its value as a string.
        // Convert the resulting PyObject to a native C/C++ type
        char* upperString;
        PyArg_Parse(uppercaseResult, "s", &upperString);
        std::cout << upperString << std::endl;

        // Add a new a variable called "x" to the module's namespace and
        // assign it the value of our earlier result.
        // x = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        PyObject_SetAttrString(stringModule, "x", uppercaseResult);

        // Call the "lower" method of the "string" module on the new "x"
        // variable to make it lower-case and print out the resulting new string.
        // print string.lower(x)
        PyRun_String("print lower(x)", file_input, dictionary, dictionary);

        // Finally, release everything by decrementing their reference counts.
        Py_DECREF(uppercaseResult);
        //Py_DECREF(dictionary);
        Py_DECREF(stringModule);

        Py_Finalize();
    }


    void testBindValue( void )
    {
        Py_Initialize();

        // Get the "string" module
        PyObject* stringModule = PyImport_ImportModule("string");

        // Retrieve the "uppercase" attribute. 
        // The attribute will be returned as a pointer to a PyObject.
        // Once we have it, we can retrieve its current string value
        // It should be "ABCDEFGHIJKLMNOPQRSTUVWXYZ" when parsed.
        PyObject* uppercaseAttribute = PyObject_GetAttrString(stringModule, "uppercase");

        // Parsing out its value as a string.
        // Convert the resulting PyObject to a native C/C++ type
        char* uppercaseString;
        PyArg_Parse(uppercaseAttribute, "s", &uppercaseString);
        std::cout << uppercaseString << std::endl;

        // Retrieve the "lower" attribute from string module
        // string.lower("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
        PyObject* lowerAttribute = PyObject_GetAttrString(stringModule, "lower");

        // Create a new value based on a format string.
        // It's similar to those accepted by the PyArg_Parse*() family of functions and a sequence of values.
        PyObject* arguments = Py_BuildValue("(s)", uppercaseString);
        PyObject* lowerResult = PyEval_CallObject(lowerAttribute, arguments);

        char* lowerString;
        PyArg_Parse(lowerResult, "s", &lowerString);
        std::cout << lowerString << std::endl;

        // Finally, release everything by decrementing their reference counts.
        //
        Py_DECREF(lowerResult);
        Py_DECREF(uppercaseAttribute );
        Py_DECREF(lowerAttribute);
        Py_DECREF(arguments);
        Py_DECREF(stringModule);

        Py_Finalize();
    }

    void testBuiltins( void )
    {
        Py_Initialize();

        // Create a new namespace dictionary
        // and set the typical built-in values or variables.
        PyObject* dictionary = PyDict_New();
        PyDict_SetItemString(dictionary, "__builtins__", PyEval_GetBuiltins());

        // Create a new variable in the namespace dictionary called "y"
        // and set its value to 5.
        // y = 5
        PyDict_SetItemString(dictionary, "y", PyInt_FromLong(5));

        // Using our new namespace dictionary to run two python statements.
        // Note how the new variable "y" gets used.
        // x = 100
        PyRun_String("x = 100",   file_input, dictionary, dictionary);
        PyRun_String("x = x + y", file_input, dictionary, dictionary);

        // Pull the variable "x" from the namespace dictionary
        PyObject* xResult = PyDict_GetItemString(dictionary, "x");

        // convert the resulting PyObject to a native C/C++ type
        // parsing out its value as an integer.
        int xValue;
        PyArg_Parse(xResult, "i", &xValue );
        std::cout << xValue << std::endl;

        // Finally, release everything by decrementing their reference counts.
        //
        //Py_DECREF(xResult);
        Py_DECREF(dictionary);

        Py_Finalize();
    }


    // Demonstrates how to use Interactive Interpreter and Interactive Console
    void testInterpreter()
    {
        Py_Initialize();

        // #load code module to use InteractiveInterpreter and InteractiveConsole
        // # Utilities used to emulate Python's interactive interpreter
        // # InteractiveConsole closely emulates the behavior of the interactive Python interpreter
        // # InteractiveConsole builds on InteractiveInterpreter

        // import code module
        PyObject* codeModule = PyImport_ImportModule("code");

        // Construct InteractiveInterpreter from code module
        PyObject* func = PyObject_GetAttrString(codeModule, "InteractiveInterpreter");
        PyObject* args = Py_BuildValue("()");
        PyObject* interpreter = PyEval_CallObject(func,args);

        // Provide input as code
        const char* source = "2+3";
        PyObject* sourceArgs = Py_BuildValue("(s)", source);
        PyObject* compilefunc = PyObject_GetAttrString(interpreter, "compile");
        PyObject* codeObject = PyEval_CallObject(compilefunc, sourceArgs);

        // run compiled bytecode
        PyObject* mainModule = PyImport_AddModule("__main__");
        PyObject* dict = PyModule_GetDict(mainModule);
        PyObject* presult = PyEval_EvalCode((PyCodeObject*)codeObject, dict, dict);

        // Finally, release everything by decrementing their reference counts.
        //
        Py_DECREF(presult);
        //Py_DECREF(dict);

        Py_DECREF(codeObject);
        Py_DECREF(compilefunc);
        Py_DECREF(sourceArgs);

        Py_DECREF(interpreter);
        Py_DECREF(args);
        Py_DECREF(func);

        Py_DECREF(codeModule);

        // PyImport_AddModule returns a borrowed reference.
        // Which means you're not allowed to call Py_DECREF at all unless you have actually taken control over it
        // Py_DECREF(mainModule); 
        Py_Finalize();
    }

    void run()
    {
        testRunSimpleString();
        testRunString();
        testBindValue();
        testBuiltins();

        testInterpreter();
    }
}
