int __usercall vostok::render::hw_buffer_pool::sync@<eax>(vostok::render::hw_buffer_pool *this@<ecx>, int **a2@<eax>)
{
  int *v2; // edi
  int v3; // esi
  int *v5; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h]

  v2 = *a2;
  v5 = a2[1];
  v6 = 0;
  if ( *a2 != v5 )
  {
    do
    {
      if ( *(_DWORD *)(*v2 + 796) )
      {
        v3 = *v2;
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->UpdateSubresource(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          *(ID3D11Resource **)(*v2 + 780),
          0,
          0,
          *(const void **)(*v2 + 788),
          0,
          0);
        _InterlockedExchange((volatile __int32 *)(v3 + 796), 0);
        ++v6;
      }
      ++v2;
    }
    while ( v2 != v5 );
  }
  return v6;
}
