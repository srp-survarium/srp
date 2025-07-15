void __thiscall Scaleform::GFx::AS3::InstanceTraits::RTraits::~RTraits(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  unsigned int RefCount; // eax

  pNode = this->Name.pNode;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::RTraits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable';
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::RTraits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable';
  pObject = this->Ns.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
      Scaleform::GFx::AS3::Traits::~Traits(this);
      return;
    }
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
}
