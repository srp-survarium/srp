void __thiscall Wm4::ConvexHull1<float>::~ConvexHull1<float>(Wm4::ConvexHull1<float> *this)
{
  bool v2; // zf

  v2 = !this->m_bOwner;
  this->__vftable = (Wm4::ConvexHull1<float>_vtbl *)&Wm4::ConvexHull1<float>::`vftable';
  if ( !v2 )
    operator delete[](this->m_afVertex);
  Wm4::ConvexHull<float>::~ConvexHull<float>(this);
}
