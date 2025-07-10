Wm4::ConvexHull<float> *__thiscall Wm4::ConvexHull<float>::`vector deleting destructor'(
        Wm4::ConvexHull<float> *this,
        char a2)
{
  int *m_aiIndex; // [esp-4h] [ebp-8h]

  m_aiIndex = this->m_aiIndex;
  this->__vftable = (Wm4::ConvexHull<float>_vtbl *)&Wm4::ConvexHull<float>::`vftable';
  operator delete[](m_aiIndex);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
