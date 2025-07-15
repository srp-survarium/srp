char __thiscall Scaleform::StatBag::GetStat(Scaleform::StatBag *this, Scaleform::StatInfo *pstat, unsigned int statId)
{
  int v3; // edx
  unsigned __int8 *pMem; // eax
  int v5; // ecx
  Scaleform::Stat *v6; // edi
  Scaleform::StatInfo::StatInterface *Interface; // eax

  if ( statId >= 0x1000 )
    return 0;
  v3 = this->IdPageTable[statId >> 4];
  if ( v3 == 0xFFFF )
    return 0;
  pMem = this->pMem;
  v5 = *(unsigned __int16 *)&this->pMem[8 * v3 + 2 * (statId & 0xF)];
  if ( v5 == 0xFFFF )
    return 0;
  v6 = (Scaleform::Stat *)&pMem[8 * v5];
  if ( !v6 )
    return 0;
  Interface = Scaleform::StatBag::GetInterface(statId);
  pstat->StatId = statId;
  pstat->pInterface = Interface;
  pstat->pData = v6;
  return 1;
}
