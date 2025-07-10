void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::~Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v2; // ecx
  Scaleform::GFx::XML::Node *pRealNode; // eax
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // eax
  Scaleform::GFx::XML::RootNode *pObject; // ecx

  v2 = &this->Scaleform::GFx::AS2::GASPrototypeBase;
  this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v2->__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::`vftable';
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v2);
  pRealNode = this->pRealNode;
  this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( pRealNode )
  {
    pShadow = pRealNode->pShadow;
    if ( pShadow )
      pShadow[1].__vftable = 0;
  }
  pObject = this->pRootNode.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::GFx::AS2::Object::~Object(this);
}
