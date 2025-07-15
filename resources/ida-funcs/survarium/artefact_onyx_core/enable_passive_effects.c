void __thiscall survarium::artefact_onyx_core::enable_passive_effects(survarium::artefact_onyx_core *this)
{
  int v2; // ecx
  int v3; // ebx
  int v4; // ebp
  int v5; // [esp+4h] [ebp-8h]
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v6; // [esp+8h] [ebp-4h]

  v6 = this->m_inventory->m_holder->damage_model(this->m_inventory->m_holder);
  v2 = 112;
  if ( this->m_damage_protectors.m_end - this->m_damage_protectors.m_begin )
  {
    v3 = 0;
    v4 = 0;
    v5 = this->m_damage_protectors.m_end - this->m_damage_protectors.m_begin;
    do
    {
      survarium::damage_model::register_body_part_damage_protector(
        v6->m_object,
        &this->m_damage_protectors.m_begin[v4++],
        (survarium::damage_model *)v2,
        this->m_config.protected_body_parts.m_begin[v3++].m_begin);
      --v5;
    }
    while ( v5 );
  }
}
