void __usercall btCollisionWorld::RayResultCallback::RayResultCallback(
        btCollisionWorld::RayResultCallback *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm0_4

  v2 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_WORD *)(a2 + 12) = 1;
  *(_DWORD *)(a2 + 20) = -1;
  *(_DWORD *)a2 = &btCollisionWorld::RayResultCallback::`vftable';
  *(float *)(a2 + 4) = v2;
  *(_WORD *)(a2 + 14) = -1;
}
