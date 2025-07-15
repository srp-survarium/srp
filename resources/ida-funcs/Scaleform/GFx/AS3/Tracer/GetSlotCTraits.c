const Scaleform::GFx::AS3::ClassTraits::Traits *__cdecl Scaleform::GFx::AS3::Tracer::GetSlotCTraits(
        const Scaleform::GFx::AS3::Traits *tr,
        Scaleform::GFx::AS3::SlotIndex ind)
{
  signed int v2; // eax
  unsigned int FirstOwnSlotNum; // edx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // eax

  v2 = tr->FirstOwnSlotInd.Index + ind.Index - 1;
  if ( v2 >= 0 )
  {
    FirstOwnSlotNum = tr->FirstOwnSlotNum;
    if ( v2 >= FirstOwnSlotNum )
      return Scaleform::GFx::AS3::SlotInfo::GetDataType(&tr->VArray.Data.Data[v2 - FirstOwnSlotNum].Value, tr->pVM);
  }
  SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                (Scaleform::GFx::AS3::Slots *)tr->Parent,
                                                (Scaleform::GFx::AS3::AbsoluteIndex)(tr->FirstOwnSlotInd.Index
                                                                                   + ind.Index
                                                                                   - 1));
  return Scaleform::GFx::AS3::SlotInfo::GetDataType(SlotInfo, tr->pVM);
}
