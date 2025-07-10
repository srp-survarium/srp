void __usercall vostok::render::system_renderer::set_w(
        vostok::render::system_renderer *this@<eax>,
        const vostok::math::float4x4 *m@<edx>)
{
  vostok::render::renderer_context::set_w((int)this->m_renderer_context, m, this->m_renderer_context);
}
