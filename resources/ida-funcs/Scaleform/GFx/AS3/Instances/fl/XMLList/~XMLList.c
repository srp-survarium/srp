void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::~XMLList(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this)
{
  Scaleform::GFx::ASStringNode *TargetProperty; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // ecx
  unsigned int v7; // eax

  TargetProperty = this->TargetProperty;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLList_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLList::`vftable';
  if ( TargetProperty )
  {
    if ( TargetProperty->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(TargetProperty);
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)this->List.Data.Data,
    this->List.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->List.Data.Data);
  pObject = this->TargetNamespace.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->TargetNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  v6 = this->TargetObject.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->TargetObject.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v6 - 1);
      Scaleform::GFx::AS3::Instance::~Instance(this);
      return;
    }
    v7 = v6->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v7) != 0 )
    {
      v6->RefCount = v7 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
    }
  }
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
