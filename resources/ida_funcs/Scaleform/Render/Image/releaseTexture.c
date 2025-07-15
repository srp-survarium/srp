void __thiscall Scaleform::Render::Image::releaseTexture(Scaleform::Render::Image *this)
{
  Scaleform::RefCountVImpl *v1; // esi

  v1 = (Scaleform::RefCountVImpl *)InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  if ( v1 )
  {
    v1->__vftable[2].Release(v1);
    Scaleform::RefCountImpl::Release(v1);
  }
}
