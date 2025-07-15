void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::CounterStat>::Add(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::CounterStat> *this,
        Scaleform::Stat *p,
        Scaleform::Stat *p2)
{
  *(_DWORD *)p += *(_DWORD *)p2;
}


void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat>::Add(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat> *this,
        Scaleform::Stat *p,
        Scaleform::Stat *p2)
{
  *(_DWORD *)p += *(_DWORD *)p2;
  *(_DWORD *)&p[4] += *(_DWORD *)&p2[4];
  *(_DWORD *)&p[8] += *(_DWORD *)&p2[8];
}


void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::TimerStat>::Add(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::TimerStat> *this,
        Scaleform::Stat *p,
        Scaleform::Stat *p2)
{
  bool v3; // cf

  v3 = __CFADD__(*(_DWORD *)p2, *(_DWORD *)p);
  *(_DWORD *)p += *(_DWORD *)p2;
  *(_DWORD *)&p[4] += *(_DWORD *)&p2[4] + v3;
}
