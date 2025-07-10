void __thiscall Scaleform::Render::Text::TextFormat::Release(Scaleform::Render::Text::TextFormat *this)
{
  if ( this->RefCount-- == 1 )
  {
    Scaleform::Render::Text::TextFormat::~TextFormat(this);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}
