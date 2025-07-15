void __thiscall Scaleform::GFx::AS3::SlotInfo::~SlotInfo(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::ASStringNode *pObject; // ecx
  Scaleform::GFx::AS3::VMAbcFile *v4; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // ecx
  unsigned int v7; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // ecx
  unsigned int v9; // eax

  pObject = this->Name.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
  }
  v4 = this->File.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->File.pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)v4 - 1);
    }
    else
    {
      RefCount = v4->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  v6 = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->CTraits.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->CTraits.pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( (v7 & 0x3FFFFF) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
  v8 = this->pNs.pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      this->pNs.pObject = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
  }
}
