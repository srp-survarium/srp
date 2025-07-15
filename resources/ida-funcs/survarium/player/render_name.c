void __thiscall survarium::player::render_name(survarium::player *this, int is_current, char a3)
{
  int v3; // eax
  survarium::player *m_object; // ecx
  int insert; // ecx
  BOOL v6; // ecx
  int v7; // esi
  bool v8; // zf
  bool v9; // al
  vostok::math::float4x4 *v10; // eax
  int v11; // esi
  survarium::game_world_ui *v12; // ecx
  survarium::game_world_ui *v13; // ecx
  float v14; // xmm0_4
  unsigned int y; // ecx
  unsigned int v16; // eax
  survarium::base_network_client *v17; // edi
  survarium::game_world_ui *v18; // eax
  vostok::math::float3 v19; // [esp-14h] [ebp-D4h]
  survarium::base_game_scene *v20; // [esp-8h] [ebp-C8h]
  survarium::base_game_scene *v21; // [esp-8h] [ebp-C8h]
  char v22; // [esp+13h] [ebp-ADh]
  survarium::base_network_client *v23; // [esp+14h] [ebp-ACh]
  survarium::game_world_ui *v24; // [esp+14h] [ebp-ACh]
  survarium::game_world_ui *v25; // [esp+14h] [ebp-ACh]
  int v26; // [esp+18h] [ebp-A8h]
  survarium::game_world_ui *v27; // [esp+18h] [ebp-A8h]
  vostok::math::float3 p; // [esp+1Ch] [ebp-A4h] BYREF
  unsigned __int8 icon_uid[4]; // [esp+28h] [ebp-98h]
  vostok::math::float2 result; // [esp+2Ch] [ebp-94h] BYREF
  vostok::math::float3 v31; // [esp+34h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v32; // [esp+40h] [ebp-80h] BYREF
  vostok::math::float4x4 v33; // [esp+80h] [ebp-40h] BYREF

  if ( !*(_BYTE *)(is_current + 767)
    || *((_BYTE *)&loc_1143B + is_current)
    || a3
    || (v22 = 1, !*(_BYTE *)(is_current + 764)) )
  {
    v22 = 0;
  }
  v3 = *(int *)((char *)&dword_11414 + is_current);
  v23 = *(survarium::base_network_client **)(v3 + 13912);
  m_object = v23->m_current_player.m_object;
  if ( m_object )
  {
    insert = (int)(*(survarium::player_vtbl **)((char *)&m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                              + (_DWORD)&loc_11066
                                              + 2))[6].insert;
    v26 = insert;
  }
  else
  {
    v26 = 2;
    insert = 2;
  }
  v6 = insert == *(_DWORD *)(*(_DWORD *)((char *)&loc_11066 + is_current + 2) + 440)
    || insert == 2
    || *(_DWORD *)(is_current + 772);
  v7 = v3 + 708;
  v8 = *(_DWORD *)(*(_DWORD *)(v3 + 344) + 132) == 0;
  *(_DWORD *)icon_uid = v3 + 708;
  v9 = v6 && !v8;
  LOBYTE(v6) = v22;
  if ( (v9 & (unsigned __int8)v22) != 0 )
  {
    v10 = vostok::math::create_translation(&survarium::s_icon_name_offset, &v33);
    vostok::math::mul4x3((const vostok::math::float4x4 *)((char *)&loc_11160 + is_current), v10, &v32);
    *(_QWORD *)&v19.elements[1] = *(_QWORD *)&v32.lines[3].x;
    v11 = *(_DWORD *)icon_uid;
    LODWORD(v19.x) = *(unsigned __int8 *)(is_current + 304);
    if ( survarium::game_world_ui::draw_object_icon(v12, *(int *)icon_uid, v19, v32.c.z, 0.0) )
    {
      survarium::game_world_ui::set_hud_icon_modifier_visible(
        v13,
        *(int *)icon_uid,
        *(_BYTE *)(is_current + 304),
        *(_DWORD *)(*(_DWORD *)(is_current + 268) + 380) != 0);
      result.x = SNaN;
      result.y = SNaN;
      p.x = *(float *)&byte_10E5C[is_current];
      p.y = *(float *)&byte_10E5C[is_current + 4] - 0.1;
      v20 = *(survarium::base_game_scene **)((char *)&dword_11410 + is_current);
      p.z = *(float *)&byte_10E5C[is_current + 8];
      survarium::base_game_scene::point_to_screen(&result, v20, &p);
      p.x = SNaN;
      p.y = SNaN;
      v31.x = v32.c.x;
      v21 = *(survarium::base_game_scene **)((char *)&dword_11410 + is_current);
      v31.y = v32.c.y + 0.1;
      v31.z = v32.c.z;
      survarium::base_game_scene::point_to_screen((vostok::math::float2 *)&p, v21, &v31);
      v14 = (float)(result.y - p.y) * 0.2631579;
      y = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + is_current) + 160) + 112) + 264) >> 1;
      if ( y > (unsigned __int16)(int)(float)(p.x + v14)
        || y < (unsigned __int16)(int)(float)(p.x - v14)
        || (y = (unsigned __int16)(int)p.y,
            v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + is_current) + 160) + 112) + 268) >> 1,
            v16 < y)
        || (y = (unsigned __int16)(int)result.y, LOBYTE(p.x) = 1, v16 > y) )
      {
        LOBYTE(p.x) = 0;
      }
      survarium::game_world_ui::set_hud_icon_name_visible(
        (survarium::game_world_ui *)y,
        v11,
        *(_BYTE *)(is_current + 304),
        SLOBYTE(p.x));
      if ( v26 == *(_DWORD *)(*(_DWORD *)((char *)&loc_11066 + is_current + 2) + 440) )
      {
        v17 = v23;
        survarium::base_network_client::get_current_player(
          v23,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&p);
        v24 = (survarium::game_world_ui *)*(unsigned __int8 *)(LODWORD(p.x) + 304);
        v27 = (survarium::game_world_ui *)*((unsigned __int8 *)&v24->__vftable
                                          + (unsigned int)v17->match_options(v17)->squads.elems);
        v25 = (survarium::game_world_ui *)*(unsigned __int8 *)(is_current + 304);
        v18 = (survarium::game_world_ui *)*((unsigned __int8 *)&v25->__vftable
                                          + (unsigned int)v17->match_options(v17)->squads.elems);
        if ( v27 == v18 && v18 )
          survarium::game_world_ui::set_hud_icon_color(
            v25,
            *(int *)icon_uid,
            *(_BYTE *)(is_current + 304),
            0x61u,
            0xFFu,
            0x55u);
        else
          survarium::game_world_ui::set_hud_icon_color(
            v25,
            *(int *)icon_uid,
            *(_BYTE *)(is_current + 304),
            0xFFu,
            0xFFu,
            0xFFu);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&p);
      }
      else
      {
        survarium::game_world_ui::set_hud_icon_color(
          (survarium::game_world_ui *)v26,
          v11,
          *(_BYTE *)(is_current + 304),
          0xFFu,
          0,
          0);
      }
    }
  }
  else if ( !*((_BYTE *)&loc_1143B + is_current) )
  {
    survarium::game_world_ui::set_hud_icon_visible((survarium::game_world_ui *)v6, v7, *(_BYTE *)(is_current + 304), 0);
  }
}
