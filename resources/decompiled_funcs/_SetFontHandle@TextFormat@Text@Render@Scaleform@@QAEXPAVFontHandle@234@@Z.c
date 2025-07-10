void __thiscall Scaleform::Render::Text::TextFormat::SetFontHandle(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::GFx::Resource *pfontHandle)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( pfontHandle )
    Scaleform::RefCountImpl::AddRef(pfontHandle);
  pObject = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)pfontHandle;
  this->PresentMask |= 0x800u;
}
