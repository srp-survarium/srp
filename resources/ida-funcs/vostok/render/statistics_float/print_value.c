void __userpurge vostok::render::statistics_float::print_value(
        vostok::render::statistics_float *this@<ecx>,
        __int64 a2@<xmm0>,
        vostok::fs_new::virtual_path_string *out_result)
{
  vostok::buffer_string *v4; // ecx
  vostok::buffer_string *v5; // ecx
  const char *m_decimal_numbers; // [esp+4h] [ebp-124h]
  vostok::render::statistics_value<double> *v7; // [esp+4h] [ebp-124h]
  vostok::buffer_string v8[22]; // [esp+10h] [ebp-118h] BYREF
  char v9; // [esp+120h] [ebp-8h]

  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)this, v8, "%.");
  m_decimal_numbers = (const char *)this->m_decimal_numbers;
  v9 = 47;
  vostok::buffer_string::appendf(v8, v4, (vostok::buffer_string *)"%df", m_decimal_numbers);
  vostok::render::statistics_value<double>::average(v7, (int)this);
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    v5,
    (vostok::buffer_string *)v8[0].m_begin,
    (const char *)a2,
    HIDWORD(a2));
}
