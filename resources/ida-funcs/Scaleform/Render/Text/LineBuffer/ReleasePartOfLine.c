void __cdecl Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
        Scaleform::Render::Text::LineBuffer::GlyphEntry *pglyphs,
        unsigned int n,
        Scaleform::Render::Text::LineBuffer::FormatDataEntry *pnextFormatData)
{
  unsigned __int16 *p_Flags; // esi
  unsigned int v5; // ebx

  if ( n )
  {
    p_Flags = &pglyphs->Flags;
    v5 = n;
    do
    {
      if ( (*p_Flags & 0x4000) != 0 )
      {
        if ( (*p_Flags & 0x2000) != 0 )
        {
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pnextFormatData->pFont);
          ++pnextFormatData;
        }
        if ( (*p_Flags & 0x1000) != 0 )
          ++pnextFormatData;
        if ( (*p_Flags & 0x800) != 0 )
        {
          Scaleform::RefCountNTSImpl::Release(pnextFormatData->pImage);
          ++pnextFormatData;
        }
      }
      p_Flags += 4;
      --v5;
    }
    while ( v5 );
  }
}
