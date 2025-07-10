char __thiscall Scaleform::Render::Texture::Unmap(Scaleform::Render::Texture *this)
{
  Scaleform::Render::TextureManagerLocks *pObject; // eax

  if ( !this->pMap )
    return 0;
  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pObject->pManager->unmapTexture(pObject->pManager, this, 1);
  else
    (*(void (__thiscall **)(_DWORD, Scaleform::Render::Texture *, int))(MEMORY[0] + 88))(0, this, 1);
  return 1;
}
