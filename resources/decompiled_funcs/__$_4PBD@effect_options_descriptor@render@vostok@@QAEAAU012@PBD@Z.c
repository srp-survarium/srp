vostok::render::effect_options_descriptor *__usercall vostok::render::effect_options_descriptor::operator=<char const *>@<eax>(
        vostok::render::effect_options_descriptor *this@<esi>,
        char *value@<edx>)
{
  const char *v2; // eax
  unsigned __int8 *data; // ecx

  v2 = &value[strlen(value) + 1];
  data = this->data;
  LOWORD(v2) = (_WORD)v2 - (_WORD)value;
  this->count = (unsigned __int16)v2;
  memcpy(data, (unsigned __int8 *)value, (unsigned __int16)v2);
  if ( this->type == 3 )
    this->bytes += this->count;
  if ( (`vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' & 1) != 0 )
  {
    this->type = (unsigned __int16)`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id;
  }
  else
  {
    `vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' |= 1u;
    LOWORD(`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
    this->type = vostok::render::static_type::type_id_counter;
  }
  return this;
}
