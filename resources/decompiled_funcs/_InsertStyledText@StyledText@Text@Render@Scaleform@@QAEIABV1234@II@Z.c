unsigned int __thiscall Scaleform::Render::Text::StyledText::InsertStyledText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::StyledText *text,
        unsigned int pos,
        unsigned int length)
{
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edi
  Scaleform::Render::Text::Paragraph *pArray; // edi
  int CurIndex; // ebx
  unsigned int v10; // ebp
  unsigned int v11; // eax
  bool v12; // zf
  Scaleform::Render::Text::Paragraph *pPara; // esi
  unsigned int Size; // eax
  unsigned int v15; // edx
  wchar_t *v16; // ecx
  signed int v17; // eax
  bool v18; // cc
  Scaleform::Render::Text::Paragraph *v19; // esi
  Scaleform::Render::Text::Paragraph *inserted; // eax
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *Data; // ecx
  const Scaleform::Render::Text::Paragraph *v22; // edi
  unsigned int v23; // eax
  unsigned int v24; // ebx
  unsigned int v25; // edx
  wchar_t *v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edx
  wchar_t *v29; // ecx
  unsigned int v30; // eax
  unsigned int v31; // ecx
  unsigned int v32; // eax
  wchar_t *pText; // esi
  unsigned int v34; // ecx
  wchar_t *v35; // esi
  signed int v36; // eax
  Scaleform::Render::Text::Paragraph *v37; // edi
  unsigned int v38; // esi
  unsigned int v39; // ecx
  wchar_t *v40; // eax
  Scaleform::Render::Text::Paragraph *v41; // esi
  Scaleform::Render::Text::Paragraph *v42; // ecx
  unsigned int v43; // eax
  wchar_t *v44; // ecx
  unsigned int v45; // edx
  wchar_t *v46; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *v47; // esi
  int v48; // edx
  unsigned int v49; // ecx
  Scaleform::Render::Text::Paragraph *v50; // eax
  signed int v51; // ecx
  signed int v52; // eax
  Scaleform::Render::Text::Paragraph *appended; // eax
  unsigned int v54; // ecx
  unsigned int v55; // esi
  wchar_t *v56; // ecx
  wchar_t v57; // cx
  Scaleform::Render::Text::Allocator *pObject; // [esp-18h] [ebp-44h]
  unsigned int v60; // [esp-8h] [ebp-34h]
  unsigned int v61; // [esp-8h] [ebp-34h]
  Scaleform::Render::Text::Paragraph *remainedLen; // [esp+10h] [ebp-1Ch]
  unsigned int remainedLena; // [esp+10h] [ebp-1Ch]
  Scaleform::Render::Text::Paragraph *newPara; // [esp+14h] [ebp-18h] BYREF
  int v66; // [esp+18h] [ebp-14h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator destParaIter; // [esp+1Ch] [ebp-10h] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator srcParaIter; // [esp+24h] [ebp-8h]

  v5 = Scaleform::Render::Text::StyledText::GetLength(text);
  v6 = length;
  if ( length == -1 || length > v5 )
  {
    v6 = v5;
    length = v5;
  }
  if ( !v6 || !text->Paragraphs.Data.Size )
    return 0;
  v7 = pos;
  this->OnTextInserting(this, pos, v6, (const char *)&buf);
  pos = 0;
  Scaleform::Render::Text::StyledText::GetNearestParagraphByIndex(this, &destParaIter, v7, &pos);
  pArray = (Scaleform::Render::Text::Paragraph *)destParaIter.pArray;
  if ( destParaIter.pArray
    && (CurIndex = destParaIter.CurIndex, destParaIter.CurIndex >= 0)
    && destParaIter.CurIndex < (signed int)destParaIter.pArray->Data.Size )
  {
    v10 = pos;
  }
  else
  {
    Scaleform::Render::Text::StyledText::AppendNewParagraph(this, 0);
    pArray = (Scaleform::Render::Text::Paragraph *)&this->Paragraphs;
    CurIndex = 0;
    destParaIter.pArray = &this->Paragraphs;
    destParaIter.CurIndex = 0;
    v10 = 0;
  }
  if ( pArray && CurIndex >= 0 && CurIndex < (signed int)pArray->Text.Size )
    v11 = *(_DWORD *)(*(_DWORD *)&pArray->Text.pText[2 * CurIndex] + 28);
  else
    v11 = 0;
  v12 = text->Paragraphs.Data.Size == 1;
  pos = v11;
  if ( v12 )
  {
    pPara = text->Paragraphs.Data.Data->pPara;
    Size = pPara->Text.Size;
    remainedLen = *(Scaleform::Render::Text::Paragraph **)&pArray->Text.pText[2 * CurIndex];
    if ( Size )
    {
      v15 = Size - 1;
      if ( pPara->Text.pText && v15 < Size )
        v16 = &pPara->Text.pText[v15];
      else
        v16 = 0;
      if ( !*v16 )
        --Size;
    }
    Scaleform::Render::Text::Paragraph::Copy(remainedLen, this->pTextAllocator.pObject, pPara, 0, v10, Size);
    if ( !v10 )
      Scaleform::Render::Text::Paragraph::SetFormat(remainedLen, this->pTextAllocator.pObject, pPara->pFormat.pObject);
    v17 = pArray->Text.Size;
    pos += remainedLen->Text.Size;
    v18 = CurIndex < v17;
  }
  else
  {
    v18 = CurIndex < (signed int)pArray->Text.Size;
    v19 = *(Scaleform::Render::Text::Paragraph **)&pArray->Text.pText[2 * CurIndex];
    srcParaIter.CurIndex = 0;
    newPara = pArray;
    v66 = CurIndex;
    if ( v18 )
      v66 = CurIndex + 1;
    inserted = Scaleform::Render::Text::StyledText::InsertNewParagraph(
                 this,
                 (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *)&newPara,
                 v19->pFormat.pObject);
    v60 = v19->Text.Size - v10;
    pObject = this->pTextAllocator.pObject;
    newPara = inserted;
    Scaleform::Render::Text::Paragraph::Copy(inserted, pObject, v19, v10, 0, v60);
    Data = text->Paragraphs.Data.Data;
    v22 = Data->pPara;
    v23 = Data->pPara->Text.Size;
    v24 = v19->Text.Size - v10;
    if ( v23 )
    {
      v25 = v23 - 1;
      if ( v22->Text.pText && v25 < v23 )
        v26 = &v22->Text.pText[v25];
      else
        v26 = 0;
      if ( !*v26 )
        --v23;
    }
    Scaleform::Render::Text::Paragraph::Copy(v19, this->pTextAllocator.pObject, v22, 0, v10, v23);
    v27 = v22->Text.Size;
    if ( v27 )
    {
      v28 = v27 - 1;
      if ( v22->Text.pText && v28 < v27 )
        v29 = &v22->Text.pText[v28];
      else
        v29 = 0;
      if ( !*v29 )
        --v27;
    }
    remainedLena = length - v27;
    if ( !v10 )
      Scaleform::Render::Text::Paragraph::SetFormat(v19, this->pTextAllocator.pObject, v22->pFormat.pObject);
    if ( v24 )
    {
      v30 = v19->Text.Size;
      v31 = v24;
      if ( v24 >= v30 )
        v31 = v19->Text.Size;
      Scaleform::Render::Text::Paragraph::Remove(v19, v30 - v31, v19->Text.Size);
    }
    v32 = v19->Text.Size;
    if ( v32 )
    {
      pText = v19->Text.pText;
      v34 = v32 - 1;
      if ( pText && v34 < v32 )
        v35 = &pText[v34];
      else
        v35 = 0;
      if ( !*v35 )
        --v32;
    }
    pos += v32;
    if ( destParaIter.CurIndex < (signed int)destParaIter.pArray->Data.Size )
      ++destParaIter.CurIndex;
    v36 = text->Paragraphs.Data.Size;
    if ( v36 > 0 )
      srcParaIter.CurIndex = 1;
    while ( srcParaIter.CurIndex >= 0 && srcParaIter.CurIndex < v36 && remainedLena )
    {
      v37 = text->Paragraphs.Data.Data[srcParaIter.CurIndex].pPara;
      v38 = v37->Text.Size;
      if ( v38 )
      {
        v39 = v38 - 1;
        if ( v37->Text.pText && v39 < v38 )
          v40 = &v37->Text.pText[v39];
        else
          v40 = 0;
        if ( !*v40 )
          --v38;
      }
      if ( v38 > remainedLena || v38 == remainedLena && !Scaleform::Render::Text::Paragraph::HasNewLine(v37) )
      {
        v61 = v38;
        v41 = newPara;
        Scaleform::Render::Text::Paragraph::Copy(newPara, this->pTextAllocator.pObject, v37, 0, 0, v61);
        Scaleform::Render::Text::Paragraph::SetFormat(v41, this->pTextAllocator.pObject, v37->pFormat.pObject);
        break;
      }
      Scaleform::Render::Text::StyledText::InsertCopyOfParagraph(this, &destParaIter, v37);
      v36 = text->Paragraphs.Data.Size;
      remainedLena -= v38;
      pos += v38;
      if ( srcParaIter.CurIndex < v36 )
        ++srcParaIter.CurIndex;
      if ( destParaIter.CurIndex < (signed int)destParaIter.pArray->Data.Size )
        ++destParaIter.CurIndex;
    }
    v42 = newPara;
    newPara->StartIndex = pos;
    v43 = v42->Text.Size;
    if ( v43 )
    {
      v44 = v42->Text.pText;
      v45 = v43 - 1;
      if ( v44 && v45 < v43 )
        v46 = &v44[v45];
      else
        v46 = 0;
      if ( !*v46 )
        --v43;
    }
    pos += v43;
    v17 = destParaIter.pArray->Data.Size;
    v18 = destParaIter.CurIndex < v17;
  }
  if ( v18 )
    ++destParaIter.CurIndex;
  v47 = destParaIter.pArray;
  v48 = destParaIter.CurIndex;
  v49 = pos;
  while ( v48 >= 0 )
  {
    if ( v48 >= v17 )
      break;
    v50 = v47->Data.Data[v48].pPara;
    if ( v50->StartIndex == v49 )
      break;
    v50->StartIndex = v49;
    v49 += v50->Text.Size;
    v17 = v47->Data.Size;
    if ( v48 < v17 )
      ++v48;
  }
  v51 = this->Paragraphs.Data.Size;
  v52 = v51 - 1;
  if ( v51 - 1 >= 0 && v52 < v51 && (appended = this->Paragraphs.Data.Data[v52].pPara) != 0
    || (appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, 0)) != 0 )
  {
    v54 = appended->Text.Size;
    if ( !v54
      || ((v55 = v54 - 1, !appended->Text.pText) || v55 >= v54 ? (v56 = 0) : (v56 = &appended->Text.pText[v55]),
          (v57 = *v56, v57 != 13) && v57 != 10) )
    {
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        appended,
        this->pTextAllocator.pObject,
        this->pDefaultTextFormat.pObject);
    }
  }
  if ( (text->RTFlags & 1) != 0 )
    this->RTFlags |= 1u;
  return length;
}
