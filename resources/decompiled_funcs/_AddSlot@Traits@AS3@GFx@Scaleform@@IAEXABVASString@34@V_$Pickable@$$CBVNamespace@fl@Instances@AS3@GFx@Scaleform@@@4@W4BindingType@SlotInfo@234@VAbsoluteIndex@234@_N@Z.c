void __thiscall Scaleform::GFx::AS3::Traits::AddSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt,
        Scaleform::GFx::AS3::AbsoluteIndex offset,
        Scaleform::GFx::AS3::AbsoluteIndex const_)
{
  Scaleform::GFx::AS3::Slots *v6; // esi
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax
  Scaleform::GFx::AS3::SlotInfo v; // [esp+4h] [ebp-14h] BYREF

  v.pNs.pObject = ns.pV;
  memset(&v.CTraits, 0, 12);
  *(_DWORD *)&v = ((LOBYTE(const_.Index) != 0) + 2) & 0x1F ^ (*(_DWORD *)&v & 0xF8000000 | 0x7FFFC00);
  v6 = &this->Scaleform::GFx::AS3::Slots;
  Scaleform::GFx::AS3::Slots::Add(&this->Scaleform::GFx::AS3::Slots, &const_, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  p_Value = &v6->VArray.Data.Data[const_.Index - v6->FirstOwnSlotNum].Value;
  *(_DWORD *)p_Value ^= (*(_DWORD *)p_Value ^ (32 * dt)) & 0x3E0;
  *(_DWORD *)p_Value ^= (*(_DWORD *)p_Value ^ (offset.Index << 10)) & 0x7FFFC00;
}
