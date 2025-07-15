void __fastcall vostok::render::shader_buffer::unlock_write_discard(vostok::render::shader_buffer *this, int a2)
{
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Unmap(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    *(ID3D11Resource **)(*(_DWORD *)(a2 + 4) + 16),
    0);
}
