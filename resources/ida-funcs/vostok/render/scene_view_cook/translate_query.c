void __thiscall vostok::render::scene_view_cook::translate_query(
        vostok::render::scene_view_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  char *v5; // eax
  vostok::render::scene_view *v6; // ecx
  vostok::render::scene_view *v7; // eax
  vostok::render::scene_view *v8; // edi
  survarium::pure_game_effect_emitter_base *v9; // ecx
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::query_result_for_cook *v11; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v12; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v13; // [esp-8h] [ebp-18h]
  void *v14; // [esp-4h] [ebp-14h]
  const char *v15; // [esp+0h] [ebp-10h]
  const char *v16; // [esp+4h] [ebp-Ch]
  unsigned int v17; // [esp+8h] [ebp-8h]
  vostok::render::scene_view *v18; // [esp+Ch] [ebp-4h] BYREF

  v2 = vostok::render::g_allocator;
  v3 = type_info::raw_name(&vostok::render::scene_view `RTTI Type Descriptor');
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(v4, (int)v2, (unsigned int)&unk_10E30, v3, v15, v16, v17);
  if ( v5 )
  {
    vostok::render::scene_view::scene_view(v6, (int)v5);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v18 = v8;
  vostok::buffer_vector<vostok::render::scene_view *>::push_back(
    (vostok::buffer_vector<vostok::render::scene_view *> *)v6,
    (int)&vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_views,
    &v18);
  v14 = &unk_10E30;
  v13 = &vostok::resources::nocache_memory;
  v12.m_object = v9;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v12,
    (survarium::pure_game_effect_emitter_base *)v8);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v10,
    parent,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v12.m_object,
    v13,
    (unsigned int)v14);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v11,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
