vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(
        vostok::fs_new::path_string_impl *this,
        const vostok::fixed_string<260> *s)
{
  const vostok::fixed_string<260> *v2; // eax
  vostok::fixed_string<260> v4; // [esp+8h] [ebp-114h] BYREF

  v2 = (const vostok::fixed_string<260> *)vostok::buffer_string::append(
                                            &s->vostok::buffer_string,
                                            this->m_string.m_end,
                                            this->m_string.m_begin);
  vostok::fixed_string<260>::fixed_string<260>(&v4, v2);
  return (vostok::fs_new::path_string_impl *)s;
}
