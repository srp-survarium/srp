void __thiscall Scaleform::Render::Text::ParagraphFormat::SetTabStops(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int *psrcTabStops)
{
  if ( psrcTabStops && *psrcTabStops )
  {
    Scaleform::Render::Text::ParagraphFormat::CopyTabStops(this, psrcTabStops);
    this->PresentMask |= 0x40u;
  }
  else
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
    this->PresentMask &= ~0x40u;
    this->pTabStops = 0;
  }
}
