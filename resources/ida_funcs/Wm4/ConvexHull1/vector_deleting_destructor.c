Wm4::ConvexHull1<float> *__thiscall Wm4::ConvexHull1<float>::`vector deleting destructor'(
        Wm4::ConvexHull1<float> *this,
        char a2)
{
  bool v3; // zf
  int *m_aiIndex; // [esp-4h] [ebp-8h]

  v3 = !this->m_bOwner;
  this->__vftable = (Wm4::ConvexHull1<float>_vtbl *)&Wm4::ConvexHull1<float>::`vftable';
  if ( !v3 )
    operator delete[](this->m_afVertex);
  m_aiIndex = this->m_aiIndex;
  this->__vftable = (Wm4::ConvexHull1<float>_vtbl *)&Wm4::ConvexHull<float>::`vftable';
  operator delete[](m_aiIndex);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
