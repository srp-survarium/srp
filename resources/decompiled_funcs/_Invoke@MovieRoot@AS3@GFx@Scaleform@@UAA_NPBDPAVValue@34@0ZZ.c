int Scaleform::GFx::AS3::MovieRoot::Invoke(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, pargFmt);
  return ((int (__thiscall *)(Scaleform::GFx::AS3::MovieRoot *, const char *, Scaleform::GFx::Value *, const char *, char *))this->InvokeArgs)(
           this,
           pmethodName,
           presult,
           pargFmt,
           va);
}
