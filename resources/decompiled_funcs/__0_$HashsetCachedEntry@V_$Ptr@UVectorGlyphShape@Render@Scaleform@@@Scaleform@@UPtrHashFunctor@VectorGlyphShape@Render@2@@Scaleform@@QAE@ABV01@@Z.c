void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>(
        Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> *this,
        const Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> *e)
{
  Scaleform::Render::VectorGlyphShape *pObject; // eax

  this->NextInChain = e->NextInChain;
  this->HashValue = e->HashValue;
  pObject = e->Value.pObject;
  if ( pObject )
    pObject->AddRef(&pObject->Scaleform::Render::MeshProvider);
  this->Value.pObject = e->Value.pObject;
}
