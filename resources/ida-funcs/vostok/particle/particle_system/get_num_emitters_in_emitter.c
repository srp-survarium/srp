int __thiscall vostok::particle::particle_system::get_num_emitters_in_emitter<vostok::configs::binary_config_value>(
        vostok::particle::particle_system *this,
        const vostok::configs::binary_config_value *emitter_config)
{
  const vostok::configs::binary_config_value *v3; // eax
  char **pointer; // ebx
  char *v5; // esi
  vostok::configs::binary_config_value *v6; // eax
  int v7; // eax
  vostok::particle::particle_system *v8; // [esp-10h] [ebp-38h]
  vostok::configs::binary_config_value v9; // [esp+0h] [ebp-28h] BYREF
  const vostok::configs::binary_config_value *v10; // [esp+18h] [ebp-10h]
  vostok::particle::particle_system *v11; // [esp+1Ch] [ebp-Ch]
  int v12; // [esp+20h] [ebp-8h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  v11 = this;
  if ( !vostok::configs::binary_config_value::value_exists(
          (vostok::configs::binary_config_value *)this,
          (int)emitter_config,
          (unsigned int)"children") )
    return 0;
  v13 = 0;
  v3 = vostok::configs::binary_config_value::operator[](emitter_config, "children_order");
  pointer = (char **)v3->data.pointer;
  v10 = v3;
  while ( pointer != (char **)v3->data.pointer + 6 * v3->count )
  {
    v5 = *pointer;
    v6 = vostok::configs::binary_config_value::operator[](emitter_config, "children");
    qmemcpy((void *)&v9, vostok::configs::binary_config_value::operator[](v6, v5), sizeof(v9));
    v12 = 38;
    if ( (unsigned int)(vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                          "type_index",
                          0,
                          &v9,
                          (const vostok::configs::binary_config_value *)&v12)
                      - 25) <= 3 )
    {
      v7 = vostok::particle::particle_system::get_num_total_emitters<vostok::configs::binary_config_value>(v8, v11, &v9);
      v13 += v7;
    }
    v3 = v10;
    pointer += 6;
  }
  return v13;
}
