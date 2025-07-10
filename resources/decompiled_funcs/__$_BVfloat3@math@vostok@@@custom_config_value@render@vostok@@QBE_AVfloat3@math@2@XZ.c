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
