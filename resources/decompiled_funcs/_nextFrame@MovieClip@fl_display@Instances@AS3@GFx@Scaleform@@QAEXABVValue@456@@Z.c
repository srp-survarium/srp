void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::nextFrame(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  int v3; // edi
  int v4; // eax

  pObject = this->pDispObj.pObject;
  v3 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetXScale)(pObject);
  v4 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(pObject);
  if ( v4 < v3 )
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, int))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetXScale)(
      pObject,
      v4 + 1);
  ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, int))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetZScale)(
    pObject,
    1);
}
