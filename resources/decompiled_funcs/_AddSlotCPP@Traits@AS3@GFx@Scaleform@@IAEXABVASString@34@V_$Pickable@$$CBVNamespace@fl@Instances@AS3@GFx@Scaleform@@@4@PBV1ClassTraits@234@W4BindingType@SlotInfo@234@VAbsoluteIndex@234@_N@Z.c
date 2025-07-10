void __thiscall Scaleform::GFx::AS3::Traits::AddSlotCPP(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt,
        Scaleform::GFx::AS3::AbsoluteIndex offset,
        Scaleform::GFx::AS3::AbsoluteIndex const_)
{
  unsigned int v7; // eax
  unsigned __int8 v8; // dl
  Scaleform::GFx::AS3::Slots *v9; // esi
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax
  Scaleform::GFx::AS3::SlotInfo v; // [esp+4h] [ebp-14h] BYREF

  v.pNs.pObject = ns.pV;
  v7 = *(_DWORD *)&v & 0xF8000000 | 0x7FFFC00;
  v.CTraits.pObject = tr;
  v8 = ((LOBYTE(const_.Index) != 0) + 2) | 0x10;
  if ( tr )
    tr->RefCount = (tr->RefCount + 1) & 0x8FBFFFFF;
  *(_DWORD *)&v = (v8 ^ (unsigned __int8)v7) & 0x1F ^ v7;
  v9 = &this->Scaleform::GFx::AS3::Slots;
  v.File.pObject = 0;
  v.TI = 0;
  Scaleform::GFx::AS3::Slots::Add(&this->Scaleform::GFx::AS3::Slots, &const_, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  p_Value = &v9->VArray.Data.Data[const_.Index - v9->FirstOwnSlotNum].Value;
  *(_DWORD *)p_Value ^= (*(_DWORD *)p_Value ^ (32 * dt)) & 0x3E0;
  *(_DWORD *)p_Value ^= (*(_DWORD *)p_Value ^ (offset.Index << 10)) & 0x7FFFC00;
}
