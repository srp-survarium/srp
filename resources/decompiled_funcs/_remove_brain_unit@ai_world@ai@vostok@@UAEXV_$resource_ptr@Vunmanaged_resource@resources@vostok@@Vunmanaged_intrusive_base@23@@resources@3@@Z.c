void __thiscall vostok::ai::ai_world::remove_brain_unit(
        vostok::ai::ai_world *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> brain)
{
  survarium::game_camera *v2; // ecx
  survarium::weapon_user_animations_container *object; // [esp+2Ch] [ebp-Ch]
  vostok::resources::resource_ptr<vostok::ai::brain_unit,vostok::resources::unmanaged_intrusive_base> brain_unit; // [esp+34h] [ebp-4h] BYREF

  object = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain);
  brain_unit.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain_unit,
    object);
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::ai::brain_unit::clear_resources(brain_unit.m_object);
  vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    &this->m_brain_units,
    brain_unit.m_object);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain_unit);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&brain);
}
