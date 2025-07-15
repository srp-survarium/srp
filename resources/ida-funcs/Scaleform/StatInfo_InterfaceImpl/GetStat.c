void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::CounterStat>::GetStat(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::CounterStat> *this,
        Scaleform::Stat *p,
        Scaleform::Stat::StatValue *pval,
        unsigned int index)
{
  unsigned int v4; // ecx

  if ( !index )
  {
    v4 = *(_DWORD *)p;
    pval->Type = VT_Null;
    pval->pName = "Count";
    pval->IValue = v4;
  }
}


void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat>::GetStat(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat> *this,
        Scaleform::MemoryStat *p,
        Scaleform::Stat::StatValue *pval,
        unsigned int index)
{
  Scaleform::MemoryStat::GetStat(p, pval, index);
}


void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::TimerStat>::GetStat(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::TimerStat> *this,
        Scaleform::Stat *p,
        Scaleform::Stat::StatValue *pval,
        unsigned int index)
{
  unsigned int v4; // ecx
  int v5; // edx

  if ( !index )
  {
    v4 = *(_DWORD *)p;
    v5 = *(_DWORD *)&p[4];
    pval->Type = VT_Boolean;
    pval->pName = "Ticks";
    pval->IValue = v4;
    *((_DWORD *)&pval->FValue + 1) = v5;
  }
}
