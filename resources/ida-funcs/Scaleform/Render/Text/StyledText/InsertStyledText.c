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
  Scaleform::Render::Text::Paragraph *v63; // [esp+10h] [ebp-1Ch]
  Scaleform::Render::Text::Paragraph *v64; // [esp+10h] [ebp-1Ch]
  Scaleform::Render::Text::Paragraph *v65; // [esp+14h] [ebp-18h] BYREF
  int v66; // [esp+18h] [ebp-14h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+1Ch] [ebp-10h] BYREF
  int v68; // [esp+28h] [ebp-4h]

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
  this->OnTextInserting(this, pos, v6, uri);
  pos = 0;
  Scaleform::Render::Text::StyledText::GetNearestParagraphByIndex(this, &result, v7, &pos);
  pArray = (Scaleform::Render::Text::Paragraph *)result.pArray;
  if ( result.pArray
    && (CurIndex = result.CurIndex, result.CurIndex >= 0)
    && result.CurIndex < (signed int)result.pArray->Data.Size )
  {
    v10 = pos;
  }
  else
  {
    Scaleform::Render::Text::StyledText::AppendNewParagraph(this, 0);
    pArray = (Scaleform::Render::Text::Paragraph *)&this->Paragraphs;
    CurIndex = 0;
    result.pArray = &this->Paragraphs;
    result.CurIndex = 0;
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
    v63 = *(Scaleform::Render::Text::Paragraph **)&pArray->Text.pText[2 * CurIndex];
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
    Scaleform::Render::Text::Paragraph::Copy(v63, this->pTextAllocator.pObject, pPara, 0, v10, Size);
    if ( !v10 )
      Scaleform::Render::Text::Paragraph::SetFormat(v63, this->pTextAllocator.pObject, pPara->pFormat.pObject);
    v17 = pArray->Text.Size;
    pos += v63->Text.Size;
    v18 = CurIndex < v17;
  }
  else
  {
    v18 = CurIndex < (signed int)pArray->Text.Size;
    v19 = *(Scaleform::Render::Text::Paragraph **)&pArray->Text.pText[2 * CurIndex];
    v68 = 0;
    v65 = pArray;
    v66 = CurIndex;
    if ( v18 )
      v66 = CurIndex + 1;
    inserted = Scaleform::Render::Text::StyledText::InsertNewParagraph(
                 this,
                 (Scaleform::Render::Text::Paragraph *)&v65,
                 v19->pFormat.pObject);
    v60 = v19->Text.Size - v10;
    pObject = this->pTextAllocator.pObject;
    v65 = inserted;
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
    v64 = (Scaleform::Render::Text::Paragraph *)(length - v27);
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
    if ( result.CurIndex < (signed int)result.pArray->Data.Size )
      ++result.CurIndex;
    v36 = text->Paragraphs.Data.Size;
    if ( v36 > 0 )
      v68 = 1;
    while ( v68 >= 0 && v68 < v36 && v64 )
    {
      v37 = text->Paragraphs.Data.Data[v68].pPara;
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
      if ( v38 > (unsigned int)v64
        || (Scaleform::Render::Text::Paragraph *)v38 == v64 && !Scaleform::Render::Text::Paragraph::HasNewLine(v37) )
      {
        v61 = v38;
        v41 = v65;
        Scaleform::Render::Text::Paragraph::Copy(v65, this->pTextAllocator.pObject, v37, 0, 0, v61);
        Scaleform::Render::Text::Paragraph::SetFormat(v41, this->pTextAllocator.pObject, v37->pFormat.pObject);
        break;
      }
      Scaleform::Render::Text::StyledText::InsertCopyOfParagraph(this, &result, v37);
      v36 = text->Paragraphs.Data.Size;
      v64 = (Scaleform::Render::Text::Paragraph *)((char *)v64 - v38);
      pos += v38;
      if ( v68 < v36 )
        ++v68;
      if ( result.CurIndex < (signed int)result.pArray->Data.Size )
        ++result.CurIndex;
    }
    v42 = v65;
    v65->StartIndex = pos;
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
    v17 = result.pArray->Data.Size;
    v18 = result.CurIndex < v17;
  }
  if ( v18 )
    ++result.CurIndex;
  v47 = result.pArray;
  v48 = result.CurIndex;
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
