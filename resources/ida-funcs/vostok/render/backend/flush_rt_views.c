void __thiscall vostok::render::backend::flush_rt_views(vostok::render::backend *this)
{
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->OMSetRenderTargets(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    8u,
    `vostok::render::backend::flush_rt_views'::`2'::null_views,
    0);
}
