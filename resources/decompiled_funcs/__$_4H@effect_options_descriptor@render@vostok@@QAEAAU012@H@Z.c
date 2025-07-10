vostok::render::effect_options_descriptor *__usercall vostok::render::effect_options_descriptor::operator=<int>@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        vostok::render::effect_options_descriptor *result@<eax>)
{
  result->data = 0;
  result->data = (unsigned __int8 *)1;
  result->count = 4;
  if ( (`vostok::render::static_type::get_type_id<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<int>'::`2'::`local static guard' |= 1u;
    `vostok::render::static_type::get_type_id<int>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
  }
  result->type = `vostok::render::static_type::get_type_id<int>'::`2'::current_id;
  if ( result != (vostok::render::effect_options_descriptor *)-4 )
    result->destroyer = &stru_965008.m_surface;
  return result;
}
