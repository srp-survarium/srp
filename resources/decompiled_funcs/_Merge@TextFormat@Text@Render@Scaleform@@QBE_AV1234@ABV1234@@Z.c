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
  Scaleform::Render::Text::TextFormat resulta; // [esp+Ch] [ebp-28h] BYREF

  pHeap = this->FontList.pHeap;
  resulta.RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&resulta.FontList, &this->FontList, pHeap);
  Scaleform::StringDH::CopyConstructHelper(&resulta.Url, &this->Url, this->FontList.pHeap);
  pObject = this->pImageDesc.pObject;
  if ( pObject )
    ++pObject->RefCount;
  resulta.pImageDesc.pObject = this->pImageDesc.pObject;
  v5 = (Scaleform::GFx::Resource *)this->pFontHandle.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::AddRef(v5);
  LetterSpacing = this->LetterSpacing;
  ColorV = this->ColorV;
  resulta.pFontHandle.pObject = this->pFontHandle.pObject;
  FontSize = this->FontSize;
  resulta.LetterSpacing = LetterSpacing;
  LOBYTE(LetterSpacing) = this->FormatFlags;
  resulta.FontSize = FontSize;
  PresentMask = this->PresentMask;
  resulta.FormatFlags = LetterSpacing;
  LOBYTE(LetterSpacing) = LOBYTE(fmt->PresentMask) >> 4;
  resulta.ColorV = ColorV;
  resulta.PresentMask = PresentMask;
  if ( (LetterSpacing & 1) != 0 )
  {
    Scaleform::Render::Text::TextFormat::SetBold(&resulta, fmt->FormatFlags & 1);
    ColorV = resulta.ColorV;
  }
  if ( (fmt->PresentMask & 0x20) != 0 )
  {
    Scaleform::Render::Text::TextFormat::SetItalic(&resulta, (fmt->FormatFlags & 2) != 0);
    ColorV = resulta.ColorV;
  }
  v10 = fmt->PresentMask;
  if ( (v10 & 0x40) != 0 )
  {
    if ( (fmt->FormatFlags & 4) != 0 )
      resulta.FormatFlags |= 4u;
    else
      resulta.FormatFlags &= ~4u;
    resulta.PresentMask |= 0x40u;
  }
  if ( (v10 & 0x80u) != 0 )
  {
    if ( (fmt->FormatFlags & 8) != 0 )
      resulta.FormatFlags |= 8u;
    else
      resulta.FormatFlags &= ~8u;
    resulta.PresentMask |= 0x80u;
  }
  if ( (fmt->PresentMask & 1) != 0 )
  {
    ColorV = fmt->ColorV;
    resulta.PresentMask |= 1u;
    resulta.ColorV = ColorV;
  }
  if ( (v10 & 0x400) != 0 )
  {
    v11 = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & ColorV | (HIBYTE(fmt->ColorV) << 24);
    resulta.PresentMask |= 0x400u;
    resulta.ColorV = v11;
  }
  if ( (v10 & 2) != 0 )
  {
    v12 = fmt->LetterSpacing;
    resulta.PresentMask |= 2u;
    resulta.LetterSpacing = v12;
  }
  if ( (v10 & 8) != 0 )
  {
    v13 = fmt->FontSize;
    if ( v13 > (unsigned int)&_sbh_sizeHeaderList )
      LOWORD(v13) = -1;
    resulta.PresentMask |= 8u;
    resulta.FontSize = v13;
  }
  if ( (v10 & 4) != 0 )
  {
    if ( (_S1_3 & 1) == 0 )
    {
      _S1_3 |= 1u;
      Scaleform::String::String(&emptyStr);
      atexit(Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
    }
    p_FontList = &fmt->FontList;
    if ( (fmt->PresentMask & 4) == 0 )
      p_FontList = (Scaleform::StringDH *)&emptyStr;
    Scaleform::Render::Text::TextFormat::SetFontList(&resulta, p_FontList);
  }
  if ( (fmt->PresentMask & 0x800) != 0 )
  {
    v15 = fmt->pFontHandle.pObject;
    if ( v15 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)fmt->pFontHandle.pObject);
    if ( resulta.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)resulta.pFontHandle.pObject);
    resulta.PresentMask |= 0x800u;
    resulta.pFontHandle.pObject = v15;
  }
  if ( (fmt->PresentMask & 0x100) == 0 || Scaleform::String::GetLength(&fmt->Url) )
  {
    if ( (fmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&fmt->Url) )
    {
      Scaleform::String::operator=(&resulta.Url, &fmt->Url);
      resulta.PresentMask |= 0x100u;
    }
  }
  else
  {
    Scaleform::String::Clear(&resulta.Url);
    resulta.PresentMask &= ~0x100u;
  }
  if ( (fmt->PresentMask & 0x200) != 0 )
  {
    v16 = fmt->pImageDesc.pObject;
    if ( v16 )
      ++v16->RefCount;
    if ( resulta.pImageDesc.pObject )
      Scaleform::RefCountNTSImpl::Release(resulta.pImageDesc.pObject);
    resulta.PresentMask |= 0x200u;
    resulta.pImageDesc.pObject = v16;
  }
  v25 = resulta.FontList.pHeap;
  result->RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&result->FontList, &resulta.FontList, v25);
  Scaleform::StringDH::CopyConstructHelper(&result->Url, &resulta.Url, resulta.FontList.pHeap);
  v17 = resulta.pImageDesc.pObject;
  if ( resulta.pImageDesc.pObject )
  {
    ++resulta.pImageDesc.pObject->RefCount;
    v17 = resulta.pImageDesc.pObject;
  }
  v18 = (Scaleform::GFx::Resource *)resulta.pFontHandle.pObject;
  result->pImageDesc.pObject = v17;
  if ( v18 )
  {
    Scaleform::RefCountImpl::AddRef(v18);
    v18 = (Scaleform::GFx::Resource *)resulta.pFontHandle.pObject;
  }
  v19 = resulta.LetterSpacing;
  v20 = resulta.ColorV;
  result->pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)v18;
  v21 = resulta.FontSize;
  result->LetterSpacing = v19;
  v22 = resulta.PresentMask;
  result->ColorV = v20;
  LOBYTE(v20) = resulta.FormatFlags;
  result->FontSize = v21;
  result->FormatFlags = v20;
  result->PresentMask = v22;
  Scaleform::Render::Text::TextFormat::~TextFormat(&resulta);
  return result;
}
