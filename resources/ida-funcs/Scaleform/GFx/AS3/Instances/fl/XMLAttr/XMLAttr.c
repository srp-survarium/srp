void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLAttr::XMLAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        const Scaleform::GFx::ASString *n,
        const Scaleform::GFx::ASString *v,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  const Scaleform::GFx::ASString *v7; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // eax
  const Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  v7 = n;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLAttr_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  pNode = v7->pNode;
  this->Text = (Scaleform::GFx::ASString)v7->pNode;
  ++pNode->RefCount;
  v9 = p;
  this->Parent.pObject = p;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  v10 = v;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLAttr_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLAttr::`vftable';
  this->Ns.pObject = 0;
  v11 = v10->pNode;
  this->Data.pNode = v11;
  ++v11->RefCount;
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
