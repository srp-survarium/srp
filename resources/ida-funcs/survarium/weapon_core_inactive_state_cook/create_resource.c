void __thiscall survarium::weapon_core_inactive_state_cook::create_resource(
        survarium::weapon_core_inactive_state_cook *this,
        vostok::resources::query_result_for_cook *parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  const vostok::variant<32> **v4; // eax
  vostok::resources::memory_usage_type *v5; // eax
  vostok::resources::unmanaged_resource *v6; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v7; // [esp-4h] [ebp-34h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+0h] [ebp-30h]
  vostok::resources::unmanaged_resource *object; // [esp+4h] [ebp-2Ch]
  survarium::weapon_core_inactive_state *v10; // [esp+8h] [ebp-28h]
  survarium::weapon_core_inactive_state_cook *thisa; // [esp+Ch] [ebp-24h]
  survarium::weapon_core *weapon; // [esp+14h] [ebp-1Ch]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v13; // [esp+1Ch] [ebp-14h] BYREF
  survarium::weapon_core_base_state *v14; // [esp+24h] [ebp-Ch]
  survarium::weapon_core_inactive_state *object_to_cook; // [esp+28h] [ebp-8h]
  const survarium::weapon_state_creation_params *params; // [esp+2Ch] [ebp-4h]

  thisa = this;
  params = (const survarium::weapon_state_creation_params *)raw_file_data.m_data;
  v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&in_out_unmanaged_resource_buffer);
  v14 = (survarium::weapon_core_base_state *)operator new(0x138u, v4);
  if ( v14 )
  {
    weapon = params->weapon;
    survarium::weapon_core_base_state::weapon_core_base_state(v14, weapon, 0);
    v14->vostok::ai::fsm_state::__vftable = (survarium::weapon_core_base_state_vtbl *)&survarium::weapon_core_inactive_state::`vftable'{for `vostok::ai::fsm_state'};
    v14->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_inactive_state::`vftable'{for `vostok::resources::unmanaged_resource'};
    v14->m_is_ready_to_be_deactivated = 1;
    v10 = (survarium::weapon_core_inactive_state *)v14;
  }
  else
  {
    v10 = 0;
  }
  object_to_cook = v10;
  if ( v10 )
    object = &object_to_cook->vostok::resources::unmanaged_resource;
  else
    object = 0;
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v13,
    (vostok::network_core::packet_reader *)0x138,
    (vostok::network_core::packet_reader *)memory_usage);
  memory_usage = v5;
  v7.m_object = v6;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v7,
    (vostok::configs::binary_config *)object);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(parent, v7, memory_usage);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
}
