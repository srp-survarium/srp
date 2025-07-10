Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::TextFormat::Intersection(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *result,
        Scaleform::Render::Text::TextFormat *fmt)
{
  Scaleform::MemoryHeap *pHeap; // ebp
  char v5; // dl
  unsigned int ColorV; // ecx
  bool v7; // al
  bool v8; // al
  unsigned __int16 PresentMask; // bx
  unsigned int v10; // eax
  unsigned __int8 ColorV_high; // al
  __int16 LetterSpacing; // cx
  unsigned __int16 FontSize; // ax
  Scaleform::StringDH *FontList; // eax
  Scaleform::Render::Text::FontHandle *FontHandle; // ebx
  Scaleform::GFx::Resource *v16; // eax
  Scaleform::Render::Text::HTMLImageTagDesc *ImageDesc; // ebx
  Scaleform::Render::Text::HTMLImageTagDesc *v18; // eax
  Scaleform::Render::Text::HTMLImageTagDesc *v19; // esi
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // eax
  Scaleform::GFx::Resource *v21; // ecx
  __int16 v22; // dx
  unsigned __int16 v23; // ax
  unsigned __int8 FormatFlags; // cl
  unsigned __int16 v25; // dx
  Scaleform::MemoryHeap *v27; // [esp-4h] [ebp-3Ch]
  Scaleform::Render::Text::TextFormat resulta; // [esp+10h] [ebp-28h] BYREF

  pHeap = fmt->FontList.pHeap;
  resulta.RefCount = 1;
  Scaleform::StringDH::StringDH(&resulta.FontList, pHeap);
  Scaleform::StringDH::StringDH(&resulta.Url, pHeap);
  resulta.FontSize = 0;
  v5 = LOBYTE(this->PresentMask) >> 4;
  ColorV = -16777216;
  resulta.pImageDesc.pObject = 0;
  resulta.pFontHandle.pObject = 0;
  resulta.ColorV = -16777216;
  resulta.LetterSpacing = 0;
  resulta.FormatFlags = 0;
  resulta.PresentMask = 0;
  if ( (v5 & 1) != 0 && (fmt->PresentMask & 0x10) != 0 )
  {
    v7 = fmt->FormatFlags & 1;
    if ( (this->FormatFlags & 1) == v7 )
    {
      Scaleform::Render::Text::TextFormat::SetBold(&resulta, v7);
      ColorV = resulta.ColorV;
    }
  }
  if ( (this->PresentMask & 0x20) != 0 && (fmt->PresentMask & 0x20) != 0 )
  {
    v8 = (fmt->FormatFlags & 2) != 0;
    if ( ((this->FormatFlags & 2) != 0) == v8 )
    {
      Scaleform::Render::Text::TextFormat::SetItalic(&resulta, v8);
      ColorV = resulta.ColorV;
    }
  }
  PresentMask = this->PresentMask;
  if ( (PresentMask & 0x40) != 0
    && (fmt->PresentMask & 0x40) != 0
    && ((this->FormatFlags & 4) != 0) == ((fmt->FormatFlags & 4) != 0) )
  {
    if ( (fmt->FormatFlags & 4) != 0 )
      resulta.FormatFlags |= 4u;
    else
      resulta.FormatFlags &= ~4u;
    resulta.PresentMask |= 0x40u;
  }
  if ( (PresentMask & 0x80u) != 0
    && SLOBYTE(fmt->PresentMask) < 0
    && ((this->FormatFlags & 8) != 0) == ((fmt->FormatFlags & 8) != 0) )
  {
    if ( (fmt->FormatFlags & 8) != 0 )
      resulta.FormatFlags |= 8u;
    else
      resulta.FormatFlags &= ~8u;
    resulta.PresentMask |= 0x80u;
  }
  if ( (this->PresentMask & 1) != 0 && (fmt->PresentMask & 1) != 0 )
  {
    v10 = fmt->ColorV;
    if ( this->ColorV == v10 )
    {
      resulta.PresentMask |= 1u;
      ColorV = v10;
      resulta.ColorV = v10;
    }
  }
  if ( (PresentMask & 0x400) != 0 && (fmt->PresentMask & 0x400) != 0 )
  {
    ColorV_high = HIBYTE(fmt->ColorV);
    if ( HIBYTE(this->ColorV) == ColorV_high )
    {
      resulta.PresentMask |= 0x400u;
      resulta.ColorV = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & ColorV | (ColorV_high << 24);
    }
  }
  if ( (PresentMask & 2) != 0 && (fmt->PresentMask & 2) != 0 )
  {
    LetterSpacing = fmt->LetterSpacing;
    if ( (double)(LetterSpacing / 20) == (double)(this->LetterSpacing / 20) )
    {
      resulta.PresentMask |= 2u;
      resulta.LetterSpacing = LetterSpacing;
    }
  }
  if ( (PresentMask & 8) != 0 && (fmt->PresentMask & 8) != 0 )
  {
    FontSize = fmt->FontSize;
    if ( this->FontSize == FontSize )
    {
      if ( FontSize > (unsigned int)&_sbh_sizeHeaderList )
        resulta.FontSize = -1;
      else
        resulta.FontSize = fmt->FontSize;
      resulta.PresentMask |= 8u;
    }
  }
  if ( (PresentMask & 4) != 0
    && (fmt->PresentMask & 4) != 0
    && !Scaleform::String::CompareNoCase(
          (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFC) + 8),
          (const char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFC) + 8)) )
  {
    FontList = Scaleform::Render::Text::TextFormat::GetFontList(fmt);
    Scaleform::Render::Text::TextFormat::SetFontList(&resulta, FontList);
  }
  if ( (this->PresentMask & 0x800) != 0 && (fmt->PresentMask & 0x800) != 0 )
  {
    FontHandle = Scaleform::Render::Text::TextFormat::GetFontHandle(fmt);
    if ( Scaleform::Render::Text::TextFormat::GetFontHandle(this) == FontHandle )
    {
      v16 = (Scaleform::GFx::Resource *)Scaleform::Render::Text::TextFormat::GetFontHandle(fmt);
      Scaleform::Render::Text::TextFormat::SetFontHandle(&resulta, v16);
    }
  }
  if ( (this->PresentMask & 0x100) != 0
    && Scaleform::String::GetLength(&this->Url)
    && (fmt->PresentMask & 0x100) != 0
    && Scaleform::String::GetLength(&fmt->Url)
    && !Scaleform::String::CompareNoCase(
          (const char *)((this->Url.HeapTypeBits & 0xFFFFFFFC) + 8),
          (const char *)((fmt->Url.HeapTypeBits & 0xFFFFFFFC) + 8)) )
  {
    Scaleform::String::operator=(&resulta.Url, &fmt->Url);
    resulta.PresentMask |= 0x100u;
  }
  if ( (this->PresentMask & 0x200) != 0 && (fmt->PresentMask & 0x200) != 0 )
  {
    ImageDesc = Scaleform::Render::Text::TextFormat::GetImageDesc(fmt);
    if ( Scaleform::Render::Text::TextFormat::GetImageDesc(this) == ImageDesc )
    {
      v18 = Scaleform::Render::Text::TextFormat::GetImageDesc(fmt);
      v19 = v18;
      if ( v18 )
        ++v18->RefCount;
      if ( resulta.pImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(resulta.pImageDesc.pObject);
      resulta.PresentMask |= 0x200u;
      resulta.pImageDesc.pObject = v19;
    }
  }
  v27 = resulta.FontList.pHeap;
  result->RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&result->FontList, &resulta.FontList, v27);
  Scaleform::StringDH::CopyConstructHelper(&result->Url, &resulta.Url, resulta.FontList.pHeap);
  pObject = resulta.pImageDesc.pObject;
  if ( resulta.pImageDesc.pObject )
  {
    ++resulta.pImageDesc.pObject->RefCount;
    pObject = resulta.pImageDesc.pObject;
  }
  v21 = (Scaleform::GFx::Resource *)resulta.pFontHandle.pObject;
  result->pImageDesc.pObject = pObject;
  if ( v21 )
  {
    Scaleform::RefCountImpl::AddRef(v21);
    v21 = (Scaleform::GFx::Resource *)resulta.pFontHandle.pObject;
  }
  v22 = resulta.LetterSpacing;
  v23 = resulta.FontSize;
  result->pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)v21;
  result->ColorV = resulta.ColorV;
  FormatFlags = resulta.FormatFlags;
  result->LetterSpacing = v22;
  v25 = resulta.PresentMask;
  result->FormatFlags = FormatFlags;
  result->FontSize = v23;
  result->PresentMask = v25;
  Scaleform::Render::Text::TextFormat::~TextFormat(&resulta);
  return result;
}
