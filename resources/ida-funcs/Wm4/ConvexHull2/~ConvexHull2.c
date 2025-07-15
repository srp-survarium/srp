void __thiscall Wm4::ConvexHull2<float>::~ConvexHull2<float>(Wm4::ConvexHull2<float> *this)
{
  bool v2; // zf
  Wm4::Query2<float> *m_pkQuery; // ecx

  v2 = !this->m_bOwner;
  this->__vftable = (Wm4::ConvexHull2<float>_vtbl *)&Wm4::ConvexHull2<float>::`vftable';
  if ( !v2 )
    operator delete[](this->m_akVertex);
  operator delete[](this->m_akSVertex);
  m_pkQuery = this->m_pkQuery;
  if ( m_pkQuery )
    ((void (__thiscall *)(Wm4::Query2<float> *, int))m_pkQuery->~Wm4::Query2<float>)(m_pkQuery, 1);
  Wm4::ConvexHull<float>::~ConvexHull<float>(this);
}
