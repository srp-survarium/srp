void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::~Namespace(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this)
{
  Scaleform::GFx::AS3::NamespaceInstanceFactory *pObject; // eax
  Scaleform::GFx::AS3::Value *p_Prefix; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *key; // [esp+4h] [ebp-4h] BYREF

  pObject = this->pFactory.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::Namespace_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable';
  if ( pObject )
  {
    key = this;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::RemoveAlt<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
      &pObject->NamespaceSet,
      &key);
  }
  p_Prefix = &this->Prefix;
  if ( (this->Prefix.Flags & 0x1F) > 9 )
  {
    if ( (this->Prefix.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_Prefix);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_Prefix);
  }
  v4 = (Scaleform::RefCountVImpl *)this->pFactory.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  pNode = this->Uri.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}
