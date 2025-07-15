Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::`scalar deleting destructor'(
        Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *this,
        char a2)
{
  Scaleform::GFx::AS3::VMAbcFile *pObject; // ecx
  unsigned int RefCount; // eax

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
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
