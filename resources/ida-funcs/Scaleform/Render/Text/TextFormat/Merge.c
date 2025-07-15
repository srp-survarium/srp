Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::TextFormat::Merge(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *result,
        const Scaleform::Render::Text::TextFormat *fmt)
{
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // eax
  Scaleform::GFx::Resource *v5; // ecx
  __int16 LetterSpacing; // cx
  unsigned int ColorV; // eax
  unsigned __int16 FontSize; // dx
  unsigned __int16 PresentMask; // dx
  unsigned __int16 v10; // cx
  unsigned int v11; // edx
  __int16 v12; // ax
  unsigned int v13; // eax
  Scaleform::StringDH *p_FontList; // eax
  Scaleform::Render::Text::FontHandle *v15; // edi
  Scaleform::Render::Text::HTMLImageTagDesc *v16; // esi
  Scaleform::Render::Text::HTMLImageTagDesc *v17; // eax
  Scaleform::GFx::Resource *v18; // ecx
  __int16 v19; // ax
  unsigned int v20; // edx
  unsigned __int16 v21; // cx
  unsigned __int16 v22; // ax
  Scaleform::MemoryHeap *pHeap; // [esp-4h] [ebp-38h]
  Scaleform::MemoryHeap *v25; // [esp-4h] [ebp-38h]
  Scaleform::Render::Text::TextFormat v26; // [esp+Ch] [ebp-28h] BYREF

  pHeap = this->FontList.pHeap;
  v26.RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&v26.FontList, &this->FontList, pHeap);
  Scaleform::StringDH::CopyConstructHelper(&v26.Url, &this->Url, this->FontList.pHeap);
  pObject = this->pImageDesc.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v26.pImageDesc.pObject = this->pImageDesc.pObject;
  v5 = (Scaleform::GFx::Resource *)this->pFontHandle.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::AddRef(v5);
  LetterSpacing = this->LetterSpacing;
  ColorV = this->ColorV;
  v26.pFontHandle.pObject = this->pFontHandle.pObject;
  FontSize = this->FontSize;
  v26.LetterSpacing = LetterSpacing;
  LOBYTE(LetterSpacing) = this->FormatFlags;
  v26.FontSize = FontSize;
  PresentMask = this->PresentMask;
  v26.FormatFlags = LetterSpacing;
  LOBYTE(LetterSpacing) = LOBYTE(fmt->PresentMask) >> 4;
  v26.ColorV = ColorV;
  v26.PresentMask = PresentMask;
  if ( (LetterSpacing & 1) != 0 )
  {
    Scaleform::Render::Text::TextFormat::SetBold(&v26, fmt->FormatFlags & 1);
    ColorV = v26.ColorV;
  }
  if ( (fmt->PresentMask & 0x20) != 0 )
  {
    Scaleform::Render::Text::TextFormat::SetItalic(&v26, (fmt->FormatFlags & 2) != 0);
    ColorV = v26.ColorV;
  }
  v10 = fmt->PresentMask;
  if ( (v10 & 0x40) != 0 )
  {
    if ( (fmt->FormatFlags & 4) != 0 )
      v26.FormatFlags |= 4u;
    else
      v26.FormatFlags &= ~4u;
    v26.PresentMask |= 0x40u;
  }
  if ( (v10 & 0x80u) != 0 )
  {
    if ( (fmt->FormatFlags & 8) != 0 )
      v26.FormatFlags |= 8u;
    else
      v26.FormatFlags &= ~8u;
    v26.PresentMask |= 0x80u;
  }
  if ( (fmt->PresentMask & 1) != 0 )
  {
    ColorV = fmt->ColorV;
    v26.PresentMask |= 1u;
    v26.ColorV = ColorV;
  }
  if ( (v10 & 0x400) != 0 )
  {
    v11 = ColorV & 0xFFFFFF | (HIBYTE(fmt->ColorV) << 24);
    v26.PresentMask |= 0x400u;
    v26.ColorV = v11;
  }
  if ( (v10 & 2) != 0 )
  {
    v12 = fmt->LetterSpacing;
    v26.PresentMask |= 2u;
    v26.LetterSpacing = v12;
  }
  if ( (v10 & 8) != 0 )
  {
    v13 = fmt->FontSize;
    if ( v13 > (unsigned int)&_sbh_sizeHeaderList )
      LOWORD(v13) = -1;
    v26.PresentMask |= 8u;
    v26.FontSize = v13;
  }
  if ( (v10 & 4) != 0 )
  {
    if ( (_S1_4 & 1) == 0 )
    {
      _S1_4 |= 1u;
      Scaleform::String::String(&emptyStr);
      atexit(Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
    }
    p_FontList = &fmt->FontList;
    if ( (fmt->PresentMask & 4) == 0 )
      p_FontList = (Scaleform::StringDH *)&emptyStr;
    Scaleform::Render::Text::TextFormat::SetFontList(&v26, p_FontList);
  }
  if ( (fmt->PresentMask & 0x800) != 0 )
  {
    v15 = fmt->pFontHandle.pObject;
    if ( v15 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)fmt->pFontHandle.pObject);
    if ( v26.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v26.pFontHandle.pObject);
    v26.PresentMask |= 0x800u;
    v26.pFontHandle.pObject = v15;
  }
  if ( (fmt->PresentMask & 0x100) == 0 || Scaleform::String::GetLength(&fmt->Url) )
  {
    if ( (fmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&fmt->Url) )
    {
      Scaleform::String::operator=(&v26.Url, &fmt->Url);
      v26.PresentMask |= 0x100u;
    }
  }
  else
  {
    Scaleform::String::Clear(&v26.Url);
    v26.PresentMask &= ~0x100u;
  }
  if ( (fmt->PresentMask & 0x200) != 0 )
  {
    v16 = fmt->pImageDesc.pObject;
    if ( v16 )
      ++v16->RefCount;
    if ( v26.pImageDesc.pObject )
      Scaleform::RefCountNTSImpl::Release(v26.pImageDesc.pObject);
    v26.PresentMask |= 0x200u;
    v26.pImageDesc.pObject = v16;
  }
  v25 = v26.FontList.pHeap;
  result->RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&result->FontList, &v26.FontList, v25);
  Scaleform::StringDH::CopyConstructHelper(&result->Url, &v26.Url, v26.FontList.pHeap);
  v17 = v26.pImageDesc.pObject;
  if ( v26.pImageDesc.pObject )
  {
    ++v26.pImageDesc.pObject->RefCount;
    v17 = v26.pImageDesc.pObject;
  }
  v18 = (Scaleform::GFx::Resource *)v26.pFontHandle.pObject;
  result->pImageDesc.pObject = v17;
  if ( v18 )
  {
    Scaleform::RefCountImpl::AddRef(v18);
    v18 = (Scaleform::GFx::Resource *)v26.pFontHandle.pObject;
  }
  v19 = v26.LetterSpacing;
  v20 = v26.ColorV;
  result->pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)v18;
  v21 = v26.FontSize;
  result->LetterSpacing = v19;
  v22 = v26.PresentMask;
  result->ColorV = v20;
  LOBYTE(v20) = v26.FormatFlags;
  result->FontSize = v21;
  result->FormatFlags = v20;
  result->PresentMask = v22;
  Scaleform::Render::Text::TextFormat::~TextFormat(&v26);
  return result;
}
