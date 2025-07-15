void __thiscall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS2::IntervalTimer *this,
        const Scaleform::GFx::AS2::FunctionRef *function,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::FunctionRef *p_Function; // ecx
  Scaleform::GFx::AS2::FunctionObject *v5; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ebp
  Scaleform::GFx::ASStringNode *RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS2::IntervalTimer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS2::IntervalTimer_vtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable';
  p_Function = &this->Function;
  p_Function->Flags = 0;
  v5 = function->Function;
  p_Function->Function = function->Function;
  if ( v5 )
    v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
  p_Function->pLocalFrame = 0;
  pLocalFrame = function->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_Function, pLocalFrame, function->Flags & 1);
  this->pObject.pObject = 0;
  this->Character.pProxy.pObject = 0;
  RefCount = (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  this->MethodName.pNode = RefCount;
  ++RefCount->RefCount;
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
