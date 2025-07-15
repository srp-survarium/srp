void __thiscall Scaleform::Render::Text::Paragraph::InsertString(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        const __m128i *pstr,
        unsigned int pos,
        unsigned int length,
        Scaleform::Render::Text::TextFormat *pnewFmt)
{
  unsigned int i; // edi
  int v8; // ebp
  wchar_t *Position; // esi
  wchar_t *v10; // esi

  i = length;
  if ( length )
  {
    if ( length == -1 )
    {
      for ( i = 0; pstr->m128i_i16[i]; ++i )
        ;
    }
    if ( i )
    {
      v8 = pos;
      Position = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(&this->Text, pallocator, pos, i);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &this->FormatInfo,
        v8,
        i);
      ++this->ModCounter;
      if ( Position )
      {
        memcpy((int)Position, pstr, 2 * i);
        v10 = (wchar_t *)pnewFmt;
        if ( pnewFmt )
        {
          ++pnewFmt->RefCount;
          pstr = (const __m128i *)v10;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            &this->FormatInfo,
            v8,
            i,
            (const Scaleform::Ptr<Scaleform::Render::Text::TextFormat> *)&pstr);
          if ( (*(_DWORD *)v10)-- == 1 )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)v10);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
          }
        }
        Scaleform::Render::Text::Paragraph::SetTermNullFormat(this);
        ++this->ModCounter;
      }
    }
  }
}
