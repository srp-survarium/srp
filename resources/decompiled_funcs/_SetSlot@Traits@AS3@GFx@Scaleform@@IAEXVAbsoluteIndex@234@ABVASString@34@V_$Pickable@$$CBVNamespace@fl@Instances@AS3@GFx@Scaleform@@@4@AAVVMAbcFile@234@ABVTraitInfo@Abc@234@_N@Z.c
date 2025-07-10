void __thiscall Scaleform::GFx::AS3::Traits::SetSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::AbsoluteIndex index,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::Abc::TraitInfo *ti,
        bool _const)
{
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Slots *v8; // esi
  Scaleform::GFx::AS3::SlotInfo other; // [esp+8h] [ebp-14h] BYREF

  other.pNs.pObject = ns.pV;
  other.CTraits.pObject = 0;
  other.File.pObject = file;
  v7 = *(_DWORD *)&other & 0xF8000000 | 0x7FFFC00;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  other.TI = ti;
  *(_DWORD *)&other = ((unsigned __int8)(_const + 2) ^ (unsigned __int8)v7) & 0x1F ^ v7;
  v8 = &this->Scaleform::GFx::AS3::Slots;
  Scaleform::GFx::AS3::SlotInfo::operator=(&this->VArray.Data.Data[index.Index - this->FirstOwnSlotNum].Value, &other);
  Scaleform::GFx::AS3::Slots::SetKey(v8, index, name);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&other);
}
