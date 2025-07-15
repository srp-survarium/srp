void __thiscall Scaleform::Render::Text::ParagraphFormat::FreeTabStops(Scaleform::Render::Text::ParagraphFormat *this)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
  this->pTabStops = 0;
}
