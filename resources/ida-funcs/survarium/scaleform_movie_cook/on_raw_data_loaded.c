void __thiscall survarium::scaleform_movie_cook::on_raw_data_loaded(
        survarium::scaleform_movie_cook *this,
        vostok::resources::queries_result *data,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent)
{
  vostok::resources::managed_resource *v3; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::resources::unmanaged_resource *v9; // ecx
  survarium::pure_game_effect_emitter_base *v10; // esi
  vostok::fs_new::virtual_path_string *v11; // eax
  survarium::flash_factory *v12; // ecx
  survarium::flash_movie *v13; // eax
  survarium::pure_game_effect_emitter_base *v14; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v15; // edi
  vostok::resources::query_result_for_cook *v16; // ecx
  vostok::resources::query_result_for_cook *v17; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v18; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp-Ch] [ebp-13Ch] BYREF
  const vostok::resources::memory_type *v20; // [esp-8h] [ebp-138h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v21[4]; // [esp-4h] [ebp-134h] BYREF
  vostok::fs_new::virtual_path_string v22; // [esp+Ch] [ebp-124h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+120h] [ebp-10h] BYREF
  void *raw_data; // [esp+124h] [ebp-Ch]
  unsigned int raw_data_size; // [esp+128h] [ebp-8h]
  survarium::scaleform_movie_cook *v26; // [esp+12Ch] [ebp-4h]

  v26 = this;
  vostok::resources::query_result_for_user::get_managed_resource(
    &data->m_queries[0],
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
  v21[0].m_object = v3;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    v21,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v4,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
    v21[0]);
  v5 = survarium::g_allocator;
  v6 = type_info::raw_name(&survarium::flash_movie_resource `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(
         v7,
         (int)v5,
         0x110u,
         v6,
         (const char *const)v21[1].m_object,
         (const char *const)v21[2].m_object,
         (const unsigned int)v21[3].m_object);
  v10 = (survarium::pure_game_effect_emitter_base *)v8;
  if ( v8 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(v9, v8, fs_iterator_class);
    v10->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&survarium::flash_movie_resource::`vftable';
  }
  else
  {
    v10 = 0;
  }
  v11 = vostok::resources::resource_base::reusable_request_name(v9, (int)data, &v22);
  v13 = survarium::flash_factory::build_movie(
          v12,
          &v26->m_factory->m_gfx_loader,
          raw_data,
          raw_data_size,
          v11->m_string.m_begin);
  v21[0].m_object = (vostok::resources::managed_resource *)272;
  v20 = &vostok::resources::nocache_memory;
  v19.m_object = v14;
  v10[1].__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)v13;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v19,
    v10);
  v15 = parent;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v16,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v19.m_object,
    v20,
    (unsigned int)v21[0].m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v17,
    v15,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v18);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
}
