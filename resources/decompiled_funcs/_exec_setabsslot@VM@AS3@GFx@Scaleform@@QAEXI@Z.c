void __thiscall Scaleform::GFx::AS3::VM::exec_setabsslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_ind)
{
  Scaleform::GFx::AS3::ReadValueObject args; // [esp+0h] [ebp-28h] BYREF

  args.VMRef = this;
  args.OpStack = &this->OpStack;
  args.ArgValue = *this->OpStack.pCurrent--;
  args.ArgObject = *(const Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
    Scaleform::GFx::AS3::Traits::SetSlotValue(
      *(Scaleform::GFx::AS3::Traits **)(args.ArgObject.value.VS._1.VInt + 20),
      (Scaleform::GFx::AS3::CheckResult *)&slot_ind,
      (Scaleform::GFx::AS3::AbsoluteIndex)(slot_ind - 1),
      &args.ArgValue,
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)args.ArgObject.value.VS._1.VInt);
  Scaleform::GFx::AS3::ReadValueObject::~ReadValueObject(&args);
}
