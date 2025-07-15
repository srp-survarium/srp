void __thiscall vostok::render::culling::portal_sector_structure_cook::translate_query(
        vostok::render::culling::portal_sector_structure_cook *this,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent)
{
  vostok::configs::binary_config_value *v2; // ecx
  vostok::configs::binary_config_value **m_lods; // esi
  unsigned int v4; // ebx
  const vostok::configs::binary_config_value *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::render::culling::portal_sector_structure *v10; // ecx
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // esi
  survarium::pure_game_effect_emitter_base *v13; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v14; // edi
  vostok::resources::query_result_for_cook *v15; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp-Ch] [ebp-3Ch] BYREF
  assert_on_fail_bool v17; // [esp-8h] [ebp-38h]
  vostok::resources::cook_base::result_enum v18; // [esp-4h] [ebp-34h]
  const char *v19; // [esp+0h] [ebp-30h]
  const char *v20; // [esp+4h] [ebp-2Ch]
  unsigned int v21; // [esp+8h] [ebp-28h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v22; // [esp+10h] [ebp-20h] BYREF
  vostok::memory::base_allocator *portals_count; // [esp+14h] [ebp-1Ch]
  vostok::configs::binary_config_value v24; // [esp+18h] [ebp-18h] BYREF

  v22.m_object = 0;
  if ( vostok::variant<32>::try_get<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::variant<32> *)this,
         (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)parent[5].m_on_out_of_memory.functor.bound_memfunc_ptr.obj_ptr,
         (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v22)
    && (m_lods = (vostok::configs::binary_config_value **)v22.m_object->m_lods,
        vostok::configs::binary_config_value::value_exists(
          v2,
          (int)v22.m_object->m_lods[0].m_template.m_object,
          (unsigned int)"portal_system")) )
  {
    qmemcpy((void *)&v24, vostok::configs::binary_config_value::operator[](*m_lods, "portal_system"), sizeof(v24));
    v4 = 24 * vostok::configs::binary_config_value::operator[](&v24, "sectors")->count / 24;
    v5 = vostok::configs::binary_config_value::operator[](&v24, "portals");
    v6 = vostok::render::g_allocator;
    portals_count = (vostok::memory::base_allocator *)(24 * v5->count / 24);
    v7 = type_info::raw_name(&vostok::render::culling::portal_sector_structure `RTTI Type Descriptor');
    v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x140u, v7, v19, v20, v21);
    if ( v9 )
    {
      vostok::render::culling::portal_sector_structure::portal_sector_structure(
        v10,
        v9,
        (unsigned int)portals_count,
        v4,
        (unsigned int)v19);
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    vostok::render::culling::portal_sector_structure::load(v10, v12, &v24);
    v18 = 320;
    v17 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
    v16.m_object = v13;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v16,
      (survarium::pure_game_effect_emitter_base *)v12);
    v14 = parent;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v15,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v16.m_object,
      (const vostok::resources::memory_type *)v17,
      v18);
    v18 = result_fail;
    v17 = assert_on_fail_true;
    v16.m_object = (survarium::pure_game_effect_emitter_base *)3;
  }
  else
  {
    v18 = result_out_of_memory|0x8;
    v17 = assert_on_fail_true;
    v16.m_object = (survarium::pure_game_effect_emitter_base *)1;
    v14 = parent;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)v2,
    v14,
    (vostok::resources::cook_base::result_enum)v16.m_object,
    v17,
    v18);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v22);
}
