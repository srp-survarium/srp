void __userpurge vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        vostok::render::backend *this@<esi>,
        const vostok::math::float3 *arg@<eax>,
        const vostok::render::shader_constant_host *c)
{
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(&this->m_ps_constants_handler, c, arg);
  ++this->num_setted_shader_constants;
}
