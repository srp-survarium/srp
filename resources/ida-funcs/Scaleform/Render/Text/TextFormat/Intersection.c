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
  Scaleform::Render::Text::TextFormat v28; // [esp+10h] [ebp-28h] BYREF

  pHeap = fmt->FontList.pHeap;
  v28.RefCount = 1;
  Scaleform::StringDH::StringDH(&v28.FontList, pHeap);
  Scaleform::StringDH::StringDH(&v28.Url, pHeap);
  v28.FontSize = 0;
  v5 = LOBYTE(this->PresentMask) >> 4;
  ColorV = -16777216;
  v28.pImageDesc.pObject = 0;
  v28.pFontHandle.pObject = 0;
  v28.ColorV = -16777216;
  v28.LetterSpacing = 0;
  v28.FormatFlags = 0;
  v28.PresentMask = 0;
  if ( (v5 & 1) != 0 && (fmt->PresentMask & 0x10) != 0 )
  {
    v7 = fmt->FormatFlags & 1;
    if ( (this->FormatFlags & 1) == v7 )
    {
      Scaleform::Render::Text::TextFormat::SetBold(&v28, v7);
      ColorV = v28.ColorV;
    }
  }
  if ( (this->PresentMask & 0x20) != 0 && (fmt->PresentMask & 0x20) != 0 )
  {
    v8 = (fmt->FormatFlags & 2) != 0;
    if ( ((this->FormatFlags & 2) != 0) == v8 )
    {
      Scaleform::Render::Text::TextFormat::SetItalic(&v28, v8);
      ColorV = v28.ColorV;
    }
  }
  PresentMask = this->PresentMask;
  if ( (PresentMask & 0x40) != 0
    && (fmt->PresentMask & 0x40) != 0
    && ((this->FormatFlags & 4) != 0) == ((fmt->FormatFlags & 4) != 0) )
  {
    if ( (fmt->FormatFlags & 4) != 0 )
      v28.FormatFlags |= 4u;
    else
      v28.FormatFlags &= ~4u;
    v28.PresentMask |= 0x40u;
  }
  if ( (PresentMask & 0x80u) != 0
    && SLOBYTE(fmt->PresentMask) < 0
    && ((this->FormatFlags & 8) != 0) == ((fmt->FormatFlags & 8) != 0) )
  {
    if ( (fmt->FormatFlags & 8) != 0 )
      v28.FormatFlags |= 8u;
    else
      v28.FormatFlags &= ~8u;
    v28.PresentMask |= 0x80u;
  }
  if ( (this->PresentMask & 1) != 0 && (fmt->PresentMask & 1) != 0 )
  {
    v10 = fmt->ColorV;
    if ( this->ColorV == v10 )
    {
      v28.PresentMask |= 1u;
      ColorV = v10;
      v28.ColorV = v10;
    }
  }
  if ( (PresentMask & 0x400) != 0 && (fmt->PresentMask & 0x400) != 0 )
  {
    ColorV_high = HIBYTE(fmt->ColorV);
    if ( HIBYTE(this->ColorV) == ColorV_high )
    {
      v28.PresentMask |= 0x400u;
      v28.ColorV = ColorV & 0xFFFFFF | (ColorV_high << 24);
    }
  }
  if ( (PresentMask & 2) != 0 && (fmt->PresentMask & 2) != 0 )
  {
    LetterSpacing = fmt->LetterSpacing;
    if ( (double)(LetterSpacing / 20) == (double)(this->LetterSpacing / 20) )
    {
      v28.PresentMask |= 2u;
      v28.LetterSpacing = LetterSpacing;
    }
  }
  if ( (PresentMask & 8) != 0 && (fmt->PresentMask & 8) != 0 )
  {
    FontSize = fmt->FontSize;
    if ( this->FontSize == FontSize )
    {
      if ( FontSize > (unsigned int)&_sbh_sizeHeaderList )
        v28.FontSize = -1;
      else
        v28.FontSize = fmt->FontSize;
      v28.PresentMask |= 8u;
    }
  }
  if ( (PresentMask & 4) != 0
    && (fmt->PresentMask & 4) != 0
    && !Scaleform::String::CompareNoCase(
          (char *)((this->FontList.HeapTypeBits & 0xFFFFFFFC) + 8),
          (char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFC) + 8)) )
  {
    FontList = Scaleform::Render::Text::TextFormat::GetFontList(fmt);
    Scaleform::Render::Text::TextFormat::SetFontList(&v28, FontList);
  }
  if ( (this->PresentMask & 0x800) != 0 && (fmt->PresentMask & 0x800) != 0 )
  {
    FontHandle = Scaleform::Render::Text::TextFormat::GetFontHandle(fmt);
    if ( Scaleform::Render::Text::TextFormat::GetFontHandle(this) == FontHandle )
    {
      v16 = (Scaleform::GFx::Resource *)Scaleform::Render::Text::TextFormat::GetFontHandle(fmt);
      Scaleform::Render::Text::TextFormat::SetFontHandle(&v28, v16);
    }
  }
  if ( (this->PresentMask & 0x100) != 0
    && Scaleform::String::GetLength(&this->Url)
    && (fmt->PresentMask & 0x100) != 0
    && Scaleform::String::GetLength(&fmt->Url)
    && !Scaleform::String::CompareNoCase(
          (char *)((this->Url.HeapTypeBits & 0xFFFFFFFC) + 8),
          (char *)((fmt->Url.HeapTypeBits & 0xFFFFFFFC) + 8)) )
  {
    Scaleform::String::operator=(&v28.Url, &fmt->Url);
    v28.PresentMask |= 0x100u;
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
      if ( v28.pImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(v28.pImageDesc.pObject);
      v28.PresentMask |= 0x200u;
      v28.pImageDesc.pObject = v19;
    }
  }
  v27 = v28.FontList.pHeap;
  result->RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&result->FontList, &v28.FontList, v27);
  Scaleform::StringDH::CopyConstructHelper(&result->Url, &v28.Url, v28.FontList.pHeap);
  pObject = v28.pImageDesc.pObject;
  if ( v28.pImageDesc.pObject )
  {
    ++v28.pImageDesc.pObject->RefCount;
    pObject = v28.pImageDesc.pObject;
  }
  v21 = (Scaleform::GFx::Resource *)v28.pFontHandle.pObject;
  result->pImageDesc.pObject = pObject;
  if ( v21 )
  {
    Scaleform::RefCountImpl::AddRef(v21);
    v21 = (Scaleform::GFx::Resource *)v28.pFontHandle.pObject;
  }
  v22 = v28.LetterSpacing;
  v23 = v28.FontSize;
  result->pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)v21;
  result->ColorV = v28.ColorV;
  FormatFlags = v28.FormatFlags;
  result->LetterSpacing = v22;
  v25 = v28.PresentMask;
  result->FormatFlags = FormatFlags;
  result->FontSize = v23;
  result->PresentMask = v25;
  Scaleform::Render::Text::TextFormat::~TextFormat(&v28);
  return result;
}
