void __thiscall vostok::particle::particle_system_wrapper_cook::on_resource_ready(
        vostok::particle::particle_system_wrapper_cook *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result *v2; // eax
  vostok::resources::query_result_for_user *v3; // ecx
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // ecx
  vostok::resources::cook_base *v5; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  const vostok::variant<32> **v9; // eax
  vostok::resources::resource_base *v10; // ecx
  vostok::resources::unmanaged_resource *v11; // ecx
  vostok::resources::query_result *v12; // eax
  vostok::resources::query_result_for_user *v13; // ecx
  vostok::resources::query_result_for_user::error_type_enum error_type; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v15[2]; // [esp-4h] [ebp-20h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-18h]
  vostok::particle::particle_system_wrapper_cook *thisa; // [esp+8h] [ebp-14h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> resource; // [esp+14h] [ebp-8h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+18h] [ebp-4h]

  thisa = this;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)result);
  v2 = vostok::resources::queries_result::operator[](result, 0);
  vostok::resources::query_result_for_user::get_unmanaged_resource(
    v3,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v2,
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource);
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
         v4,
         &resource) )
  {
    v15[0].m_object = (vostok::resources::unmanaged_resource *)vostok::resources::cook_base::allocate_thread_id(
                                                                 v5,
                                                                 (int)thisa);
    v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)&resource);
    vostok::resources::unmanaged_resource::set_deleter_object(
      (vostok::resources::unmanaged_resource *)thisa,
      v7,
      (vostok::resources::cook_base *)v15[0].m_object,
      (unsigned int)v15[1].m_object);
    v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v8, (int)&resource);
    memory_usage = (vostok::resources::memory_usage_type *)vostok::resources::resource_base::memory_usage(v10, (int)v9);
    v15[0].m_object = v11;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
      v15,
      &resource);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v15[0]);
  }
  v15[0].m_object = (vostok::resources::unmanaged_resource *)vostok::resources::queries_result::assert_on_fail(
                                                               (vostok::resources::queries_result *)v5,
                                                               (int)result);
  v12 = vostok::resources::queries_result::operator[](result, 0);
  error_type = vostok::resources::query_result_for_user::get_error_type(v13, (int)v12);
  vostok::resources::query_result_for_cook::finish_query(parent, error_type, (assert_on_fail_bool)v15[0].m_object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&resource);
}
