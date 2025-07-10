void __thiscall Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::operator=(
        Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> > *this,
        const Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeRef *src)
{
  Scaleform::GFx::Resource **pSecond; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  this->First = *src->pFirst;
  pSecond = (Scaleform::GFx::Resource **)src->pSecond;
  if ( *pSecond )
    Scaleform::RefCountImpl::AddRef(*pSecond);
  pObject = (Scaleform::RefCountVImpl *)this->Second.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Second.pObject = (Scaleform::Render::Text::FontHandle *)*pSecond;
}
