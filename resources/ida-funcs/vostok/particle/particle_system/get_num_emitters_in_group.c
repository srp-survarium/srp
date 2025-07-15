int __thiscall vostok::particle::particle_system::get_num_emitters_in_group<vostok::configs::binary_config_value>(
        vostok::particle::particle_system *this,
        const vostok::configs::binary_config_value *group_config)
{
  const vostok::configs::binary_config_value *v3; // esi
  int *pointer; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  char **v7; // eax
  char *v8; // esi
  vostok::configs::binary_config_value *v9; // eax
  const char *v10; // eax
  int v11; // eax
  vostok::configs::binary_config_value group_configa; // [esp+4h] [ebp-2Ch] BYREF
  const vostok::configs::binary_config_value *v13; // [esp+1Ch] [ebp-14h]
  int v14; // [esp+20h] [ebp-10h] BYREF
  vostok::particle::particle_system *v15; // [esp+24h] [ebp-Ch]
  int *v16; // [esp+28h] [ebp-8h]
  int v17; // [esp+2Ch] [ebp-4h]

  v15 = this;
  if ( !vostok::configs::binary_config_value::value_exists(
          (vostok::configs::binary_config_value *)this,
          (int)group_config,
          (unsigned int)"children") )
    return 0;
  v17 = 0;
  v3 = vostok::configs::binary_config_value::operator[](group_config, "children_order");
  pointer = (int *)v3->data.pointer;
  v13 = v3;
  v16 = pointer;
  while ( pointer != (int *)v3->data.pointer + 6 * v3->count )
  {
    v14 = *pointer;
    v5 = vostok::configs::binary_config_value::operator[](group_config, "children");
    v6 = vostok::configs::binary_config_value::operator[](v5, (char *)v14);
    if ( vostok::configs::binary_config_value::operator[](v6, "type_index")->data.pointer == (const void *)2 )
      ++v17;
    v16 += 6;
    pointer = v16;
  }
  v7 = (char **)v3->data.pointer;
  v16 = (int *)v3->data.pointer;
  while ( v7 != (char **)v3->data.pointer + 6 * v3->count )
  {
    v8 = *v7;
    v9 = vostok::configs::binary_config_value::operator[](group_config, "children");
    qmemcpy((void *)&group_configa, vostok::configs::binary_config_value::operator[](v9, v8), sizeof(group_configa));
    v14 = 38;
    v10 = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
            "type_index",
            0,
            &group_configa,
            (const vostok::configs::binary_config_value *)&v14);
    if ( v10 == (const char *)2 )
    {
      v11 = vostok::particle::particle_system::get_num_emitters_in_emitter<vostok::configs::binary_config_value>(
              v15,
              &group_configa);
    }
    else
    {
      if ( v10 != (const char *)1 )
        goto LABEL_15;
      v11 = vostok::particle::particle_system::get_num_emitters_in_group<vostok::configs::binary_config_value>(
              v15,
              &group_configa);
    }
    v17 += v11;
LABEL_15:
    v16 += 6;
    v3 = v13;
    v7 = (char **)v16;
  }
  return v17;
}
