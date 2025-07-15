void __usercall vostok::render::renderer_context::update_eye_rays(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm0_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  int v6; // xmm1_4

  v2 = s_bm_current_air_resistance
     / (float)((float)((float)(*(float *)(a2 + 20016) - (float)(*(float *)(a2 + 19968) * s_bm_current_air_resistance))
                     + *(float *)(a2 + 20000))
             + *(float *)(a2 + 19984));
  v3 = (float)((float)((float)(*(float *)(a2 + 20012) - (float)(*(float *)(a2 + 19964) * s_bm_current_air_resistance))
                     + *(float *)(a2 + 19996))
             + *(float *)(a2 + 19980))
     * v2;
  v4 = (float)((float)((float)(*(float *)(a2 + 20004) - (float)(*(float *)(a2 + 19956) * s_bm_current_air_resistance))
                     + *(float *)(a2 + 19988))
             + *(float *)(a2 + 19972))
     * v2;
  v5 = (float)((float)((float)(*(float *)(a2 + 20008) - (float)(*(float *)(a2 + 19960) * s_bm_current_air_resistance))
                     + *(float *)(a2 + 19992))
             + *(float *)(a2 + 19976))
     * v2;
  *(float *)(a2 + 20932) = v4;
  *(float *)(a2 + 20936) = v5;
  *(float *)(a2 + 20940) = v3;
  *(float *)(a2 + 20944) = v4;
  *(_DWORD *)(a2 + 20948) = LODWORD(v5) ^ _mask__NegFloat_;
  *(float *)(a2 + 20952) = v3;
  v6 = LODWORD(v4) ^ _mask__NegFloat_;
  *(_DWORD *)(a2 + 20956) = v6;
  *(float *)(a2 + 20960) = v5;
  *(float *)(a2 + 20964) = v3;
  *(_DWORD *)(a2 + 20968) = v6;
  *(_DWORD *)(a2 + 20972) = LODWORD(v5) ^ _mask__NegFloat_;
  *(float *)(a2 + 20976) = v3;
}
