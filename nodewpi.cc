#include <wiringPi.h>
#include <softPwm.h>
#include <napi.h>

Napi::Value _setup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  wiringPiSetup();
  int ret = 0; 
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Value _pinMode(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  int pin = info[0].As<Napi::Number>().Int32Value();
  int mode = info[1].As<Napi::Number>().Int32Value();
  int ret = 0;
  pinMode(pin, mode);
  
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Value _digitalWrite(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  int pin = info[0].As<Napi::Number>().Int32Value();
  int value = info[1].As<Napi::Number>().Int32Value();
  int ret = 0;
  digitalWrite(pin, value);
  
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Value _digitalRead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  int pin = info[0].As<Napi::Number>().Int32Value();
  int ret = digitalRead(pin);
  
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Value _pwmSetMode(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  int mode = info[0].As<Napi::Number>().Int32Value();
  int ret = 0;
  pwmSetMode(mode);
  
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Value _pwmSetClock(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  int clock = info[0].As<Napi::Number>().Int32Value();
  int ret = 0;
  pwmSetClock(clock);
  
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Value _pwmSetRange(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  int range = info[0].As<Napi::Number>().Int32Value();
  int ret = 0;
  pwmSetRange(range);
  
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Value _softPwmCreate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  int pin = info[0].As<Napi::Number>().Int32Value();
  int minRange = info[1].As<Napi::Number>().Int32Value();
  int maxRange = info[2].As<Napi::Number>().Int32Value();
  int ret = 0;
  softPwmCreate(pin, minRange, maxRange);
  
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Value _softPwmWrite(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //devOpen();
  int pin = info[0].As<Napi::Number>().Int32Value();
  int value = info[1].As<Napi::Number>().Int32Value();
  int ret = 0;
  softPwmWrite(pin, value);
  
  Napi::Number num = Napi::Number::New(env, ret);
  //devClose();
  return num;
}

Napi::Object Func(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "setup"), Napi::Function::New(env, _setup));
  exports.Set(Napi::String::New(env, "pinMode"), Napi::Function::New(env, _pinMode));
  exports.Set(Napi::String::New(env, "digitalWrite"), Napi::Function::New(env, _digitalWrite));
  exports.Set(Napi::String::New(env, "digitalRead"), Napi::Function::New(env, _digitalRead));
  exports.Set(Napi::String::New(env, "pwmSetMode"), Napi::Function::New(env, _pwmSetMode));
  exports.Set(Napi::String::New(env, "pwmSetClock"), Napi::Function::New(env, _pwmSetClock));
  exports.Set(Napi::String::New(env, "pwmSetRange"), Napi::Function::New(env, _pwmSetRange));
  exports.Set(Napi::String::New(env, "softPwmCreate"), Napi::Function::New(env, _softPwmCreate));
  exports.Set(Napi::String::New(env, "softPwmWrite"), Napi::Function::New(env, _softPwmWrite));
  return exports;
}

NODE_API_MODULE(nodewpi, Func)
