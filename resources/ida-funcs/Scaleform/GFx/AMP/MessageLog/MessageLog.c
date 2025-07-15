void __thiscall Scaleform::GFx::AMP::MessageLog::MessageLog(
        Scaleform::GFx::AMP::MessageLog *this,
        const Scaleform::String *logText,
        unsigned int logCategory,
        unsigned __int64 timeStamp)
{
  this->__vftable = (Scaleform::GFx::AMP::MessageLog_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageLog_vtbl *)&Scaleform::GFx::AMP::MessageLog::`vftable';
  Scaleform::StringLH::StringLH(&this->LogText);
  Scaleform::StringLH::StringLH(&this->TimeStamp);
  Scaleform::GFx::AMP::MessageLog::SetLog(this, logText, logCategory, timeStamp);
}
