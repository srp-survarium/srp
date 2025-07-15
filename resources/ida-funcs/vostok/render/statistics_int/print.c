void __thiscall vostok::render::statistics_int::print(
        vostok::render::statistics_int *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  unsigned __int8 *v3; // eax
  unsigned __int64 v4; // kr00_8
  unsigned __int8 *max_value; // eax
  unsigned __int64 v6; // kr08_8
  unsigned __int8 *min_value; // eax
  unsigned __int64 v8; // kr10_8
  vostok::fixed_string<260> *v9; // ecx
  vostok::fixed_string<260> *v10; // eax
  vostok::buffer_string *v11; // eax
  vostok::fixed_string<260> *v12; // eax
  vostok::buffer_string *v13; // eax
  vostok::fixed_string<260> *v14; // eax
  int v15; // eax
  vostok::buffer_string *v16; // ecx
  int v17; // [esp-8h] [ebp-238h]
  int v18; // [esp-4h] [ebp-234h]
  vostok::buffer_string v19[22]; // [esp+10h] [ebp-220h] BYREF
  _BYTE v20[272]; // [esp+120h] [ebp-110h] BYREF

  v3 = (unsigned __int8 *)vostok::render::statistics_value<int>::average(this);
  v4 = this->value_num_max_digits - (unsigned __int64)(unsigned int)vostok::render::get_num_digits(v3);
  max_value = (unsigned __int8 *)this->max_value;
  this->value_num_max_digits = this->value_num_max_digits
                             - (v4 & BYTE4(v4))
                             - (this->value_num_max_digits == ((unsigned int)v4 & HIDWORD(v4))
                              ? this->value_num_max_digits - (v4 & BYTE4(v4)) - 1
                              : 0);
  v6 = this->max_value_num_max_digits - (unsigned __int64)(unsigned int)vostok::render::get_num_digits(max_value);
  min_value = (unsigned __int8 *)this->min_value;
  this->max_value_num_max_digits = this->max_value_num_max_digits
                                 - (v6 & BYTE4(v6))
                                 - (this->max_value_num_max_digits == ((unsigned int)v6 & HIDWORD(v6))
                                  ? this->max_value_num_max_digits - (v6 & BYTE4(v6)) - 1
                                  : 0);
  v8 = this->min_value_num_max_digits - (unsigned __int64)(unsigned int)vostok::render::get_num_digits(min_value);
  v9 = (vostok::fixed_string<260> *)(this->min_value_num_max_digits - (v8 & HIDWORD(v8)));
  LOBYTE(v9) = (_BYTE)v9
             - (this->min_value_num_max_digits == ((unsigned int)v8 & HIDWORD(v8))
              ? this->min_value_num_max_digits - (v8 & BYTE4(v8)) - 1
              : 0);
  this->min_value_num_max_digits = (unsigned __int8)v9;
  vostok::fixed_string<260>::fixed_string<260>(v9, v19, "%s: ");
  vostok::buffer_string::operator+=(v19, "%");
  v10 = vostok::render::u32_to_string((int)v20, (vostok::fixed_string<260> *)this->value_num_max_digits);
  vostok::buffer_string::append(v19, v10->m_end, v10->m_begin);
  v11 = vostok::buffer_string::operator+=(v19, "d (");
  vostok::buffer_string::operator+=(v11, "%");
  v12 = vostok::render::u32_to_string((int)v20, (vostok::fixed_string<260> *)this->min_value_num_max_digits);
  vostok::buffer_string::append(v19, v12->m_end, v12->m_begin);
  v13 = vostok::buffer_string::operator+=(v19, "d..");
  vostok::buffer_string::operator+=(v13, "%");
  v14 = vostok::render::u32_to_string((int)v20, (vostok::fixed_string<260> *)this->min_value_num_max_digits);
  vostok::buffer_string::append(v19, v14->m_end, v14->m_begin);
  vostok::buffer_string::operator+=(v19, "d)");
  v18 = this->max_value;
  v17 = this->min_value;
  v15 = vostok::render::statistics_value<int>::average(this);
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    v16,
    (vostok::buffer_string *)v19[0].m_begin,
    this->m_name.m_begin,
    v15,
    v17,
    v18);
}
