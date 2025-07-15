void __fastcall vostok::render::res_texture::unmap2D(vostok::render::res_texture *this, int a2)
{
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Unmap(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    *(ID3D11Resource **)(a2 + 440),
    0);
}
