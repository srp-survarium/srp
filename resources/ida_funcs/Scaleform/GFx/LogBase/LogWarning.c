void Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *v2; // ecx
  int v3; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this )
    v2 = this - 3;
  else
    v2 = 0;
  v3 = ((int (__thiscall *)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *))v2->__vftable[37].~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>)(v2);
  if ( v3 )
    (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)v3 + 4))(v3, 135168, pfmt, va);
}


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


void Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *this,
        const char *pfmt,
        ...)
{
  int Namespace; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  Namespace = Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)this);
  if ( Namespace )
    (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)Namespace + 4))(Namespace, 135168, pfmt, va);
}
