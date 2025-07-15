void __userpurge vostok::render::particle_shader_constants::set_time(
        vostok::render::particle_shader_constants *this@<ecx>,
        float time,
        vostok::math::float3 a3)
{
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    (vostok::render::backend *)this,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::shader_constant_host **)(LODWORD(time) + 16),
    &a3);
}
