void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall> *this,
        const char *pfmt,
        ...)
{
  int v2; // eax
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this->IsVerboseActionErrors(this) )
  {
    v2 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[6].__vftable[14].~Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>
                                       + 296))(this[6].__vftable[14].~Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>);
    if ( v2 )
      (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)v2 + 4))(v2, 147456, pfmt, va);
  }
}
