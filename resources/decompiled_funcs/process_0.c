bool __thiscall process_0(btBroadphaseAabbCallback *this, const btBroadphaseProxy *a2)
{
  float *v2; // eax
  float v3; // xmm0_4

  if ( v3 >= 0.0 )
    *v2 = *v2 + v3;
  else
    *(float *)&this->__vftable = *(float *)&this->__vftable + v3;
  return (char)v2;
}
