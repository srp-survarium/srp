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
