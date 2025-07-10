Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SlotIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  signed int v6; // eax
  unsigned int FirstOwnSlotNum; // esi
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax

  pObject = this->pTraits.pObject;
  v6 = pObject->FirstOwnSlotInd.Index + ind.Index - 1;
  if ( v6 >= 0 && (FirstOwnSlotNum = pObject->FirstOwnSlotNum, v6 >= FirstOwnSlotNum) )
    p_Value = &pObject->VArray.Data.Data[v6 - FirstOwnSlotNum].Value;
  else
    p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                 (Scaleform::GFx::AS3::Slots *)pObject->Parent,
                                                 (Scaleform::GFx::AS3::AbsoluteIndex)v6);
  Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(p_Value, result, value, (Scaleform::GFx::ASStringNode *)this);
  return result;
}
