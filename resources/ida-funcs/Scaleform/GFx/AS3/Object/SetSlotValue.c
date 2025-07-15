Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Object::SetSlotValue(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SlotIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // ebx
  signed int v7; // eax
  unsigned int FirstOwnSlotNum; // esi
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  v7 = pObject->FirstOwnSlotInd.Index + ind.Index - 1;
  if ( v7 >= 0 && (FirstOwnSlotNum = pObject->FirstOwnSlotNum, v7 >= FirstOwnSlotNum) )
    p_Value = &pObject->VArray.Data.Data[v7 - FirstOwnSlotNum].Value;
  else
    p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                 (Scaleform::GFx::AS3::Slots *)pObject->Parent,
                                                 (Scaleform::GFx::AS3::AbsoluteIndex)v7);
  Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
    p_Value,
    result,
    pVM,
    value,
    (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)this);
  return result;
}
