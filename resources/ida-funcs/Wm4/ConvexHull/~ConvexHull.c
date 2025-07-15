void __thiscall Wm4::ConvexHull<float>::~ConvexHull<float>(Wm4::ConvexHull<float> *this)
{
  int *m_aiIndex; // [esp-4h] [ebp-4h]

  m_aiIndex = this->m_aiIndex;
  this->__vftable = (Wm4::ConvexHull<float>_vtbl *)&Wm4::ConvexHull<float>::`vftable';
  operator delete[](m_aiIndex);
}
