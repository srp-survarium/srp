vostok::fs_new::path_string_impl *__userpurge vostok::fs_new::path_string_impl::substr@<eax>(
        unsigned int pos@<edi>,
        int a2@<eax>,
        vostok::fs_new::path_string_impl *this,
        char *count)
{
  char m_separator; // bl
  const vostok::fixed_string<260> *v6; // ecx
  vostok::buffer_string out_dest; // [esp+8h] [ebp-110h] BYREF
  _BYTE v9[260]; // [esp+14h] [ebp-104h] BYREF
  char vars0; // [esp+118h] [ebp+0h] BYREF

  out_dest.m_begin = v9;
  out_dest.m_end = v9;
  out_dest.m_max_end = &vars0;
  v9[0] = 0;
  vostok::buffer_string::substr(pos, count, &out_dest, &this->m_string);
  m_separator = this->m_separator;
  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)a2, v6);
  *(_BYTE *)(a2 + 272) = m_separator;
  return (vostok::fs_new::path_string_impl *)a2;
}
