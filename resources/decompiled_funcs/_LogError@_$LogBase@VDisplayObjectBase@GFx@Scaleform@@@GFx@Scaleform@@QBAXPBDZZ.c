void Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
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
    (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)v3 + 4))(v3, 200704, pfmt, va);
}
