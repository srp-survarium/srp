char __thiscall Scaleform::StatBag::Add(Scaleform::StatBag *this, unsigned int statId, Scaleform::Stat *a3)
{
  Scaleform::StatDesc *v4; // eax
  Scaleform::StatInfo::StatInterface *v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax

  if ( !Stats_InitDone )
    Scaleform::StatDesc::InitChildTree();
  v4 = (Scaleform::StatDesc *)Scaleform::StatDescRegistryInstance.IdPageTable[statId >> 3];
  if ( Scaleform::StatDescRegistryInstance.IdPageTable[statId >> 3] )
    v4 = Scaleform::StatDescRegistryInstance.DescMem[(_DWORD)v4 + (statId & 7) - 1];
  v5 = Scaleform::Stats_InterfaceTable[v4->Type];
  if ( statId >= 0x1000
    || (v6 = this->IdPageTable[statId >> 4], v6 == 0xFFFF)
    || (v7 = *(unsigned __int16 *)&this->pMem[8 * v6 + 2 * (statId & 0xF)], v7 == 0xFFFF)
    || (v8 = &this->pMem[8 * v7]) == 0 )
  {
    v9 = v5->GetStatDataSize(v5);
    v8 = Scaleform::StatBag::AllocStatData(this, statId, v9);
    if ( !v8 )
      return 0;
    v5->Init(v5, (Scaleform::Stat *)v8);
  }
  v5->Add(v5, (Scaleform::Stat *)v8, a3);
  return 1;
}
