void Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *this,
        const char *pfmt,
        ...)
{
  int Namespace; // eax
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape((Scaleform::GFx::Stream *)this) )
  {
    Namespace = Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)this);
    if ( Namespace )
      (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)Namespace + 4))(Namespace, 20481, pfmt, va);
  }
}
