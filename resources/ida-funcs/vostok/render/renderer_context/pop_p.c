void __usercall vostok::render::renderer_context::pop_p(
        vostok::render::renderer_context *this@<ecx>,
        vostok::render::renderer_context *a2@<esi>)
{
  vostok::render::renderer_context::set_p((const vostok::math::float4x4 *)a2->m_p_stack.m_end - 1, a2);
  --a2->m_p_stack.m_end;
}
