void Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v2; // esi
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v3; // eax
  Scaleform::Log *GlobalLog; // eax
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this )
    v2 = this - 3;
  else
    v2 = 0;
  if ( v2 == (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)-12 )
    v3 = 0;
  else
    v3 = v2;
  if ( v3[3].IsVerboseActionErrors(v3 + 3) )
  {
    GlobalLog = (Scaleform::Log *)v2[4].__vftable;
    if ( !GlobalLog )
      GlobalLog = Scaleform::Log::GetGlobalLog();
    ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))GlobalLog->LogMessageVarg)(
      GlobalLog,
      147456,
      pfmt,
      va);
  }
}
