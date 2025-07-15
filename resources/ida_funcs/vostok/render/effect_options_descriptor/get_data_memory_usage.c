unsigned int __thiscall vostok::render::effect_options_descriptor::get_data_memory_usage(
        vostok::render::effect_options_descriptor *this,
        unsigned int *need_bytes_to_align4,
        unsigned int *last_align_value)
{
  unsigned int v4; // ebx
  unsigned __int8 *data; // esi
  unsigned int i; // edi
  unsigned __int16 count; // ax
  int v9; // eax

  v4 = 0;
  if ( this->id )
    v4 = strlen(this->id) + 1;
  if ( this->type == 3 )
  {
    data = this->data;
    for ( i = 0; i < this->count; ++i )
    {
      v4 += vostok::render::effect_options_descriptor::get_data_memory_usage(
              (vostok::render::effect_options_descriptor *)data,
              need_bytes_to_align4,
              last_align_value);
      data += vostok::render::effect_options_descriptor::get_num_used_bytes((vostok::render::effect_options_descriptor *)data);
    }
    return v4;
  }
  count = this->count;
  if ( count > 4u )
    v4 += count;
  if ( (v4 & 3) == 0 )
    return v4;
  v9 = 4 - (v4 & 3);
  *last_align_value = v9;
  *need_bytes_to_align4 += v9;
  return v4;
}
