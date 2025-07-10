int __usercall survarium::get_animation_vertices_count@<eax>(
        const vostok::configs::binary_config_value *groups_config@<eax>)
{
  vostok::configs::binary_config_value *pointer; // esi
  char *v2; // edi
  int v3; // ebx
  const vostok::configs::binary_config_value *v4; // eax

  pointer = (vostok::configs::binary_config_value *)groups_config->data.pointer;
  v2 = (char *)groups_config->data.pointer + 24 * groups_config->count;
  v3 = 0;
  if ( groups_config->data.pointer != v2 )
  {
    do
    {
      v4 = vostok::configs::binary_config_value::operator[](pointer++, "vertices");
      v3 += 24 * v4->count / 24;
    }
    while ( pointer != (vostok::configs::binary_config_value *)v2 );
  }
  return v3;
}
