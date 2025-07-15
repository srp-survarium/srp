void __thiscall survarium::victory_items_container_core::load(
        survarium::victory_items_container_core *this,
        vostok::configs::binary_config_value *cfg)
{
  const vostok::configs::binary_config_value *v2; // eax
  vostok::configs::binary_config_value *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // ecx

  survarium::usable_object::load(this, cfg);
  v2 = vostok::configs::binary_config_value::operator[](cfg, "team");
  this->m_owner_team = vostok::configs::binary_config_value::operator unsigned char(v3, (int)v2);
  v4 = vostok::configs::binary_config_value::operator[](cfg, "id");
  this->m_container_id = vostok::configs::binary_config_value::operator unsigned char(v5, (int)v4);
}
