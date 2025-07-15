void __thiscall vostok::sound::sound_scene_cook::translate_query(
        vostok::sound::sound_scene_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  IXAudio2SubmixVoice *submix_voice; // eax
  vostok::configs::binary_config *v3; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp-Ch] [ebp-58h] BYREF
  const vostok::resources::memory_type *v5; // [esp-8h] [ebp-54h]
  unsigned int v6; // [esp-4h] [ebp-50h]
  vostok::sound::sound_scene *v7; // [esp+0h] [ebp-4Ch]
  unsigned int dbg_id; // [esp+4h] [ebp-48h]
  vostok::sound::sound_scene_cook *thisa; // [esp+8h] [ebp-44h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v10; // [esp+Ch] [ebp-40h]
  vostok::sound::sound_scene *v11; // [esp+24h] [ebp-28h]
  vostok::memory::doug_lea_allocator *m_object; // [esp+28h] [ebp-24h]
  vostok::variant<32> *m_user_data; // [esp+2Ch] [ebp-20h]
  vostok::sound::sound_scene *v14; // [esp+34h] [ebp-18h]
  char v15; // [esp+3Ah] [ebp-12h]
  bool result; // [esp+3Bh] [ebp-11h]
  vostok::sound::sound_scene *created_scene; // [esp+3Ch] [ebp-10h]
  vostok::sound::sound_scene_creation_params params; // [esp+40h] [ebp-Ch] BYREF

  thisa = this;
  m_user_data = parent->m_user_data;
  result = vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>(m_user_data, &params);
  v15 = 0;
  m_object = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
  v11 = (vostok::sound::sound_scene *)vostok::memory::doug_lea_allocator::malloc_impl(
                                        (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                        0x270u);
  v14 = v11;
  if ( v11 )
  {
    dbg_id = id++;
    v6 = (unsigned int)parent;
    v5 = (const vostok::resources::memory_type *)dbg_id;
    submix_voice = vostok::sound::sound_world::create_submix_voice(thisa->m_sound_world, 2u, 2u);
    vostok::sound::sound_scene::sound_scene(v14, thisa->m_sound_world, &params, submix_voice, dbg_id, parent);
    v7 = (vostok::sound::sound_scene *)v3;
  }
  else
  {
    v7 = 0;
  }
  created_scene = v7;
  v6 = 624;
  v5 = &vostok::resources::nocache_memory;
  v10 = &v4;
  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    (vostok::configs::binary_config *)v7);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v4.m_object,
    v5,
    v6);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
}
