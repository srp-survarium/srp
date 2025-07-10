void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::LogAction(
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>_vtbl *v2; // ecx
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( LOBYTE(this[2].__vftable) )
  {
    v2 = this[1].__vftable;
    if ( v2 )
      (*((void (__thiscall **)(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>_vtbl *, int, const char *, char *))v2->~Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>
       + 1))(
        v2,
        24576,
        pfmt,
        va);
  }
}
