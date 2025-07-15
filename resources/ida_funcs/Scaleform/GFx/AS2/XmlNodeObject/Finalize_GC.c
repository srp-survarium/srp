void __thiscall Scaleform::GFx::AS2::XmlNodeObject::Finalize_GC(Scaleform::GFx::AS2::XmlNodeObject *this)
{
  Scaleform::GFx::XML::Node *pRealNode; // eax
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // eax
  Scaleform::GFx::XML::RootNode *pObject; // ecx

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
