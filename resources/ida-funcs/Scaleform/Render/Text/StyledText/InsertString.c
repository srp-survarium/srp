unsigned int __thiscall Scaleform::Render::Text::StyledText::InsertString(
        Scaleform::Render::Text::StyledText *this,
        wchar_t *pstr,
        unsigned int pos,
        unsigned int length,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy)
{
  return Scaleform::Render::Text::StyledText::InsertString(
           this,
           pstr,
           pos,
           length,
           newLinePolicy,
           this->pDefaultTextFormat.pObject,
           this->pDefaultParagraphFormat.pObject);
}


unsigned int __thiscall Scaleform::Render::Text::StyledText::InsertString(
        Scaleform::Render::Text::StyledText *this,
        wchar_t *pstr,
        unsigned int pos,
        unsigned int length,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy,
        Scaleform::Render::Text::TextFormat *pdefTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  unsigned int v7; // esi
  unsigned int v10; // ebx
  unsigned int StartIndex; // eax
  unsigned int v12; // edx
  bool v13; // zf
  const wchar_t *v14; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *pArray; // eax
  signed int CurIndex; // ebp
  Scaleform::Render::Text::StyledText *v17; // edi
  Scaleform::Render::Text::Paragraph *pPara; // esi
  unsigned int Size; // eax
  bool v20; // zf
  unsigned int v21; // edx
  wchar_t *v22; // ecx
  int v23; // ecx
  unsigned int v24; // eax
  int v25; // ebx
  bool v26; // cc
  Scaleform::Render::Text::Paragraph *inserted; // eax
  Scaleform::Render::Text::ParagraphFormat *pObject; // ebp
  Scaleform::Render::Text::Paragraph *v29; // edi
  Scaleform::Render::Text::ParagraphFormat *v30; // ebx
  unsigned int v31; // ebx
  Scaleform::Render::Text::StyledText *v32; // edx
  unsigned int v33; // edi
  unsigned int v34; // eax
  unsigned int v35; // ecx
  unsigned int v36; // edi
  unsigned int v37; // ebp
  __int16 v38; // dx
  wchar_t v39; // ax
  unsigned int v40; // ecx
  unsigned int v41; // eax
  wchar_t *pText; // ecx
  unsigned int v43; // edx
  wchar_t *v44; // edx
  int v45; // edi
  unsigned int v46; // edx
  wchar_t *v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // esi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *v50; // edx
  int v51; // eax
  Scaleform::Render::Text::Paragraph *v52; // ecx
  Scaleform::Render::Text::StyledText *v53; // edi
  signed int v54; // ecx
  signed int v55; // eax
  Scaleform::Render::Text::Paragraph *appended; // eax
  unsigned int v57; // ecx
  unsigned int v58; // esi
  wchar_t *v59; // ecx
  wchar_t v60; // cx
  unsigned int indexInPara; // [esp+10h] [ebp-24h] BYREF
  Scaleform::Render::Text::StyledText *v62; // [esp+14h] [ebp-20h]
  int uniChar; // [esp+18h] [ebp-1Ch]
  unsigned int nextParaStartingPos; // [esp+1Ch] [ebp-18h]
  unsigned int totalInsertedLen; // [esp+20h] [ebp-14h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+24h] [ebp-10h] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator newParaIter; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int remainingSrcStrLen; // [esp+3Ch] [ebp+8h]
  unsigned int insLineLen; // [esp+40h] [ebp+Ch]

  v7 = length;
  v62 = this;
  if ( !length )
    return 0;
  v10 = pos;
  if ( pos > Scaleform::Render::Text::StyledText::GetLength(this) )
    v10 = Scaleform::Render::Text::StyledText::GetLength(this);
  if ( length == -1 )
  {
    v7 = 0;
    if ( *pstr )
    {
      do
        ++v7;
      while ( pstr[v7] );
    }
  }
  this->OnTextInserting(this, v10, v7, pstr);
  indexInPara = 0;
  remainingSrcStrLen = v7;
  Scaleform::Render::Text::StyledText::GetNearestParagraphByIndex(this, &paraIter, v10, &indexInPara);
  if ( paraIter.pArray && paraIter.CurIndex >= 0 && paraIter.CurIndex < (signed int)paraIter.pArray->Data.Size )
    StartIndex = paraIter.pArray->Data.Data[paraIter.CurIndex].pPara->StartIndex;
  else
    StartIndex = 0;
  nextParaStartingPos = StartIndex;
  uniChar = 0;
  totalInsertedLen = 0;
  do
  {
    if ( newLinePolicy == NLP_IgnoreCRLF )
    {
      v12 = remainingSrcStrLen;
      v13 = remainingSrcStrLen == 0;
      if ( remainingSrcStrLen )
      {
        v14 = pstr;
        do
        {
          if ( *v14 != 13 && *v14 != 10 )
            break;
          ++v14;
          --v12;
        }
        while ( v12 );
        pstr = (wchar_t *)v14;
        remainingSrcStrLen = v12;
        v13 = v12 == 0;
      }
      if ( v13 )
        break;
    }
    pArray = paraIter.pArray;
    if ( paraIter.pArray
      && (CurIndex = paraIter.CurIndex, paraIter.CurIndex >= 0)
      && paraIter.CurIndex < (signed int)paraIter.pArray->Data.Size )
    {
      v17 = v62;
    }
    else
    {
      v17 = v62;
      Scaleform::Render::Text::StyledText::AppendNewParagraph(v62, pdefParaFmt);
      pArray = &v17->Paragraphs;
      CurIndex = 0;
      paraIter.pArray = &v17->Paragraphs;
      paraIter.CurIndex = 0;
      indexInPara = 0;
    }
    pPara = pArray->Data.Data[CurIndex].pPara;
    Size = pPara->Text.Size;
    v20 = Size == 0;
    if ( Size )
    {
      v21 = Size - 1;
      if ( pPara->Text.pText && v21 < Size )
        v22 = &pPara->Text.pText[v21];
      else
        v22 = 0;
      if ( !*v22 )
        --Size;
      v20 = Size == 0;
    }
    if ( v20 )
      Scaleform::Render::Text::Paragraph::SetFormat(pPara, v17->pTextAllocator.pObject, pdefParaFmt);
    LOWORD(v23) = uniChar;
    v24 = 0;
    v25 = -1;
    insLineLen = 0;
    if ( newLinePolicy == NLP_CompressCRLF && (_WORD)uniChar == 13 && *pstr == 10 )
    {
      ++pstr;
      if ( !--remainingSrcStrLen )
        break;
      v17 = v62;
      CurIndex = paraIter.CurIndex;
    }
    if ( remainingSrcStrLen )
    {
      while ( 1 )
      {
        v23 = pstr[v24];
        uniChar = v23;
        if ( (_WORD)v23 == 10 || (_WORD)v23 == 13 )
          break;
        if ( (_WORD)v23 )
        {
          if ( ++v24 < remainingSrcStrLen )
            continue;
        }
        insLineLen = v24;
        goto LABEL_48;
      }
      insLineLen = v24;
      if ( newLinePolicy == NLP_IgnoreCRLF )
      {
        uniChar = 1;
LABEL_67:
        Scaleform::Render::Text::Paragraph::InsertString(
          pPara,
          v17->pTextAllocator.pObject,
          pstr,
          indexInPara,
          v24,
          pdefTextFmt);
        v31 = indexInPara;
        goto LABEL_68;
      }
      v25 = v24;
    }
LABEL_48:
    if ( (_WORD)v23 == 10 || (_WORD)v23 == 13 )
      insLineLen = ++v24;
    if ( v25 == -1 )
      goto LABEL_67;
    v26 = CurIndex < (signed int)paraIter.pArray->Data.Size;
    newParaIter.pArray = paraIter.pArray;
    newParaIter.CurIndex = CurIndex;
    if ( v26 )
      newParaIter.CurIndex = CurIndex + 1;
    inserted = Scaleform::Render::Text::StyledText::InsertNewParagraph(v17, &newParaIter, pdefParaFmt);
    pObject = pPara->pFormat.pObject;
    v29 = inserted;
    if ( pObject )
      ++pObject->RefCount;
    v30 = inserted->pFormat.pObject;
    if ( v30 )
    {
      v13 = v30->RefCount-- == 1;
      if ( v13 )
      {
        Scaleform::Render::Text::ParagraphFormat::FreeTabStops(v30);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v30);
      }
    }
    v31 = indexInPara;
    v32 = v62;
    v29->pFormat.pObject = pObject;
    ++v29->ModCounter;
    Scaleform::Render::Text::Paragraph::Copy(v29, v32->pTextAllocator.pObject, pPara, v31, 0, pPara->Text.Size - v31);
    v33 = pPara->Text.Size - v31;
    Scaleform::Render::Text::Paragraph::InsertString(
      pPara,
      v62->pTextAllocator.pObject,
      pstr,
      v31,
      insLineLen,
      pdefTextFmt);
    if ( !v33 )
      goto LABEL_68;
    v34 = pPara->Text.Size;
    v35 = v33;
    if ( v33 >= v34 )
      v35 = pPara->Text.Size;
    v36 = v34 - v35;
    if ( v34 == -1 )
    {
      v37 = -1;
LABEL_73:
      if ( v36 < v34 )
      {
        if ( v36 + v37 < v34 )
        {
          memmove(
            (unsigned __int8 *)&pPara->Text.pText[v34 - v35],
            (unsigned __int8 *)&pPara->Text.pText[v36 + v37],
            2 * (v35 - v37));
          pPara->Text.Size -= v37;
        }
        else
        {
          pPara->Text.Size = v36;
        }
      }
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
        &pPara->FormatInfo,
        v36,
        v37);
      v41 = pPara->Text.Size;
      if ( v41 )
      {
        pText = pPara->Text.pText;
        v43 = v41 - 1;
        if ( pPara->Text.pText && v43 < v41 )
          v44 = &pText[v43];
        else
          v44 = 0;
        if ( !*v44 )
        {
          v45 = pPara->Text.Size;
          v46 = v41 - 1;
          if ( pText && v46 < v41 )
            v47 = &pText[v46];
          else
            v47 = 0;
          if ( !*v47 )
            --v45;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
            &pPara->FormatInfo,
            v45,
            1u);
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
            &pPara->FormatInfo,
            v45 + 1,
            1u);
        }
      }
      ++pPara->ModCounter;
      goto LABEL_68;
    }
    v37 = v35;
    if ( v34 != v36 )
      goto LABEL_73;
