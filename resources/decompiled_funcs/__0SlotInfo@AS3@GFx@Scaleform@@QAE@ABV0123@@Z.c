void __thiscall Scaleform::GFx::AS3::SlotInfo::SlotInfo(
        Scaleform::GFx::AS3::SlotInfo *this,
        const Scaleform::GFx::AS3::SlotInfo *other)
{
  int v3; // ecx
  int v4; // esi
  int v5; // ecx
  int v6; // esi
  int v7; // ecx
  const Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *v9; // ecx
  Scaleform::GFx::AS3::VMAbcFile *v10; // ecx

  *(_DWORD *)this ^= (*(_DWORD *)this ^ *(_DWORD *)other) & 1;
  v3 = *(_DWORD *)this ^ ((unsigned __int8)*(_DWORD *)this ^ (unsigned __int8)*(_DWORD *)other) & 2;
  *(_DWORD *)this = v3;
  v4 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)*(_DWORD *)other) & 4;
  *(_DWORD *)this = v4;
  v5 = v4 ^ ((unsigned __int8)v4 ^ (unsigned __int8)*(_DWORD *)other) & 8;
  *(_DWORD *)this = v5;
  v6 = v5 ^ ((unsigned __int8)v5 ^ (unsigned __int8)*(_DWORD *)other) & 0x10;
  *(_DWORD *)this = v6;
  v7 = v6 ^ ((unsigned __int16)v6 ^ (unsigned __int16)((__int16)(*(_WORD *)other << 6) >> 6)) & 0x3E0;
  *(_DWORD *)this = v7;
  *(_DWORD *)this = v7 ^ (v7 ^ ((32 * *(_DWORD *)other) >> 5)) & 0x7FFFC00;
  pObject = other->pNs.pObject;
  this->pNs.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  v9 = other->CTraits.pObject;
  this->CTraits.pObject = v9;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  v10 = other->File.pObject;
  this->File.pObject = v10;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
  this->TI = other->TI;
}
