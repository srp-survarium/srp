void __thiscall Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat *defaultTextFmt)
{
  const Scaleform::Render::Text::TextFormat *v2; // esi
  char v4; // al
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::Ptr<Scaleform::Render::Text::HTMLImageTagDesc> *p_pImageDesc; // edx
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // ebp
  Scaleform::Render::Text::HTMLImageTagDesc *v8; // eax
  Scaleform::GFx::Resource *v9; // ecx
  Scaleform::Render::Text::HTMLImageTagDesc *v10; // eax
  Scaleform::Render::Text::FontHandle *v11; // ecx
  unsigned __int16 FontSize; // dx
  unsigned __int16 PresentMask; // dx
  Scaleform::Render::Text::Allocator *Allocator; // eax
  Scaleform::Render::Text::TextFormat *v15; // eax
  Scaleform::Render::Text::TextFormat *v16; // esi
  Scaleform::Render::Text::TextFormat *v17; // ebx
  bool v18; // zf
  Scaleform::Render::Text::Allocator *v19; // eax
  Scaleform::Render::Text::TextFormat *TextFormat; // eax
  Scaleform::Render::Text::TextFormat *v21; // esi
  Scaleform::Render::Text::TextFormat *v22; // ebx
  Scaleform::MemoryHeap *pHeap; // [esp-4h] [ebp-3Ch]
  Scaleform::Render::Text::TextFormat textfmt; // [esp+10h] [ebp-28h] BYREF

  v2 = defaultTextFmt;
  v4 = 0;
  if ( (defaultTextFmt->PresentMask & 0x200) != 0 )
  {
    v5 = (Scaleform::RefCountNTSImpl *)defaultTextFmt;
    p_pImageDesc = &defaultTextFmt->pImageDesc;
  }
  else
  {
    v5 = 0;
    v4 = 1;
    defaultTextFmt = 0;
    p_pImageDesc = (Scaleform::Ptr<Scaleform::Render::Text::HTMLImageTagDesc> *)&defaultTextFmt;
  }
  pObject = p_pImageDesc->pObject;
  if ( (v4 & 1) != 0 && v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  if ( pObject )
  {
    pHeap = v2->FontList.pHeap;
    textfmt.RefCount = 1;
    Scaleform::StringDH::CopyConstructHelper(&textfmt.FontList, &v2->FontList, pHeap);
    Scaleform::StringDH::CopyConstructHelper(&textfmt.Url, &v2->Url, v2->FontList.pHeap);
    v8 = v2->pImageDesc.pObject;
    if ( v8 )
      ++v8->RefCount;
    v9 = (Scaleform::GFx::Resource *)v2->pFontHandle.pObject;
    v10 = v2->pImageDesc.pObject;
    textfmt.pImageDesc.pObject = v10;
    if ( v9 )
    {
      Scaleform::RefCountImpl::AddRef(v9);
      v10 = textfmt.pImageDesc.pObject;
    }
    v11 = v2->pFontHandle.pObject;
    textfmt.ColorV = v2->ColorV;
    FontSize = v2->FontSize;
    textfmt.pFontHandle.pObject = v11;
    LOWORD(v11) = v2->LetterSpacing;
    textfmt.FontSize = FontSize;
    PresentMask = v2->PresentMask;
    textfmt.LetterSpacing = (__int16)v11;
    textfmt.FormatFlags = v2->FormatFlags;
    textfmt.PresentMask = PresentMask;
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release(v10);
    textfmt.PresentMask |= 0x200u;
    textfmt.pImageDesc.pObject = 0;
    Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
    v15 = Scaleform::Render::Text::Allocator::AllocateTextFormat(Allocator, &textfmt);
    v16 = this->pDefaultTextFormat.pObject;
    v17 = v15;
    if ( v16 )
    {
      v18 = v16->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v16);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
    }
    this->pDefaultTextFormat.pObject = v17;
    Scaleform::Render::Text::TextFormat::~TextFormat(&textfmt);
  }
  else
  {
    v19 = Scaleform::Render::Text::StyledText::GetAllocator(this);
    TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(v19, v2);
    v21 = this->pDefaultTextFormat.pObject;
    v22 = TextFormat;
    if ( v21 )
    {
      v18 = v21->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v21);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
      }
    }
    this->pDefaultTextFormat.pObject = v22;
  }
}


void __thiscall Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat *pdefaultTextFmt)
{
  Scaleform::Render::Text::TextFormat *v2; // edi
  char v4; // al
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::Ptr<Scaleform::Render::Text::HTMLImageTagDesc> *p_pImageDesc; // edx
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // esi
  Scaleform::Render::Text::TextFormat *v8; // esi

  v2 = pdefaultTextFmt;
  v4 = 0;
  if ( (pdefaultTextFmt->PresentMask & 0x200) != 0 )
  {
    v5 = (Scaleform::RefCountNTSImpl *)pdefaultTextFmt;
    p_pImageDesc = &pdefaultTextFmt->pImageDesc;
  }
  else
  {
    v5 = 0;
    v4 = 1;
    pdefaultTextFmt = 0;
    p_pImageDesc = (Scaleform::Ptr<Scaleform::Render::Text::HTMLImageTagDesc> *)&pdefaultTextFmt;
  }
  pObject = p_pImageDesc->pObject;
  if ( (v4 & 1) != 0 && v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  if ( pObject )
  {
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this, v2);
  }
  else
  {
    ++v2->RefCount;
    v8 = this->pDefaultTextFormat.pObject;
    if ( v8 )
    {
      if ( v8->RefCount-- == 1 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v8);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
    }
    this->pDefaultTextFormat.pObject = v2;
  }
}
