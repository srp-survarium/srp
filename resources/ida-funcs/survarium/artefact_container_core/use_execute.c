char __userpurge survarium::artefact_container_core::use_execute@<al>(
        survarium::artefact_container_core *this@<ecx>,
        float a2@<xmm0>,
        survarium::usable_object_user_data *user)
{
  unsigned int v3; // ebx
  survarium::base_player *v5; // eax
  float v6; // xmm0_4
  unsigned int v7; // eax
  survarium::inventory_holder *v8; // eax
  survarium::artefact_container_core *v9; // ecx
  survarium::statistics_events_handler *m_statistics_events_handler; // esi
  survarium::statistics_events_handler_vtbl *v11; // ebx
  survarium::base_player *v12; // eax
  float m_artefact_search_time_ms; // [esp+0h] [ebp-14h]
  float v15; // [esp+4h] [ebp-10h]

  v3 = user->current_time_ms - user->start_using_time_ms;
  v5 = user->owner->cast_to_base_player(user->owner);
  m_artefact_search_time_ms = (float)this->m_artefact_search_time_ms;
  v6 = survarium::player_params_modifiers_container::apply_modifier(
         (survarium::player_params_modifiers_container *)&(*(survarium::base_player_vtbl **)((char *)&v5->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                                                           + (_DWORD)&loc_11066
                                                                                           + 2))[7],
         artefact_search_time_modifier,
         a2,
         m_artefact_search_time_ms,
         1.0);
  v7 = vostok::math::ceil(v6);
  if ( v3 < v7 )
  {
    v15 = (double)v3 / (double)v7 * s_spot_max_distance;
    user->current_progress = vostok::math::floor(v15);
    return 1;
  }
  else
  {
    user->current_progress = -1;
    this->on_artefact_search_complete(this, user->owner);
    v8 = user->owner->cast_to_inventory_holder(user->owner);
    survarium::artefact_container_core::transfer_artefact(v9, (int)this, v8);
    if ( this->m_owner )
      this->m_owner->on_artefact_container_use(this->m_owner, this, user->current_time_ms);
    m_statistics_events_handler = this->m_game_world_core->m_statistics_events_handler;
    if ( m_statistics_events_handler )
    {
      v11 = m_statistics_events_handler->__vftable;
      v12 = user->owner->cast_to_base_player(user->owner);
      v11->on_artefact_took(m_statistics_events_handler, v12->id);
    }
    return 0;
  }
}
