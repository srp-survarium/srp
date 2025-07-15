Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::operator=(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *other)
{
  Scaleform::GFx::ASStringNode *pNode; // ebx
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v7; // ecx

  if ( this != other )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Prefix, &other->Prefix);
    pNode = other->Uri.pNode;
    ++pNode->RefCount;
    v4 = this->Uri.pNode;
    if ( v4->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    this->Uri.pNode = pNode;
    *((_DWORD *)this + 5) ^= (*((_DWORD *)this + 5) ^ ((int)(*((_DWORD *)other + 5) << 28) >> 28)) & 0xF;
    pObject = (Scaleform::GFx::Resource *)other->pFactory.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::AddRef(pObject);
    v7 = (Scaleform::RefCountVImpl *)this->pFactory.pObject;
    if ( v7 )
      Scaleform::RefCountImpl::Release(v7);
    this->pFactory.pObject = other->pFactory.pObject;
  }
  return this;
}


BOOL __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::operator==(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *other)
{
  return this->Uri.pNode == other->Uri.pNode && ((*((_BYTE *)this + 20) ^ *((_BYTE *)other + 20)) & 0xF) == 0;
}
