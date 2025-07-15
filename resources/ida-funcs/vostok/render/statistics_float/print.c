void __userpurge vostok::render::statistics_float::print(
        vostok::render::statistics_float *this@<ecx>,
        __int64 a2@<xmm0>,
        vostok::fs_new::virtual_path_string *out_result)
{
  vostok::buffer_string *v4; // ecx
  vostok::buffer_string *v5; // ecx
  vostok::buffer_string *v6; // ecx
  vostok::buffer_string *v7; // ecx
  vostok::buffer_string *v8; // ecx
  vostok::buffer_string *v9; // ecx
  vostok::buffer_string *v10; // ecx
  vostok::buffer_string *v11; // ecx
  vostok::buffer_string *v12; // ecx
  vostok::buffer_string *v13; // ecx
  vostok::render::statistics_value<double> *v14; // ecx
  vostok::buffer_string *v15; // ecx
  long double min_value; // [esp+8h] [ebp-250h]
  long double max_value; // [esp+10h] [ebp-248h]
  const char *m_decimal_numbers; // [esp+14h] [ebp-244h]
  vostok::buffer_string *v19; // [esp+14h] [ebp-244h]
  vostok::buffer_string *v20[3]; // [esp+28h] [ebp-230h] BYREF
  _BYTE v21[260]; // [esp+34h] [ebp-224h] BYREF
  char v22; // [esp+138h] [ebp-120h] BYREF
  char *v23[3]; // [esp+140h] [ebp-118h] BYREF
  _BYTE v24[260]; // [esp+14Ch] [ebp-10Ch] BYREF
  char v25; // [esp+250h] [ebp-8h] BYREF

  v20[0] = (vostok::buffer_string *)v21;
  v20[1] = (vostok::buffer_string *)v21;
  v20[2] = (vostok::buffer_string *)&v22;
  m_decimal_numbers = (const char *)this->m_decimal_numbers;
  v23[0] = v24;
  v23[1] = v24;
  v23[2] = &v25;
  v21[0] = 0;
  v22 = 47;
  v24[0] = 0;
  v25 = 47;
  vostok::fs_new::path_string_impl::assignf(
    v23,
    (vostok::buffer_string *)this,
    (vostok::buffer_string *)"%d",
    m_decimal_numbers);
  vostok::buffer_string::append(v19, (int)v20, "%s: ");
  vostok::buffer_string::append(v4, (int)v20, "%.");
  vostok::buffer_string::append(v5, (int)v20, v23[0]);
  vostok::buffer_string::append(v6, (int)v20, "f ");
  vostok::buffer_string::append(v7, (int)v20, "(%.");
  vostok::buffer_string::append(v8, (int)v20, v23[0]);
  vostok::buffer_string::append(v9, (int)v20, "f ");
  vostok::buffer_string::append(v10, (int)v20, "..");
  vostok::buffer_string::append(v11, (int)v20, "%.");
  vostok::buffer_string::append(v12, (int)v20, v23[0]);
  vostok::buffer_string::append(v13, (int)v20, "f)");
  max_value = this->max_value;
  min_value = this->min_value;
  vostok::render::statistics_value<double>::average(v14, (int)this);
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    v15,
    v20[0],
    this->m_name.m_begin,
    (_DWORD)a2,
    HIDWORD(a2),
    min_value,
    max_value);
}
