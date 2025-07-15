void Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParseAction(
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v2; // eax
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v3; // ecx
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *v4; // eax
  Scaleform::Log *GlobalLog; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this )
    v2 = this - 5;
  else
    v2 = 0;
  if ( v2 == (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)-20 )
    v3 = 0;
  else
    v3 = v2;
  if ( ((int)v3[6].__vftable & 2) != 0 )
  {
    v4 = v2[4].__vftable;
    if ( v4[1].IsVerboseActionErrors )
    {
      GlobalLog = (Scaleform::Log *)*((_DWORD *)v4[1].IsVerboseActionErrors + 4);
      if ( GlobalLog || (GlobalLog = Scaleform::Log::GetGlobalLog()) != 0 )
        ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))GlobalLog->LogMessageVarg)(
          GlobalLog,
          20483,
          pfmt,
          va);
    }
  }
}


void Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseAction(
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *this,
        const char *pfmt,
        ...)
{
  int Namespace; // eax
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseAction((Scaleform::GFx::Stream *)this) )
  {
    Namespace = Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)this);
    if ( Namespace )
      (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)Namespace + 4))(Namespace, 20483, pfmt, va);
  }
}
