void __thiscall vostok::render::renderer_context::set_v(
        vostok::render::renderer_context *this,
        const vostok::math::float4x4 *m,
        const vostok::math::float4x4 *a3)
{
  float v4; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // esi
  vostok::render::backend *v14; // ecx
  vostok::render::backend *v15; // ecx
  vostok::render::backend *v16; // ecx
  vostok::render::backend *v17; // ecx
  vostok::render::backend *v18; // ecx
  vostok::math::float4x4 v19; // [esp+10h] [ebp-D0h] BYREF
  vostok::math::float4x4 v20; // [esp+50h] [ebp-90h] BYREF
  vostok::math::float4x4 v21; // [esp+90h] [ebp-50h] BYREF
  float y; // [esp+D0h] [ebp-10h]
  float z; // [esp+D4h] [ebp-Ch]
  float w; // [esp+D8h] [ebp-8h]
  float v25; // [esp+DCh] [ebp-4h]

  qmemcpy(&m[304].lines[3].elements[1], a3, sizeof(const vostok::math::float4x4));
  qmemcpy(
    &m[305].lines[3].elements[1],
    vostok::math::transpose((const vostok::math::float4x4 *)((char *)m + 19508), &v21),
    sizeof(const vostok::math::float4x4));
  vostok::math::float4x4::try_invert(a3, (vostok::math::float4x4 *)&m[306].lines[3].elements[1]);
  qmemcpy(
    &m[307].lines[3].elements[1],
    vostok::math::transpose((const vostok::math::float4x4 *)((char *)m + 19636), &v21),
    sizeof(const vostok::math::float4x4));
  v4 = (float)((float)(m[307].j.y + m[306].c.y) * 0.0) + (float)(m[307].i.y * 1000.0);
  v5 = (float)((float)(m[307].j.z + m[306].c.z) * 0.0) + (float)(m[307].i.z * 1000.0);
  v6 = (float)((float)(m[307].j.w + m[306].c.w) * 0.0) + (float)(m[307].i.w * 1000.0);
  v7 = s_bm_current_air_resistance;
  v8 = s_bm_current_air_resistance / fsqrt((float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v4 * v4));
  w = v5 * v8;
  z = v8 * v4;
  v25 = v6 * v8;
  m[253].c.x = v8 * v4;
  m[253].c.y = w;
  m[253].c.z = v25;
  v9 = (float)((float)(m[307].j.y + m[307].i.y) * 0.0) + (float)(m[306].c.y * 1000.0);
  v10 = (float)((float)(m[307].j.z + m[307].i.z) * 0.0) + (float)(m[306].c.z * 1000.0);
  v11 = (float)((float)(m[307].j.w + m[307].i.w) * 0.0) + (float)(m[306].c.w * 1000.0);
  v12 = v7 / fsqrt((float)((float)(v9 * v9) + (float)(v11 * v11)) + (float)(v10 * v10));
  z = v12 * v9;
  w = v10 * v12;
  v25 = v11 * v12;
  m[253].c.w = v12 * v9;
  m[254].i.x = w;
  m[254].i.y = v25;
  vostok::math::mul4x3(
    (const vostok::math::float4x4 *)((char *)m + 19508),
    (const vostok::math::float4x4 *)((char *)m + 19380),
    &v21);
  qmemcpy(&m[312].lines[3].elements[1], &v21, sizeof(const vostok::math::float4x4));
  qmemcpy(
    &m[313].lines[3].elements[1],
    vostok::math::transpose((const vostok::math::float4x4 *)((char *)m + 20020), &v21),
    sizeof(const vostok::math::float4x4));
  qmemcpy(
    &m[314].lines[3].elements[1],
    vostok::math::mul4x4(
      (const vostok::math::float4x4 *)((char *)m + 19828),
      (const vostok::math::float4x4 *)((char *)m + 19508),
      &v21),
    sizeof(const vostok::math::float4x4));
  qmemcpy(
    &m[315].lines[3].elements[1],
    vostok::math::transpose((const vostok::math::float4x4 *)((char *)m + 20148), &v20),
    sizeof(const vostok::math::float4x4));
  qmemcpy(
    &m[316].lines[3].elements[1],
    vostok::math::mul4x4(
      (const vostok::math::float4x4 *)((char *)m + 19828),
      (const vostok::math::float4x4 *)((char *)m + 20020),
      &v20),
    sizeof(const vostok::math::float4x4));
  qmemcpy(
    &m[317].lines[3].elements[1],
    vostok::math::transpose((const vostok::math::float4x4 *)((char *)m + 20276), &v19),
    sizeof(const vostok::math::float4x4));
  y = m[307].k.y;
  z = m[307].k.z;
  w = m[307].k.w;
  v25 = s_bm_current_air_resistance;
  m[330].i.w = y;
  m[330].j.x = z;
  m[330].j.y = w;
  m[330].j.z = v25;
  y = m[307].j.y;
  z = m[307].j.z;
  w = m[307].j.w;
  v25 = 0.0;
  m[330].j.w = y;
  m[330].k.x = z;
  m[330].k.y = w;
  m[330].k.z = v25;
  v13 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    (vostok::render::backend *)&m[330].lines[0].elements[3],
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    (const vostok::render::shader_constant_host *)LODWORD(m[331].c.x),
    (const vostok::math::float3 *)&m[330].lines[0].elements[3]);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[331].c.x),
    (const unsigned int *)&m[330].i.w);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v14,
    (vostok::render::constants_handler<1> *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[331].c.z),
    (const vostok::math::float3 *)&m[330].lines[1].elements[3]);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[331].c.z),
    (const unsigned int *)&m[330].j.w);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[330].c.y),
    (const unsigned int *)&m[305].c.y);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[331].i.x),
    (const unsigned int *)&m[315].c.y);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[330].c.w),
    (const unsigned int *)&m[313].c.y);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[331].i.y),
    (const unsigned int *)&m[317].c.y);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v15,
    (vostok::render::constants_handler<1> *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[330].c.y),
    (const vostok::math::float3 *)&m[305].lines[3].elements[1]);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v16,
    (vostok::render::constants_handler<1> *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[331].i.x),
    (const vostok::math::float3 *)&m[315].lines[3].elements[1]);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v17,
    (vostok::render::constants_handler<1> *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[330].c.w),
    (const vostok::math::float3 *)&m[313].lines[3].elements[1]);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v18,
    (vostok::render::constants_handler<1> *)LODWORD(v13),
    (const vostok::render::shader_constant_host *)LODWORD(m[331].i.y),
    (const vostok::math::float3 *)&m[317].lines[3].elements[1]);
}
