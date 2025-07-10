void __thiscall Scaleform::GFx::AS3::VM::exec_getabsslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_ind)
{
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::VM *Flags; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // edx
  Scaleform::GFx::AS3::Value *VInt; // eax
  Scaleform::GFx::AS3::Traits *pWeakProxy; // ecx
  Scaleform::GFx::AS3::AbsoluteIndex v8; // [esp-8h] [ebp-20h]
  Scaleform::GFx::AS3::ReadObjectRef args; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::Value::V2U v10; // [esp+14h] [ebp-4h]

  pCurrent = this->OpStack.pCurrent;
  args.VMRef = this;
  args.OpStack = &this->OpStack;
  args.ArgObject = pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, pCurrent);
  if ( !this->HandleException )
  {
    Flags = (Scaleform::GFx::AS3::VM *)pCurrent->Flags;
    v5.VObj = (Scaleform::GFx::AS3::Object *)pCurrent->value.VS._2;
    args.OpStack = (Scaleform::GFx::AS3::ValueStack *)pCurrent->Bonus.pWeakProxy;
    args.VMRef = Flags;
    VInt = (Scaleform::GFx::AS3::Value *)pCurrent->value.VS._1.VInt;
    v8.Index = slot_ind - 1;
    pCurrent->Flags = 0;
    pWeakProxy = (Scaleform::GFx::AS3::Traits *)VInt[1].Bonus.pWeakProxy;
    args.ArgObject = VInt;
    v10.VObj = v5.VObj;
    Scaleform::GFx::AS3::Traits::GetSlotValueUnsafe(
      pWeakProxy,
      (Scaleform::GFx::AS3::CheckResult *)&slot_ind,
      pCurrent,
      v8,
      (Scaleform::GFx::ASStringNode *)VInt);
    Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&args);
  }
}
