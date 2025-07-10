void __thiscall Scaleform::Render::Text::Paragraph::SetFormat(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        const Scaleform::Render::Text::ParagraphFormat *fmt)
{
  Scaleform::Render::Text::ParagraphFormat *pObject; // ecx
  const Scaleform::Render::Text::ParagraphFormat *v5; // eax
  Scaleform::Render::Text::ParagraphFormat *ParagraphFormat; // esi
  Scaleform::Render::Text::ParagraphFormat *v7; // edi
  bool v8; // zf
  Scaleform::Render::Text::ParagraphFormat result; // [esp+Ch] [ebp-14h] BYREF

  pObject = this->pFormat.pObject;
  if ( pObject )
  {
    v5 = Scaleform::Render::Text::ParagraphFormat::Merge(pObject, &result, fmt);
    ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(pallocator, v5);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&result);
  }
  else
  {
    ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(pallocator, fmt);
  }
  if ( ParagraphFormat )
    ++ParagraphFormat->RefCount;
  v7 = this->pFormat.pObject;
  if ( v7 )
  {
    v8 = v7->RefCount-- == 1;
    if ( v8 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(v7);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
  }
  this->pFormat.pObject = ParagraphFormat;
  ++this->ModCounter;
  if ( ParagraphFormat )
  {
    v8 = ParagraphFormat->RefCount-- == 1;
    if ( v8 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(ParagraphFormat);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ParagraphFormat);
    }
  }
}
