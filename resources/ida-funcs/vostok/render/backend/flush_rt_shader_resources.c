void __thiscall vostok::render::backend::flush_rt_shader_resources(vostok::render::backend *this, int a2)
{
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetShaderResources(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    32u,
    `vostok::render::backend::flush_rt_shader_resources'::`2'::null_views);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetShaderResources(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    32u,
    `vostok::render::backend::flush_rt_shader_resources'::`2'::null_views);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetShaderResources(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    32u,
    `vostok::render::backend::flush_rt_shader_resources'::`2'::null_views);
  memset(a2 + 3752, 0, 0x200u);
}
