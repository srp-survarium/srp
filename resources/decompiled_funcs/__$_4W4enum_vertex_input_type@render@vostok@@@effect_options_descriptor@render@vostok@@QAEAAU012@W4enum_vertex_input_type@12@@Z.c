vostok::render::effect_options_descriptor *__usercall vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        vostok::render::effect_options_descriptor *result@<eax>)
{
  result->data = 0;
  result->data = (unsigned __int8 *)this;
  result->count = 4;
  if ( (`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard' |= 1u;
    LOWORD(`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
  }
  result->type = (unsigned __int16)`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id;
  if ( result != (vostok::render::effect_options_descriptor *)-4 )
    result->destroyer = &vostok::render::destroy_data_helper<enum vostok::render::enum_vertex_input_type const>::`vftable';
  return result;
}
