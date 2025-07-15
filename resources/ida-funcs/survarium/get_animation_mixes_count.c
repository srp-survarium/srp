stlp_std::pair<unsigned int,unsigned int> *__usercall survarium::get_animation_mixes_count@<eax>(
        const vostok::configs::binary_config_value *groups_config@<eax>,
        _DWORD *a2@<esi>)
{
  vostok::configs::binary_config_value *pointer; // edi
  vostok::configs::binary_config_value *v3; // ebp
  const void *v4; // ebx
  int v5; // ecx

  pointer = (vostok::configs::binary_config_value *)groups_config->data.pointer;
  v3 = (vostok::configs::binary_config_value *)((char *)groups_config->data.pointer + 24 * groups_config->count);
  *a2 = 0;
  for ( a2[1] = 0; pointer != v3; ++pointer )
  {
    v4 = vostok::configs::binary_config_value::operator[](pointer, "intervals_count")->data.pointer;
    if ( vostok::configs::binary_config_value::value_exists(pointer, "mixable") )
    {
      v5 = 24 * vostok::configs::binary_config_value::operator[](pointer, "mixable")->count;
      *a2 += v5 / 24;
      a2[1] += v5 / 24 * ((_DWORD)v4 + 1);
    }
  }
  return (stlp_std::pair<unsigned int,unsigned int> *)a2;
}
