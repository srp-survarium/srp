void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::CounterStat>::SetMax(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::CounterStat> *this,
        Scaleform::Stat *p,
        Scaleform::Stat *p2)
{
  if ( *(_DWORD *)p2 <= *(_DWORD *)p )
    *(_DWORD *)p = *(_DWORD *)p;
  else
    *(_DWORD *)p = *(_DWORD *)p2;
}


void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat>::SetMax(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat> *this,
        Scaleform::Stat *p,
        Scaleform::Stat *p2)
{
  int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // ecx

  v3 = *(_DWORD *)p2;
  if ( *(_DWORD *)p2 <= *(_DWORD *)p )
    v3 = *(_DWORD *)p;
  v4 = *(_DWORD *)&p[4];
  *(_DWORD *)p = v3;
  v5 = *(_DWORD *)&p2[4];
  if ( v5 <= v4 )
    v5 = v4;
  v6 = *(_DWORD *)&p[8];
  *(_DWORD *)&p[4] = v5;
  v7 = *(_DWORD *)&p2[8];
  if ( v7 <= v6 )
    *(_DWORD *)&p[8] = v6;
  else
    *(_DWORD *)&p[8] = v7;
}


void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::TimerStat>::SetMax(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::TimerStat> *this,
        Scaleform::Stat *p,
        Scaleform::Stat *p2)
{
  int v3; // esi
  int v4; // eax

  v3 = *(_DWORD *)p2;
  v4 = *(_DWORD *)&p2[4];
  if ( *(_QWORD *)p2 <= *(_QWORD *)p )
  {
    v3 = *(_DWORD *)p;
    v4 = *(_DWORD *)&p[4];
  }
  *(_DWORD *)p = v3;
  *(_DWORD *)&p[4] = v4;
}
