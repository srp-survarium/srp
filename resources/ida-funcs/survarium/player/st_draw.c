void __thiscall survarium::player::st_draw(survarium::player *this, survarium::base_player *a2)
{
  survarium::player *v3; // ecx
  survarium::game_world_ui *v4; // ecx
  unsigned int current_progress; // esi
  survarium::usable_object *v6; // eax
  survarium::game_world_ui *v7; // ecx
  vostok::physics::world *m_physics_world; // ecx
  _DWORD *v9; // esi
  int v10; // edi
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  int v13; // eax
  survarium::game_world_ui *v14; // ecx
  int v15; // eax
  survarium::inventory_item *m_object; // ecx
  int v17; // esi
  void (__thiscall *v18)(struct survarium::game_world_ui *); // edx
  int v19; // edi
  _DWORD *v20; // edi
  int v21; // ebx
  bool v22; // zf
  float *v23; // esi
  vostok::math::float3 v24; // [esp-4h] [ebp-D0h]
  vostok::math::float3 v25; // [esp-4h] [ebp-D0h]
  char *v26; // [esp+Ch] [ebp-C0h]
  _BYTE v27[48]; // [esp+20h] [ebp-ACh] BYREF
  int v28; // [esp+50h] [ebp-7Ch]
  int v29; // [esp+54h] [ebp-78h]
  int v30; // [esp+58h] [ebp-74h]
  _BYTE v31[76]; // [esp+60h] [ebp-6Ch] BYREF
  int v32; // [esp+ACh] [ebp-20h] BYREF
  int v33; // [esp+B0h] [ebp-1Ch]
  vostok::memory::pthreads3_allocator *v34; // [esp+B4h] [ebp-18h]
  int v35; // [esp+B8h] [ebp-14h]
  survarium::game_world_ui *v36; // [esp+BCh] [ebp-10h]
  float *i; // [esp+C0h] [ebp-Ch]
  unsigned __int8 v38; // [esp+C4h] [ebp-8h]
  bool is_player_current; // [esp+D4h] [ebp+8h]
  unsigned __int8 v40; // [esp+D7h] [ebp+Bh]
  unsigned __int8 v41; // [esp+D7h] [ebp+Bh]
  unsigned __int8 v42; // [esp+D7h] [ebp+Bh]

  is_player_current = survarium::base_network_client::is_player_current(
                        (survarium::base_network_client *)this,
                        *(_DWORD *)(*(int *)((char *)&dword_11414 + (_DWORD)a2) + 13912),
                        a2->id);
  survarium::player::render_name(v3, (int)a2, is_player_current);
  if ( is_player_current )
  {
    if ( a2->m_usable_object_user_data.current_object )
    {
      current_progress = a2->m_usable_object_user_data.current_progress;
      if ( current_progress != -1 )
        survarium::game_world_ui::set_using_progress_message(
          v4,
          *(int *)((char *)&dword_1141C + (_DWORD)a2),
          current_progress);
    }
    else
    {
      v6 = survarium::base_player::detect_usable_object(
             a2,
             (const vostok::math::float4x4 *)((char *)&loc_11160 + (_DWORD)a2));
      if ( v6 )
        v26 = (char *)v6->use_info(v6, &a2->m_usable_object_user_data);
      else
        v26 = (char *)uri;
      survarium::game_world_ui::set_using_info_message(v7, *(const char **)((char *)&dword_1141C + (_DWORD)a2), v26);
    }
    survarium::game_world_ui::set_stamina(
      v4,
      *(float *)((char *)&a2->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
               + (_DWORD)&locret_110FB
               + 1),
      *(float *)((char *)&dword_1141C + (_DWORD)a2));
    m_physics_world = a2->m_physics_world;
    v32 = 0;
    v33 = 0;
    v34 = &vostok::memory::g_mt_allocator;
    v35 = 0;
    ((void (__thiscall *)(vostok::physics::world *, char *, _DWORD, int, int, int *))m_physics_world->get_all_objects_in_radius)(
      m_physics_world,
      &byte_10E5C[(_DWORD)a2],
      LODWORD(s_grenades_sensor_radius),
      8,
      2048,
      &v32);
    v40 = 0;
    for ( i = 0; (unsigned __int16)i < (unsigned int)((v33 - v32) >> 2); i = (float *)((char *)i + 1) )
    {
      if ( v40 >= 6u )
        break;
      v9 = *(_DWORD **)(v32 + 4 * (unsigned __int16)i);
      if ( v9[3] && (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v9[3] + 12))(v9[3]) )
      {
        v10 = 12 * v40;
        v11 = (_DWORD *)((*(int (__thiscall **)(_DWORD *, _BYTE *))(*v9 + 28))(v9, v27) + 48);
        ++v40;
        v12 = &v31[v10];
        *v12++ = *v11;
        *v12 = v11[1];
        v12[1] = v11[2];
      }
    }
    v36 = *(survarium::game_world_ui **)((char *)&dword_1141C + (_DWORD)a2);
    v13 = (v33 - v32) >> 2;
    v14 = (survarium::game_world_ui *)v31;
    v38 = v13;
    v41 = 0;
    i = (float *)v31;
    while ( 1 )
    {
      if ( v41 < (unsigned __int8)v13 )
      {
        *(_QWORD *)&v24.elements[1] = *(_QWORD *)i;
        LODWORD(v24.x) = (unsigned __int8)(v41 + 32);
        survarium::game_world_ui::draw_object_icon(v14, (int)v36, v24, i[2], COERCE_FLOAT(1));
      }
      else
      {
        survarium::game_world_ui::set_hud_icon_visible(v14, (int)v36, v41 + 32, 0);
      }
      ++v41;
      i += 3;
      if ( v41 >= 6u )
        break;
      LOBYTE(v13) = v38;
    }
    v15 = *(int *)((char *)&a2->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                 + (_DWORD)&loc_11433
                 + 1);
    if ( v15 != 23 )
    {
      m_object = a2->m_inventory.m_object->m_slots.elems[v15].m_object;
      v42 = 0;
      v17 = (int)m_object->cast_booby_trap_set_core(m_object);
      v14 = *(survarium::game_world_ui **)(v17 + 288);
      i = (float *)v17;
      while ( 1 )
      {
        v36 = v14;
        if ( v14 == *(survarium::game_world_ui **)(v17 + 292) || v42 >= 6u )
          break;
        v18 = v14->__vftable[51].~survarium::game_world_ui;
        if ( v18 && v18 != (void (__thiscall *)(struct survarium::game_world_ui *))3 )
        {
          (*(void (__thiscall **)(void (__thiscall *)(struct survarium::game_world_ui *, survarium::flash_movie *, const char *, const survarium::flash_value *, unsigned int), _BYTE *))(*(_DWORD *)v14->scaleform_callback + 28))(
            v14->scaleform_callback,
            v27);
          v14 = v36;
          v19 = 12 * v42++;
          v20 = &v31[v19];
          *v20++ = v28;
          *v20 = v29;
          v20[1] = v30;
          v17 = (int)i;
        }
        v14 = (survarium::game_world_ui *)((char *)v14 + 4);
      }
      v21 = *(int *)((char *)&dword_1141C + (_DWORD)a2);
      v22 = *(_BYTE *)(v21 + 597) == 0;
      v38 = 0;
      if ( !v22 )
      {
        do
        {
          if ( v38 < v42 )
          {
            v23 = (float *)&v31[12 * v38];
            v25.y = *v23++;
            v25.z = *v23;
            LODWORD(v25.x) = (unsigned __int8)(v38 + 38);
            survarium::game_world_ui::draw_object_icon(v14, v21, v25, v23[1], 0.0);
          }
          else
          {
            survarium::game_world_ui::set_hud_icon_visible(v14, v21, v38 + 38, 0);
          }
          ++v38;
        }
        while ( v38 < *(_BYTE *)(v21 + 597) );
      }
    }
    stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
      (stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *)v14,
      (int)&v32);
  }
}
