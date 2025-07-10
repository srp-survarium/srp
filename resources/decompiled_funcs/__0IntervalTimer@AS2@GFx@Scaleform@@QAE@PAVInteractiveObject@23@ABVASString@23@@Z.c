void __thiscall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::InteractiveObject *character,
        const Scaleform::GFx::ASString *methodName)
{
  Scaleform::WeakPtrProxy *WeakProxy; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax

  this->__vftable = (Scaleform::GFx::AS2::IntervalTimer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS2::IntervalTimer_vtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable';
  this->Function.Flags = 0;
  this->Function.Function = 0;
  this->Function.pLocalFrame = 0;
  this->pObject.pObject = 0;
  if ( character )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(character);
  else
    WeakProxy = 0;
  this->Character.pProxy.pObject = WeakProxy;
  pNode = methodName->pNode;
  this->MethodName = (Scaleform::GFx::ASString)methodName->pNode;
  ++pNode->RefCount;
  this->Params.Data.Data = 0;
  this->Params.Data.Size = 0;
  this->Params.Data.Policy.Capacity = 0;
  LODWORD(this->Interval) = 0;
  HIDWORD(this->Interval) = 0;
  LODWORD(this->InvokeTime) = 0;
  HIDWORD(this->InvokeTime) = 0;
  this->Id = 0;
  this->LevelHandle.pObject = 0;
  this->Timeout = 0;
  this->Active = 1;
}
