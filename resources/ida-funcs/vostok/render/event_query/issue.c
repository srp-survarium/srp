void __fastcall vostok::render::event_query::issue(vostok::render::event_query *this, ID3D11Asynchronous **a2)
{
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->End(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    *a2);
}
