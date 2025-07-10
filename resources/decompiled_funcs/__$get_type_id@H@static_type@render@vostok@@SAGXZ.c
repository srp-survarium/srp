unsigned __int16 __cdecl vostok::render::static_type::get_type_id<int>()
{
  unsigned __int16 result; // ax

  if ( (`vostok::render::static_type::get_type_id<int>'::`2'::`local static guard' & 1) != 0 )
    return `vostok::render::static_type::get_type_id<int>'::`2'::current_id;
  `vostok::render::static_type::get_type_id<int>'::`2'::`local static guard' |= 1u;
  result = vostok::render::static_type::type_id_counter + 1;
  vostok::render::static_type::type_id_counter = result;
  `vostok::render::static_type::get_type_id<int>'::`2'::current_id = result;
  return result;
}
