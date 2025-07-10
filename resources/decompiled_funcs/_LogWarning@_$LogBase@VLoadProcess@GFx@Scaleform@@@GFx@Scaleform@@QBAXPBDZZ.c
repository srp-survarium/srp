void Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v2; // eax
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *v3; // eax
  Scaleform::Log *GlobalLog; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this )
    v2 = this - 5;
  else
    v2 = 0;
  v3 = v2[4].__vftable;
  if ( v3[1].IsVerboseActionErrors )
  {
    GlobalLog = (Scaleform::Log *)*((_DWORD *)v3[1].IsVerboseActionErrors + 4);
    if ( GlobalLog || (GlobalLog = Scaleform::Log::GetGlobalLog()) != 0 )
      ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))GlobalLog->LogMessageVarg)(
        GlobalLog,
        135168,
        pfmt,
        va);
  }
}
