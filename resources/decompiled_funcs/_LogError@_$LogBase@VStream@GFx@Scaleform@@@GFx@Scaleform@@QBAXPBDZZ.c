void Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *this,
        const char *pfmt,
        ...)
{
  int Namespace; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  Namespace = Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)this);
  if ( Namespace )
    (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)Namespace + 4))(Namespace, 200704, pfmt, va);
}
