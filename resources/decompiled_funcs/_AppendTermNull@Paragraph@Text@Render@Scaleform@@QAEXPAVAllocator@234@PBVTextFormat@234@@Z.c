void __thiscall Scaleform::Render::Text::Paragraph::AppendTermNull(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        const Scaleform::Render::Text::TextFormat *pdefTextFmt)
{
  unsigned int Size; // eax
  unsigned int v5; // edx
  wchar_t *v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // edx
  wchar_t *v9; // eax
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *p_FormatInfo; // ebx
  wchar_t *Position; // ebp
  Scaleform::Render::Text::Allocator *TextFormat; // esi

  Size = this->Text.Size;
  if ( !Size || ((v5 = Size - 1, !this->Text.pText) || v5 >= Size ? (v6 = 0) : (v6 = &this->Text.pText[v5]), *v6) )
  {
    v7 = Size;
    if ( Size )
    {
      v8 = Size - 1;
      if ( this->Text.pText && v8 < Size )
        v9 = &this->Text.pText[v8];
      else
        v9 = 0;
      if ( !*v9 )
        --v7;
    }
    p_FormatInfo = &this->FormatInfo;
    Position = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(&this->Text, pallocator, v7, 1u);
    Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
      &this->FormatInfo,
      v7,
      1u);
    ++this->ModCounter;
    if ( Position )
    {
      *Position = 0;
      if ( !this->FormatInfo.Ranges.Data.Size )
      {
        if ( pdefTextFmt )
        {
          TextFormat = (Scaleform::Render::Text::Allocator *)Scaleform::Render::Text::Allocator::AllocateTextFormat(
                                                               pallocator,
                                                               pdefTextFmt);
          pallocator = TextFormat;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            p_FormatInfo,
            v7,
            1u,
            (const Scaleform::Ptr<Scaleform::Render::Text::TextFormat> *)&pallocator);
          if ( TextFormat )
          {
            if ( TextFormat->__vftable-- == (Scaleform::Render::Text::Allocator_vtbl *)1 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)TextFormat);
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, TextFormat);
            }
          }
        }
      }
    }
  }
}
