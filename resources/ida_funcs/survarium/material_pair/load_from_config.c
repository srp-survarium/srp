void __userpurge survarium::material_pair::load_from_config(
        survarium::material_pair *this@<ecx>,
        float a2@<xmm0>,
        survarium::game_material_manager *manager,
        vostok::configs::binary_config_value *val)
{
  const vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // ecx
  const vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  unsigned __int16 first_mtrl_id; // [esp+44h] [ebp-8h]
  unsigned __int16 second_mtrl_id; // [esp+48h] [ebp-4h]

  v4 = vostok::configs::binary_config_value::operator[](val, "mtrl_1_id");
  first_mtrl_id = vostok::configs::binary_config_value::operator unsigned short(v5, (int)v4);
  v6 = vostok::configs::binary_config_value::operator[](val, "mtrl_2_id");
  second_mtrl_id = vostok::configs::binary_config_value::operator unsigned short(v7, (int)v6);
  vostok::configs::binary_config_value::operator[](val, "decal1_size");
  vostok::configs::binary_config_value::operator float(v8);
  this->m_decal1_size = a2;
  vostok::configs::binary_config_value::operator[](val, "decal2_size");
  vostok::configs::binary_config_value::operator float(v9);
  this->m_decal2_size = a2;
  this->m_first_material = survarium::game_material_manager::get_material(manager, first_mtrl_id);
  this->m_second_material = survarium::game_material_manager::get_material(manager, second_mtrl_id);
}
