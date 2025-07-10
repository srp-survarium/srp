void __thiscall Scaleform::Render::Text::ParagraphFormat::ClearTabStops(Scaleform::Render::Text::ParagraphFormat *this)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
  this->PresentMask &= ~0x40u;
  this->pTabStops = 0;
}
