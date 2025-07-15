void __thiscall vostok::sound::sound_scene_cook::translate_query(
        vostok::sound::sound_scene_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::sound::sound_world *v6; // ecx
  void *v7; // esi
  const vostok::resources::memory_type *v8; // eax
  IXAudio2SubmixVoice *submix_voice; // eax
  vostok::sound::sound_scene *v10; // ecx
  survarium::pure_game_effect_emitter_base *v11; // eax
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp-Ch] [ebp-24h] BYREF
  const vostok::resources::memory_type *v15; // [esp-8h] [ebp-20h]
  unsigned int v16; // [esp-4h] [ebp-1Ch]
  const char *v17; // [esp+0h] [ebp-18h]
  const char *v18; // [esp+4h] [ebp-14h]
  unsigned int v19; // [esp+8h] [ebp-10h]
  vostok::sound::sound_scene_creation_params out_value; // [esp+Ch] [ebp-Ch] BYREF

  vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>(
    (vostok::variant<32> *)this,
    (int)parent->m_user_data->m_helper_storage,
    &out_value);
  v3 = vostok::sound::g_allocator;
  v4 = type_info::raw_name(&vostok::sound::sound_scene `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0x300u, v4, v17, v18, v19);
  if ( v7 )
  {
    v8 = (const vostok::resources::memory_type *)id;
    v16 = (unsigned int)parent;
    ++id;
    v15 = v8;
    submix_voice = vostok::sound::sound_world::create_submix_voice(v6, (int)this->m_sound_world);
    vostok::sound::sound_scene::sound_scene(
      v10,
      (int)v7,
      this->m_sound_world,
      (vostok::threading::mutex_tasks_unaware *)&out_value,
      submix_voice,
      (unsigned int)v15,
      parent);
  }
  else
  {
    v11 = 0;
  }
  v16 = 768;
  v15 = &vostok::resources::nocache_memory;
  v14.m_object = (survarium::pure_game_effect_emitter_base *)v6;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v14,
    v11);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v12,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v14.m_object,
    v15,
    v16);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v13,
    (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
