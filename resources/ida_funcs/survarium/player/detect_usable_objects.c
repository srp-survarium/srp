void __userpurge survarium::player::detect_usable_objects(
        survarium::player *this@<ecx>,
        int a2@<esi>,
        unsigned int current_time_in_ms)
{
  int v3; // eax
  int v4; // ecx
  survarium::collision_geometry *v5; // eax
  void *v6; // edi
  int v7; // eax
  void *v8; // ecx
  int v9; // eax
  const char *v10; // eax
  int v11; // ecx
  int v12; // [esp+14h] [ebp-44h]
  vostok::vectora<survarium::usable_object *> results; // [esp+20h] [ebp-38h] BYREF
  vostok::physics::closest_ray_result ray_result; // [esp+30h] [ebp-28h] BYREF

  if ( a2 )
    v3 = a2 + 12;
  else
    v3 = 0;
  v4 = *(int *)((char *)&dword_10F00 + a2);
  *(_DWORD *)(a2 + 16) = v3;
  *(_DWORD *)(a2 + 28) = current_time_in_ms;
  (*(void (__stdcall **)(vostok::physics::closest_ray_result *, int, int, _DWORD, int, int))(**(_DWORD **)(v4 + 176) + 60))(
    &ray_result,
    a2 + 120,
    a2 + 104,
    LODWORD(s_usable_objects_detection_distance),
    256,
    128);
  if ( ray_result.object )
  {
    v5 = ray_result.object->user_data->cast_to_collision_geometry(ray_result.object->user_data);
    results._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
    results._M_impl._M_start = 0;
    results._M_impl._M_finish = 0;
    results._M_impl._M_end_of_storage._M_data = 0;
    survarium::collision_geometry::query_objects_by_type<survarium::usable_object>(
      v5,
      &results,
      (survarium::usable_object *(__thiscall *__ptr64)(survarium::collision_geometry_subscriber *))(unsigned int) __thiscall vostok::ai::perceptors::enemy_perceptor::`vcall'{4,{flat}});
    v6 = *results._M_impl._M_start;
    v7 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 36))(a2);
    v8 = *(void **)(a2 + 20);
    if ( (*(_DWORD *)(v7 + 16) & 0x10000000) != 0 )
    {
      if ( v8 )
      {
        v12 = a2 + 16;
        if ( v8 == v6 )
        {
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)v6 + 20))(v6, v12);
          results._M_impl._M_end_of_storage.m_allocator->call_free(
            results._M_impl._M_end_of_storage.m_allocator,
            results._M_impl._M_start);
          return;
        }
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)v8 + 24))(v8, v12);
      }
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)v6 + 16))(v6, a2 + 16);
      results._M_impl._M_end_of_storage.m_allocator->call_free(
        results._M_impl._M_end_of_storage.m_allocator,
        results._M_impl._M_start);
    }
    else
    {
      if ( v8 )
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)v8 + 24))(v8, a2 + 16);
      v9 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F04 + a2) + 952) + 8);
      if ( v9
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && *(_BYTE *)(v9 + 52) == *(_BYTE *)(a2 + 52) )
      {
        if ( *(int *)((char *)&dword_10F7C + a2) )
        {
          v10 = (const char *)(*(int (__thiscall **)(void *, int))(*(_DWORD *)v6 + 28))(v6, a2 + 16);
          survarium::game_world_ui::set_using_info_message(
            *(int *)((char *)&dword_10F7C + a2),
            v10,
            *(survarium::game_world_ui **)((char *)&dword_10F7C + a2));
        }
      }
      results._M_impl._M_end_of_storage.m_allocator->call_free(
        results._M_impl._M_end_of_storage.m_allocator,
        results._M_impl._M_start);
    }
  }
  else
  {
    v11 = *(_DWORD *)(a2 + 20);
    if ( v11 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 24))(v11, a2 + 16);
  }
}
