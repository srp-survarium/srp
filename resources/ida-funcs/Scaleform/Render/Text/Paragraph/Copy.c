void __thiscall Scaleform::Render::Text::Paragraph::Copy(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        const Scaleform::Render::Text::Paragraph *psrcPara,
        int startSrcIndex,
        unsigned int startDestIndex,
        unsigned int length)
{
  unsigned int v6; // edi
  Scaleform::Render::Text::Paragraph *v7; // ebx
  int v8; // ebp
  const Scaleform::Render::Text::Paragraph *v9; // esi
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v10; // eax
  int Index; // ecx
  unsigned int v12; // esi
  int v13; // ebx
  const Scaleform::Render::Text::TextFormat *pObject; // eax
  const Scaleform::Render::Text::Paragraph *TextFormat; // edi
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v17; // edx
  unsigned int Size; // ecx
  unsigned int v19; // eax
  wchar_t *pText; // ecx
  unsigned int v21; // edx
  wchar_t *v22; // edx
  int v23; // edi
  unsigned int v24; // edx
  wchar_t *v25; // eax
  Scaleform::Render::Text::TextFormat *v26; // eax
  Scaleform::Render::Text::TextFormat *v27; // esi
  Scaleform::Render::Text::Paragraph::FormatRunIterator v29; // [esp+Ch] [ebp-24h] BYREF

  v6 = length;
  v7 = this;
  if ( length )
  {
    v8 = startSrcIndex;
    v9 = psrcPara;
    Scaleform::Render::Text::Paragraph::InsertString(
      this,
      pallocator,
      (const __m128i *)&psrcPara->Text.pText[startSrcIndex],
      startDestIndex,
      length,
      0);
    Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(&v29, &v9->FormatInfo, &v9->Text, v8);
    length = v6;
    if ( v29.CurTextIndex < v29.pText->Size )
    {
      while ( 1 )
      {
        if ( !v6 )
          goto LABEL_24;
        v10 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29);
        Index = v10->PlaceHolder.Index;
        v12 = v10->PlaceHolder.Length;
        if ( Index >= v8 )
        {
          v13 = Index - v8;
        }
        else
        {
          v13 = 0;
          v12 = Index + v12 - v8;
        }
        if ( v12 >= v6 )
          v12 = v6;
        pObject = v10->PlaceHolder.pFormat.pObject;
        if ( pObject )
        {
          TextFormat = (const Scaleform::Render::Text::Paragraph *)Scaleform::Render::Text::Allocator::AllocateTextFormat(
                                                                     pallocator,
                                                                     pObject);
          psrcPara = TextFormat;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            &this->FormatInfo,
            startDestIndex + v13,
            v12,
            (const Scaleform::Ptr<Scaleform::Render::Text::TextFormat> *)&psrcPara);
          if ( TextFormat )
          {
            if ( TextFormat->Text.pText-- == (wchar_t *)1 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)TextFormat);
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)TextFormat);
            }
          }
        }
        length -= v12;
        if ( v29.FormatIterator.Index < 0 || v29.FormatIterator.Index >= v29.FormatIterator.pArray->Ranges.Data.Size )
          break;
        v17 = &v29.FormatIterator.pArray->Ranges.Data.Data[v29.FormatIterator.Index];
        if ( v29.CurTextIndex < v17->Index )
        {
          Size = v29.FormatIterator.pArray->Ranges.Data.Data[v29.FormatIterator.Index].Index;
LABEL_22:
          v29.CurTextIndex = Size;
          goto LABEL_23;
        }
        Size = v17->Length + v29.CurTextIndex;
        v29.CurTextIndex = Size;
        if ( v29.FormatIterator.Index < (signed int)v29.FormatIterator.pArray->Ranges.Data.Size )
          ++v29.FormatIterator.Index;
LABEL_23:
        v7 = this;
        if ( Size >= v29.pText->Size )
          goto LABEL_24;
        v6 = length;
      }
      Size = v29.pText->Size;
      goto LABEL_22;
    }
LABEL_24:
    v19 = v7->Text.Size;
    if ( v19 )
    {
      pText = v7->Text.pText;
      v21 = v19 - 1;
      if ( v7->Text.pText && v21 < v19 )
        v22 = &pText[v21];
      else
        v22 = 0;
      if ( !*v22 )
      {
        v23 = v7->Text.Size;
        v24 = v19 - 1;
        if ( pText && v24 < v19 )
          v25 = &pText[v24];
        else
          v25 = 0;
        if ( !*v25 )
          --v23;
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
          &v7->FormatInfo,
          v23,
          1u);
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
          &v7->FormatInfo,
          v23 + 1,
          1u);
      }
    }
    v26 = v29.PlaceHolder.pFormat.pObject;
    ++v7->ModCounter;
    if ( v26 )
    {
      --v26->RefCount;
      v27 = v26;
      if ( !v26->RefCount )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v26);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v27);
      }
    }
  }
}
