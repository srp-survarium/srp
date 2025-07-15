void __usercall vostok::render::radiance_volume::set_origin(vostok::render::radiance_volume *this@<ecx>, int a2@<eax>)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4

  *(_QWORD *)(a2 + 216) = 0;
  *(_QWORD *)(a2 + 204) = 0;
  *(_DWORD *)(a2 + 224) = 0;
  *(_DWORD *)(a2 + 212) = 0;
  v2 = *(float *)(a2 + 192);
  *(float *)(a2 + 216) = *(float *)(a2 + 216) + v2;
  v3 = v2;
  v4 = v2 + *(float *)(a2 + 224);
  *(float *)(a2 + 220) = v3 + *(float *)(a2 + 220);
  *(float *)(a2 + 224) = v4;
  *(float *)(a2 + 204) = *(float *)(a2 + 204) + *(float *)&this->m_rt_rms_albedo_source.m_object;
  *(float *)(a2 + 208) = *(float *)&this->m_t_rms_albedo_source.m_object + *(float *)(a2 + 208);
  *(float *)(a2 + 212) = *(float *)&this->m_rt_rms_normal_source.m_object + *(float *)(a2 + 212);
  *(float *)(a2 + 216) = *(float *)(a2 + 216) + *(float *)&this->m_rt_rms_albedo_source.m_object;
  *(float *)(a2 + 220) = *(float *)(a2 + 220) + *(float *)&this->m_t_rms_albedo_source.m_object;
  *(float *)(a2 + 224) = *(float *)(a2 + 224) + *(float *)&this->m_rt_rms_normal_source.m_object;
}
