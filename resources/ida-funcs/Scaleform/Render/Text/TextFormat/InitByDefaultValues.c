void __thiscall Scaleform::Render::Text::TextFormat::InitByDefaultValues(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  unsigned __int16 PresentMask; // ax
  Scaleform::RefCountVImpl *v4; // ecx
  unsigned __int16 v5; // cx

  this->ColorV &= 0xFF000000;
  this->PresentMask |= 1u;
  Scaleform::Render::Text::TextFormat::SetFontList(this, "Times New Roman", 0xFFFFFFFF);
  Scaleform::Render::Text::TextFormat::SetFontSize(this, 12.0);
  if ( (this->PresentMask & 0x800) != 0 && (this->FormatFlags & 1) != 0 )
  {
    pObject = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFontHandle.pObject = 0;
    this->PresentMask &= ~0x800u;
  }
  this->PresentMask |= 0x10u;
  PresentMask = this->PresentMask;
  this->FormatFlags &= ~1u;
  if ( (PresentMask & 0x800) != 0 && (this->FormatFlags & 2) != 0 )
  {
    v4 = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    this->pFontHandle.pObject = 0;
    this->PresentMask &= ~0x800u;
  }
  v5 = this->PresentMask;
  this->FormatFlags &= 0xF1u;
  this->ColorV |= 0xFF000000;
  this->LetterSpacing = 0;
  this->PresentMask = v5 & 0xFB1D | 0xE0;
  Scaleform::String::Clear(&this->Url);
  this->PresentMask &= ~0x100u;
}
