void __thiscall Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(
        Scaleform::Render::Text::ParagraphFormat *this)
{
  unsigned __int16 PresentMask; // dx
  unsigned int *pTabStops; // eax

  this->Leading = 0;
  PresentMask = this->PresentMask;
  this->BlockIndent = 0;
  this->LeftMargin = 0;
  pTabStops = this->pTabStops;
  this->PresentMask = PresentMask & 0x7940 | 1;
  this->Indent = 0;
  this->RightMargin = 0;
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pTabStops);
  this->PresentMask &= ~0x40u;
  this->pTabStops = 0;
}
