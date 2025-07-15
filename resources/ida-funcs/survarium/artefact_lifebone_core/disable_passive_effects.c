void __thiscall survarium::artefact_lifebone_core::disable_passive_effects(survarium::artefact_lifebone_core *this)
{
  int m_first; // ecx
  int v3; // ebx
  survarium::body_part_regeneration_modifier *v4; // edi
  survarium::body_part_parameters *body_part; // eax
  vostok::intrusive_list<survarium::body_part_regeneration_modifier,survarium::body_part_regeneration_modifier *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy> *p_m_regeneration_modifiers; // eax
  survarium::damage_model *v7; // edx
  unsigned int v8; // edi
  survarium::damage_model *m_object; // [esp+8h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  m_object = this->m_inventory->m_holder->damage_model(this->m_inventory->m_holder)->m_object;
  m_first = 52;
  v3 = 0;
  if ( this->m_config.passive.regeneration_modifiers._M_impl._M_finish
     - this->m_config.passive.regeneration_modifiers._M_impl._M_start )
  {
    v11 = 0;
    v10 = this->m_config.passive.regeneration_modifiers._M_impl._M_finish
        - this->m_config.passive.regeneration_modifiers._M_impl._M_start;
    do
    {
      v4 = &this->m_regeneration_modifier_subscribers[v11];
      body_part = survarium::damage_model::get_body_part(
                    (survarium::damage_model *)m_first,
                    (int)m_object,
                    this->m_config.passive.regeneration_modifiers._M_impl._M_start[v3].body_part.m_begin);
      m_first = (int)body_part->m_regeneration_modifiers.m_first;
      p_m_regeneration_modifiers = &body_part->m_regeneration_modifiers;
      if ( m_first )
      {
        v7 = 0;
        while ( (survarium::body_part_regeneration_modifier *)m_first != v4 )
        {
          v7 = (survarium::damage_model *)m_first;
          m_first = *(_DWORD *)(m_first + 32);
          if ( !m_first )
          {
            if ( v4 )
              goto LABEL_15;
            break;
          }
        }
        v8 = *(_DWORD *)(m_first + 32);
        if ( v7 )
          v7->m_uid = v8;
        else
          p_m_regeneration_modifiers->m_first = (survarium::body_part_regeneration_modifier *)v8;
        if ( !*(_DWORD *)(m_first + 32) )
        {
          m_first = (int)v7;
          if ( !v7 )
            m_first = (int)p_m_regeneration_modifiers->m_first;
          p_m_regeneration_modifiers->m_last = (survarium::body_part_regeneration_modifier *)m_first;
        }
      }
LABEL_15:
      ++v11;
      ++v3;
      --v10;
    }
    while ( v10 );
  }
}
