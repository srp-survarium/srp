void __thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat>::Reset(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat> *this,
        Scaleform::Stat *p)
{
  *(_DWORD *)p = 0;
  *(_DWORD *)&p[4] = 0;
  *(_DWORD *)&p[8] = 0;
}
