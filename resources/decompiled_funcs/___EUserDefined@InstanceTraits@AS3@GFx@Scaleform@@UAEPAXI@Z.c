Scaleform::GFx::AS3::InstanceTraits::UserDefined *__thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::`vector deleting destructor'(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->Script.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Script.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)((char *)pObject - 1);
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
  Scaleform::GFx::AS3::InstanceTraits::RTraits::~RTraits(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
