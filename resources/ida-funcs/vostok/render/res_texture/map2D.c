void *__userpurge vostok::render::res_texture::map2D@<eax>(
        vostok::render::res_texture *this@<ecx>,
        int a2@<esi>,
        _DWORD *mode,
        char mip_level,
        unsigned int *row_pitch,
        bool dot_not_wait)
{
  _DWORD v7[3]; // [esp+0h] [ebp-10h] BYREF
  int v8; // [esp+Ch] [ebp-4h] BYREF

  if ( !*(_DWORD *)(a2 + 440) )
    return 0;
  if ( !*(_BYTE *)(a2 + 456) )
    return 0;
  (*(void (__stdcall **)(_DWORD, int *))(**(_DWORD **)(a2 + 440) + 28))(*(_DWORD *)(a2 + 440), &v8);
  if ( v8 != 3 )
    return 0;
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Map(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    *(ID3D11Resource **)(a2 + 440),
    0,
    D3D11_MAP_READ,
    mip_level != 0 ? (unsigned int)&loc_100000 : 0,
    (D3D11_MAPPED_SUBRESOURCE *)v7);
  *mode = v7[1];
  return (void *)v7[0];
}
