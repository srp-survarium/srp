unsigned int __thiscall vostok::render::effect_options_descriptor::get_num_used_bytes(
        vostok::render::effect_options_descriptor *this)
{
  unsigned int bytes; // ebp
  unsigned __int8 *data; // esi
  unsigned int i; // edi

  bytes = this->bytes;
  if ( this->type != 3 )
    return this->bytes;
  data = this->data;
  for ( i = 0;
        i < this->count;
        data += vostok::render::effect_options_descriptor::get_num_used_bytes((vostok::render::effect_options_descriptor *)data) )
  {
    bytes += vostok::render::effect_options_descriptor::get_num_used_bytes((vostok::render::effect_options_descriptor *)data);
    ++i;
  }
  return bytes;
}
