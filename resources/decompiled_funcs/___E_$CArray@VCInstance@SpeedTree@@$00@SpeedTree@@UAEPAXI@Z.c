bool *__thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::`vector deleting destructor'(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        char a2)
{
  if ( (a2 & 2) != 0 )
  {
    `vector destructor iterator'(
      (char *)this,
      0x14u,
      *(_DWORD *)&this[-1].m_bExternalMemory,
      (void (__thiscall *)(void *))SpeedTree::CArray<SpeedTree::CInstance,1>::~CArray<SpeedTree::CInstance,1>);
    if ( (a2 & 1) != 0 )
      operator delete[](&this[-1].m_bExternalMemory);
    return &this[-1].m_bExternalMemory;
  }
  else
  {
    SpeedTree::CArray<SpeedTree::CInstance,1>::~CArray<SpeedTree::CInstance,1>(this);
    if ( (a2 & 1) != 0 )
      operator delete(this);
    return (bool *)this;
  }
}
