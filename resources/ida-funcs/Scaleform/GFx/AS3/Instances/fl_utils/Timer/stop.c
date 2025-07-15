void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Timer::stop(
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::IntervalTimer *pObject; // ecx
  void (__thiscall *v4)(Scaleform::GFx::AS3::VM *); // edi
  int v5; // eax
  Scaleform::RefCountVImpl *v6; // ecx

  pObject = this->pCoreTimer.pObject;
  if ( pObject && pObject->IsActive(pObject) )
  {
    v4 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
    v5 = this->pCoreTimer.pObject->GetId(this->pCoreTimer.pObject);
    Scaleform::GFx::MovieImpl::ClearIntervalTimer((Scaleform::GFx::MovieImpl *)v4, v5);
  }
  v6 = (Scaleform::RefCountVImpl *)this->pCoreTimer.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pCoreTimer.pObject = 0;
}
