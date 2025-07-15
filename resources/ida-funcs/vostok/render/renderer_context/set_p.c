void __userpurge vostok::render::renderer_context::set_p(
        const vostok::math::float4x4 *in_m@<eax>,
        vostok::render::renderer_context *this)
{
  const void *v3; // edx
  vostok::math::float4x4 *v4; // esi
  vostok::math::float4x4 *p_m_p_inverted; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float z; // esi
  vostok::render::backend *v11; // ecx
  vostok::render::backend *v12; // ecx
  vostok::render::backend *v13; // ecx
  vostok::math::float4x4 v14; // [esp+10h] [ebp-100h] BYREF
  vostok::math::float4x4 v15; // [esp+50h] [ebp-C0h] BYREF
  vostok::math::float4x4 v16; // [esp+90h] [ebp-80h] BYREF
  vostok::math::float4x4 v17; // [esp+D0h] [ebp-40h] BYREF

  qmemcpy(&v15, in_m, sizeof(v15));
  qmemcpy(&this->m_p, &v15, sizeof(this->m_p));
  qmemcpy(&this->m_p_transposed, vostok::math::transpose(&this->m_p, &v14), sizeof(this->m_p_transposed));
  qmemcpy(&this->m_p, &v15, sizeof(this->m_p));
  vostok::math::try_invert4x4(&v15, &v14);
  qmemcpy(&this->m_p_inverted, v3, sizeof(this->m_p_inverted));
  qmemcpy(&this->m_vp, vostok::math::mul4x4(&this->m_p, &this->m_v, &v14), sizeof(this->m_vp));
  qmemcpy(&this->m_vp_transposed, vostok::math::transpose(&this->m_vp, &v16), sizeof(this->m_vp_transposed));
  qmemcpy(&this->m_wvp, vostok::math::mul4x4(&this->m_p, &this->m_wv, &v16), sizeof(this->m_wvp));
  v4 = vostok::math::transpose(&this->m_wvp, &v17);
  p_m_p_inverted = &this->m_p_inverted;
  qmemcpy(&this->m_wvp_transposed, v4, sizeof(this->m_wvp_transposed));
  v6 = (float)((float)((float)((float)(this->m_p_inverted.k.z + p_m_p_inverted->j.z) + p_m_p_inverted->i.z) * 0.0)
             + p_m_p_inverted->c.z)
     / (float)((float)((float)((float)(p_m_p_inverted->k.w + p_m_p_inverted->j.w) + p_m_p_inverted->i.w) * 0.0)
             + p_m_p_inverted->c.w);
  this->m_near_far_invn_invf.x = v6;
  v7 = (float)((float)((float)((float)(this->m_p_inverted.j.z + p_m_p_inverted->i.z) * 0.0) + p_m_p_inverted->c.z)
             + p_m_p_inverted->k.z)
     / (float)((float)((float)((float)(p_m_p_inverted->j.w + p_m_p_inverted->i.w) * 0.0) + p_m_p_inverted->c.w)
             + p_m_p_inverted->k.w);
  v8 = s_bm_current_air_resistance / v6;
  v9 = s_bm_current_air_resistance / v7;
  this->m_near_far_invn_invf.y = v7;
  this->m_near_far_invn_invf.z = v8;
  this->m_near_far_invn_invf.w = v9;
  vostok::render::renderer_context::update_eye_rays(0, (int)this);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    this->m_c_p,
    (const unsigned int *)&this->m_p_transposed);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    this->m_c_vp,
    (const unsigned int *)&this->m_vp_transposed);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    this->m_c_wvp,
    (const unsigned int *)&this->m_wvp_transposed);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v11,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_c_p,
    (const vostok::math::float3 *)&this->m_p_transposed);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v12,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_c_vp,
    (const vostok::math::float3 *)&this->m_vp_transposed);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v13,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_c_wvp,
    (const vostok::math::float3 *)&this->m_wvp_transposed);
}
