void __thiscall Scaleform::GFx::AS3::IntervalTimer::Start(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot)
{
  this->InvokeTime = this->Interval + proot->TimeElapsed;
}
