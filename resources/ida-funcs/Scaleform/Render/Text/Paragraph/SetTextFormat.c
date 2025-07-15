void __thiscall Scaleform::Render::Text::Paragraph::SetTextFormat(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        const Scaleform::Render::Text::TextFormat *fmt,
        unsigned int startPos,
        unsigned int endPos)
{
  unsigned int v5; // ebx
  Scaleform::Render::Text::Paragraph *v6; // esi
  unsigned int v7; // eax
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v8; // edi
  Scaleform::MemoryHeap *pHeap; // esi
  Scaleform::Render::Text::TextFormat *pObject; // ecx
  const Scaleform::Render::Text::TextFormat *v11; // eax
  void *v12; // esi
  void *v13; // esi
  Scaleform::Render::Text::TextFormat *TextFormat; // eax
  unsigned int v15; // ebp
  Scaleform::Render::Text::TextFormat *v16; // esi
  Scaleform::Render::Text::TextFormat *v17; // edi
  bool v18; // zf
  void *v19; // esi
  void *v20; // esi
  Scaleform::Render::Text::TextFormat *v21; // eax
  Scaleform::Render::Text::TextFormat *v22; // esi
  int v23; // [esp+10h] [ebp-90h]
  unsigned int Index; // [esp+18h] [ebp-88h]
  unsigned int Length; // [esp+1Ch] [ebp-84h]
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [esp+20h] [ebp-80h] BYREF
  Scaleform::Render::Text::TextFormat v28; // [esp+2Ch] [ebp-74h] BYREF
  Scaleform::Render::Text::Paragraph::FormatRunIterator v29; // [esp+54h] [ebp-4Ch] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+78h] [ebp-28h] BYREF

  v5 = startPos;
  v6 = this;
  Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(
    &v29,
    &this->FormatInfo,
    &this->Text,
    startPos);
  v7 = endPos;
  if ( endPos < startPos )
    v7 = startPos;
  if ( v7 == -1 )
  {
    v23 = 0x7FFFFFFF;
  }
  else
  {
    v23 = v7 - startPos;
    if ( (int)(v7 - startPos) <= 0 )
      goto LABEL_41;
  }
  while ( v29.CurTextIndex < v29.pText->Size )
  {
    v8 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29);
    Index = v8->PlaceHolder.Index;
    Length = v8->PlaceHolder.Length;
    if ( v5 <= Index )
      v5 = v8->PlaceHolder.Index;
    pHeap = pallocator->pHeap;
    v28.RefCount = 1;
    Scaleform::StringDH::StringDH(&v28.FontList, pHeap);
    Scaleform::StringDH::StringDH(&v28.Url, pHeap);
    v28.pImageDesc.pObject = 0;
    v28.pFontHandle.pObject = 0;
    v28.ColorV = -16777216;
    v28.LetterSpacing = 0;
    v28.FontSize = 0;
    v28.FormatFlags = 0;
    v28.PresentMask = 0;
    pObject = v8->PlaceHolder.pFormat.pObject;
    if ( pObject )
    {
      v11 = Scaleform::Render::Text::TextFormat::Merge(pObject, &result, fmt);
      Scaleform::Render::Text::TextFormat::operator=(&v28, v11);
      if ( result.pFontHandle.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pFontHandle.pObject);
      if ( result.pImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pImageDesc.pObject);
      v12 = (void *)(result.Url.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((result.Url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
      v13 = (void *)(result.FontList.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((result.FontList.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
      TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(pallocator, &v28);
    }
    else
    {
      TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(pallocator, fmt);
    }
    v15 = v23;
    v16 = TextFormat;
    if ( Index + Length - v5 < v23 )
      v15 = Index + Length - v5;
    range.Index = v5;
    range.Length = v15;
    if ( TextFormat )
      ++TextFormat->RefCount;
    range.Data.pObject = TextFormat;
    Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
      &this->FormatInfo,
      &range);
    v17 = range.Data.pObject;
    if ( range.Data.pObject )
    {
      v18 = range.Data.pObject->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v17);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
      }
    }
    v23 -= v15;
    Scaleform::Render::Text::Paragraph::FormatRunIterator::SetTextPos(&v29, Index + Length);
    if ( v16 )
    {
      v18 = v16->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v16);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
    }
    if ( v28.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v28.pFontHandle.pObject);
    if ( v28.pImageDesc.pObject )
      Scaleform::RefCountNTSImpl::Release(v28.pImageDesc.pObject);
    v19 = (void *)(v28.Url.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v28.Url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
    v20 = (void *)(v28.FontList.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v28.FontList.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
    v6 = this;
    if ( v23 <= 0 )
      break;
    v5 = startPos;
  }
LABEL_41:
  v21 = v29.PlaceHolder.pFormat.pObject;
  ++v6->ModCounter;
  if ( v21 )
  {
    --v21->RefCount;
    v22 = v21;
    if ( !v21->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v21);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
    }
  }
}
