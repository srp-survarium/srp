Scaleform::GFx::AS3::NamespaceInstanceFactory *__thiscall Scaleform::GFx::AS3::NamespaceInstanceFactory::`scalar deleting destructor'(
        Scaleform::GFx::AS3::NamespaceInstanceFactory *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::NamespaceInstanceFactory_vtbl *)&Scaleform::GFx::AS3::NamespaceInstanceFactory::`vftable';
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::Clear(&this->NamespaceSet);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
