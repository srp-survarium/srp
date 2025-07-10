void __fastcall btRigidBody::setGravity(btRigidBody *this, int a2)
{
  float v2; // xmm1_4
  unsigned int v3; // xmm1_4
  __int64 v4; // [esp+0h] [ebp-10h]

  v2 = *(float *)(a2 + 352);
  if ( v2 != 0.0 )
  {
    *(float *)&v4 = *(float *)&this->__vftable * (float)(*(float *)&clear_value / v2);
    *((float *)&v4 + 1) = *((float *)&this->__vftable + 1) * (float)(*(float *)&clear_value / v2);
    *(float *)&v3 = *((float *)&this->__vftable + 2) * (float)(*(float *)&clear_value / v2);
    *(_QWORD *)(a2 + 384) = v4;
    *(_QWORD *)(a2 + 392) = v3;
  }
  *(_QWORD *)(a2 + 400) = *(_QWORD *)&this->__vftable;
  *(_QWORD *)(a2 + 408) = *((_QWORD *)&this->__vftable + 1);
}
