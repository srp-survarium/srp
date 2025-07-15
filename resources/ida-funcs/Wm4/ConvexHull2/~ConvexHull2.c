void __thiscall Wm4::ConvexHull2<float>::~ConvexHull2<float>(Wm4::ConvexHull2<float> *this)
{
  bool v2; // zf
  Wm4::Query2<float> *m_pkQuery; // ecx
  int *m_aiIndex; // [esp-4h] [ebp-8h]

  v2 = !this->m_bOwner;
  this->__vftable = (Wm4::ConvexHull2<float>_vtbl *)&Wm4::ConvexHull2<float>::`vftable';
  if ( !v2 )
    operator delete[](this->m_akVertex);
  operator delete[](this->m_akSVertex);
  m_pkQuery = this->m_pkQuery;
  if ( m_pkQuery )
    ((void (__thiscall *)(Wm4::Query2<float> *, int))m_pkQuery->~Wm4::Query2<float>)(m_pkQuery, 1);
  m_aiIndex = this->m_aiIndex;
  this->__vftable = (Wm4::ConvexHull2<float>_vtbl *)&Wm4::ConvexHull<float>::`vftable';
  operator delete[](m_aiIndex);
}
