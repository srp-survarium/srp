BOOL __thiscall survarium::artefact_container_core::can_use(
        survarium::artefact_container_core *this,
        const survarium::usable_object_user_data *user)
{
  survarium::base_player *v3; // eax
  survarium::artefact_base *m_object; // esi
  survarium::inventory *v5; // eax
  BOOL result; // eax

  v3 = user->owner->cast_to_base_player(user->owner);
  result = 0;
  if ( !this->m_usable_object_users.m_first )
  {
    m_object = this->m_artefact.m_object;
    if ( m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( m_object->m_state == artefact_state_spawned )
        {
          v5 = v3->m_inventory.m_object;
          if ( v5->m_artefact_slots_count )
          {
            if ( !v5->m_carried_item )
              return 1;
          }
        }
      }
    }
  }
  return result;
}
