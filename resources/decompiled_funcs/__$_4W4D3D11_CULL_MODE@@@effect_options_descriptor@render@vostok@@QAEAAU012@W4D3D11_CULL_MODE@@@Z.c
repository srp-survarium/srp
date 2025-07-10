vostok::render::effect_options_descriptor *__usercall vostok::render::effect_options_descriptor::operator=<enum D3D11_CULL_MODE>@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        vostok::render::effect_options_descriptor *result@<eax>)
{
  result->data = 0;
  result->data = (unsigned __int8 *)this;
  result->count = 4;
  if ( (`vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' |= 1u;
    `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
  }
  result->type = `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id;
  if ( result != (vostok::render::effect_options_descriptor *)-4 )
    result->destroyer = &vostok::render::destroy_data_helper<enum D3D11_CULL_MODE const>::`vftable';
  return result;
}
