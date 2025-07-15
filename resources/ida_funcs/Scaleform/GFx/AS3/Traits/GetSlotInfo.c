const Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Traits::GetSlotInfo(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  unsigned int FirstOwnSlotNum; // esi

  if ( ind.Index >= 0 && (FirstOwnSlotNum = this->FirstOwnSlotNum, ind.Index >= FirstOwnSlotNum) )
    return &this->VArray.Data.Data[ind.Index - FirstOwnSlotNum].Value;
  else
    return Scaleform::GFx::AS3::Slots::GetSlotInfo((Scaleform::GFx::AS3::Slots *)this->Parent, ind);
}
