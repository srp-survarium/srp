void __thiscall Scaleform::GFx::AS3::VM::exec_getabsslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_ind)
{
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::ValueStack *pWeakProxy; // ecx
  Scaleform::GFx::AS3::Value::V2U v5; // edx
  Scaleform::GFx::AS3::Value *VInt; // ebx
  unsigned int v7; // eax
  int v8; // eax
  int p_pObject; // ecx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // eax
  Scaleform::GFx::AS3::ReadObjectRef args; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::Value::V2U v12; // [esp+14h] [ebp-4h]

  pCurrent = this->OpStack.pCurrent;
  args.VMRef = this;
  args.OpStack = &this->OpStack;
  args.ArgObject = pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, pCurrent);
  if ( !this->HandleException )
  {
    pWeakProxy = (Scaleform::GFx::AS3::ValueStack *)pCurrent->Bonus.pWeakProxy;
    v5.VObj = (Scaleform::GFx::AS3::Object *)pCurrent->value.VS._2;
    VInt = (Scaleform::GFx::AS3::Value *)pCurrent->value.VS._1.VInt;
    args.VMRef = (Scaleform::GFx::AS3::VM *)pCurrent->Flags;
    v7 = slot_ind;
    args.OpStack = pWeakProxy;
    pCurrent->Flags = 0;
    v8 = v7 - 1;
    p_pObject = (int)&VInt[1].Bonus.pWeakProxy[2].pObject;
    args.ArgObject = VInt;
    v12.VObj = v5.VObj;
    if ( v8 >= 0 && (unsigned int)v8 >= *(_DWORD *)p_pObject )
      SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)(32 * (v8 - *(_DWORD *)p_pObject) + *(_DWORD *)(p_pObject + 8) + 8);
    else
      SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                    *(Scaleform::GFx::AS3::Slots **)(p_pObject + 4),
                                                    (Scaleform::GFx::AS3::AbsoluteIndex)v8);
    Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
      SlotInfo,
      (Scaleform::GFx::AS3::CheckResult *)&slot_ind,
      pCurrent,
      (Scaleform::GFx::ASStringNode *)VInt);
    Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&args);
  }
}
