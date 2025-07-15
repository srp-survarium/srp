void __userpurge vostok::render::bloom_shader_constants::set(
        vostok::render::bloom_shader_constants *this@<ecx>,
        int a2@<edi>,
        unsigned int a3@<xmm0>,
        const vostok::render::shader_constant_host **thisa,
        float a5,
        const struct vostok::math::float3 *a6)
{
  float z; // esi
  vostok::render::backend *v7; // ecx
  const vostok::render::shader_constant_host *v8; // [esp-8h] [ebp-24h]
  const vostok::render::shader_constant_host *v9; // [esp-8h] [ebp-24h]
  vostok::math::float3 v10; // [esp+8h] [ebp-14h] BYREF
  float v11; // [esp+14h] [ebp-8h]

  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  *(_QWORD *)&v10.x = __PAIR64__(LODWORD(s_bm_current_air_resistance), a3);
  v8 = *thisa;
  v10.z = 0.0;
  v11 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    (vostok::render::backend *)this,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v8,
    &v10);
  *(_QWORD *)&v10.x = *(_QWORD *)a2;
  v9 = thisa[1];
  v10.z = *(float *)(a2 + 8);
  v11 = s_bm_current_air_resistance;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v7,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    v9,
    &v10);
}
