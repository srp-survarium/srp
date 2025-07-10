Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Slots::FindAddOwnSlotInfo(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS3::SlotInfo *v,
        Scaleform::GFx::AS3::AbsoluteIndex *ind)
{
  const Scaleform::GFx::AS3::SlotInfo *v4; // ebx
  int Index; // eax
  Scaleform::GFx::AS3::AbsoluteIndex *v7; // edi

  v4 = v;
  Index = Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
            this,
            (Scaleform::GFx::AS3::AbsoluteIndex *)&v,
            name,
            v->pNs.pObject)->Index;
  v7 = ind;
  ind->Index = Index;
  if ( Index < 0 )
    v7->Index = Scaleform::GFx::AS3::Slots::Add(this, (Scaleform::GFx::AS3::AbsoluteIndex *)&v, name, v4)->Index;
  return &this->VArray.Data.Data[v7->Index - this->FirstOwnSlotNum].Value;
}
