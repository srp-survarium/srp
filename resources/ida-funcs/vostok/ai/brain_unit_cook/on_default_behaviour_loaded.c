void __thiscall vostok::ai::brain_unit_cook::on_default_behaviour_loaded(
        vostok::ai::brain_unit_cook *this,
        vostok::resources::queries_result *data,
        vostok::ai::brain_unit *const new_brain)
{
  survarium::game_camera *v3; // ecx
  vostok::resources::query_result *v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  vostok::resources::memory_usage_type *v6; // eax
  vostok::resources::unmanaged_resource *v7; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v8[2]; // [esp-4h] [ebp-3Ch] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-34h]
  vostok::ai::brain_unit_cook *thisa; // [esp+8h] [ebp-30h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // [esp+10h] [ebp-28h]
  survarium::weapon_user_animations_container *object; // [esp+14h] [ebp-24h]
  survarium::weapon_user_animations_container *v13; // [esp+18h] [ebp-20h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v14; // [esp+20h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v15; // [esp+28h] [ebp-10h] BYREF
  char v16; // [esp+2Fh] [ebp-9h]
  vostok::resources::query_result_for_cook *parent; // [esp+30h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base> default_behaviour_ptr; // [esp+34h] [ebp-4h] BYREF

  thisa = this;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v4 = vostok::resources::queries_result::operator[](data, 0);
    unmanaged_resource = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v5, (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v4, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15);
    v13 = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(unmanaged_resource);
    object = v13;
    default_behaviour_ptr.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&default_behaviour_ptr,
      v13);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v15);
    vostok::ai::brain_unit::set_behaviour(new_brain, &default_behaviour_ptr);
    vostok::resources::memory_usage_type::memory_usage_type(
      (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
      &v14,
      (vostok::network_core::packet_reader *)0x400,
      (vostok::network_core::packet_reader *)v8[1].m_object);
    memory_usage = v6;
    v8[0].m_object = v7;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      v8,
      (vostok::configs::binary_config *)new_brain);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v8[0]);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&default_behaviour_ptr);
  }
  else
  {
    v16 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
