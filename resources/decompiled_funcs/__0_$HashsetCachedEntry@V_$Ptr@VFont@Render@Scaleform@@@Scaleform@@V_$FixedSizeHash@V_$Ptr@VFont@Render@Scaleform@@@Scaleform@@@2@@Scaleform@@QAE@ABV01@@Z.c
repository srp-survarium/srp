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
