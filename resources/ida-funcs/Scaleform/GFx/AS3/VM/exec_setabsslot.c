void __thiscall Scaleform::GFx::AS3::VM::exec_setabsslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_ind)
{
  Scaleform::GFx::AS3::ReadValueObject args; // [esp+0h] [ebp-28h] BYREF

  args.VMRef = this;
  args.OpStack = &this->OpStack;
  args.ArgValue.Flags = this->OpStack.pCurrent->Flags;
  args.ArgValue.Bonus.pWeakProxy = this->OpStack.pCurrent->Bonus.pWeakProxy;
  args.ArgValue.value.VNumber = this->OpStack.pCurrent->value.VNumber;
  --this->OpStack.pCurrent;
  args.ArgObject.Flags = args.OpStack->pCurrent->Flags;
  args.ArgObject.Bonus.pWeakProxy = args.OpStack->pCurrent->Bonus.pWeakProxy;
  args.ArgObject.value.VNumber = args.OpStack->pCurrent->value.VNumber;
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
