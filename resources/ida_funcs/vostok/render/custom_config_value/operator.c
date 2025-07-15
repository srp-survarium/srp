double __usercall vostok::render::custom_config_value::operator<float> float@<st0>(
        vostok::render::custom_config_value *this@<ecx>,
        int a2@<edi>)
{
  __int16 v2; // si

  if ( (`vostok::render::static_type::get_type_id<unsigned char>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<unsigned char>'::`2'::`local static guard' |= 1u;
    `vostok::render::static_type::get_type_id<unsigned char>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
  }
  v2 = *(_WORD *)(a2 + 12);
  if ( v2 == `vostok::render::static_type::get_type_id<unsigned char>'::`2'::current_id )
    return (double)(unsigned __int64)*(int *)(a2 + 4);
  if ( (`vostok::render::static_type::get_type_id<signed char>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<signed char>'::`2'::`local static guard' |= 1u;
    `vostok::render::static_type::get_type_id<signed char>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
  }
  if ( v2 == `vostok::render::static_type::get_type_id<signed char>'::`2'::current_id
    || v2 == vostok::render::static_type::get_type_id<unsigned short>()
    || v2 == vostok::render::static_type::get_type_id<short>()
    || v2 == vostok::render::static_type::get_type_id<unsigned int>()
    || v2 == vostok::render::static_type::get_type_id<int>()
    || v2 == vostok::render::static_type::get_type_id<unsigned __int64>()
    || v2 == vostok::render::static_type::get_type_id<__int64>() )
  {
    return (double)(unsigned __int64)*(int *)(a2 + 4);
  }
  else
  {
    return *(float *)(a2 + 4);
  }
}


vostok::math::float3 *__usercall vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3@<eax>(
        vostok::render::custom_config_value *this@<ecx>,
        vostok::math::float3 *a2@<eax>,
        int a3@<edx>)
{
  int v3; // ecx
  float v4; // edx
  float v5; // ecx

  if ( (`vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' |= 1u;
    LOWORD(`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
  }
  if ( *(_WORD *)(a3 + 12) == (_WORD)`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id )
  {
    v5 = *(float *)(a3 + 12);
    *(_QWORD *)&a2->x = *(_QWORD *)(a3 + 4);
    a2->z = v5;
  }
  else
  {
    v3 = *(_DWORD *)(a3 + 4);
    v4 = *(float *)(v3 + 8);
    *(_QWORD *)&a2->x = *(_QWORD *)v3;
    a2->z = v4;
  }
  return a2;
}


vostok::math::float4 *__usercall vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4@<eax>(
        vostok::render::custom_config_value *this@<ecx>,
        vostok::math::float4 *a2@<eax>,
        int a3@<edx>)
{
  _QWORD *v3; // ecx
  __int64 v4; // xmm0_8

  if ( (`vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' |= 1u;
    LOWORD(`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
  }
  if ( *(_WORD *)(a3 + 12) == (_WORD)`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id )
  {
    *(_QWORD *)&a2->x = *(_QWORD *)(a3 + 4);
    v4 = *(_QWORD *)(a3 + 12);
  }
  else
  {
    v3 = *(_QWORD **)(a3 + 4);
    *(_QWORD *)&a2->x = *v3;
    v4 = v3[1];
  }
  *(_QWORD *)&a2->elements[2] = v4;
  return a2;
}


const vostok::render::custom_config_value *__userpurge vostok::render::custom_config_value::operator[]@<eax>(
        vostok::render::custom_config_value *this@<ecx>,
        int a2@<eax>,
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> key)
{
  unsigned __int8 *rem; // ebx
  const vostok::render::custom_config_value *v4; // edi
  const vostok::render::custom_config_value *v5; // ebp
  unsigned int v6; // ecx
  const vostok::render::custom_config_value *v7; // edi
  unsigned int crc; // [esp+14h] [ebp-4h] BYREF

  rem = (unsigned __int8 *)key.rem_;
  v4 = *(const vostok::render::custom_config_value **)(a2 + 4);
  v5 = &v4[*(unsigned __int16 *)(a2 + 14)];
  key.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(&key, rem, &rem[strlen((const char *)rem)]);
  v6 = ~key.rem_;
  LOBYTE(key.rem_) = 0;
  crc = v6;
  v7 = stlp_std::priv::__lower_bound<vostok::render::custom_config_value const *,unsigned int,stlp_std::priv::__less_2<vostok::render::custom_config_value,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::render::custom_config_value>,int>(
         v4,
         v5,
         &crc);
  while ( strcmp((const char *)rem, v7->id) )
    ;
  return v7;
}
