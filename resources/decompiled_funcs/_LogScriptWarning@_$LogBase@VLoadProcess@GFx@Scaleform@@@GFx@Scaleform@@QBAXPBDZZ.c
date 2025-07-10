void Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogScriptWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v2; // esi
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v3; // eax
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *v4; // eax
  Scaleform::Log *GlobalLog; // eax
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this )
    v2 = this - 5;
  else
    v2 = 0;
  if ( v2 == (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)-20 )
    v3 = 0;
  else
    v3 = v2;
  if ( v3[5].IsVerboseActionErrors(v3 + 5) )
  {
    v4 = v2[4].__vftable;
    if ( v4[1].IsVerboseActionErrors )
    {
      GlobalLog = (Scaleform::Log *)*((_DWORD *)v4[1].IsVerboseActionErrors + 4);
      if ( GlobalLog || (GlobalLog = Scaleform::Log::GetGlobalLog()) != 0 )
        ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))GlobalLog->LogMessageVarg)(
          GlobalLog,
          147456,
          pfmt,
          va);
    }
  }
}
