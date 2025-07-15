void __thiscall survarium::project_cooker_simple::on_object_loaded(
        survarium::project_cooker_simple *this,
        survarium::game_object_ *__formal,
        survarium::simple_game_project *project,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent_query)
{
  survarium::pure_game_effect_emitter_base *v4; // ecx
  vostok::resources::query_result_for_cook *v5; // ecx
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v7; // [esp-Ch] [ebp-14h] BYREF
  const vostok::resources::memory_type *v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]

  ++project->m_loaded.loaded_count;
  if ( survarium::simple_game_project::all_loaded((survarium::simple_game_project *)this, (int)project) )
  {
    v9 = 488;
    v8 = &vostok::resources::nocache_memory;
    v7.m_object = v4;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v7,
      (survarium::pure_game_effect_emitter_base *)&project->vostok::resources::unmanaged_resource);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v5,
      parent_query,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v7.m_object,
      v8,
      v9);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v6,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
}
