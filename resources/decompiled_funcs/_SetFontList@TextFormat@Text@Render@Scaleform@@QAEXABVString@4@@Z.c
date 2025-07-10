void __thiscall Scaleform::Render::Text::TextFormat::SetFontList(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::String *fontList)
{
  Scaleform::StringDH *p_FontList; // edi
  int Length; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::String::DataDesc *pData; // eax
  int v7; // eax

  if ( (this->PresentMask & 0x800) != 0 )
  {
    p_FontList = &this->FontList;
    Length = Scaleform::String::GetLength(&this->FontList);
    if ( Length != Scaleform::String::GetLength(fontList)
      || Scaleform::String::CompareNoCase(
           (const char *)((p_FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
           (const char *)((fontList->HeapTypeBits & 0xFFFFFFFC) + 8)) )
    {
      pObject = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      this->pFontHandle.pObject = 0;
      this->PresentMask &= ~0x800u;
    }
  }
  Scaleform::String::operator=(&this->FontList, fontList);
  pData = this->FontList.pData;
  this->PresentMask |= 4u;
  strchr((char *)(((unsigned int)pData & 0xFFFFFFFC) + 8), 0x2Cu);
  if ( v7 )
    this->PresentMask &= ~0x1000u;
  else
    this->PresentMask |= 0x1000u;
}
