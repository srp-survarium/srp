void __fastcall btRigidBody::setGravity(btRigidBody *this, int a2)
{
  float v2; // xmm2_4
  float v3; // [esp+4h] [ebp-Ch]
  float v4; // [esp+8h] [ebp-8h]

  v2 = *(float *)(a2 + 352);
  if ( v2 != 0.0 )
  {
    v3 = *((float *)&this->__vftable + 1) * (float)(s_bm_current_air_resistance / v2);
    v4 = *((float *)&this->__vftable + 2) * (float)(s_bm_current_air_resistance / v2);
    *(float *)(a2 + 384) = *(float *)&this->__vftable * (float)(s_bm_current_air_resistance / v2);
    *(float *)(a2 + 388) = v3;
    *(float *)(a2 + 392) = v4;
    *(_DWORD *)(a2 + 396) = 0;
  }
  *(_DWORD *)(a2 + 400) = this->__vftable;
  *(_DWORD *)(a2 + 404) = *((_DWORD *)&this->__vftable + 1);
  *(_DWORD *)(a2 + 408) = *((_DWORD *)&this->__vftable + 2);
  *(_DWORD *)(a2 + 412) = *((_DWORD *)&this->__vftable + 3);
}
