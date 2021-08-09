const _wpi = require('bindings')('wpi-node.node')

function $(){
}

$.INPUT = 0
$.OUTPUT = 1
$.PWM_OUTPUT = 2
$.LOW = 0
$.HIGH = 1
$.PWM_MODE_MS = 0


$.setup = (m) =>{
  _wpi.setup();
}

$.pinMode = (p, m) =>{
  _wpi.pinMode(p, m)
}

$.digitalWrite = (p, v) =>{
  _wpi.digitalWrite(p, v)
}

$.digitalRead = (p) => {
  return _wpi.digitalRead(p)
}

$.pwmSetMode = (m) => {
  _wpi.pmwSetMode(m)
}

$.pwmSetClock = (c) => {
  _wpi.pmwSetClock(c)
}

$.pwmSetRange = (r) => {
  _wpi.pmwSetRange(r)
}

$.pwmWrite = (p, v) => {
  _wpi.pwmWrite(p, v)
}

$.softPwmCreate = (p, minR, maxR) => {
  _wpi.softPwmCreate(p, minR, maxR)
}

$.softPwmWrite = (p, v) => {
  _wpi.softPwmWrite(p, v)
}

module.exports = $;

