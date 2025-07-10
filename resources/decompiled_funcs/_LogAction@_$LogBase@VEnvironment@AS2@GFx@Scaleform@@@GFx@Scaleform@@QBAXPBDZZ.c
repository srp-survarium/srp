void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>_vtbl *v2; // ecx
  int v3; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  v2 = this[28].__vftable;
  if ( (*(_DWORD *)(*((_DWORD *)v2[2].~Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> + 2) + 16244) & 4) != 0 )
  {
    v3 = (*((int (__thiscall **)(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>_vtbl *))v2->~Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>
          + 74))(v2);
    if ( v3 )
      (*(void (__thiscall **)(int, int, const char *, char *))(*(_DWORD *)v3 + 4))(v3, 24576, pfmt, va);
  }
}
