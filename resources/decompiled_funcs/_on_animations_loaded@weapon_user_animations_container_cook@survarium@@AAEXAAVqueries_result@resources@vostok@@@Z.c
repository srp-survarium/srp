void __thiscall survarium::weapon_user_animations_container_cook::on_animations_loaded(
        survarium::weapon_user_animations_container_cook *this,
        vostok::resources::queries_result *data)
{
  survarium::game_camera *v2; // ecx
  vostok::resources::queries_result *v3; // ecx
  vostok::resources::query_result_for_cook *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // eax
  survarium::weapon_user_animations_container *v6; // eax
  survarium::game_camera *v7; // ecx
  vostok::resources::memory_usage_type *v8; // eax
  vostok::resources::unmanaged_resource *v9; // ecx
  vostok::resources::queries_result *v10; // ecx
  vostok::resources::query_result_for_cook *parent_query; // eax
  vostok::resources::queries_result *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v14; // [esp-4h] [ebp-88h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+0h] [ebp-84h]
  survarium::weapon_user_animations_container *v16; // [esp+4h] [ebp-80h]
  survarium::weapon_user_animations_container_cook *thisa; // [esp+8h] [ebp-7Ch]
  void *_Where; // [esp+5Ch] [ebp-28h]
  vostok::memory::doug_lea_allocator *v19; // [esp+60h] [ebp-24h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v20; // [esp+68h] [ebp-1Ch] BYREF
  char v21; // [esp+73h] [ebp-11h]
  survarium::weapon_user_animations_container *v22; // [esp+74h] [ebp-10h]
  char v23; // [esp+7Bh] [ebp-9h]
  unsigned int resource_index; // [esp+7Ch] [ebp-8h] BYREF
  survarium::weapon_user_animations_container *container; // [esp+80h] [ebp-4h]

  thisa = this;
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    survarium::weapon_user_dead_state::finalize(v2);
    v19 = v5;
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x858u);
    v22 = (survarium::weapon_user_animations_container *)operator new(0x858u, _Where);
    if ( v22 )
    {
      survarium::weapon_user_animations_container::weapon_user_animations_container(v22);
      v16 = v6;
    }
    else
    {
      v16 = 0;
    }
    container = v16;
    resource_index = 0;
    survarium::get_animations_from_request_results_27_(data, 0x1Bu, &resource_index, v16->m_stand_animations);
    survarium::get_animations_from_request_results_27_(
      data,
      0x1Bu,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[27])container->m_stand_animations[1]);
    survarium::get_animations_from_request_results_6_(
      data,
      6u,
      &resource_index,
      container->m_stand_hands_only_animations);
    survarium::get_animations_from_request_results_6_(
      data,
      6u,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[6])container->m_stand_hands_only_animations[1]);
    survarium::get_animations_from_request_results_27_(
      data,
      0x1Bu,
      &resource_index,
      container->m_aimed_stand_animations);
    survarium::get_animations_from_request_results_27_(
      data,
      0x1Bu,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[27])container->m_aimed_stand_animations[1]);
    survarium::get_animations_from_request_results_6_(
      data,
      6u,
      &resource_index,
      container->m_aimed_stand_hands_only_animations);
    survarium::get_animations_from_request_results_6_(
      data,
      6u,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[6])container->m_aimed_stand_hands_only_animations[1]);
    survarium::get_animations_from_request_results_27_(data, 0x1Bu, &resource_index, container->m_crouch_animations);
    survarium::get_animations_from_request_results_27_(
      data,
      0x1Bu,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[27])container->m_crouch_animations[1]);
    survarium::get_animations_from_request_results_6_(
      data,
      6u,
      &resource_index,
      container->m_crouch_hands_only_animations);
    survarium::get_animations_from_request_results_6_(
      data,
      6u,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[6])container->m_crouch_hands_only_animations[1]);
    survarium::get_animations_from_request_results_27_(
      data,
      0x1Bu,
      &resource_index,
      container->m_aimed_crouch_animations);
    survarium::get_animations_from_request_results_27_(
      data,
      0x1Bu,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[27])container->m_aimed_crouch_animations[1]);
    survarium::get_animations_from_request_results_6_(
      data,
      6u,
      &resource_index,
      container->m_aimed_crouch_hands_only_animations);
    survarium::get_animations_from_request_results_6_(
      data,
      6u,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[6])container->m_aimed_crouch_hands_only_animations[1]);
    survarium::get_animations_from_request_results_2_(data, 2u, &resource_index, container->m_sprint_animations);
    survarium::get_animations_from_request_results_2_(
      data,
      2u,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[2])container->m_sprint_animations[1]);
    survarium::get_animations_from_request_results_100_(data, 0x64u, &resource_index, container->m_jump_animations);
    survarium::get_animations_from_request_results_100_(
      data,
      0x64u,
      &resource_index,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[100])container->m_jump_animations[1]);
    v21 = 0;
    survarium::weapon_user_dead_state::finalize(v7);
    vostok::resources::memory_usage_type::memory_usage_type(
      (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
      &v20,
      (vostok::network_core::packet_reader *)0x858,
      (vostok::network_core::packet_reader *)memory_usage);
    memory_usage = v8;
    v14.m_object = v9;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v14,
      (vostok::configs::binary_config *)container);
    parent_query = vostok::resources::queries_result::get_parent_query(v10, (int)data);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent_query, v14);
    v14.m_object = (vostok::resources::unmanaged_resource *)1;
    v13 = vostok::resources::queries_result::get_parent_query(v12, (int)data);
    vostok::resources::query_result_for_cook::finish_query(v13, result_success, (assert_on_fail_bool)v14.m_object);
  }
  else
  {
    v23 = 0;
    survarium::weapon_user_dead_state::finalize(v2);
    v4 = vostok::resources::queries_result::get_parent_query(v3, (int)data);
    vostok::resources::query_result_for_cook::finish_query(v4, result_error, assert_on_fail_true);
  }
}
