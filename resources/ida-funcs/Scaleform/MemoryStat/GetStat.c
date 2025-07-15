void __thiscall Scaleform::MemoryStat::GetStat(
        Scaleform::MemoryStat *this,
        Scaleform::Stat::StatValue *pval,
        unsigned int index)
{
  unsigned int AllocCount; // ecx
  unsigned int Used; // ecx
  unsigned int Allocated; // ecx

  if ( index )
  {
    if ( index == 1 )
    {
      Used = this->Used;
      pval->pName = "Used";
      pval->Type = VT_Null;
      pval->IValue = Used;
    }
    else if ( index == 2 )
    {
      AllocCount = this->AllocCount;
      pval->pName = "AllocCount";
      pval->Type = VT_Null;
      pval->IValue = AllocCount;
    }
  }
  else
  {
    Allocated = this->Allocated;
    pval->pName = "Allocated";
    pval->Type = VT_Null;
    pval->IValue = Allocated;
  }
}
