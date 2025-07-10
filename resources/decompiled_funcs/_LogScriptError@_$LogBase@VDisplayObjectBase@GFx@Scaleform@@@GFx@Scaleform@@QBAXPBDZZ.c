void Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *v2; // esi
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *v3; // eax
  int v4; // eax
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this )
    v2 = this - 3;
  else
    v2 = 0;
  if ( v2 == (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)-12 )
    v3 = 0;
  else
    v3 = v2;
  if ( v3[3].IsVerboseActionErrors(v3 + 3) )
  {
    v4 = ((int (__thiscall *)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *))v2->__vftable[37].~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>)(v2);
    if ( v4 )
      (*(void (__thiscall **)(int, void *, const char *, char *))(*(_DWORD *)v4 + 4))(v4, &loc_34000, pfmt, va);
  }
}
