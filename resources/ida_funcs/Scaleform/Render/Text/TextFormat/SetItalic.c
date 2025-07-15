void __thiscall Scaleform::Render::Text::TextFormat::SetItalic(Scaleform::Render::Text::TextFormat *this, bool italic)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( (this->PresentMask & 0x800) != 0 && ((this->FormatFlags & 2) != 0) != italic )
  {
    pObject = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFontHandle.pObject = 0;
    this->PresentMask &= ~0x800u;
  }
  if ( italic )
    this->FormatFlags |= 2u;
  else
    this->FormatFlags &= ~2u;
  this->PresentMask |= 0x20u;
}
