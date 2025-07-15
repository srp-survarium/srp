void __thiscall survarium::player_creation_params::load(
        survarium::player_creation_params *this,
        const vostok::configs::binary_config_value *root,
        vostok::configs::binary_config_value *a3)
{
  const vostok::configs::binary_config_value *v3; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v5; // eax
  float v6; // xmm0_4
  vostok::configs::binary_config_value v7; // [esp+10h] [ebp-18h] BYREF

  survarium::base_player_creation_params::base_load(this, root, a3);
  qmemcpy((void *)&v7, vostok::configs::binary_config_value::operator[](a3, "fall_params"), sizeof(v7));
  v3 = vostok::configs::binary_config_value::operator[](&v7, "noiseless_height");
  if ( v3->type == 2 )
    pointer = *(float *)&v3->data.pointer;
  else
    pointer = (float)(int)v3->data.pointer;
  *(float *)&root[24].type = fsqrt((float)(*((float *)&root[17].id.max_storage + 1) * pointer) * 2.0);
  v5 = vostok::configs::binary_config_value::operator[](&v7, "soft_landing_height");
  if ( v5->type == 2 )
    v6 = *(float *)&v5->data.pointer;
  else
    v6 = (float)(int)v5->data.pointer;
  *(float *)&root[25].data.pointer = fsqrt((float)(*((float *)&root[17].id.max_storage + 1) * v6) * 2.0);
  WORD2(root[25].data.max_storage) = vostok::configs::binary_config_value::operator[](
                                       a3,
                                       "min_toxic_damage_sounds_interval")->data.pointer;
  HIWORD(root[25].data.max_storage) = vostok::configs::binary_config_value::operator[](
                                        a3,
                                        "max_toxic_damage_sounds_interval")->data.pointer;
}
