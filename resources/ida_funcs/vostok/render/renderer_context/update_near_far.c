void __usercall vostok::render::renderer_context::update_near_far(
        vostok::render::renderer_context *this@<ecx>,
        float *a2@<eax>)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm2_4

  v2 = (float)((float)((float)((float)(a2[4027] + a2[4023]) + a2[4019]) * 0.0) + a2[4031])
     / (float)((float)((float)((float)(a2[4028] + a2[4024]) + a2[4020]) * 0.0) + a2[4032]);
  a2[3093] = v2;
  v3 = (float)((float)((float)((float)(a2[4023] + a2[4019]) * 0.0) + a2[4031]) + a2[4027])
     / (float)((float)((float)((float)(a2[4024] + a2[4020]) * 0.0) + a2[4032]) + a2[4028]);
  v4 = *(float *)&clear_value / v2;
  v5 = *(float *)&clear_value / v3;
  a2[3094] = v3;
  a2[3095] = v4;
  a2[3096] = v5;
}
