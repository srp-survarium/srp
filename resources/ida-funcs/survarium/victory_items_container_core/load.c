void __thiscall survarium::victory_items_container_core::load(
        survarium::victory_items_container_core *this,
        const vostok::configs::binary_config_value *cfg)
{
  survarium::usable_object::load(this, cfg);
  this->m_owner_team = LOBYTE(vostok::configs::binary_config_value::operator[](cfg, "team")->data.max_storage);
  this->m_id = (unsigned __int8)vostok::configs::binary_config_value::operator[](cfg, "id")->data.pointer;
}
