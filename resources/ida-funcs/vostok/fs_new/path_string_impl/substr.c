vostok::fs_new::path_string_impl *__userpurge vostok::fs_new::path_string_impl::substr@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        int a2@<eax>,
        int a3@<esi>,
        vostok::fs_new::path_string_impl *result,
        unsigned int pos,
        unsigned int count)
{
  char v7; // bl
  char *m_end; // edi
  unsigned int v9; // edi
  unsigned __int8 *m_begin; // [esp-8h] [ebp-120h]
  vostok::buffer_string out_dest; // [esp+8h] [ebp-110h] BYREF
  _BYTE v13[260]; // [esp+14h] [ebp-104h] BYREF
  char vars0; // [esp+118h] [ebp+0h] BYREF

  out_dest.m_end = v13;
  out_dest.m_max_end = &vars0;
  out_dest.m_begin = v13;
  v13[0] = 0;
  vostok::buffer_string::substr((vostok::buffer_string *)a2, 0, (unsigned int)result, &out_dest);
  v7 = *(_BYTE *)(a2 + 272);
  m_end = out_dest.m_end;
  *(_DWORD *)(a3 + 8) = a3 + 272;
  v9 = m_end - out_dest.m_begin;
  m_begin = (unsigned __int8 *)out_dest.m_begin;
  *(_DWORD *)a3 = a3 + 12;
  *(_DWORD *)(a3 + 4) = a3 + 12;
  memcpy((unsigned __int8 *)(a3 + 12), m_begin, v9);
  *(_DWORD *)(a3 + 4) += v9;
  **(_BYTE **)(a3 + 4) = 0;
  *(_BYTE *)(a3 + 272) = v7;
  return (vostok::fs_new::path_string_impl *)a3;
}
