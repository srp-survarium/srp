void __thiscall Scaleform::GFx::AS3::VM::exec_setglobalslot(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VM *slot_index)
{
  Scaleform::GFx::AS3::Value *pCurrent; // ebx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *GlobalObject; // edi
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  signed int v6; // eax
  unsigned int FirstOwnSlotNum; // ebp
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax
  Scaleform::GFx::AS3::Value *v9; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  pCurrent = this->OpStack.pCurrent;
  GlobalObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)Scaleform::GFx::AS3::VM::GetGlobalObject(this);
  pObject = GlobalObject->pTraits.pObject;
  v6 = (signed int)slot_index + pObject->FirstOwnSlotInd.Index - 1;
  slot_index = pObject->pVM;
  if ( v6 >= 0 && (FirstOwnSlotNum = pObject->FirstOwnSlotNum, v6 >= FirstOwnSlotNum) )
    p_Value = &pObject->VArray.Data.Data[v6 - FirstOwnSlotNum].Value;
  else
    p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                 (Scaleform::GFx::AS3::Slots *)pObject->Parent,
                                                 (Scaleform::GFx::AS3::AbsoluteIndex)v6);
  Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
    p_Value,
    (Scaleform::GFx::AS3::CheckResult *)&slot_index,
    slot_index,
    pCurrent,
    GlobalObject);
  v9 = this->OpStack.pCurrent;
  if ( (v9->Flags & 0x1F) <= 9 )
    goto LABEL_11;
  if ( (v9->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
LABEL_11:
    --this->OpStack.pCurrent;
    return;
  }
  pWeakProxy = v9->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  v9->Flags &= 0xFFFFFDE0;
  v9->Bonus.pWeakProxy = 0;
  v9->value.VS._1.VInt = 0;
  v9->value.VS._2.VObj = 0;
  --this->OpStack.pCurrent;
}
