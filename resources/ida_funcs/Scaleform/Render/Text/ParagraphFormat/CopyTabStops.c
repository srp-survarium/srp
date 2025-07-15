void __thiscall Scaleform::Render::Text::ParagraphFormat::CopyTabStops(
        Scaleform::Render::Text::ParagraphFormat *this,
        const unsigned int *psrcTabStops)
{
  unsigned int *pTabStops; // eax
  unsigned int v4; // edi

  pTabStops = this->pTabStops;
  if ( psrcTabStops )
  {
    v4 = *psrcTabStops;
    if ( !pTabStops || *pTabStops != v4 )
      Scaleform::Render::Text::ParagraphFormat::AllocTabStops(this, *psrcTabStops);
    memcpy((unsigned __int8 *)this->pTabStops + 4, (unsigned __int8 *)psrcTabStops + 4, 4 * v4);
  }
  else
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pTabStops);
    this->pTabStops = 0;
  }
}
