void __thiscall Scaleform::GFx::AS3::TR::State::exec_nextname(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Value val; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value obj; // [esp+18h] [ebp-10h] BYREF

  p_OpStack = &this->OpStack;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    p_OpStack,
    &obj);
  ValueTraits = Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &obj);
  if ( ValueTraits->TraitsType == Traits_Dictionary && (ValueTraits->Flags & 0x20) == 0 )
  {
    val.value.VS._1.VInt = (int)this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
LABEL_7:
    val.Flags = 72;
    goto LABEL_8;
  }
  if ( (ValueTraits->Flags & 1) == 0 )
  {
    val.value.VS._1.VInt = (int)this->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject;
    goto LABEL_7;
  }
  val.value.VS._1.VInt = (int)this->pTracer->CF->pFile->VMRef->TraitsUint.pObject->ITraits.pObject;
  val.Flags = 8;
LABEL_8:
  val.Bonus.pWeakProxy = 0;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &p_OpStack->Data,
    &val);
  Scaleform::GFx::AS3::Value::~Value(&val);
  Scaleform::GFx::AS3::Value::~Value(&obj);
}
