const Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Slots::GetSlotInfo(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  if ( ind.Index >= 0 && ind.Index >= this->FirstOwnSlotNum )
    return &this->VArray.Data.Data[ind.Index - this->FirstOwnSlotNum].Value;
  else
    return Scaleform::GFx::AS3::Slots::GetSlotInfo((Scaleform::GFx::AS3::Slots *)this->Parent, ind);
}
