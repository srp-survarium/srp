void __thiscall vostok::render::render_texture_cook::on_texture_loaded(
        vostok::render::render_texture_cook *this,
        survarium::pure_game_effect_emitter_base *data,
        vostok::render::res_texture *texture,
        const vostok::resources::memory_type *num_mips)
{
  vostok::resources::query_result_for_user *m_uid; // ecx
  vostok::render::resource_manager *v6; // esi
  vostok::resources::managed_resource *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  vostok::resources::unmanaged_resource *v12; // ecx
  char *v13; // esi
  unsigned int v14; // eax
  survarium::pure_game_effect_emitter_base *v15; // ecx
  vostok::resources::query_result_for_cook *v16; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v17; // [esp-10h] [ebp-1Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v18; // [esp-Ch] [ebp-18h] BYREF
  assert_on_fail_bool v19; // [esp-8h] [ebp-14h]
  vostok::resources::cook_base::result_enum v20; // [esp-4h] [ebp-10h]
  const char *v21; // [esp+0h] [ebp-Ch]
  const char *v22; // [esp+4h] [ebp-8h]
  unsigned int v23; // [esp+8h] [ebp-4h]
  survarium::pure_game_effect_emitter_base *v24; // [esp+14h] [ebp+8h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *num_last_mips_used; // [esp+1Ch] [ebp+10h]

  if ( data->m_parent_resources.m_lock == 1 )
  {
    m_uid = (vostok::resources::query_result_for_user *)data->m_uid;
    v6 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
    v20 = result_fail;
    v19 = (assert_on_fail_bool)num_mips;
    v18.m_object = (survarium::pure_game_effect_emitter_base *)vostok::resources::query_result_for_user::get_requested_path(m_uid);
    v17.m_object = v7;
    vostok::resources::query_result_for_user::get_managed_resource(
      (vostok::resources::query_result_for_user *)&data->m_parent_resources.m_last,
      &v17);
    vostok::render::resource_manager::on_texture_loaded_res(
      v6,
      v17,
      (const char *)v18.m_object,
      v19,
      (vostok::resources::managed_resource *)v20);
    v8 = vostok::render::g_allocator;
    v9 = type_info::raw_name(&vostok::render::render_texture_resource `RTTI Type Descriptor');
    v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, 0x110u, v9, v21, v22, v23);
    v13 = v11;
    if ( v11 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v12, v11, fs_iterator_class);
      *(_DWORD *)v13 = &vostok::render::render_texture_resource::`vftable';
      *((_DWORD *)v13 + 66) = 0;
      v24 = (survarium::pure_game_effect_emitter_base *)v13;
    }
    else
    {
      v24 = 0;
    }
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      texture,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v24[1]);
    v14 = data->m_uid;
    v20 = 272;
    v19 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
    v18.m_object = v15;
    num_last_mips_used = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v14;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v18,
      v24);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v16,
      num_last_mips_used,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v18.m_object,
      (const vostok::resources::memory_type *)v19,
      v20);
    v20 = result_fail;
    v19 = assert_on_fail_true;
    v18.m_object = (survarium::pure_game_effect_emitter_base *)3;
  }
  else
  {
    v20 = result_out_of_memory|0x8;
    v19 = assert_on_fail_true;
    v18.m_object = (survarium::pure_game_effect_emitter_base *)1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_uid,
    (vostok::resources::cook_base::result_enum)v18.m_object,
    v19,
    v20);
}
