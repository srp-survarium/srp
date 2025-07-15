void __thiscall Scaleform::Render::Text::Paragraph::InsertString(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        wchar_t *pstr,
        unsigned int pos,
        unsigned int length,
        Scaleform::Render::Text::TextFormat *pnewFmt)
{
  unsigned int v6; // edi
  int v8; // ebp
  unsigned __int8 *Position; // esi
  wchar_t *v10; // esi

  v6 = length;
  if ( length )
  {
    if ( length == -1 )
    {
      v6 = 0;
      if ( *pstr )
      {
        do
          ++v6;
        while ( pstr[v6] );
      }
    }
    if ( v6 )
    {
      v8 = pos;
      Position = (unsigned __int8 *)Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(
                                      &this->Text,
                                      pallocator,
                                      pos,
                                      v6);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &this->FormatInfo,
        v8,
        v6);
      ++this->ModCounter;
      if ( Position )
      {
        memcpy(Position, (unsigned __int8 *)pstr, 2 * v6);
        v10 = (wchar_t *)pnewFmt;
        if ( pnewFmt )
        {
          ++pnewFmt->RefCount;
          pstr = v10;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            &this->FormatInfo,
            v8,
            v6,
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
