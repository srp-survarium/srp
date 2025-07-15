void __thiscall vostok::ai::ai_world::fill_npc_stats(
        vostok::ai::ai_world *this,
        vostok::ai::npc_statistics *stats,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> brain)
{
  survarium::game_camera *v3; // ecx
  vostok::ai::brain_unit *v4; // eax
  char *v5; // [esp+0h] [ebp-B4h]
  char *name_by_id; // [esp+4h] [ebp-B0h]
  char *c_string; // [esp+8h] [ebp-ACh]
  survarium::weapon_user_animations_container *object; // [esp+4Ch] [ebp-68h]
  vostok::ai::npc *npc_object; // [esp+54h] [ebp-60h]
  int aux_id; // [esp+58h] [ebp-5Ch]
  int aux_ida; // [esp+58h] [ebp-5Ch]
  int aux_idb; // [esp+58h] [ebp-5Ch]
  vostok::fixed_string<64> new_item_content; // [esp+5Ch] [ebp-58h] BYREF
  vostok::resources::resource_ptr<vostok::ai::brain_unit,vostok::resources::unmanaged_intrusive_base> brain_unit; // [esp+B0h] [ebp-4h] BYREF

  object = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain);
  brain_unit.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain_unit,
    object);
  survarium::weapon_user_dead_state::finalize(v3);
  npc_object = brain_unit.m_object->m_npc;
  vostok::fixed_string<64>::fixed_string<64>(&new_item_content, "group: ");
  aux_id = npc_object->get_group_id(npc_object);
  if ( aux_id == -1 )
  {
    vostok::buffer_string::append(&new_item_content, "none");
  }
  else
  {
    c_string = vostok::ai::get_name_by_id(&this->m_npc_groups, aux_id);
    vostok::buffer_string::append(&new_item_content, c_string);
  }
  vostok::buffer_vector<vostok::fixed_string<64>>::push_back(&new_item_content, &stats->general_state.content);
  vostok::fs_new::path_string_impl::clear(&new_item_content);
  vostok::buffer_string::append(&new_item_content, "class: ");
  aux_ida = npc_object->get_class_id(npc_object);
  if ( aux_ida == -1 )
  {
    vostok::buffer_string::append(&new_item_content, "none");
  }
  else
  {
    name_by_id = vostok::ai::get_name_by_id(&this->m_npc_classes, aux_ida);
    vostok::buffer_string::append(&new_item_content, name_by_id);
  }
  vostok::buffer_vector<vostok::fixed_string<64>>::push_back(&new_item_content, &stats->general_state.content);
  vostok::fs_new::path_string_impl::clear(&new_item_content);
  vostok::buffer_string::append(&new_item_content, "outfit: ");
  aux_idb = npc_object->get_outfit_id(npc_object);
  if ( aux_idb == -1 )
  {
    vostok::buffer_string::append(&new_item_content, "none");
  }
  else
  {
    v5 = vostok::ai::get_name_by_id(&this->m_npc_outfits, aux_idb);
    vostok::buffer_string::append(&new_item_content, v5);
  }
  vostok::buffer_vector<vostok::fixed_string<64>>::push_back(&new_item_content, &stats->general_state.content);
  v4 = (vostok::ai::brain_unit *)vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->((vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain_unit);
  vostok::ai::brain_unit::retrieve_statistics(v4, stats);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain_unit);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&brain);
}
