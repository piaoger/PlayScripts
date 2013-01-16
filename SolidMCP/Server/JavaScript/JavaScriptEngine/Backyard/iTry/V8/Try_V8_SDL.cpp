
#include "Global/Precompiled.h"

#include <BedRock/TestSupport/AutoTest.h>

#include <V8.h>
#include <iostream>
#include <iostream>


namespace tut 
{ 
    struct try_javascript_try_v8_sdltest_data
    {
        // implements of v8 callback 
        static v8::Handle<v8::Value> set_draw_color(const v8::Arguments & args)
        {
            int r, g, b ; 
            if(args.Length() == 3) {
                r = args[0]->Int32Value() ; 
                g = args[1]->Int32Value() ; 
                b = args[2]->Int32Value() ; 
                std::cout<< "draw color rgb="<<r<<" "<<g<<" " << b << " "<<std::endl; 
            }

            return v8::Undefined() ; 
        }

        static v8::Handle<v8::Value> draw_line(const v8::Arguments & args)
        {
            int x1, y1, x2, y2 ; 
            if(args.Length() == 4) {
                x1 = args[0]->Int32Value() ; 
                y1 = args[1]->Int32Value() ; 
                x2 = args[2]->Int32Value() ; 
                y2 = args[3]->Int32Value() ; 

                std::cout<< "draw line from ="<<x1<<" "<<y1<<" ; " << x2 << " "<< y2<<std::endl;
            }

            return v8::Undefined() ; 
        }

        static v8::Handle<v8::Value> commit(const v8::Arguments & args) {
            std::cout<<"commit"<<std::endl;
            return v8::Undefined() ; 
        }

        static v8::Handle<v8::Value> clear(const v8::Arguments & args) {
            std::cout<<"clear canvas"<<std::endl;
            return v8::Undefined() ; 
        }

        static v8::Handle<v8::Value> draw_bmp(const v8::Arguments &args) {
            const char * bmp_fname[] = {"a1.bmp", "a2.bmp", "a3.bmp", "a4.bmp", "a5.bmp" } ; 
            int x, y ; 
            int bmp_index ; 

            if(args.Length() == 3)
            {
                x = args[0]->Int32Value() ; 
                y = args[1]->Int32Value() ; 
                bmp_index = args[2]->Int32Value() ; 

                std::cout<<"draw bmp "<< "x= "<< x<< "y="<<y<< "bmp index ="<<bmp_index<<std::endl;

            }

            return v8::Undefined() ; 
        }

        static v8::Handle<v8::String> loadScript(const char * jsFileName) {
            char * jsChars = NULL ; 
            int    jsSize = 0 ; 
            FILE* fp = NULL ; 
            int bytesRead ; 
            int i ; 
            v8::Handle<v8::String> jsSource ; 

            if ((fp = fopen(jsFileName, "rb")) == NULL) {
                 return v8::Handle<v8::String>();
            }

            // get the file size
            fseek(fp, 0, SEEK_END);
            jsSize = ftell(fp);
            rewind(fp);

            // read javascript out of the file
            jsChars = new char[jsSize + 1];
            jsChars[jsSize] = '\0';
            for (i = 0; i < jsSize;) {
                bytesRead = fread(&jsChars[i], 1, jsSize - i, fp) ; 
                i += bytesRead;
            }

            fclose(fp);

            jsSource = v8::String::New(jsChars, jsSize) ; 
            delete [] jsChars ;
            return jsSource ;
        }

