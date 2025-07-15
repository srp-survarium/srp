void __userpurge vostok::render::backend::set_viewports(
        vostok::render::backend *this@<ecx>,
        int a2@<eax>,
        const D3D11_VIEWPORT *count,
        const D3D11_VIEWPORT *viewports)
{
  float *p_Height; // esi
  float *i; // ecx
  void *v8; // esp
  _DWORD v9[7]; // [esp-10h] [ebp-20h] BYREF
  float *v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+18h] [ebp+8h]

  v11 = 0;
  p_Height = &count->Height;
  v10 = &count->Height;
  for ( i = (float *)(a2 + 132);
        *(i - 1) == *(p_Height - 1)
     && *i == *p_Height
     && i[2] == p_Height[2]
     && i[1] == p_Height[1]
     && *(i - 3) == *(p_Height - 3)
     && *(i - 2) == *(p_Height - 2);
        i += 6 )
  {
    ++v11;
    p_Height += 6;
    if ( v11 )
      return;
  }
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->RSSetViewports(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    1u,
    count);
  v8 = alloca(16);
  qmemcpy((void *)(a2 + 120), count, 0x18u);
  v9[0] = (int)count->TopLeftX;
  v9[2] = (int)(float)(count->Width + count->TopLeftX);
  v9[1] = (int)count->TopLeftY;
  v9[3] = (int)(float)(*v10 + count->TopLeftY);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->RSSetScissorRects(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    1u,
    (const tagRECT *)v9);
}
