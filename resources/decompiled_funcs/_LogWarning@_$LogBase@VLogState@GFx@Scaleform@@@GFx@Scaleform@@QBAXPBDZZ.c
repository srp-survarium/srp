void Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v2; // eax
  Scaleform::Log *GlobalLog; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this )
    v2 = this - 3;
  else
    v2 = 0;
  GlobalLog = (Scaleform::Log *)v2[4].__vftable;
  if ( !GlobalLog )
    GlobalLog = Scaleform::Log::GetGlobalLog();
  ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))GlobalLog->LogMessageVarg)(
    GlobalLog,
    135168,
    pfmt,
    va);
}
