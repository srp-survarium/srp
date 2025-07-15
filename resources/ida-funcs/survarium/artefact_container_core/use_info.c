const char *__thiscall survarium::artefact_container_core::use_info(
        survarium::artefact_container_core *this,
        const survarium::usable_object_user_data *user)
{
  const char *result; // eax
  survarium::artefact_base *m_object; // esi

  if ( this->can_use(this, user) )
    return "st_use_artefact_container";
  if ( user->owner->cast_to_base_player(user->owner)->m_inventory.m_object->m_carried_item )
    return uri;
  if ( this->m_usable_object_users.m_first )
    return uri;
  m_object = this->m_artefact.m_object;
  if ( !m_object )
    return uri;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    return uri;
  result = "st_artefact_no_free_slots";
  if ( m_object->m_state != artefact_state_spawned )
    return uri;
  return result;
}
