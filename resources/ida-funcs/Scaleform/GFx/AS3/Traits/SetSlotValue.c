Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Traits::SetSlotValue(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *obj)
{
  Scaleform::GFx::AS3::VM *pVM; // edi
  unsigned int FirstOwnSlotNum; // esi
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax

  pVM = this->pVM;
  if ( ind.Index >= 0 && (FirstOwnSlotNum = this->FirstOwnSlotNum, ind.Index >= FirstOwnSlotNum) )
    p_Value = &this->VArray.Data.Data[ind.Index - FirstOwnSlotNum].Value;
  else
    p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                 (Scaleform::GFx::AS3::Slots *)this->Parent,
                                                 ind);
  Scaleform::GFx::AS3::SlotInfo::SetSlotValue(p_Value, result, pVM, v, obj);
  return result;
}