        // caller
        static void runScript(const char * jsFileName)
        {
            v8::HandleScope handle_scope ; 
            v8::Handle<v8::ObjectTemplate> globalTemplate = v8::ObjectTemplate::New() ; 
            v8::Handle<v8::Context> executeContext ;
            v8::Handle<v8::String> jsSource ; 
            v8::Handle<v8::Script> js_compiled ; 

            // load the jsp source file 
            jsSource = loadScript(jsFileName) ; 

            // register global functions 
            globalTemplate->Set(v8::String::New("set_draw_color"), v8::FunctionTemplate::New(set_draw_color));
            globalTemplate->Set(v8::String::New("draw_line"), v8::FunctionTemplate::New(draw_line));
            globalTemplate->Set(v8::String::New("commit"), v8::FunctionTemplate::New(commit)) ;
            globalTemplate->Set(v8::String::New("clear"), v8::FunctionTemplate::New(clear)) ;
            globalTemplate->Set(v8::String::New("draw_bmp"),  v8::FunctionTemplate::New(draw_bmp)) ;

            // create and init execute environments
            executeContext = v8::Context::New(NULL, globalTemplate) ; 
            v8::Context::Scope contextScope(executeContext) ; 

            // compile javascript from source 
            js_compiled = v8::Script::Compile(jsSource) ; 
            if(js_compiled.IsEmpty()) {
                return ; 
            }

            // run javascript now 
            js_compiled->Run() ;
        }

        static void on_click(const char * jsFileName, int x, int y)
        {
            const int argc = 2 ; 
            v8::HandleScope handle_scope ; 
            v8::Handle<v8::ObjectTemplate> globalTemplate = v8::ObjectTemplate::New() ; 
            v8::Handle<v8::Context> executeContext ;
            v8::Handle<v8::String> jsSource ; 
            v8::Handle<v8::Script> js_compiled ; 
            v8::Handle<v8::String> js_func_name ; 
            v8::Handle<v8::Value>  js_func_val ; 
            v8::Handle<v8::Function> js_func ; 
            v8::Handle<v8::Value>  argv[argc] ; 
            v8::Handle<v8::Integer> int_x ; 
            v8::Handle<v8::Integer> int_y ; 

            // load the javascript source file 
            jsSource = loadScript(jsFileName) ; 

            // register global functions 
            globalTemplate->Set(v8::String::New("set_draw_color"),v8::FunctionTemplate::New(set_draw_color)) ;
            globalTemplate->Set(v8::String::New("draw_line"), v8::FunctionTemplate::New(draw_line)) ; 
            globalTemplate->Set(v8::String::New("commit"), v8::FunctionTemplate::New(commit)) ; 
            globalTemplate->Set(v8::String::New("clear"), v8::FunctionTemplate::New(clear)) ; 
            globalTemplate->Set(v8::String::New("draw_bmp"), v8::FunctionTemplate::New(draw_bmp)) ; 

            // create and init execute environments
            executeContext = v8::Context::New(NULL, globalTemplate) ; 
            v8::Context::Scope contextScope(executeContext) ; 

            // compile javascript from source 
            js_compiled = v8::Script::Compile(jsSource) ; 
            if(js_compiled.IsEmpty()) {
                 return ; 
            }

            // run javascript now 
            js_compiled->Run() ; 

            js_func_name = v8::String::New("OnClick") ; 
            js_func_val = executeContext->Global()->Get(js_func_name) ; 
            if(!js_func_val->IsFunction()) {
                //LOG("on_click, js_func_val->IsFunction check failed!") ; 
            } else {
                js_func = v8::Handle<v8::Function>::Cast(js_func_val) ; 
                int_x = v8::Integer::New(x) ; 
                int_y = v8::Integer::New(y) ; 
                argv[0] = int_x ; 
                argv[1] = int_y ; 
                js_func->Call(executeContext->Global(), argc, argv) ; 
            }
        }

    };
    typedef test_group<try_javascript_try_v8_sdltest_data> TestGroup;
    TestGroup ThisTestGroup("try_javascript_try_v8_sdltest_data");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("Try Google V8 Embedded Demo");

        // This sample is copied from codeproject.com
        // http://blog.chinaunix.net/uid-8272118-id-2033359.html
        // Piaoger remove SDL related things from the code
        // and just use std::cout to print information out to console instead.
        const char g_js_fname[128]="S:\\Workspace\\Test\\FileStore\\JavaScript\\sdl.js";
        on_click(g_js_fname, 0, 0);
    }
}; 
