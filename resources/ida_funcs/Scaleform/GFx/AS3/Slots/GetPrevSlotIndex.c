int __thiscall Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(Scaleform::GFx::AS3::Slots *this, unsigned int ind)
{
  for ( ; ind < this->FirstOwnSlotNum; this = (Scaleform::GFx::AS3::Slots *)this->Parent )
    ;
  return this->VArray.Data.Data[ind - this->FirstOwnSlotNum].Prev;
}
