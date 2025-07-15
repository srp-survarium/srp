void __thiscall survarium::network_client::process_initialize_victory_items(
        survarium::network_client *this,
        survarium::network_client *packet,
        vostok::network_core::packet_reader *packeta)
{
  char *m_pointer; // eax
  char v4; // cl
  char v5; // dl
  vostok::network_core::packet_reader *v6; // edi
  const unsigned __int8 *v7; // eax
  unsigned __int8 v8; // cl
  const unsigned __int8 *v9; // eax
  char v10; // cl
  unsigned __int8 v11; // bl
  float v12; // edx
  const vostok::math::float4x4 *v13; // eax
  const vostok::math::float4x4 *v14; // eax
  unsigned int m_buffer_size; // edx
  int v16; // eax
  survarium::victory_item_core *v17; // esi
  int v18; // eax
  survarium::game_world_ui *v19; // ecx
  vostok::resources::unmanaged_resource *v20; // eax
  const vostok::network_core::base_packet *m_packet; // eax
  const unsigned __int8 *v22; // eax
  unsigned __int8 v23; // cl
  const unsigned __int8 *v24; // eax
  unsigned __int8 v25; // cl
  unsigned int v26; // eax
  vostok::resources::unmanaged_resource *v27; // edx
  vostok::resources::resource_base *m_next_in_memory_type; // eax
  vostok::resources::resource_base *m_prev_in_memory_type; // esi
  vostok::resources::resource_base_vtbl *v30; // ebx
  const unsigned __int8 *v31; // eax
  unsigned __int8 v32; // cl
  const unsigned __int8 *v33; // eax
  unsigned __int8 v34; // cl
  int v35; // edx
  unsigned int v36; // ecx
  int v37; // eax
  int v38; // esi
  unsigned __int8 v39; // [esp+0h] [ebp-1BCh]
  char team_2_points[4]; // [esp+14h] [ebp-1A8h]
  char team_2_pointsa[4]; // [esp+14h] [ebp-1A8h]
  survarium::game_world_ui *team_1_points; // [esp+18h] [ebp-1A4h]
  char team_1_pointsa; // [esp+18h] [ebp-1A4h]
  char team_1_pointsb[4]; // [esp+18h] [ebp-1A4h]
  vostok::resources::unmanaged_intrusive_base *v45; // [esp+1Ch] [ebp-1A0h] BYREF
  vostok::math::float3 angles; // [esp+20h] [ebp-19Ch] BYREF
  vostok::math::float3 position; // [esp+2Ch] [ebp-190h] BYREF
  vostok::math::float4x4 dst; // [esp+38h] [ebp-184h] BYREF
  vostok::math::float4x4 transform; // [esp+78h] [ebp-144h] BYREF
  vostok::math::float4x4 left; // [esp+B8h] [ebp-104h] BYREF
  vostok::math::float4x4 v51; // [esp+F8h] [ebp-C4h] BYREF
  vostok::math::float4x4 result; // [esp+138h] [ebp-84h] BYREF
  vostok::math::float4x4 v53; // [esp+178h] [ebp-44h] BYREF

  m_pointer = (char *)packeta->m_pointer;
  v4 = *m_pointer++;
  packeta->m_pointer = (const unsigned __int8 *)m_pointer;
  v5 = *m_pointer;
  packeta->m_pointer = (const unsigned __int8 *)(m_pointer + 1);
  v6 = (vostok::network_core::packet_reader *)packet;
  LOBYTE(team_1_points) = v4;
  survarium::game_world_ui::set_victory_points(team_1_points, v4, v5);
  v7 = packeta->m_pointer;
  v8 = *v7;
  packeta->m_pointer = v7 + 1;
  if ( v8 )
  {
    *(_DWORD *)team_2_points = v8;
    do
    {
      v9 = packeta->m_pointer;
      v10 = *v9++;
      packeta->m_pointer = v9;
      v11 = *v9++;
      packeta->m_pointer = v9;
      v12 = *((float *)v9 + 2);
      team_1_pointsa = v10;
      *(_QWORD *)&position.x = *(_QWORD *)v9;
      position.z = v12;
      packeta->m_pointer = v9 + 12;
      if ( v10 == -1 )
      {
        memset((int)&dst, 0, sizeof(dst));
        LODWORD(dst.i.x) = clear_value;
        LODWORD(dst.j.y) = clear_value;
        LODWORD(dst.k.z) = clear_value;
        LODWORD(dst.c.w) = clear_value;
        memset(&angles, 0, sizeof(angles));
        v13 = vostok::math::create_rotation(&result, &angles);
        vostok::math::mul4x3(&left, v13, &dst);
        v14 = vostok::math::create_translation(&v53, &position);
        vostok::math::mul4x3(&v51, &left, v14);
        qmemcpy((void *)&transform, &v51, sizeof(transform));
        packet->m_game->m_game_world.m_victory_items._M_impl._M_start[v11].m_object->put(
          packet->m_game->m_game_world.m_victory_items._M_impl._M_start[v11].m_object,
          packet->m_game->m_game_world.m_physics_world,
          &transform,
          &packet->m_game->m_game_world.m_game->m_scheduler);
        v6 = (vostok::network_core::packet_reader *)packet;
      }
      else
      {
        m_buffer_size = v6[3].m_packet[107].m_buffer_size;
        v16 = *(_DWORD *)(m_buffer_size + 4 * v11);
        v17 = 0;
        if ( v16 )
        {
          v17 = *(survarium::victory_item_core **)(m_buffer_size + 4 * v11);
          _InterlockedExchangeAdd((volatile signed __int32 *)(v16 + 240), 1u);
        }
        v18 = ((int (__thiscall *)(vostok::network_core::packet_reader *, vostok::resources::unmanaged_intrusive_base **, char))v6->m_packet[9].m_buffer)(
                v6,
                &v45,
                v10);
        survarium::inventory::set_victory_item(*(survarium::inventory **)(*(_DWORD *)v18 + 8), v17);
        if ( v45 )
        {
          v19 = (survarium::game_world_ui *)_InterlockedExchangeAdd(&v45[62].m_reference_count, 0xFFFFFFFF);
          if ( !v19 )
          {
            if ( v45 )
              v20 = (vostok::resources::unmanaged_resource *)&v45[36];
            else
              v20 = 0;
            vostok::resources::unmanaged_intrusive_base::destroy(v45 + 62, v20);
          }
        }
        m_packet = v6[1].m_packet;
        if ( m_packet )
        {
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            LOBYTE(v19) = team_1_pointsa;
            if ( LOBYTE(m_packet[6].m_buffer_size) == team_1_pointsa )
              survarium::game_world_ui::show_item_container(v19, v39);
          }
        }
        if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            &v17->vostok::resources::unmanaged_intrusive_base,
            &v17->vostok::resources::unmanaged_resource);
      }
      --*(_DWORD *)team_2_points;
    }
    while ( *(_DWORD *)team_2_points );
  }
  v22 = packeta->m_pointer;
  v23 = *v22;
  packeta->m_pointer = v22 + 1;
  if ( v23 )
  {
    *(_DWORD *)team_1_pointsb = v23;
    do
    {
      v24 = packeta->m_pointer;
      v25 = *v24;
      packeta->m_pointer = v24 + 1;
      v26 = v6[3].m_packet[88].m_buffer_size;
      v27 = 0;
      if ( v26 )
      {
        v27 = (vostok::resources::unmanaged_resource *)v6[3].m_packet[88].m_buffer_size;
        _InterlockedExchangeAdd((volatile signed __int32 *)(v26 + 208), 1u);
      }
      m_next_in_memory_type = v27[1].m_next_in_memory_type;
      m_prev_in_memory_type = v27[1].m_prev_in_memory_type;
      v30 = 0;
      if ( m_next_in_memory_type != m_prev_in_memory_type )
      {
        while ( 1 )
        {
          v30 = m_next_in_memory_type->__vftable;
          if ( LOBYTE(m_next_in_memory_type->__vftable[1].is_increasing_quality) == v25 )
            break;
          m_next_in_memory_type = (vostok::resources::resource_base *)((char *)m_next_in_memory_type + 4);
          if ( m_next_in_memory_type == m_prev_in_memory_type )
          {
            v30 = 0;
            break;
          }
        }
      }
      if ( !_InterlockedExchangeAdd(&v27->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v27->vostok::resources::unmanaged_intrusive_base, v27);
      v31 = packeta->m_pointer;
      v32 = *v31;
      packeta->m_pointer = v31 + 1;
      if ( v32 )
      {
        *(_DWORD *)team_2_pointsa = v32;
        do
        {
          v33 = packeta->m_pointer;
          v34 = *v33;
          packeta->m_pointer = v33 + 1;
          v35 = v34;
          v36 = v6[3].m_packet[107].m_buffer_size;
          v37 = *(_DWORD *)(v36 + 4 * v35);
          v38 = 0;
          if ( v37 )
          {
            v38 = *(_DWORD *)(v36 + 4 * v35);
            _InterlockedExchangeAdd((volatile signed __int32 *)(v37 + 240), 1u);
          }
          if ( *(_BYTE *)(v38 + 364) )
            (*(void (__thiscall **)(int))(*(_DWORD *)v38 + 36))(v38);
          (*((void (__thiscall **)(vostok::resources::resource_base_vtbl *, int))v30->~vostok::resources::resource_base
           + 8))(
            v30,
            v38);
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v38 + 240), 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(
              (vostok::resources::unmanaged_intrusive_base *)(v38 + 240),
              (vostok::resources::unmanaged_resource *)(v38 + 32));
          --*(_DWORD *)team_2_pointsa;
        }
        while ( *(_DWORD *)team_2_pointsa );
      }
      --*(_DWORD *)team_1_pointsb;
    }
    while ( *(_DWORD *)team_1_pointsb );
  }
}
