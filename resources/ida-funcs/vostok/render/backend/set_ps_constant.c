void __userpurge vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        vostok::render::backend *this@<ecx>,
        vostok::render::constants_handler<1> *a2@<esi>,
        const vostok::render::shader_constant_host *c,
        const vostok::math::float3 *arg)
{
  vostok::render::constants_handler<1>::set_constant<float>(a2 + 54, c, arg, 0);
  ++a2[109].m_current.m_object;
}