LABEL_68:
    v38 = uniChar;
    if ( ((_WORD)uniChar == 13 || (_WORD)uniChar == 10)
      && (v39 = (unsigned __int8)((v62->RTFlags & 2) != 0 ? 13 : 10), (_WORD)uniChar != v39) )
    {
      v40 = insLineLen;
      pPara->Text.pText[insLineLen - 1 + v31] = v39;
    }
    else
    {
      v40 = insLineLen;
    }
    remainingSrcStrLen -= v40;
    totalInsertedLen += v40;
    pstr += v40;
    v48 = nextParaStartingPos;
    pPara->StartIndex = nextParaStartingPos;
    if ( newLinePolicy == NLP_IgnoreCRLF )
    {
      indexInPara = v40 + v31;
    }
    else
    {
      nextParaStartingPos = pPara->Text.Size + v48;
      v26 = paraIter.CurIndex < (signed int)paraIter.pArray->Data.Size;
      indexInPara = 0;
      if ( v26 )
        ++paraIter.CurIndex;
    }
  }
  while ( remainingSrcStrLen && v38 );
  v49 = nextParaStartingPos;
  v50 = paraIter.pArray;
  v51 = paraIter.CurIndex;
  while ( v50 && v51 >= 0 && v51 < (signed int)v50->Data.Size )
  {
    v52 = v50->Data.Data[v51].pPara;
    v52->StartIndex = v49;
    v49 += v52->Text.Size;
    if ( v51 < (signed int)v50->Data.Size )
      ++v51;
  }
  v53 = v62;
  v54 = v62->Paragraphs.Data.Size;
  v55 = v54 - 1;
  if ( v54 - 1 >= 0 && v55 < v54 && (appended = v62->Paragraphs.Data.Data[v55].pPara) != 0
    || (appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(v62, 0)) != 0 )
  {
    v57 = appended->Text.Size;
    if ( !v57
      || ((v58 = v57 - 1, !appended->Text.pText) || v58 >= v57 ? (v59 = 0) : (v59 = &appended->Text.pText[v58]),
          (v60 = *v59, v60 != 13) && v60 != 10) )
    {
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        appended,
        v53->pTextAllocator.pObject,
        v53->pDefaultTextFormat.pObject);
    }
  }
  if ( (pdefTextFmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&pdefTextFmt->Url) )
    v53->RTFlags |= 1u;
  return totalInsertedLen;
}
