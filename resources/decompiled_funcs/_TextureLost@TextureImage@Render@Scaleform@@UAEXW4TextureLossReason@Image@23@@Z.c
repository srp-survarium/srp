void __thiscall Scaleform::Render::TextureImage::TextureLost(
        Scaleform::Render::TextureImage *this,
        Scaleform::Render::Image::TextureLossReason __formal)
{
  Scaleform::RefCountVImpl *v2; // esi

  v2 = (Scaleform::RefCountVImpl *)InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  if ( v2 )
  {
    v2->__vftable[2].Release(v2);
    Scaleform::RefCountImpl::Release(v2);
  }
}
