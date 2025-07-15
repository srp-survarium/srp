void __thiscall Scaleform::Render::Text::DocView::OnDocumentParagraphRemoving(
        Scaleform::Render::Text::DocView *this,
        const Scaleform::Render::Text::Paragraph *para)
{
  unsigned int v2; // esi
  Scaleform::Render::Text::LineBuffer::Line *v3; // edx
  unsigned int ParagraphId; // ebx
  bool found; // [esp+13h] [ebp-1h]

  v2 = 0;
  found = 0;
  while ( this != (Scaleform::Render::Text::DocView *)-48
       && v2 < this->mLineBuffer.Lines.Data.Size
       && (v2 & 0x80000000) == 0 )
  {
    v3 = this->mLineBuffer.Lines.Data.Data[v2];
    if ( (v3->MemSize & 0x80000000) == 0 )
      ParagraphId = v3->Data32.ParagraphId;
    else
      ParagraphId = v3->Data32.GlyphsCount;
    if ( para->UniqueId == ParagraphId )
    {
      found = 1;
      if ( (v3->MemSize & 0x80000000) == 0 )
        v3->Data32.TextPos = -1;
      else
        v3->Data32.TextPos |= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
    }
    else if ( found )
    {
      break;
    }
    if ( v2 < this->mLineBuffer.Lines.Data.Size )
      ++v2;
  }
  this->RTFlags |= 1u;
}
