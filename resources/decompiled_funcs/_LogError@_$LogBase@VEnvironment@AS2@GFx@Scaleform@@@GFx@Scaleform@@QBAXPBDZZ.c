void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *this,
        const char *pfmt,
        ...)
{
  int v2; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  v2 = (*((int (__thiscall **)(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>_vtbl *))this[28].~Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>
        + 74))(this[28].__vftable);
  if ( v2 )
    (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)v2 + 4))(v2, 200704, pfmt, va);
}
