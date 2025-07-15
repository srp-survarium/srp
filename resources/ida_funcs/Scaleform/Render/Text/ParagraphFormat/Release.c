void __thiscall Scaleform::Render::Text::ParagraphFormat::Release(Scaleform::Render::Text::ParagraphFormat *this)
{
  if ( this->RefCount-- == 1 )
  {
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(this);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}
