void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor>::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor>(
        Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> *this,
        const Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> *e)
{
  Scaleform::Render::Text::TextFormat *pObject; // edx

  this->NextInChain = e->NextInChain;
  this->HashValue = e->HashValue;
  pObject = e->Value.pFormat.pObject;
  if ( pObject )
    ++pObject->RefCount;
  this->Value.pFormat.pObject = e->Value.pFormat.pObject;
}
