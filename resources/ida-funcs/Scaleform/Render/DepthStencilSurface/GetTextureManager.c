Scaleform::Render::TextureManager *__thiscall Scaleform::Render::DepthStencilSurface::GetTextureManager(
        Scaleform::Render::DepthStencilSurface *this)
{
  Scaleform::Render::TextureManagerLocks *pObject; // eax

  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    return pObject->pManager;
  else
    return 0;
}
