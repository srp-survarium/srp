void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Finalize_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // eax
  Scaleform::GFx::XML::Node *pRealNode; // eax
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // eax
  Scaleform::GFx::XML::RootNode *pObject; // ecx

  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInterfaces);
  }
  pRealNode = this->pRealNode;
  if ( pRealNode )
  {
    pShadow = pRealNode->pShadow;
    if ( pShadow )
      pShadow[1].__vftable = 0;
  }
  pObject = this->pRootNode.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pRootNode.pObject = 0;
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
