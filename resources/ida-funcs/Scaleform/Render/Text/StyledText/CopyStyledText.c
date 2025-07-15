Scaleform::Render::Text::StyledText *__thiscall Scaleform::Render::Text::StyledText::CopyStyledText(
        Scaleform::Render::Text::StyledText *this,
        unsigned int startPos,
        const Scaleform::Render::Text::Paragraph *endPos)
{
  Scaleform::Render::Text::Allocator *Allocator; // esi
  Scaleform::Render::Text::StyledText *v5; // eax
  Scaleform::Render::Text::StyledText *v6; // eax
  Scaleform::Render::Text::StyledText *v7; // esi

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
        Scaleform::Render::Text::StyledText *pdest,
        unsigned int startPos,
        const Scaleform::Render::Text::Paragraph *endPos)
{
  const Scaleform::Render::Text::Paragraph *Length; // eax
  unsigned int v6; // edi
  const Scaleform::Render::Text::Paragraph *v8; // esi
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
  Scaleform::Render::Text::Paragraph *v24; // eax
  Scaleform::Render::Text::Paragraph *v25; // esi
  Scaleform::Render::Text::Allocator *v26; // eax
  signed int v27; // ecx
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
  int v42; // [esp-Ch] [ebp-28h]
  Scaleform::Render::Text::ParagraphFormat *pObject; // [esp-4h] [ebp-20h]
  const Scaleform::Render::Text::Paragraph *v44; // [esp-4h] [ebp-20h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+14h] [ebp-8h] BYREF
  Scaleform::Render::Text::Paragraph *appended; // [esp+20h] [ebp+4h]

  Length = endPos;
  if ( endPos == (const Scaleform::Render::Text::Paragraph *)-1 )
    Length = (const Scaleform::Render::Text::Paragraph *)Scaleform::Render::Text::StyledText::GetLength(this);
  v6 = startPos;
  v8 = (const Scaleform::Render::Text::Paragraph *)((char *)Length - startPos);
  startPos = 0;
  endPos = v8;
  Scaleform::Render::Text::StyledText::Clear(pdest);
  pdest->OnTextInserting(pdest, v6, (unsigned int)v8, uri);
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(this, &result, v6, &startPos);
  pArray = result.pArray;
  if ( result.pArray )
  {
    CurIndex = result.CurIndex;
    if ( result.CurIndex >= 0 )
    {
      Size = result.pArray->Data.Size;
      if ( result.CurIndex < Size )
      {
        if ( !startPos )
          goto LABEL_19;
        pPara = result.pArray->Data.Data[result.CurIndex].pPara;
        pObject = pPara->pFormat.pObject;
        endPos = pPara;
        appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(pdest, pObject);
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
        if ( v13 - startPos >= (unsigned int)v8 )
          v17 = (unsigned int)v8;
        v42 = startPos;
        v41 = endPos;
        Allocator = Scaleform::Render::Text::StyledText::GetAllocator(pdest);
        Scaleform::Render::Text::Paragraph::Copy(appended, Allocator, v41, v42, 0, v17);
        Size = result.pArray->Data.Size;
        endPos = (const Scaleform::Render::Text::Paragraph *)((char *)v8 - v17);
        for ( pArray = result.pArray; ; Size = pArray->Data.Size )
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
            v24 = Scaleform::Render::Text::StyledText::AppendNewParagraph(pdest, v23->pFormat.pObject);
            v44 = endPos;
            v25 = v24;
            v26 = Scaleform::Render::Text::StyledText::GetAllocator(pdest);
            Scaleform::Render::Text::Paragraph::Copy(v25, v26, v23, 0, 0, (unsigned int)v44);
            break;
          }
          Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(pdest, pArray->Data.Data[CurIndex].pPara);
          endPos = (const Scaleform::Render::Text::Paragraph *)((char *)endPos - v20);
        }
      }
    }
  }
  v27 = pdest->Paragraphs.Data.Size;
  v28 = v27 - 1;
  if ( v27 - 1 >= 0 && v28 < v27 )
  {
    v29 = pdest->Paragraphs.Data.Data[v28].pPara;
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
          Scaleform::Render::Text::StyledText::AppendNewParagraph(pdest, v29->pFormat.pObject);
      }
    }
  }
  v34 = pdest->Paragraphs.Data.Size;
  v35 = v34 - 1;
  if ( v34 - 1 >= 0 && v35 < v34 && (v36 = pdest->Paragraphs.Data.Data[v35].pPara) != 0
    || (v36 = Scaleform::Render::Text::StyledText::AppendNewParagraph(pdest, 0)) != 0 )
  {
    v37 = v36->Text.Size;
    if ( !v37
      || ((v38 = v37 - 1, !v36->Text.pText) || v38 >= v37 ? (v39 = 0) : (v39 = &v36->Text.pText[v38]),
          (v40 = *v39, v40 != 13) && v40 != 10) )
    {
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        v36,
        pdest->pTextAllocator.pObject,
        pdest->pDefaultTextFormat.pObject);
    }
  }
  if ( (this->RTFlags & 1) != 0 )
    pdest->RTFlags |= 1u;
}
