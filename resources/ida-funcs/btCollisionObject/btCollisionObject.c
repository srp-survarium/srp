btCollisionObject *__usercall btCollisionObject::btCollisionObject@<eax>(btCollisionObject *this@<ecx>, int a2@<esi>)
{
  float v2; // xmm1_4

  v2 = s_bm_current_air_resistance;
  *(_DWORD *)a2 = &btCollisionObject::`vftable';
  *(float *)(a2 + 176) = v2;
  *(float *)(a2 + 180) = v2;
  *(float *)(a2 + 184) = v2;
  *(_DWORD *)(a2 + 188) = 0;
  *(_DWORD *)(a2 + 220) = -1;
  *(_DWORD *)(a2 + 224) = -1;
  *(float *)(a2 + 196) = FLOAT_9_9999998e17;
  *(_DWORD *)(a2 + 192) = 0;
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 204) = 0;
  *(_DWORD *)(a2 + 208) = 0;
  *(_DWORD *)(a2 + 212) = 0;
  *(_DWORD *)(a2 + 216) = 1;
  *(_DWORD *)(a2 + 228) = 1;
  *(_DWORD *)(a2 + 232) = 0;
  *(float *)(a2 + 236) = c_anim_center;
  *(_DWORD *)(a2 + 240) = 0;
  *(_DWORD *)(a2 + 244) = 1;
  *(_DWORD *)(a2 + 248) = 0;
  *(float *)(a2 + 252) = v2;
  *(_DWORD *)(a2 + 256) = 0;
  *(_DWORD *)(a2 + 260) = 0;
  *(_DWORD *)(a2 + 264) = 0;
  btMatrix3x3::setIdentity(0, a2 + 16);
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  return (btCollisionObject *)a2;
}
