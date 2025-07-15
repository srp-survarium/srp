void __thiscall Scaleform::Render::Text::ParagraphFormat::AllocTabStops(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int num)
{
  unsigned int *v3; // eax

  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
  this->pTabStops = 0;
  v3 = (unsigned int *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 4 * num + 4, 0);
  this->pTabStops = v3;
  *v3 = num;
}
