void __fastcall vostok::render::untyped_buffer::unmap(vostok::render::untyped_buffer *this, int a2)
{
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Unmap(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    *(ID3D11Resource **)(a2 + 16),
    0);
}
