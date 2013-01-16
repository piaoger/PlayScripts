
///////////////////////////////////////////////////////////////////////////////
// \file SimpleCXX
// \brief Implementation of SimpleCXX python module
//
// It's customized Simple module built on PyCXX.
///////////////////////////////////////////////////////////////////////////////


// PyCXX
#include "CXX/Objects.hxx"
#include "CXX/Extensions.hxx"

#include <assert.h>

#if defined( _WIN32 )
#define EXPORT_SYMBOL __declspec( dllexport )
#else
#define EXPORT_SYMBOL
#endif


static std::string querySexInternal(const std::string& name)
{
    if(name == "Piaoger") {
        return "Man!!";
    } else if(name == "Feng Jie") {
        return "Who Cares ?";
    }
    return "Who knows !";
}

// ----------------------------------------------------------------------------
// SimpleCXX Module.
// ----------------------------------------------------------------------------
class SimpleCXX_module : public Py::ExtensionModule<SimpleCXX_module>
{
public:
    SimpleCXX_module(); 
    virtual ~SimpleCXX_module();

private:
    Py::Object querySex( const Py::Tuple &rargs );
};


SimpleCXX_module::SimpleCXX_module()
: Py::ExtensionModule<SimpleCXX_module>( "SimpleCXX" )
{
    add_varargs_method("querySex", &SimpleCXX_module::querySex, "Query sex for specified user");

    // PythonDoc for Simple Module
    const char* pyDoc = "A Simple module to query sex from name.";
    initialize(pyDoc);
}

SimpleCXX_module::~SimpleCXX_module()
{
}

Py::Object SimpleCXX_module::querySex( const Py::Tuple &rargs )
{
    // Parser Arguments
    Py::String name = rargs[0];

    // Internal implementation
    std::string sex = querySexInternal(name);

    // Return Sex Value in string format.
    return Py::String(sex);
}


// ----------------------------------------------------------------------------
// Initializing modules
// ----------------------------------------------------------------------------
static SimpleCXX_module *simple;

extern "C" EXPORT_SYMBOL void initSimpleCXX()
{
    simple = new SimpleCXX_module;
}

// symbol required for the debug version
extern "C" EXPORT_SYMBOL void initSimpleCXX_d()
{
    initSimpleCXX();
}
