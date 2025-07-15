void __thiscall Scaleform::GFx::AS3::VM::exec_setslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *VInt; // edi
  int v4; // ecx
  Scaleform::GFx::AS3::VM *v5; // ebx
  signed int v6; // eax
  unsigned int v7; // esi
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // eax
  Scaleform::GFx::AS3::ReadValueObject args; // [esp+4h] [ebp-28h] BYREF

  args.VMRef = this;
  args.OpStack = &this->OpStack;
  args.ArgValue = *this->OpStack.pCurrent--;
  args.ArgObject = *(const Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( this->HandleException )
  {
    Scaleform::GFx::AS3::ReadValueObject::~ReadValueObject(&args);
  }
  else
  {
    VInt = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)args.ArgObject.value.VS._1.VInt;
    v4 = *(_DWORD *)(args.ArgObject.value.VS._1.VInt + 20);
    v5 = *(Scaleform::GFx::AS3::VM **)(v4 + 64);
    v6 = *(_DWORD *)(v4 + 44) + slot_index - 1;
    if ( v6 >= 0 && (v7 = *(_DWORD *)(v4 + 20), v6 >= v7) )
      SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)(*(_DWORD *)(v4 + 28) + 28 * (v6 - v7) + 8);
    else
      SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                    *(Scaleform::GFx::AS3::Slots **)(v4 + 24),
                                                    (Scaleform::GFx::AS3::AbsoluteIndex)v6);
    Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
      SlotInfo,
      (Scaleform::GFx::AS3::CheckResult *)&slot_index,
      v5,
      &args.ArgValue,
      VInt);
    Scaleform::GFx::AS3::ReadValueObject::~ReadValueObject(&args);
  }
}
