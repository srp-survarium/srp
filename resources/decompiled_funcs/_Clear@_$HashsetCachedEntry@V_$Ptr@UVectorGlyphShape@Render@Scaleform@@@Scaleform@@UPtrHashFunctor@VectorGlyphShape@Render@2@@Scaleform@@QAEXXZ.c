void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>::Clear(
        Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> *this)
{
  Scaleform::Render::VectorGlyphShape *pObject; // eax

  pObject = this->Value.pObject;
  if ( pObject )
    pObject->Release(&pObject->Scaleform::Render::MeshProvider);
  this->NextInChain = -2;
}
