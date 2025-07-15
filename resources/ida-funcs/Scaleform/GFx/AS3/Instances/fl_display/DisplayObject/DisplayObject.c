void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::PtrReleaseProxy<328> *v3; // eax
  Scaleform::GFx::AS3::PtrReleaseProxy<328> *v4; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::`vftable';
  this->pLoaderInfo.pObject = 0;
  this->pDispObj.pObject = 0;
  this->pReleaseProxy.pObject = 0;
  t = (Scaleform::GFx::AS3::InstanceTraits::Traits *)328;
  v3 = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this,
                                                      20,
                                                      &t);
  if ( v3 )
  {
    v3->__vftable = (Scaleform::GFx::AS3::PtrReleaseProxy<328>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v3->RefCount = 1;
    v3->__vftable = (Scaleform::GFx::AS3::PtrReleaseProxy<328>_vtbl *)&Scaleform::GFx::AS3::PtrReleaseProxy<328>::`vftable';
    v3->Data.pObject = 0;
    v3->Data2.pObject = 0;
    v3->pNext.pObject = 0;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pReleaseProxy.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pReleaseProxy.pObject = v4;
}
