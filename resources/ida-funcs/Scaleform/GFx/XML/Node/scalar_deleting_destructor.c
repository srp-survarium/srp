Scaleform::GFx::XML::TextNode *__thiscall Scaleform::GFx::XML::Node::`scalar deleting destructor'(
        Scaleform::GFx::XML::TextNode *this,
        char a2)
{
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // ecx
  Scaleform::GFx::XML::Node *pObject; // ecx
  Scaleform::GFx::XML::ObjectManager *v5; // ecx

  pShadow = this->pShadow;
  this->__vftable = (Scaleform::GFx::XML::TextNode_vtbl *)&Scaleform::GFx::XML::Node::`vftable';
  if ( pShadow )
    ((void (__thiscall *)(Scaleform::GFx::XML::ShadowRefBase *, int))pShadow->~Scaleform::GFx::XML::ShadowRefBase)(
      pShadow,
      1);
  pObject = this->NextSibling.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::GFx::XML::DOMString::~DOMString(&this->Value);
  v5 = this->MemoryManager.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
