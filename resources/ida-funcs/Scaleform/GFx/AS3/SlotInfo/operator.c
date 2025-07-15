Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::SlotInfo::operator=(
        Scaleform::GFx::AS3::SlotInfo *this,
        const Scaleform::GFx::AS3::SlotInfo *other)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  Scaleform::GFx::ASStringNode *pObject; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx

  if ( this != other )
  {
    *(_DWORD *)this ^= (*(_DWORD *)this ^ *(_DWORD *)other) & 1;
    v3 = *(_DWORD *)this ^ ((unsigned __int8)*(_DWORD *)this ^ (unsigned __int8)*(_DWORD *)other) & 2;
    *(_DWORD *)this = v3;
    v4 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)*(_DWORD *)other) & 4;
    *(_DWORD *)this = v4;
    v5 = v4 ^ ((unsigned __int8)v4 ^ (unsigned __int8)*(_DWORD *)other) & 8;
    *(_DWORD *)this = v5;
    v6 = v5 ^ ((unsigned __int8)v5 ^ (unsigned __int8)*(_DWORD *)other) & 0x10;
    *(_DWORD *)this = v6;
    *(_DWORD *)this = v6 ^ ((unsigned __int16)v6 ^ (unsigned __int16)((__int16)(*(_WORD *)other << 6) >> 6)) & 0x3E0;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->pNs,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&other->pNs);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->CTraits,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&other->CTraits);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->File,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&other->File);
    this->TI = other->TI;
    *(_DWORD *)this ^= (*(_DWORD *)this ^ ((32 * *(_DWORD *)other) >> 5)) & 0x7FFFC00;
    pObject = other->Name.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v8 = this->Name.pObject;
    if ( v8 )
    {
      if ( v8->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    this->Name.pObject = other->Name.pObject;
  }
  return this;
}
