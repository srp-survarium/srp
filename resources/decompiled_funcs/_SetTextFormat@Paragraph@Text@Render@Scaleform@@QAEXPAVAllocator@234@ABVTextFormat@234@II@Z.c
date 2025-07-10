void __thiscall Scaleform::Render::Text::Paragraph::SetTextFormat(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        const Scaleform::Render::Text::TextFormat *fmt,
        unsigned int startPos,
        unsigned int endPos)
{
  unsigned int Index; // ebx
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
  int length; // [esp+10h] [ebp-90h]
  unsigned int runIndex; // [esp+18h] [ebp-88h]
  unsigned int runLength; // [esp+1Ch] [ebp-84h]
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [esp+20h] [ebp-80h] BYREF
  Scaleform::Render::Text::TextFormat format; // [esp+2Ch] [ebp-74h] BYREF
  Scaleform::Render::Text::Paragraph::FormatRunIterator it; // [esp+54h] [ebp-4Ch] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+78h] [ebp-28h] BYREF

  Index = startPos;
  v6 = this;
  Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(
    &it,
    &this->FormatInfo,
    &this->Text,
    startPos);
  v7 = endPos;
  if ( endPos < startPos )
    v7 = startPos;
  if ( v7 == -1 )
  {
    length = 0x7FFFFFFF;
  }
  else
  {
    length = v7 - startPos;
    if ( (int)(v7 - startPos) <= 0 )
      goto LABEL_41;
  }
  while ( it.CurTextIndex < it.pText->Size )
  {
    v8 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it);
    runIndex = v8->PlaceHolder.Index;
    runLength = v8->PlaceHolder.Length;
    if ( Index <= runIndex )
      Index = v8->PlaceHolder.Index;
    pHeap = pallocator->pHeap;
    format.RefCount = 1;
    Scaleform::StringDH::StringDH(&format.FontList, pHeap);
    Scaleform::StringDH::StringDH(&format.Url, pHeap);
    format.pImageDesc.pObject = 0;
    format.pFontHandle.pObject = 0;
    format.ColorV = -16777216;
    format.LetterSpacing = 0;
    format.FontSize = 0;
    format.FormatFlags = 0;
    format.PresentMask = 0;
    pObject = v8->PlaceHolder.pFormat.pObject;
    if ( pObject )
    {
      v11 = Scaleform::Render::Text::TextFormat::Merge(pObject, &result, fmt);
      Scaleform::Render::Text::TextFormat::operator=(&format, v11);
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
      TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(pallocator, &format);
    }
    else
    {
      TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(pallocator, fmt);
    }
    v15 = length;
    v16 = TextFormat;
    if ( runIndex + runLength - Index < length )
      v15 = runIndex + runLength - Index;
    range.Index = Index;
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
    length -= v15;
    Scaleform::Render::Text::Paragraph::FormatRunIterator::SetTextPos(&it, runIndex + runLength);
    if ( v16 )
    {
      v18 = v16->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v16);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
    }
    if ( format.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)format.pFontHandle.pObject);
    if ( format.pImageDesc.pObject )
      Scaleform::RefCountNTSImpl::Release(format.pImageDesc.pObject);
    v19 = (void *)(format.Url.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((format.Url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
    v20 = (void *)(format.FontList.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((format.FontList.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
    v6 = this;
    if ( length <= 0 )
      break;
    Index = startPos;
  }
LABEL_41:
  v21 = it.PlaceHolder.pFormat.pObject;
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
