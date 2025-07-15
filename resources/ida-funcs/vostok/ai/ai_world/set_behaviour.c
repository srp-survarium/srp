void __thiscall vostok::ai::ai_world::set_behaviour(
        vostok::ai::ai_world *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> new_behaviour,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> brain)
{
  survarium::game_camera *v3; // ecx
  survarium::weapon_user_animations_container *v4; // [esp+Ch] [ebp-18h]
  survarium::weapon_user_animations_container *object; // [esp+14h] [ebp-10h]
  vostok::resources::resource_ptr<vostok::ai::brain_unit,vostok::resources::unmanaged_intrusive_base> brain_unit; // [esp+1Ch] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base> behaviour_to_set; // [esp+20h] [ebp-4h] BYREF

  object = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain);
  brain_unit.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain_unit,
    object);
  v4 = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&new_behaviour);
  behaviour_to_set.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&behaviour_to_set,
    v4);
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::ai::brain_unit::set_behaviour(brain_unit.m_object, &behaviour_to_set);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&behaviour_to_set);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain_unit);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&new_behaviour);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&brain);
}
