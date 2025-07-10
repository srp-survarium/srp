void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::framesLoadedGet(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        int *result)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx

  pObject = this->pDispObj.pObject;
  if ( pObject )
    *result = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetXScale)(pObject);
  else
    *result = 1;
}
