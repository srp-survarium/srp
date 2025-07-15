int __thiscall vostok::particle::particle_system::get_num_total_emitters<vostok::configs::binary_config_value>(
        vostok::particle::particle_system *this,
        vostok::particle::particle_system *lod_config,
        vostok::configs::binary_config_value *a3)
{
  char **pointer; // esi
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  char *v7; // esi
  vostok::configs::binary_config_value *v8; // eax
  const char *v9; // eax
  int v10; // eax
  vostok::configs::binary_config_value config_value; // [esp+10h] [ebp-28h] BYREF
  int default_value; // [esp+28h] [ebp-10h] BYREF
  char **v13; // [esp+2Ch] [ebp-Ch]
  char **i; // [esp+30h] [ebp-8h]
  int v15; // [esp+34h] [ebp-4h]

  if ( !vostok::configs::binary_config_value::value_exists(
          (vostok::configs::binary_config_value *)this,
          (int)a3,
          (unsigned int)"children") )
    return 0;
  v15 = 0;
  qmemcpy(
    (void *)&config_value,
    vostok::configs::binary_config_value::operator[](a3, "children_order"),
    sizeof(config_value));
  pointer = (char **)config_value.data.pointer;
  v13 = (char **)((char *)config_value.data.pointer + 24 * config_value.count);
  while ( pointer != v13 )
  {
    v5 = vostok::configs::binary_config_value::operator[](a3, "children");
    v6 = vostok::configs::binary_config_value::operator[](v5, *pointer);
    if ( vostok::configs::binary_config_value::operator[](v6, "type_index")->data.pointer == (const void *)2 )
      ++v15;
    pointer += 6;
  }
  for ( i = (char **)config_value.data.pointer; i != v13; i += 6 )
  {
    v7 = *i;
    v8 = vostok::configs::binary_config_value::operator[](a3, "children");
    qmemcpy((void *)&config_value, vostok::configs::binary_config_value::operator[](v8, v7), sizeof(config_value));
    default_value = 38;
    v9 = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
           "type_index",
           0,
           &config_value,
           (const vostok::configs::binary_config_value *)&default_value);
    if ( v9 == (const char *)2 )
    {
      v10 = vostok::particle::particle_system::get_num_emitters_in_emitter<vostok::configs::binary_config_value>(
              lod_config,
              &config_value);
    }
    else
    {
      if ( v9 != (const char *)1 )
        continue;
      v10 = vostok::particle::particle_system::get_num_emitters_in_group<vostok::configs::binary_config_value>(
              lod_config,
              &config_value);
    }
    v15 += v10;
  }
  return v15;
}
