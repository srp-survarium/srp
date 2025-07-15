void __thiscall Scaleform::GFx::SetBackgroundColorTag::Execute(
        Scaleform::GFx::SetBackgroundColorTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // ecx
  _DWORD *v4; // esi
  double v5; // st7
  double v6; // st7
  float v7; // [esp+Ch] [ebp+4h]

  pASRoot = m->pASRoot;
  v4 = &pASRoot->pMovieImpl->__vftable;
  if ( (v4[4061] & 0x20000) == 0 )
  {
    v7 = ((double (__thiscall *)(Scaleform::GFx::MovieImpl *))*(_DWORD *)(*v4 + 132))(pASRoot->pMovieImpl) * 255.0;
    v5 = v7;
    if ( v7 <= 0.0 )
      v6 = v5 - 0.5;
    else
      v6 = v5 + 0.5;
    this->Color.Channels.Alpha = (int)v6;
    (*(void (__thiscall **)(_DWORD *, unsigned int))(*v4 + 124))(v4, this->Color.Raw);
    v4[4061] |= (unsigned int)&loc_20000;
  }
}
