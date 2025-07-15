void __thiscall survarium::artefact_onyx_core::disable_passive_effects(survarium::artefact_onyx_core *this)
{
  int *v2; // ebx
  int v3; // ecx
  int v4; // edi
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  v2 = (int *)this->m_inventory->m_holder->damage_model(this->m_inventory->m_holder);
  v3 = 112;
  v4 = 0;
  if ( this->m_damage_protectors.m_end - this->m_damage_protectors.m_begin )
  {
    v6 = 0;
    v5 = this->m_damage_protectors.m_end - this->m_damage_protectors.m_begin;
    do
    {
      survarium::damage_model::unregister_body_part_damage_protector(
        (survarium::damage_model *)v3,
        *v2,
        this->m_config.protected_body_parts.m_begin[v4++].m_begin,
        &this->m_damage_protectors.m_begin[v6++]);
      --v5;
    }
    while ( v5 );
  }
}
