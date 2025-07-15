void __thiscall Wm4::HullEdge2<float>::DeleteSelf(Wm4::HullEdge2<float> *this)
{
  Wm4::HullEdge2<float> *v1; // eax
  Wm4::HullEdge2<float> *v2; // eax

  v1 = this->A[0];
  if ( v1 )
    v1->A[1] = 0;
  v2 = this->A[1];
  if ( v2 )
    v2->A[0] = 0;
  operator delete(this);
}
