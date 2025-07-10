void __thiscall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::AS2::Object *object,
        const Scaleform::GFx::ASString *methodName)
{
  Scaleform::GFx::ASStringNode *pNode; // edx

  this->__vftable = (Scaleform::GFx::AS2::IntervalTimer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS2::IntervalTimer_vtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable';
  this->Function.Flags = 0;
  this->Function.Function = 0;
  this->Function.pLocalFrame = 0;
  if ( object )
    object->RefCount = (object->RefCount + 1) & 0x8FFFFFFF;
  this->pObject.pObject = object;
  this->Character.pProxy.pObject = 0;
  pNode = methodName->pNode;
  this->MethodName = (Scaleform::GFx::ASString)methodName->pNode;
  ++pNode->RefCount;
  this->Params.Data.Data = 0;
  this->Params.Data.Size = 0;
  this->Params.Data.Policy.Capacity = 0;
  this->Interval = 0;
  this->InvokeTime = 0;
  this->Id = 0;
  this->LevelHandle.pObject = 0;
  this->Active = 1;
  this->Timeout = 0;
}
