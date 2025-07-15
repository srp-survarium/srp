void __thiscall Scaleform::GFx::AS3::VM::exec_getslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::Value::V2U v4; // edx
  Scaleform::GFx::AS3::ValueStack *pWeakProxy; // ecx
  Scaleform::GFx::AS3::Object *ArgObject; // ecx
  Scaleform::GFx::AS3::SlotIndex v7; // [esp-8h] [ebp-20h]
  Scaleform::GFx::AS3::ReadObjectRef args; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::Value::V2U v9; // [esp+14h] [ebp-4h]

  pCurrent = this->OpStack.pCurrent;
  args.VMRef = this;
  args.OpStack = &this->OpStack;
  args.ArgObject = pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, pCurrent);
  if ( !this->HandleException )
  {
    v4.VObj = (Scaleform::GFx::AS3::Object *)pCurrent->value.VS._2;
    pWeakProxy = (Scaleform::GFx::AS3::ValueStack *)pCurrent->Bonus.pWeakProxy;
    args.VMRef = (Scaleform::GFx::AS3::VM *)pCurrent->Flags;
    v9.VObj = v4.VObj;
    args.OpStack = pWeakProxy;
    v7.Index = slot_index;
    args.ArgObject = (Scaleform::GFx::AS3::Value *)pCurrent->value.VS._1.VInt;
    ArgObject = (Scaleform::GFx::AS3::Object *)args.ArgObject;
    pCurrent->Flags = 0;
    Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
      ArgObject,
      (Scaleform::GFx::AS3::CheckResult *)&slot_index,
      v7,
      pCurrent);
    Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&args);
  }
}
