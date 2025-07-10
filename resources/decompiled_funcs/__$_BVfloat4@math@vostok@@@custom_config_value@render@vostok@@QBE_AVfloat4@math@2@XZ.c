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
