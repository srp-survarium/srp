void __thiscall Scaleform::Render::Text::Paragraph::~Paragraph(Scaleform::Render::Text::Paragraph *this)
{
  Scaleform::Render::Text::ParagraphFormat *pObject; // edi

  Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
    this->FormatInfo.Ranges.Data.Data,
    this->FormatInfo.Ranges.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FormatInfo.Ranges.Data.Data);
  pObject = this->pFormat.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
}
