void __thiscall Scaleform::Render::Text::TextFormat::SetBold(Scaleform::Render::Text::TextFormat *this, bool bold)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( (this->PresentMask & 0x800) != 0 && (this->FormatFlags & 1) != bold )
  {
    pObject = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFontHandle.pObject = 0;
    this->PresentMask &= ~0x800u;
  }
  if ( bold )
    this->FormatFlags |= 1u;
  else
    this->FormatFlags &= ~1u;
  this->PresentMask |= 0x10u;
}
