void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor>::Clear(
        Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> *this)
{
  Scaleform::Render::Text::TextFormat *pObject; // esi

  pObject = this->Value.pFormat.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->NextInChain = -2;
}
