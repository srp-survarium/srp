void __thiscall survarium::sound_player_cook::on_sounds_loaded(
        survarium::sound_player_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config)
{
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  volatile int m_result; // eax
  vostok::ai::npc *npc; // ebx
  vostok::configs::binary_config *v6; // eax
  bool v7; // zf
  int v8; // ecx
  const vostok::configs::binary_config_value *v9; // ebp
  vostok::resources::query_result_for_cook *v10; // eax
  vostok::variant<32> *m_user_data; // eax
  char v12; // al
  vostok::resources::unmanaged_resource *m_object; // esi
  vostok::resources::unmanaged_resource *v14; // eax
  int v15; // esi
  vostok::memory::doug_lea_allocator *v16; // eax
  int *v17; // esi
  const vostok::sound::sound_producer *v18; // eax
  const vostok::sound::sound_receiver *v19; // ecx
  int count; // eax
  vostok::configs::binary_config_value *pointer; // ebp
  survarium::ai_sound_player::sounds_collection_type *v22; // ebx
  survarium::ai_sound_player::sounds_collection_type *v23; // esi
  const void *v24; // edi
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v25; // esi
  vostok::configs::binary_config *v26; // eax
  vostok::resources::unmanaged_intrusive_base *v27; // ecx
  vostok::resources::query_result_for_cook *v28; // edi
  vostok::resources::query_result_for_cook *v29; // ecx
  survarium::ai_sound_player *v30; // [esp-Ch] [ebp-50h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v31; // [esp-4h] [ebp-48h] BYREF
  int v32; // [esp+10h] [ebp-34h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> sound_scene; // [esp+14h] [ebp-30h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v34; // [esp+18h] [ebp-2Ch] BYREF
  int v35; // [esp+1Ch] [ebp-28h]
  survarium::ai_sound_player *player; // [esp+20h] [ebp-24h]
  survarium::ai_sound_player::sounds_collection_type *end; // [esp+24h] [ebp-20h]
  const vostok::configs::binary_config_value *it_end; // [esp+28h] [ebp-1Ch]
  unsigned int resource_size; // [esp+2Ch] [ebp-18h]
  vostok::resources::query_result_for_cook *parent; // [esp+30h] [ebp-14h]
  vostok::ai::brain_unit_cook_params params; // [esp+34h] [ebp-10h] BYREF

  m_parent_query = data->m_parent_query;
  m_result = data->m_result;
  npc = 0;
  v32 = 0;
  parent = m_parent_query;
  if ( m_result == 1 )
  {
    v9 = vostok::configs::binary_config_value::operator[](config.m_object->m_root, "sounds");
    sound_scene.m_object = 0;
    v10 = m_parent_query->m_parent->m_parent_query;
    player = 0;
    if ( v10 )
    {
      if ( v10->m_class_id == brain_unit_class )
      {
        m_user_data = v10->m_user_data;
        memset(&params, 0, sizeof(params));
        if ( m_user_data )
        {
          v12 = vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>(m_user_data, &params, v8);
          m_object = params.sound_scene.m_object;
          if ( v12 )
          {
            npc = params.npc;
            v14 = 0;
            if ( params.sound_scene.m_object )
            {
              v14 = params.sound_scene.m_object;
              _InterlockedExchangeAdd(&params.sound_scene.m_object->m_reference_count, 1u);
            }
            sound_scene.m_object = v14;
            player = (survarium::ai_sound_player *)params.sound_world_user;
          }
          if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(
              &m_object->vostok::resources::unmanaged_intrusive_base,
              m_object);
        }
      }
    }
    v15 = 16 * v9->count;
    v16 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
    resource_size = v15 + 424;
    v17 = vostok::memory::doug_lea_allocator::malloc_impl(v16, v15 + 424);
    v18 = 0;
    if ( v17 )
    {
      if ( npc )
      {
        v19 = (const vostok::sound::sound_receiver *)&npc[7];
        v18 = (const vostok::sound::sound_producer *)&npc[3];
      }
      else
      {
        v19 = 0;
      }
      survarium::ai_sound_player::ai_sound_player(
        (survarium::ai_sound_player *)&sound_scene,
        (int)v17,
        &sound_scene,
        v9->count,
        (vostok::sound::world_user *)player,
        v18,
        v19);
    }
    player = (survarium::ai_sound_player *)v18;
    count = v9->count;
    pointer = (vostok::configs::binary_config_value *)v9->data.pointer;
    v22 = (survarium::ai_sound_player::sounds_collection_type *)(v17 + 106);
    v23 = (survarium::ai_sound_player::sounds_collection_type *)&v17[4 * count + 106];
    end = v23;
    it_end = &pointer[count];
    if ( pointer != it_end )
    {
      v35 = 0;
      do
      {
        if ( v22 == v23 )
          break;
        v24 = vostok::configs::binary_config_value::operator[](pointer, "collection_type")->data.pointer;
        params.sound_scene.m_object = 0;
        if ( v22 )
        {
          v32 |= 1u;
          v25 = (vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)vostok::configs::binary_config_value::operator[](pointer, "priority")->data.pointer;
          params.sound_scene.m_object = 0;
          v34.m_object = 0;
          vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
            &v34,
            (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[v35 >> 4].m_unmanaged_resource);
          v31.m_object = 0;
          vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
            &v31,
            v34.m_object);
          survarium::ai_sound_player::sounds_collection_type::sounds_collection_type(
            v22,
            player,
            (vostok::ai::sound_collection_types)v24,
            v25,
            (vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>)v31.m_object);
          v23 = end;
        }
        if ( (v32 & 1) != 0 )
        {
          v26 = v34.m_object;
          v32 &= ~1u;
          if ( v34.m_object )
          {
            v27 = &v34.m_object->vostok::resources::unmanaged_intrusive_base;
            if ( !_InterlockedExchangeAdd(&v34.m_object->m_reference_count, 0xFFFFFFFF) )
              vostok::resources::unmanaged_intrusive_base::destroy(v27, v26);
          }
        }
        v35 += 16;
        ++pointer;
        ++v22;
      }
      while ( pointer != it_end );
    }
    v31.m_object = (vostok::configs::binary_config *)resource_size;
    v30 = 0;
    if ( player )
    {
      v30 = player;
      _InterlockedExchangeAdd(&player->m_reference_count, 1u);
    }
    v28 = parent;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v30,
      &vostok::resources::nocache_memory,
      (unsigned int)v31.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(v29, (int)v28, result_success, assert_on_fail_true, 0);
    if ( sound_scene.m_object && !_InterlockedExchangeAdd(&sound_scene.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &sound_scene.m_object->vostok::resources::unmanaged_intrusive_base,
        sound_scene.m_object);
    v6 = config.m_object;
    v7 = config.m_object == 0;
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
    v6 = config.m_object;
    v7 = config.m_object == 0;
  }
  if ( !v7 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &config.m_object->vostok::resources::unmanaged_intrusive_base,
      config.m_object);
}
