void __usercall vostok::render::renderer_context::update_eye_rays(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm2_4
  unsigned int v5; // xmm3_4
  unsigned int v6; // xmm0_4
  __int64 v7; // [esp+0h] [ebp-24h]

  v2 = (float)((float)(*(float *)(a2 + 16128) - (float)(*(float *)(a2 + 16080) * *(float *)&clear_value))
             + *(float *)(a2 + 16112))
     + *(float *)(a2 + 16096);
  v3 = (float)((float)((float)(*(float *)(a2 + 16116) - (float)(*(float *)(a2 + 16068) * *(float *)&clear_value))
                     + *(float *)(a2 + 16100))
             + *(float *)(a2 + 16084))
     * (float)(*(float *)&clear_value / v2);
  *(float *)&v5 = (float)((float)((float)(*(float *)(a2 + 16120)
                                        - (float)(*(float *)(a2 + 16072) * *(float *)&clear_value))
                                + *(float *)(a2 + 16104))
                        + *(float *)(a2 + 16088))
                * (float)(*(float *)&clear_value / v2);
  *(float *)&v7 = v3;
  *((float *)&v7 + 1) = *(float *)&v5;
  v4 = (float)((float)((float)(*(float *)(a2 + 16124) - (float)(*(float *)(a2 + 16076) * *(float *)&clear_value))
                     + *(float *)(a2 + 16108))
             + *(float *)(a2 + 16092))
     * (float)(*(float *)&clear_value / v2);
  *(_QWORD *)(a2 + 16772) = v7;
  *(float *)(a2 + 16780) = v4;
  *(float *)&v7 = v3;
  *((float *)&v7 + 1) = -*(float *)&v5;
  *(float *)&v6 = -v3;
  *(_QWORD *)(a2 + 16784) = v7;
  *(float *)(a2 + 16792) = v4;
  *(_QWORD *)(a2 + 16796) = __PAIR64__(v5, v6);
  *(_QWORD *)(a2 + 16808) = __PAIR64__(-*(float *)&v5, v6);
  *(float *)(a2 + 16804) = v4;
  *(float *)(a2 + 16816) = v4;
}
