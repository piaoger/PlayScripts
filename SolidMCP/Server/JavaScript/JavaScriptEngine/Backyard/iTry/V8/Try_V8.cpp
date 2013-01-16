
#include "Global/Precompiled.h"

#include <BedRock/TestSupport/AutoTest.h>

#include <V8.h>
#include <iostream>

namespace tut 
{ 
    struct try_javascript_try_v8_data
    {
        // Test2
        static const char* toCString(const v8::String::Utf8Value& value)
        {
            return *value ? *value : "";
        }

        static v8::Handle<v8::Value> Alert(const v8::Arguments& args)
        {
            v8::String::Utf8Value title(args[0]);
            v8::String::Utf8Value text(args[1]);
            std::cout << "Title:" << toCString(title) << "Text:" << toCString(text)<< std::endl;
            return v8::Undefined();
        }
    };

    typedef test_group<try_javascript_try_v8_data> TestGroup;
    TestGroup ThisTestGroup("javascript_try_v8");
    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("Try Google V8 JavaScript engine");
        // This example is copied from
        // https://developers.google.com/v8/get_started

        // Create a stack-allocated handle scope.
        v8::HandleScope handle_scope;
        // Create a new context.  
        v8::Persistent<v8::Context> context = v8::Context::New();

        // Enter the created context for compiling and  
        // running the hello world script.   
        v8::Context::Scope context_scope(context);  

        // Create a string containing the JavaScript source code.
        v8::Handle<v8::String> source = v8::String::New("'Hello' + ', World!'");  
        // Compile the source code.  
        v8::Handle<v8::Script> script = v8::Script::Compile(source);  

        // Run the script to get the result.  
        v8::Handle<v8::Value> result = script->Run();
        // Dispose the persistent context.  
        context.Dispose();  

        // Convert the result to an ASCII string and print it.  
        v8::String::AsciiValue ascii(result);
        // 'Hello' + ', World!' ---> Hello, World!
        ensure(std::string("Hello, World!") == *ascii);
    }
    template<> 
    template<> 
    void TestObject::test<2>() 
    {
        set_test_name("Try Google V8 JavaScript engine");
        // This example is copied from
        // https://developers.google.com/v8/get_started

        // Create a stack-allocated handle scope.
        v8::HandleScope handle_scope;
        // Create Global 
        v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();

        global->Set(v8::String::New("alert"), v8::FunctionTemplate::New(Alert));

        v8::Handle<v8::ObjectTemplate> host = v8::ObjectTemplate::New();
        host->Set("alert", v8::FunctionTemplate::New(Alert));
        global->Set("host", host);

        v8::Handle<v8::Context> context = v8::Context::New(NULL, global);
        v8::Context::Scope context_scope(context);
        v8::Handle<v8::String> source = v8::String::New("alert('v8', 'hell v8!')");
        v8::Handle<v8::Script> script = v8::Script::Compile(source, v8::String::New(""));
        script->Run(); 

        // Cannot call dispose for it releasing v8 
        //v8::V8::Dispose();
    }
}; 
