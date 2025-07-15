void __thiscall survarium::artefact_lifebone_core::enable_passive_effects(survarium::artefact_lifebone_core *this)
{
  int m_last; // ecx
  int v3; // ebx
  survarium::body_part_regeneration_modifier *v4; // esi
  survarium::body_part_parameters *body_part; // eax
  vostok::intrusive_list<survarium::body_part_regeneration_modifier,survarium::body_part_regeneration_modifier *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy> *p_m_regeneration_modifiers; // eax
  bool v7; // zf
  survarium::damage_model *m_object; // [esp+8h] [ebp-Ch]
  int v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  m_object = this->m_inventory->m_holder->damage_model(this->m_inventory->m_holder)->m_object;
  m_last = 52;
  v3 = 0;
  if ( this->m_config.passive.regeneration_modifiers._M_impl._M_finish
     - this->m_config.passive.regeneration_modifiers._M_impl._M_start )
  {
    v10 = 0;
    v9 = this->m_config.passive.regeneration_modifiers._M_impl._M_finish
       - this->m_config.passive.regeneration_modifiers._M_impl._M_start;
    do
    {
      v4 = &this->m_regeneration_modifier_subscribers[v10];
      body_part = survarium::damage_model::get_body_part(
                    (survarium::damage_model *)m_last,
                    (int)m_object,
                    this->m_config.passive.regeneration_modifiers._M_impl._M_start[v3].body_part.m_begin);
      v4->next = 0;
      p_m_regeneration_modifiers = &body_part->m_regeneration_modifiers;
      if ( p_m_regeneration_modifiers->m_first )
      {
        m_last = (int)p_m_regeneration_modifiers->m_last;
        *(_DWORD *)(m_last + 32) = v4;
      }
      else
      {
        p_m_regeneration_modifiers->m_first = v4;
      }
      ++v10;
      ++v3;
      v7 = v9-- == 1;
      p_m_regeneration_modifiers->m_last = v4;
    }
    while ( !v7 );
  }
}
