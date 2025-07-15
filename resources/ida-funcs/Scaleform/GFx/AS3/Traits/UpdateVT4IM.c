void __thiscall Scaleform::GFx::AS3::Traits::UpdateVT4IM(
        Scaleform::GFx::AS3::Traits *this,
        const Scaleform::GFx::ASString *mn_name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *mn_ns,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  Scaleform::GFx::AS3::Slots *v6; // edi
  signed int Prev; // esi
  Scaleform::GFx::AS3::SlotInfo *v8; // ebx
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType v10; // ecx
  int v11; // esi
  const Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi

  if ( mn_ns == this->pVM->PublicNamespace.pObject )
  {
    v6 = &this->Scaleform::GFx::AS3::Slots;
    Prev = *(_DWORD *)Scaleform::GFx::AS3::Slots::FindSlotValues(&this->Scaleform::GFx::AS3::Slots, mn_name);
    if ( Prev >= 0 )
    {
      while ( 1 )
      {
        v8 = Prev >= v6->FirstOwnSlotNum
           ? &this->VArray.Data.Data[Prev - v6->FirstOwnSlotNum].Value
           : (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                (Scaleform::GFx::AS3::Slots *)this->Parent,
                                                (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
        if ( (*((_DWORD *)v8->pNs.pObject + 5) & 0x10) != 0 )
          break;
        if ( Prev >= v6->FirstOwnSlotNum )
          Prev = this->VArray.Data.Data[Prev - v6->FirstOwnSlotNum].Prev;
        else
          Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex((Scaleform::GFx::AS3::Slots *)this->Parent, Prev);
        if ( Prev < 0 )
          return;
      }
      VT = Scaleform::GFx::AS3::Traits::GetVT(this);
      v10 = bt;
      v11 = (32 * *(_DWORD *)v8) >> 15;
      if ( (int)(*(_DWORD *)v8 << 22) >> 27 != 11 || bt == BT_Code )
      {
        pObject = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v8->Name.pObject;
        ++pObject->pPrev;
        mn_ns = pObject;
        Scaleform::GFx::AS3::VTable::SetMethod(
          VT,
          (Scaleform::GFx::AS3::AbsoluteIndex)v11,
          v,
          v10,
          (const Scaleform::GFx::ASString *)&mn_ns);
        if ( pObject->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1 )
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pObject);
      }
    }
  }
}
