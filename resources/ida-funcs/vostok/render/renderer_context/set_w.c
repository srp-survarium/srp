void __userpurge vostok::render::renderer_context::set_w(
        const vostok::math::float4x4 *m@<eax>,
        vostok::render::renderer_context *this)
{
  vostok::math::float4x4 *v3; // esi
  const vostok::render::shader_constant_host *m_c_w; // eax
  float z; // esi
  vostok::render::backend *v6; // ecx
  vostok::render::backend *v7; // ecx
  vostok::render::backend *v8; // ecx
  vostok::math::float4x4 v9; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float4x4 v10; // [esp+50h] [ebp-40h] BYREF

  qmemcpy(&this->m_w, m, sizeof(this->m_w));
  vostok::math::mul4x3(&this->m_v, &this->m_w, &v9);
  qmemcpy(&this->m_wv, &v9, sizeof(this->m_wv));
  qmemcpy(&this->m_wvp, vostok::math::mul4x4(&this->m_p, &this->m_wv, &v10), sizeof(this->m_wvp));
  qmemcpy(&this->m_wv_inverted_transposed, &v9, sizeof(this->m_wv_inverted_transposed));
  vostok::math::float4x4::try_invert(&this->m_wv_inverted_transposed, &this->m_wv_inverted_transposed);
  qmemcpy(
    &this->m_wv_inverted_transposed,
    vostok::math::transpose(&this->m_wv_inverted_transposed, &v10),
    sizeof(this->m_wv_inverted_transposed));
  qmemcpy(&this->m_w_transposed, vostok::math::transpose(&this->m_w, &v10), sizeof(this->m_w_transposed));
  qmemcpy(&this->m_wv_transposed, vostok::math::transpose(&this->m_wv, &v10), sizeof(this->m_wv_transposed));
  v3 = vostok::math::transpose(&this->m_wvp, &v10);
  m_c_w = this->m_c_w;
  qmemcpy(&this->m_wvp_transposed, v3, sizeof(this->m_wvp_transposed));
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    m_c_w,
    (const unsigned int *)&this->m_w_transposed);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    this->m_c_wv_inv,
    (const unsigned int *)&this->m_wv_inverted_transposed);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    this->m_c_wv,
    (const unsigned int *)&this->m_wv_transposed);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    this->m_c_wvp,
    (const unsigned int *)&this->m_wvp_transposed);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v6,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_c_w,
    (const vostok::math::float3 *)&this->m_w_transposed);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v7,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_c_wv,
    (const vostok::math::float3 *)&this->m_wv_transposed);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v8,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_c_wvp,
    (const vostok::math::float3 *)&this->m_wvp_transposed);
}
