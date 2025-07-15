int __thiscall vostok::render::effect_options_descriptor::get_num_total_fields(
        vostok::render::effect_options_descriptor *this)
{
  int count; // ebp
  unsigned __int8 *data; // esi
  unsigned int i; // edi

  if ( this->type != 3 )
    return 0;
  count = this->count;
  data = this->data;
  for ( i = 0; i < this->count; ++i )
  {
    count += vostok::render::effect_options_descriptor::get_num_total_fields((vostok::render::effect_options_descriptor *)data);
    data += vostok::render::effect_options_descriptor::get_num_used_bytes((vostok::render::effect_options_descriptor *)data);
  }
  return count;
}
