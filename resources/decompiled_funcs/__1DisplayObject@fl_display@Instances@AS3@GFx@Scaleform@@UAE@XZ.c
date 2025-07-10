void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::DisplayObject *v3; // eax
  Scaleform::Ptr<Scaleform::RefCountNTSImpl> *p_Data; // edi
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::GFx::DisplayObject *v6; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v7; // ecx
  unsigned int RefCount; // eax

  pObject = this->pDispObj.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::`vftable';
  if ( pObject )
  {
    Scaleform::GFx::AS3::AvmDisplayObj::ReleaseAS3Obj((Scaleform::GFx::AS3::AvmDisplayObj *)(&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                           + pObject->AvmObjOffset));
    if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(((int)this->pTraits.pObject & 0xFFFFFFFE) + 64) + 16) + 76) & 4) != 0 )
    {
      v3 = this->pDispObj.pObject;
      p_Data = &this->pReleaseProxy.pObject->Data;
      if ( v3 )
        ++v3->RefCount;
      if ( p_Data->pObject )
        Scaleform::RefCountNTSImpl::Release(p_Data->pObject);
      p_Data->pObject = this->pDispObj.pObject;
      Scaleform::GFx::AS3::RefCountCollector<328>::AddDelayedReleaseProxy(
        *(Scaleform::GFx::AS3::RefCountCollector<328> **)(*(_DWORD *)(((int)this->pTraits.pObject & 0xFFFFFFFE) + 64)
                                                        + 16),
        (Scaleform::GFx::Resource *)this->pReleaseProxy.pObject);
    }
  }
  v5 = (Scaleform::RefCountVImpl *)this->pReleaseProxy.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = this->pDispObj.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  v7 = this->pLoaderInfo.pObject;
  if ( v7 )
  {
    if ( ((unsigned __int8)v7 & 1) != 0 )
    {
      this->pLoaderInfo.pObject = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)((char *)v7 - 1);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
      return;
    }
    RefCount = v7->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      v7->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
}
