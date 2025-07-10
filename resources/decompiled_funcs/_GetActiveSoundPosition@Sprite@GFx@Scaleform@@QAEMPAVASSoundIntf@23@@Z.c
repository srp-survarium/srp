double __thiscall Scaleform::GFx::Sprite::GetActiveSoundPosition(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::ASSoundIntf *psobj)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  int v4; // edi
  Scaleform::RefCountNTSImpl **p_pObject; // ecx
  Scaleform::RefCountNTSImpl *v6; // esi
  float psobja; // [esp+14h] [ebp+4h]

  pActiveSounds = this->pActiveSounds;
  if ( !pActiveSounds )
    return 0.0;
  if ( !psobj )
    return 0.0;
  v4 = 0;
  if ( !pActiveSounds->Sounds.Data.Size )
    return 0.0;
  while ( 1 )
  {
    p_pObject = &pActiveSounds->Sounds.Data.Data[v4].pObject;
    if ( *p_pObject )
      ++(*p_pObject)->RefCount;
    v6 = *p_pObject;
    if ( (Scaleform::GFx::ASSoundIntf *)(*p_pObject)[1].RefCount == psobj )
    {
      if ( v6[1].__vftable )
        break;
    }
    Scaleform::RefCountNTSImpl::Release(*p_pObject);
    pActiveSounds = this->pActiveSounds;
    if ( ++v4 >= pActiveSounds->Sounds.Data.Size )
      return 0.0;
  }
  psobja = ((double (__thiscall *)(Scaleform::RefCountNTSImpl_vtbl *))*((_DWORD *)v6[1].~Scaleform::RefCountNTSImpl + 7))(v6[1].__vftable);
  Scaleform::RefCountNTSImpl::Release(v6);
  return psobja;
}
