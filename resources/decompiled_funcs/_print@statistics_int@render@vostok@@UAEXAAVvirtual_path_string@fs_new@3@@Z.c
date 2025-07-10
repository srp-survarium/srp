void __thiscall vostok::render::statistics_int::print(
        vostok::render::statistics_int *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  unsigned int num_digits; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  char *m_buffer; // eax
  const char *v10; // ecx
  char *m_end; // eax
  const char *v12; // ecx
  int v13; // edi
  char *v14; // ecx
  const char *v15; // eax
  char *v16; // eax
  const char *v17; // ecx
  int v18; // edi
  char *v19; // ecx
  const char *v20; // eax
  char *v21; // eax
  const char *v22; // ecx
  int v23; // edi
  char *v24; // ecx
  const char *v25; // eax
  int value_num_max_digits; // [esp-4h] [ebp-234h]
  int min_value_num_max_digits; // [esp-4h] [ebp-234h]
  int v28; // [esp-4h] [ebp-234h]
  vostok::fixed_string<260> rule; // [esp+10h] [ebp-220h] BYREF
  vostok::buffer_string v30; // [esp+120h] [ebp-110h] BYREF
  _BYTE v31[260]; // [esp+12Ch] [ebp-104h] BYREF
  char vars0; // [esp+230h] [ebp+0h] BYREF

  num_digits = vostok::render::get_num_digits((char *)this->value);
  v4 = vostok::math::max(this->value_num_max_digits, num_digits);
  this->value_num_max_digits = vostok::math::max(v4, 1u);
  v5 = vostok::render::get_num_digits((char *)this->max_value);
  v6 = vostok::math::max(this->max_value_num_max_digits, v5);
  this->max_value_num_max_digits = vostok::math::max(v6, 1u);
  v7 = vostok::render::get_num_digits((char *)this->min_value);
  v8 = vostok::math::max(this->min_value_num_max_digits, v7);
  this->min_value_num_max_digits = vostok::math::max(v8, 1u);
  m_buffer = rule.m_buffer;
  rule.m_end = rule.m_buffer;
  rule.m_buffer[0] = 0;
  v10 = "%s: ";
  do
  {
    if ( m_buffer >= (char *)&v30 )
      break;
    *m_buffer = *v10;
    m_buffer = rule.m_end + 1;
    ++v10;
    ++rule.m_end;
  }
  while ( *v10 );
  *m_buffer = 0;
  m_end = rule.m_end;
  v12 = "%";
  do
  {
    if ( m_end >= (char *)&v30 )
      break;
    *m_end = *v12;
    m_end = rule.m_end + 1;
    ++v12;
    ++rule.m_end;
  }
  while ( *v12 );
  *m_end = 0;
  value_num_max_digits = this->value_num_max_digits;
  v30.m_end = v31;
  v30.m_begin = v31;
  v30.m_max_end = &vars0;
  v31[0] = 0;
  vostok::buffer_string::assignf(&v30, "%d", value_num_max_digits);
  v13 = v30.m_end - v30.m_begin;
  memcpy((unsigned __int8 *)rule.m_end, (unsigned __int8 *)v30.m_begin, v30.m_end - v30.m_begin);
  rule.m_end += v13;
  *rule.m_end = 0;
  v14 = rule.m_end;
  v15 = "d (";
  do
  {
    if ( v14 >= (char *)&v30 )
      break;
    *v14 = *v15;
    v14 = rule.m_end + 1;
    ++v15;
    ++rule.m_end;
  }
  while ( *v15 );
  *v14 = 0;
  v16 = rule.m_end;
  v17 = "%";
  do
  {
    if ( v16 >= (char *)&v30 )
      break;
    *v16 = *v17;
    v16 = rule.m_end + 1;
    ++v17;
    ++rule.m_end;
  }
  while ( *v17 );
  *v16 = 0;
  min_value_num_max_digits = this->min_value_num_max_digits;
  v30.m_end = v31;
  v30.m_begin = v31;
  v30.m_max_end = &vars0;
  v31[0] = 0;
  vostok::buffer_string::assignf(&v30, "%d", min_value_num_max_digits);
  v18 = v30.m_end - v30.m_begin;
  memcpy((unsigned __int8 *)rule.m_end, (unsigned __int8 *)v30.m_begin, v30.m_end - v30.m_begin);
  rule.m_end += v18;
  *rule.m_end = 0;
  v19 = rule.m_end;
  v20 = "d..";
  do
  {
    if ( v19 >= (char *)&v30 )
      break;
    *v19 = *v20;
    v19 = rule.m_end + 1;
    ++v20;
    ++rule.m_end;
  }
  while ( *v20 );
  *v19 = 0;
  v21 = rule.m_end;
  v22 = "%";
  do
  {
    if ( v21 >= (char *)&v30 )
      break;
    *v21 = *v22;
    v21 = rule.m_end + 1;
    ++v22;
    ++rule.m_end;
  }
  while ( *v22 );
  *v21 = 0;
  v28 = this->min_value_num_max_digits;
  v30.m_end = v31;
  v30.m_begin = v31;
  v30.m_max_end = &vars0;
  v31[0] = 0;
  vostok::buffer_string::assignf(&v30, "%d", v28);
  v23 = v30.m_end - v30.m_begin;
  memcpy((unsigned __int8 *)rule.m_end, (unsigned __int8 *)v30.m_begin, v30.m_end - v30.m_begin);
  rule.m_end += v23;
  *rule.m_end = 0;
  v24 = rule.m_end;
  v25 = "d)";
  do
  {
    if ( v24 >= (char *)&v30 )
      break;
    *v24 = *v25;
    v24 = rule.m_end + 1;
    ++v25;
    ++rule.m_end;
  }
  while ( *v25 );
  *v24 = 0;
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    rule.m_buffer,
    this->m_name.m_begin,
    this->value,
    this->min_value,
    this->max_value);
}
