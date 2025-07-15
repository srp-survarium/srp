const Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Slots::FindSlotInfo(
        Scaleform::GFx::AS3::Slots *this,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(this, (Scaleform::GFx::AS3::AbsoluteIndex *)&ns, name, ns);
  if ( (int)ns < 0 )
    return 0;
  if ( (unsigned int)ns >= this->FirstOwnSlotNum )
    return &this->VArray.Data.Data[(unsigned int)ns - this->FirstOwnSlotNum].Value;
  return Scaleform::GFx::AS3::Slots::GetSlotInfo(
           (Scaleform::GFx::AS3::Slots *)this->Parent,
           (Scaleform::GFx::AS3::AbsoluteIndex)ns);
}
