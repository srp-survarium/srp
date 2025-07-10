void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::XMLElement(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        const Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  const Scaleform::GFx::ASString *v6; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  v6 = n;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLElement_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  pNode = v6->pNode;
  this->Text = (Scaleform::GFx::ASString)v6->pNode;
  ++pNode->RefCount;
  v8 = p;
  this->Parent.pObject = p;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLElement_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::`vftable';
  this->Ns.pObject = 0;
  this->Namespaces.Data.Data = 0;
  this->Namespaces.Data.Size = 0;
  this->Namespaces.Data.Policy.Capacity = 0;
  this->Attrs.Data.Data = 0;
  this->Attrs.Data.Size = 0;
  this->Attrs.Data.Policy.Capacity = 0;
  this->Children.Data.Data = 0;
  this->Children.Data.Size = 0;
  this->Children.Data.Policy.Capacity = 0;
  pV = Scaleform::GFx::AS3::VM::MakeNamespace(
         this->pTraits.pObject->pVM,
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&t,
         NS_Public,
         &ns->Uri,
         &ns->Prefix)->pV;
  pObject = this->Ns.pObject;
  if ( pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
        this->Ns.pObject = pV;
        return;
      }
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->Ns.pObject = pV;
  }
}
