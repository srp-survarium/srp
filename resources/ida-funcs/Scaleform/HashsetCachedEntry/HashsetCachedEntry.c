void __thiscall Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
        Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        const Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *e)
{
  Scaleform::GFx::AS3::Value *p_Value; // ecx
  unsigned int Flags; // eax

  *this = *e;
  p_Value = &e->Value;
  Flags = e->Value.Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(p_Value);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Value);
  }
}


void __thiscall Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
        Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        Scaleform::GFx::AS3::Value *key,
        int next)
{
  this->NextInChain = next;
  this->Value = *key;
  if ( (key->Flags & 0x1F) > 9 )
  {
    if ( (key->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(key);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(key);
  }
}


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


void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>>::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>>(
        Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> *this,
        const Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> *e)
{
  Scaleform::GFx::Resource *pObject; // ecx

  this->NextInChain = e->NextInChain;
  this->Value.First = e->Value.First;
  pObject = (Scaleform::GFx::Resource *)e->Value.Second.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  this->Value.Second.pObject = e->Value.Second.pObject;
}


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
