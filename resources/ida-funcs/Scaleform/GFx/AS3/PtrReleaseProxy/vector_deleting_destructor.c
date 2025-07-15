Scaleform::GFx::AS3::PtrReleaseProxy<328> *__thiscall Scaleform::GFx::AS3::PtrReleaseProxy<328>::`vector deleting destructor'(
        Scaleform::GFx::AS3::PtrReleaseProxy<328> *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *v4; // ecx
  unsigned int RefCount; // eax
  Scaleform::RefCountNTSImpl *v6; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pNext.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->Data2.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->Data2.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v4 - 1);
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
  v6 = this->Data.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
