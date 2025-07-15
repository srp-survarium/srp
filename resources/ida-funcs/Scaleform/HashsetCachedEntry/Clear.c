void __thiscall Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>::Clear(
        Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->Value.pState.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->NextInChain = -2;
}


void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>::Clear(
        Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> *this)
{
  Scaleform::Render::VectorGlyphShape *pObject; // eax

  pObject = this->Value.pObject;
  if ( pObject )
    pObject->Release(&pObject->Scaleform::Render::MeshProvider);
  this->NextInChain = -2;
}


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
