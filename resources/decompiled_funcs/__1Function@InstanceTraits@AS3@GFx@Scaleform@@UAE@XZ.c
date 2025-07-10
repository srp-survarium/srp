void __thiscall Scaleform::GFx::AS3::InstanceTraits::Function::~Function(
        Scaleform::GFx::AS3::InstanceTraits::Function *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VMAbcFile *v4; // ecx
  unsigned int v5; // eax

  pObject = this->GOS.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->GOS.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)((char *)pObject - 1);
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
  v4 = this->File.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->File.pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)v4 - 1);
      Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(this);
      return;
    }
    v5 = v4->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(this);
}
