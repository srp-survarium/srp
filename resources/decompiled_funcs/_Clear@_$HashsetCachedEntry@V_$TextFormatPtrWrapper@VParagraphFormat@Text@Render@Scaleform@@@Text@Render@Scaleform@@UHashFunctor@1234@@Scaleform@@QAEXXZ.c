void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor>::Clear(
        Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor> *this)
{
  Scaleform::Render::Text::ParagraphFormat *pObject; // esi

  pObject = this->Value.pFormat.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->NextInChain = -2;
}
