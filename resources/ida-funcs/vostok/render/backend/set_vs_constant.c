void __userpurge vostok::render::backend::set_vs_constant<vostok::math::float4>(
        vostok::render::backend *this@<esi>,
        const vostok::math::float3 *arg@<eax>,
        const vostok::render::shader_constant_host *c)
{
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(c, &this->m_vs_constants_handler, arg);
  ++this->num_setted_shader_constants;
}
