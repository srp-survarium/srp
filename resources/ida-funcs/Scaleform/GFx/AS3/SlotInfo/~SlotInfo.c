void __thiscall Scaleform::GFx::AS3::SlotInfo::~SlotInfo(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::VMAbcFile *pObject; // ecx
  unsigned int RefCount; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // ecx
  unsigned int v7; // eax

  pObject = this->File.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->File.pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)pObject - 1);
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
  v4 = this->CTraits.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->CTraits.pObject = (const Scaleform::GFx::AS3::ClassTraits::Traits *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  v6 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->pNs.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v7) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
}
