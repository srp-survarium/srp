void __thiscall survarium::player::on_before_active_object_changed(
        survarium::player *this,
        const vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base> *current_active_object,
        const vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base> *target_active_object)
{
  if ( current_active_object->m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    current_active_object->m_object->assign_game_ui(current_active_object->m_object, 0);
  }
  if ( target_active_object->m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      target_active_object->m_object->assign_game_ui(
        target_active_object->m_object,
        *(survarium::game_world_ui **)((char *)&dword_10F7C + (_DWORD)this));
  }
}
