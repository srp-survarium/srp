void *__thiscall vostok::render::untyped_buffer::map(
        vostok::render::untyped_buffer *this,
        D3D11_MAP mode,
        D3D11_MAP a3)
{
  _DWORD v4[3]; // [esp+0h] [ebp-Ch] BYREF

  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Map(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    *(ID3D11Resource **)(mode + 16),
    0,
    a3,
    0,
    (D3D11_MAPPED_SUBRESOURCE *)v4);
  return (void *)v4[0];
}
