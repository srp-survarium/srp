void __userpurge Scaleform::Render::Text::StyledText::Remove(
        Scaleform::Render::Text::StyledText *this@<ecx>,
        Scaleform::Render::Text::Paragraph *a2@<edi>,
        unsigned int startPos,
        unsigned int length)
{
  Scaleform::Render::Text::StyledText *v4; // ebx
  unsigned int v5; // edi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *pArray; // esi
  int CurIndex; // ebp
  Scaleform::Render::Text::Paragraph *pPara; // ecx
  unsigned int Size; // ebx
  Scaleform::Render::Text::Paragraph *v10; // edi
  unsigned int v11; // ebx
  Scaleform::Render::Text::Paragraph *v12; // edi
  Scaleform::Render::Text::ParagraphFormat *pObject; // ebx
  Scaleform::Render::Text::Paragraph *v15; // edi
  signed int v16; // ecx
  signed int v17; // eax
  Scaleform::Render::Text::Paragraph *appended; // eax
  unsigned int v19; // ecx
  unsigned int v20; // esi
  wchar_t *v21; // ecx
  wchar_t v22; // cx
  unsigned int v23; // [esp+8h] [ebp-2Ch]
  unsigned int v26; // [esp+20h] [ebp-14h]
  Scaleform::Render::Text::Paragraph *v27; // [esp+24h] [ebp-10h]
  unsigned int pindexInParagraph; // [esp+28h] [ebp-Ch] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+2Ch] [ebp-8h] BYREF
  bool index; // [esp+38h] [ebp+4h]

  v4 = this;
  if ( length == -1 )
    length = Scaleform::Render::Text::StyledText::GetLength(this);
  v5 = length;
  v4->OnTextRemoving(v4, startPos, length);
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(v4, &result, startPos, &pindexInParagraph);
  pArray = result.pArray;
  CurIndex = result.CurIndex;
  v27 = 0;
  v26 = length;
  index = 0;
  if ( result.pArray )
  {
    if ( result.CurIndex >= 0 && result.CurIndex < (signed int)result.pArray->Data.Size )
    {
      pPara = result.pArray->Data.Data[result.CurIndex].pPara;
      Size = pPara->Text.Size;
      if ( length >= Size - pindexInParagraph )
        v5 = pPara->Text.Size - pindexInParagraph;
      if ( v5 > Size )
        goto LABEL_11;
      index = v5 + pindexInParagraph >= Size;
      v27 = result.pArray->Data.Data[result.CurIndex].pPara;
      Scaleform::Render::Text::Paragraph::Remove(pPara, pindexInParagraph, v5 + pindexInParagraph);
      v4 = this;
      v26 = length - v5;
      if ( CurIndex < (signed int)pArray->Data.Size )
        result.CurIndex = ++CurIndex;
    }
    while ( pArray )
    {
      if ( CurIndex < 0 || CurIndex >= (signed int)pArray->Data.Size )
        goto LABEL_31;
      v10 = pArray->Data.Data[CurIndex].pPara;
      v11 = v10->Text.Size;
      pindexInParagraph = v11;
      if ( v26 < v11 )
      {
        if ( v27 && index )
        {
          v23 = v11 - v26;
          v4 = this;
          Scaleform::Render::Text::Paragraph::Copy(v27, this->pTextAllocator.pObject, v10, v26, v27->Text.Size, v23);
          Scaleform::Render::Text::StyledText::RemoveParagraph(this, &result, v10);
          index = 0;
        }
        else
        {
LABEL_30:
          v4 = this;
        }
LABEL_31:
        if ( CurIndex >= 0 && CurIndex < (signed int)pArray->Data.Size )
        {
          v15 = pArray->Data.Data[CurIndex].pPara;
          if ( v15->Text.Size )
          {
            if ( v27 && index )
            {
              Scaleform::Render::Text::Paragraph::Copy(
                v27,
                v4->pTextAllocator.pObject,
                v15,
                0,
                v27->Text.Size,
                v15->Text.Size);
              Scaleform::Render::Text::StyledText::RemoveParagraph(v4, &result, v15);
            }
          }
          else
          {
            Scaleform::Render::Text::StyledText::RemoveParagraph(v4, &result, pArray->Data.Data[CurIndex].pPara);
          }
        }
        while ( CurIndex >= 0 && CurIndex < (signed int)pArray->Data.Size )
        {
          pArray->Data.Data[CurIndex].pPara->StartIndex -= length;
          if ( CurIndex < (signed int)pArray->Data.Size )
            ++CurIndex;
        }
        break;
      }
      this->OnParagraphRemoving(this, v10);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10->Text.pText);
      v10->Text.pText = 0;
      v10->Text.Allocated = 0;
      v10->Text.Size = 0;
      if ( CurIndex < (signed int)pArray->Data.Size )
      {
        if ( pArray->Data.Size == 1 )
        {
          Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper>::DestructArray(
            v10,
            pArray->Data.Data,
            1u);
          if ( (pArray->Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
          {
            if ( pArray->Data.Data )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pArray->Data.Data);
              pArray->Data.Data = 0;
            }
            pArray->Data.Policy.Capacity = 0;
          }
          pArray->Data.Size = 0;
        }
        else
        {
          v12 = pArray->Data.Data[CurIndex].pPara;
          if ( v12 )
          {
            Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
              v12->FormatInfo.Ranges.Data.Data,
              v12->FormatInfo.Ranges.Data.Size);
            ((void (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *, Scaleform::Render::Text::Paragraph *))Scaleform::Memory::pGlobalHeap->Free)(
              Scaleform::Memory::pGlobalHeap,
              v12->FormatInfo.Ranges.Data.Data,
              a2);
            pObject = v12->pFormat.pObject;
            if ( pObject )
            {
              if ( pObject->RefCount-- == 1 )
              {
                Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
              }
            }
            a2 = v12;
            ((void (__thiscall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->Free)(Scaleform::Memory::pGlobalHeap);
            v11 = pindexInParagraph;
          }
          memmove(
            (int)&pArray->Data.Data[CurIndex],
            (const __m128i *)&pArray->Data.Data[CurIndex + 1],
            4 * (pArray->Data.Size - CurIndex) - 4);
          --pArray->Data.Size;
        }
      }
      v26 -= v11;
      if ( !v26 )
        goto LABEL_30;
LABEL_11:
      v4 = this;
    }
  }
  v16 = v4->Paragraphs.Data.Size;
  v17 = v16 - 1;
  if ( v16 - 1 >= 0 && v17 < v16 && (appended = v4->Paragraphs.Data.Data[v17].pPara) != 0
    || (appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(v4, 0)) != 0 )
  {
    v19 = appended->Text.Size;
    if ( !v19
      || ((v20 = v19 - 1, !appended->Text.pText) || v20 >= v19 ? (v21 = 0) : (v21 = &appended->Text.pText[v20]),
          (v22 = *v21, v22 != 13) && v22 != 10) )
    {
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        appended,
        v4->pTextAllocator.pObject,
        v4->pDefaultTextFormat.pObject);
    }
  }
}
