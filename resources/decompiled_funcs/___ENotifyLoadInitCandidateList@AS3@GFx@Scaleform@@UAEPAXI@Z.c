Scaleform::GFx::AS3::NotifyLoadInitCandidateList *__thiscall Scaleform::GFx::AS3::NotifyLoadInitCandidateList::`vector deleting destructor'(
        Scaleform::GFx::AS3::NotifyLoadInitCandidateList *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v4; // ecx
  unsigned int RefCount; // eax

  pObject = (Scaleform::RefCountVImpl *)this->pASIMEManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pLoader.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->pLoader.pObject = (Scaleform::GFx::AS3::Instances::fl_display::Loader *)((char *)v4 - 1);
    }
    else
    {
      RefCount = v4->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
