Scaleform::Render::Text::Paragraph *__thiscall Scaleform::Render::Text::StyledText::CopyStyledText(
        Scaleform::Render::Text::StyledText *this,
        unsigned int startPos,
        Scaleform::Render::Text::Paragraph *endPos)
{
  Scaleform::Render::Text::Allocator *Allocator; // esi
  Scaleform::Render::Text::StyledText *v5; // eax
  Scaleform::Render::Text::Paragraph *v6; // eax
  Scaleform::Render::Text::Paragraph *v7; // esi

  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v5 = (Scaleform::Render::Text::StyledText *)Allocator->pHeap->Alloc(Allocator->pHeap, 36u, 0);
  if ( v5 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v5, Allocator);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  Scaleform::Render::Text::StyledText::CopyStyledText(this, v7, startPos, endPos);
  return v7;
}


void __thiscall Scaleform::Render::Text::StyledText::CopyStyledText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::Paragraph *pdest,
        unsigned int startPos,
        Scaleform::Render::Text::Paragraph *endPos)
{
  unsigned int Length; // eax
  unsigned int v6; // edi
  unsigned int v8; // esi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *pArray; // ebx
  int CurIndex; // edi
  signed int Size; // eax
  Scaleform::Render::Text::Paragraph *pPara; // ebx
  unsigned int v13; // eax
  wchar_t *pText; // ebx
  unsigned int v15; // ecx
  wchar_t *v16; // ecx
  unsigned int v17; // ebx
  Scaleform::Render::Text::Allocator *Allocator; // eax
  Scaleform::Render::Text::Paragraph *v19; // eax
  unsigned int v20; // esi
  unsigned int v21; // edx
  wchar_t *v22; // ecx
  const Scaleform::Render::Text::Paragraph *v23; // edi
  Scaleform::Render::Text::Paragraph *appended; // eax
  Scaleform::Render::Text::Paragraph *v25; // esi
  Scaleform::Render::Text::Allocator *v26; // eax
  signed int Data; // ecx
  signed int v28; // eax
  Scaleform::Render::Text::Paragraph *v29; // eax
  unsigned int v30; // ecx
  unsigned int v31; // esi
  wchar_t *v32; // ecx
  wchar_t v33; // cx
  signed int v34; // ecx
  signed int v35; // eax
  Scaleform::Render::Text::Paragraph *v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // esi
  wchar_t *v39; // ecx
  wchar_t v40; // cx
  const Scaleform::Render::Text::Paragraph *v41; // [esp-10h] [ebp-2Ch]
  unsigned int v42; // [esp-Ch] [ebp-28h]
  Scaleform::Render::Text::ParagraphFormat *pObject; // [esp-4h] [ebp-20h]
  unsigned int v44; // [esp-4h] [ebp-20h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+14h] [ebp-8h] BYREF
  Scaleform::Render::Text::Paragraph *pdestPara; // [esp+20h] [ebp+4h]

  Length = (unsigned int)endPos;
  if ( endPos == (Scaleform::Render::Text::Paragraph *)-1 )
    Length = Scaleform::Render::Text::StyledText::GetLength(this);
  v6 = startPos;
  v8 = Length - startPos;
  startPos = 0;
  endPos = (Scaleform::Render::Text::Paragraph *)v8;
  Scaleform::Render::Text::StyledText::Clear((Scaleform::Render::Text::StyledText *)pdest);
  (*((void (__thiscall **)(Scaleform::Render::Text::Paragraph *, unsigned int, unsigned int, const survarium::flash_text *))pdest->Text.pText
   + 1))(
    pdest,
    v6,
    v8,
    &buf);
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(this, &paraIter, v6, &startPos);
  pArray = paraIter.pArray;
  if ( paraIter.pArray )
  {
    CurIndex = paraIter.CurIndex;
    if ( paraIter.CurIndex >= 0 )
    {
      Size = paraIter.pArray->Data.Size;
      if ( paraIter.CurIndex < Size )
      {
        if ( !startPos )
          goto LABEL_19;
        pPara = paraIter.pArray->Data.Data[paraIter.CurIndex].pPara;
        pObject = pPara->pFormat.pObject;
        endPos = pPara;
        pdestPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(
                      (Scaleform::Render::Text::StyledText *)pdest,
                      pObject);
        v13 = pPara->Text.Size;
        if ( v13 )
        {
          pText = pPara->Text.pText;
          v15 = v13 - 1;
          if ( pText && v15 < v13 )
            v16 = &pText[v15];
          else
            v16 = 0;
          if ( !*v16 )
            --v13;
        }
        v17 = v13 - startPos;
        if ( v13 - startPos >= v8 )
          v17 = v8;
        v42 = startPos;
        v41 = endPos;
        Allocator = Scaleform::Render::Text::StyledText::GetAllocator((Scaleform::Render::Text::StyledText *)pdest);
        Scaleform::Render::Text::Paragraph::Copy(pdestPara, Allocator, v41, v42, 0, v17);
        Size = paraIter.pArray->Data.Size;
        endPos = (Scaleform::Render::Text::Paragraph *)(v8 - v17);
        for ( pArray = paraIter.pArray; ; Size = pArray->Data.Size )
        {
          if ( CurIndex < Size )
            ++CurIndex;
LABEL_19:
          if ( CurIndex < 0 || CurIndex >= Size || !endPos )
            break;
          v19 = pArray->Data.Data[CurIndex].pPara;
          v20 = v19->Text.Size;
          if ( v20 )
          {
            v21 = v20 - 1;
            if ( v19->Text.pText && v21 < v20 )
              v22 = &v19->Text.pText[v21];
            else
              v22 = 0;
            if ( !*v22 )
              --v20;
          }
          if ( v20 > (unsigned int)endPos )
          {
            v23 = pArray->Data.Data[CurIndex].pPara;
            appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(
                         (Scaleform::Render::Text::StyledText *)pdest,
                         v23->pFormat.pObject);
            v44 = (unsigned int)endPos;
            v25 = appended;
            v26 = Scaleform::Render::Text::StyledText::GetAllocator((Scaleform::Render::Text::StyledText *)pdest);
            Scaleform::Render::Text::Paragraph::Copy(v25, v26, v23, 0, 0, v44);
            break;
          }
          Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(
            (Scaleform::Render::Text::StyledText *)pdest,
            pArray->Data.Data[CurIndex].pPara);
          endPos = (Scaleform::Render::Text::Paragraph *)((char *)endPos - v20);
        }
      }
    }
  }
  Data = (signed int)pdest->FormatInfo.Ranges.Data.Data;
  v28 = Data - 1;
  if ( Data - 1 >= 0 && v28 < Data )
  {
    v29 = (Scaleform::Render::Text::Paragraph *)*(&pdest->pFormat.pObject->RefCount + v28);
    if ( v29 )
    {
      v30 = v29->Text.Size;
      if ( v30 )
      {
        v31 = v30 - 1;
        if ( v29->Text.pText && v31 < v30 )
          v32 = &v29->Text.pText[v31];
        else
          v32 = 0;
        v33 = *v32;
        if ( v33 == 13 || v33 == 10 )
          Scaleform::Render::Text::StyledText::AppendNewParagraph(
            (Scaleform::Render::Text::StyledText *)pdest,
            v29->pFormat.pObject);
      }
    }
  }
  v34 = (signed int)pdest->FormatInfo.Ranges.Data.Data;
  v35 = v34 - 1;
  if ( v34 - 1 >= 0
    && v35 < v34
    && (v36 = (Scaleform::Render::Text::Paragraph *)*(&pdest->pFormat.pObject->RefCount + v35)) != 0
    || (v36 = Scaleform::Render::Text::StyledText::AppendNewParagraph((Scaleform::Render::Text::StyledText *)pdest, 0)) != 0 )
  {
    v37 = v36->Text.Size;
    if ( !v37
      || ((v38 = v37 - 1, !v36->Text.pText) || v38 >= v37 ? (v39 = 0) : (v39 = &v36->Text.pText[v38]),
          (v40 = *v39, v40 != 13) && v40 != 10) )
    {
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        v36,
        (Scaleform::Render::Text::Allocator *)pdest->Text.Allocated,
        (const Scaleform::Render::Text::TextFormat *)pdest->StartIndex);
    }
  }
  if ( (this->RTFlags & 1) != 0 )
    LOBYTE(pdest->UniqueId) |= 1u;
}
