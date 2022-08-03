#include <node.h>
#include <v8.h>
#include <iostream>

using namespace std;

namespace addon
{

  using v8::Exception;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::NewStringType;
  using v8::Number;
  using v8::Object;
  using v8::String;
  using v8::Value;

  class ITestInterface
  {
  public:
    virtual void TestFun() = 0;
  };

  void Log(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "hello world", NewStringType::kNormal).ToLocalChecked());
    cout << "hello world" << "\n";
  }

  void Initialize(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "log", Log);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}
