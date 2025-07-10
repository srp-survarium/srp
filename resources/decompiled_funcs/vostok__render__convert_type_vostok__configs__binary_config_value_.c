unsigned __int16 __usercall vostok::render::convert_type_vostok::configs::binary_config_value_@<ax>(
        unsigned __int16 lua_type@<ax>)
{
  unsigned __int16 result; // ax

  switch ( lua_type )
  {
    case 0u:
      result = vostok::render::static_type::get_type_id<bool>();
      break;
    case 1u:
      result = vostok::render::static_type::get_type_id<int>();
      break;
    case 2u:
      result = vostok::render::static_type::get_type_id<float>();
      break;
    case 3u:
    case 4u:
      result = 3;
      break;
    case 5u:
      result = vostok::render::static_type::get_type_id<char const *>();
      break;
    case 6u:
      result = vostok::render::static_type::get_type_id<vostok::math::float2>();
      break;
    case 7u:
      result = vostok::render::static_type::get_type_id<vostok::math::float3>();
      break;
    case 8u:
      result = vostok::render::static_type::get_type_id<vostok::math::float4>();
      break;
  }
  return result;
}
