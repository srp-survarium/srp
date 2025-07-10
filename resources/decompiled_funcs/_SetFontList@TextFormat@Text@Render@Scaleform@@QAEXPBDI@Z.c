void __thiscall Scaleform::Render::Text::TextFormat::SetFontList(
        Scaleform::Render::Text::TextFormat *this,
        char *pfontList,
        unsigned int fontListSz)
{
  unsigned int v3; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::String::DataDesc *pData; // edi
  int v7; // eax

  v3 = fontListSz;
  if ( fontListSz == -1 )
    v3 = strlen(pfontList);
  if ( (this->PresentMask & 0x800) != 0
    && (Scaleform::String::GetLength(&this->FontList) != v3
     || Scaleform::String::CompareNoCase((const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFC) + 8), pfontList, v3)) )
  {
    pObject = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFontHandle.pObject = 0;
    this->PresentMask &= ~0x800u;
  }
  Scaleform::String::Clear(&this->FontList);
  Scaleform::String::AppendString(&this->FontList, pfontList, v3);
  pData = this->FontList.pData;
  this->PresentMask |= 4u;
  strchr((char *)(((unsigned int)pData & 0xFFFFFFFC) + 8), 0x2Cu);
  if ( v7 )
    this->PresentMask &= ~0x1000u;
  else
    this->PresentMask |= 0x1000u;
}
