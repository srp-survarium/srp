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
  unsigned int runLen; // [esp+14h] [ebp-A4h]
  unsigned int indexInPara; // [esp+18h] [ebp-A0h] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+1Ch] [ebp-9Ch] BYREF
  int pi; // [esp+24h] [ebp-94h]
  Scaleform::Render::Text::ParagraphFormat finalParaFmt; // [esp+28h] [ebp-90h] BYREF
  int i; // [esp+3Ch] [ebp-7Ch]
  Scaleform::Render::Text::TextFormat finalTextFmt; // [esp+40h] [ebp-78h] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+68h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat v33; // [esp+90h] [ebp-28h] BYREF

  v6 = endPos - startPos;
  runLen = endPos - startPos;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(this, &paraIter, startPos, &indexInPara);
  v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  finalTextFmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&finalTextFmt.FontList, v7);
  Scaleform::StringDH::StringDH(&finalTextFmt.Url, v7);
  v8 = 0;
  finalTextFmt.pImageDesc.pObject = 0;
  finalTextFmt.pFontHandle.pObject = 0;
  finalTextFmt.ColorV = -16777216;
  finalTextFmt.LetterSpacing = 0;
  finalTextFmt.FontSize = 0;
  finalTextFmt.FormatFlags = 0;
  finalTextFmt.PresentMask = 0;
  finalParaFmt.RefCount = 1;
  memset(&finalParaFmt.pTabStops, 0, 16);
  pi = 0;
  if ( endPos != startPos )
  {
    while ( paraIter.pArray && paraIter.CurIndex >= 0 && paraIter.CurIndex < (signed int)paraIter.pArray->Data.Size )
    {
      pPara = paraIter.pArray->Data.Data[paraIter.CurIndex].pPara;
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
      i = v8 + 1;
      if ( v8 )
      {
        TextFormat = Scaleform::Render::Text::Paragraph::GetTextFormat(pPara, &v33, indexInPara, indexInPara + v6);
        v17 = Scaleform::Render::Text::TextFormat::Intersection(TextFormat, &result, &finalTextFmt);
        Scaleform::Render::Text::TextFormat::operator=(&finalTextFmt, v17);
        if ( result.pFontHandle.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pFontHandle.pObject);
        if ( result.pImageDesc.pObject )
          Scaleform::RefCountNTSImpl::Release(result.pImageDesc.pObject);
        v18 = (void *)(result.Url.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((result.Url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
        v19 = (void *)(result.FontList.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((result.FontList.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
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
        v13 = Scaleform::Render::Text::Paragraph::GetTextFormat(pPara, &result, indexInPara, indexInPara + v6);
        Scaleform::Render::Text::TextFormat::operator=(&finalTextFmt, v13);
        if ( result.pFontHandle.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pFontHandle.pObject);
        if ( result.pImageDesc.pObject )
          Scaleform::RefCountNTSImpl::Release(result.pImageDesc.pObject);
        v14 = (void *)(result.Url.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((result.Url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
        pData = result.FontList.pData;
      }
      v21 = (volatile LONG *)((unsigned int)pData & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v21 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v21);
      if ( !indexInPara )
      {
        pObject = pPara->pFormat.pObject;
        if ( pObject )
        {
          if ( pi++ )
          {
            v24 = Scaleform::Render::Text::ParagraphFormat::Intersection(
                    pObject,
                    (Scaleform::Render::Text::ParagraphFormat *)&result,
                    &finalParaFmt);
            Scaleform::Render::Text::ParagraphFormat::operator=(&finalParaFmt, v24);
            Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&result);
          }
          else
          {
            Scaleform::Render::Text::ParagraphFormat::operator=(&finalParaFmt, pObject);
          }
        }
      }
      runLen -= v6;
      if ( paraIter.CurIndex < (signed int)paraIter.pArray->Data.Size )
        ++paraIter.CurIndex;
      if ( !runLen )
        break;
      v6 = runLen;
      v8 = i;
    }
  }
  if ( pdestTextFmt )
    Scaleform::Render::Text::TextFormat::operator=(pdestTextFmt, &finalTextFmt);
  if ( pdestParaFmt )
    Scaleform::Render::Text::ParagraphFormat::operator=(pdestParaFmt, &finalParaFmt);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&finalParaFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&finalTextFmt);
}


Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat **ppdestTextFmt,
        Scaleform::Render::Text::ParagraphFormat **ppdestParaFmt,
        unsigned int pos)
{
  Scaleform::Render::Text::ParagraphFormat *v5; // esi
  Scaleform::Render::Text::TextFormat *result; // eax
  Scaleform::Render::Text::Paragraph *pPara; // esi
  Scaleform::Render::Text::TextFormat *pObject; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+8h] [ebp-8h] BYREF

  result = (Scaleform::Render::Text::TextFormat *)Scaleform::Render::Text::StyledText::GetParagraphByIndex(
                                                    this,
                                                    &paraIter,
                                                    pos,
                                                    &pos);
  v5 = 0;
  LOBYTE(result) = 0;
  if ( !paraIter.pArray
    || paraIter.CurIndex < 0
    || paraIter.CurIndex >= (signed int)paraIter.pArray->Data.Size
    || (pPara = paraIter.pArray->Data.Data[paraIter.CurIndex].pPara,
        result = Scaleform::Render::Text::Paragraph::GetTextFormatPtr(pPara, pos),
        v5 = pPara->pFormat.pObject,
        pObject = result,
        LOBYTE(result) = 1,
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
  return result;
}
