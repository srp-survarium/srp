void __thiscall Scaleform::Render::Text::TextFormat::SetFontList(
        Scaleform::Render::Text::TextFormat *this,
        const wchar_t *pfontList,
        unsigned int fontListSz)
{
  int v3; // ebp
  int v5; // edi
  int v6; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::String::DataDesc *pData; // edi
  int v10; // eax

  v3 = fontListSz;
  if ( fontListSz == -1 )
  {
    v3 = Scaleform::SFwcslen(pfontList);
    fontListSz = v3;
  }
  if ( (this->PresentMask & 0x800) != 0 )
  {
    if ( Scaleform::String::GetLength(&this->FontList) == v3 )
    {
      v5 = 0;
      if ( v3 )
      {
        while ( 1 )
        {
          v6 = Scaleform::SFtowlower((unsigned __int16)*(char *)((this->FontList.HeapTypeBits & 0xFFFFFFFC) + v5 + 8));
          if ( v6 != Scaleform::SFtowlower(pfontList[v5]) )
            break;
          v3 = fontListSz;
          if ( ++v5 >= fontListSz )
            goto LABEL_15;
        }
        pObject = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
        if ( pObject )
          Scaleform::RefCountImpl::Release(pObject);
        v3 = fontListSz;
        this->pFontHandle.pObject = 0;
        this->PresentMask &= ~0x800u;
      }
    }
    else
    {
      v8 = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      this->pFontHandle.pObject = 0;
      this->PresentMask &= ~0x800u;
    }
  }
LABEL_15:
  Scaleform::String::Clear(&this->FontList);
  Scaleform::String::AppendString(&this->FontList, pfontList, v3);
  pData = this->FontList.pData;
  this->PresentMask |= 4u;
  strchr((char *)(((unsigned int)pData & 0xFFFFFFFC) + 8), 0x2Cu);
  if ( v10 )
    this->PresentMask &= ~0x1000u;
  else
    this->PresentMask |= 0x1000u;
}
