void __thiscall Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat *pdestTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdestParaFmt,
        unsigned int startPos,
        unsigned int endPos)
{
  unsigned int v6; // ebp
  Scaleform::MemoryHeap *v7; // esi
  int v8; // esi
  Scaleform::Render::Text::Paragraph *pPara; // edi
  unsigned int Size; // eax
  unsigned int v11; // edx
  wchar_t *v12; // ecx
  const Scaleform::Render::Text::TextFormat *v13; // eax
  void *v14; // esi
  Scaleform::String::DataDesc *pData; // esi
  Scaleform::Render::Text::TextFormat *TextFormat; // eax
  const Scaleform::Render::Text::TextFormat *v17; // eax
  void *v18; // esi
  void *v19; // esi
  void *v20; // esi
  volatile LONG *v21; // esi
  Scaleform::Render::Text::ParagraphFormat *pObject; // ecx
  const Scaleform::Render::Text::ParagraphFormat *v24; // eax
  unsigned int v25; // [esp+14h] [ebp-A4h]
  unsigned int pindexInParagraph; // [esp+18h] [ebp-A0h] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+1Ch] [ebp-9Ch] BYREF
  int v28; // [esp+24h] [ebp-94h]
  Scaleform::Render::Text::ParagraphFormat src; // [esp+28h] [ebp-90h] BYREF
  int v30; // [esp+3Ch] [ebp-7Ch]
  Scaleform::Render::Text::TextFormat fmt; // [esp+40h] [ebp-78h] BYREF
  Scaleform::Render::Text::TextFormat v32; // [esp+68h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat v33; // [esp+90h] [ebp-28h] BYREF

  v6 = endPos - startPos;
  v25 = endPos - startPos;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(this, &result, startPos, &pindexInParagraph);
  v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  fmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&fmt.FontList, v7);
  Scaleform::StringDH::StringDH(&fmt.Url, v7);
  v8 = 0;
  fmt.pImageDesc.pObject = 0;
  fmt.pFontHandle.pObject = 0;
  fmt.ColorV = -16777216;
  fmt.LetterSpacing = 0;
  fmt.FontSize = 0;
  fmt.FormatFlags = 0;
  fmt.PresentMask = 0;
  src.RefCount = 1;
  memset(&src.pTabStops, 0, 16);
  v28 = 0;
  if ( endPos != startPos )
  {
    while ( result.pArray && result.CurIndex >= 0 && result.CurIndex < (signed int)result.pArray->Data.Size )
    {
      pPara = result.pArray->Data.Data[result.CurIndex].pPara;
      Size = pPara->Text.Size;
      if ( Size )
      {
        v11 = Size - 1;
        if ( pPara->Text.pText && v11 < Size )
          v12 = &pPara->Text.pText[v11];
        else
          v12 = 0;
        if ( !*v12 )
          --Size;
      }
      if ( v6 >= Size )
        v6 = Size;
      if ( !v6 )
        break;
      v30 = v8 + 1;
      if ( v8 )
      {
        TextFormat = Scaleform::Render::Text::Paragraph::GetTextFormat(
                       pPara,
                       &v33,
                       pindexInParagraph,
                       pindexInParagraph + v6);
        v17 = Scaleform::Render::Text::TextFormat::Intersection(TextFormat, &v32, &fmt);
        Scaleform::Render::Text::TextFormat::operator=(&fmt, v17);
        if ( v32.pFontHandle.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v32.pFontHandle.pObject);
        if ( v32.pImageDesc.pObject )
          Scaleform::RefCountNTSImpl::Release(v32.pImageDesc.pObject);
        v18 = (void *)(v32.Url.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v32.Url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
        v19 = (void *)(v32.FontList.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v32.FontList.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
        if ( v33.pFontHandle.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v33.pFontHandle.pObject);
        if ( v33.pImageDesc.pObject )
          Scaleform::RefCountNTSImpl::Release(v33.pImageDesc.pObject);
        v20 = (void *)(v33.Url.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v33.Url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
        pData = v33.FontList.pData;
      }
      else
      {
        v13 = Scaleform::Render::Text::Paragraph::GetTextFormat(pPara, &v32, pindexInParagraph, pindexInParagraph + v6);
        Scaleform::Render::Text::TextFormat::operator=(&fmt, v13);
        if ( v32.pFontHandle.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v32.pFontHandle.pObject);
        if ( v32.pImageDesc.pObject )
          Scaleform::RefCountNTSImpl::Release(v32.pImageDesc.pObject);
        v14 = (void *)(v32.Url.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v32.Url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
        pData = v32.FontList.pData;
      }
      v21 = (volatile LONG *)((unsigned int)pData & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v21 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v21);
      if ( !pindexInParagraph )
      {
        pObject = pPara->pFormat.pObject;
        if ( pObject )
        {
          if ( v28++ )
          {
            v24 = Scaleform::Render::Text::ParagraphFormat::Intersection(
                    pObject,
                    (Scaleform::Render::Text::ParagraphFormat *)&v32,
                    &src);
            Scaleform::Render::Text::ParagraphFormat::operator=(&src, v24);
            Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&v32);
          }
          else
          {
            Scaleform::Render::Text::ParagraphFormat::operator=(&src, pObject);
          }
        }
      }
      v25 -= v6;
      if ( result.CurIndex < (signed int)result.pArray->Data.Size )
        ++result.CurIndex;
      if ( !v25 )
        break;
      v6 = v25;
      v8 = v30;
    }
  }
  if ( pdestTextFmt )
    Scaleform::Render::Text::TextFormat::operator=(pdestTextFmt, &fmt);
  if ( pdestParaFmt )
    Scaleform::Render::Text::ParagraphFormat::operator=(pdestParaFmt, &src);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&src);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}


Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat **ppdestTextFmt,
        Scaleform::Render::Text::ParagraphFormat **ppdestParaFmt,
        unsigned int pos)
{
  Scaleform::Render::Text::ParagraphFormat *v5; // esi
  Scaleform::Render::Text::TextFormat *ParagraphByIndex; // eax
  Scaleform::Render::Text::Paragraph *pPara; // esi
  Scaleform::Render::Text::TextFormat *pObject; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+8h] [ebp-8h] BYREF

  ParagraphByIndex = (Scaleform::Render::Text::TextFormat *)Scaleform::Render::Text::StyledText::GetParagraphByIndex(
                                                              this,
                                                              &result,
                                                              pos,
                                                              &pos);
  v5 = 0;
  LOBYTE(ParagraphByIndex) = 0;
  if ( !result.pArray
    || result.CurIndex < 0
    || result.CurIndex >= (signed int)result.pArray->Data.Size
    || (pPara = result.pArray->Data.Data[result.CurIndex].pPara,
        ParagraphByIndex = Scaleform::Render::Text::Paragraph::GetTextFormatPtr(pPara, pos),
        v5 = pPara->pFormat.pObject,
        pObject = ParagraphByIndex,
        LOBYTE(ParagraphByIndex) = 1,
        !pObject) )
  {
    pObject = this->pDefaultTextFormat.pObject;
  }
  if ( !v5 )
    v5 = this->pDefaultParagraphFormat.pObject;
  if ( ppdestTextFmt )
    *ppdestTextFmt = pObject;
  if ( ppdestParaFmt )
    *ppdestParaFmt = v5;
  return ParagraphByIndex;
}
