Scaleform::GFx::AS3::AbsoluteIndex *__thiscall Scaleform::GFx::AS3::Traits::AddSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::Abc::TraitInfo *ti,
        bool const_)
{
  unsigned int v7; // eax
  Scaleform::GFx::AS3::SlotInfo v; // [esp+4h] [ebp-14h] BYREF

  v.pNs.pObject = ns.pV;
  v.CTraits.pObject = 0;
  v.File.pObject = file;
  v7 = *(_DWORD *)&v & 0xF8000000 | 0x7FFFC00;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  v.TI = ti;
  *(_DWORD *)&v = ((unsigned __int8)(const_ + 2) ^ (unsigned __int8)v7) & 0x1F ^ v7;
  Scaleform::GFx::AS3::Slots::Add(&this->Scaleform::GFx::AS3::Slots, result, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  return result;
}
