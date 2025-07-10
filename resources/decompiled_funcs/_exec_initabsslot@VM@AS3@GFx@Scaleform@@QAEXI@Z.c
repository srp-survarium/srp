void __thiscall Scaleform::GFx::AS3::VM::exec_initabsslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_ind)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *VInt; // ecx
  unsigned int v4; // eax
  Scaleform::GFx::AS3::ReadValueObject args; // [esp+4h] [ebp-28h] BYREF

  args.VMRef = this;
  args.OpStack = &this->OpStack;
  args.ArgValue = *this->OpStack.pCurrent--;
  args.ArgObject = *(const Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    VInt = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)args.ArgObject.value.VS._1.VInt;
    v4 = slot_ind;
    ++this->InInitializer;
    Scaleform::GFx::AS3::Traits::SetSlotValue(
      VInt->pTraits.pObject,
      (Scaleform::GFx::AS3::CheckResult *)&slot_ind,
      (Scaleform::GFx::AS3::AbsoluteIndex)(v4 - 1),
      &args.ArgValue,
      VInt);
    --this->InInitializer;
  }
  Scaleform::GFx::AS3::ReadValueObject::~ReadValueObject(&args);
}
