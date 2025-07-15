void __thiscall survarium::bullet_manager::deserialize(
        survarium::bullet_manager *this,
        survarium::bullet *reader,
        survarium::bullet **time_offset,
        vostok::network_core::buffer_reader *readera)
{
  vostok::network_core::buffer_reader *v4; // ecx
  survarium::bullet **v5; // ebx
  survarium::bullet ***v6; // esi
  char *v7; // eax
  survarium::bullet_manager *v8; // ecx
  survarium::bullet ***v9; // esi
  survarium::bullet ***v10; // esi
  vostok::buffer_vector<survarium::bullet *> *v11; // edi
  int m_variable; // esi
  vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock> *v13; // ecx
  survarium::bullet *impl; // eax
  int v15; // eax
  vostok::buffer_vector<survarium::bullet *> *v16; // ecx
  bool v17; // zf
  unsigned int v18; // [esp+0h] [ebp-14h]
  unsigned int m_id; // [esp+10h] [ebp-4h]

  v4 = readera;
  v5 = time_offset;
  v6 = (survarium::bullet ***)time_offset[1];
  time_offset = *v6;
  v5[1] = (survarium::bullet *)(v6 + 1);
  v7 = (char *)time_offset + (_DWORD)v4;
  v8 = (survarium::bullet_manager *)reader;
  LODWORD(reader[1].m_start_position.y) = v7;
  v9 = (survarium::bullet ***)v5[1];
  time_offset = *v9;
  v5[1] = (survarium::bullet *)(v9 + 1);
  reader->m_id = (unsigned int)time_offset;
  v10 = (survarium::bullet ***)v5[1];
  time_offset = *v10;
  v5[1] = (survarium::bullet *)(v10 + 1);
  LODWORD(reader->m_position.x) = time_offset;
  m_id = v5[1]->m_id;
  v5[1] = (survarium::bullet *)((char *)v5[1] + 4);
  v11 = (vostok::buffer_vector<survarium::bullet *> *)&reader->m_position.elements[1];
  while ( LODWORD(reader->m_position.y) != LODWORD(reader->m_position.z) )
  {
    time_offset = v11->m_begin;
    survarium::bullet_manager::destroy_bullet(v8, (vostok::render::ambient_light **const *)&time_offset, 0);
    v8 = (survarium::bullet_manager *)reader;
  }
  if ( m_id )
  {
    while ( 1 )
    {
      m_variable = (int)v8->m_bullets_allocator_ref.m_variable;
      type_info::raw_name(&survarium::bullet `RTTI Type Descriptor');
      impl = (survarium::bullet *)vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::allocate_impl(
                                    v13,
                                    m_variable);
      if ( impl )
        survarium::bullet::bullet(
          reader,
          impl,
          LODWORD(reader[1].m_start_position.y),
          (const vostok::math::float3 *)&reader->m_velocity.elements[1],
          (vostok::math::float3 *)v5,
          readera,
          v18);
      else
        v15 = 0;
      v16 = *(vostok::buffer_vector<survarium::bullet *> **)(v15 + 52);
      v17 = LOBYTE(v16[29].m_begin) == 0;
      time_offset = (survarium::bullet **)v15;
      if ( !v17 )
      {
        v16 = *(vostok::buffer_vector<survarium::bullet *> **)&reader->m_ricochet_count;
        if ( v16 )
          (*((void (__thiscall **)(vostok::buffer_vector<survarium::bullet *> *, int))v16->m_begin + 5))(v16, v15);
      }
      vostok::buffer_vector<survarium::bullet *>::push_back(v16, (int)v11, (survarium::bullet **)&time_offset);
      if ( !--m_id )
        break;
      v8 = (survarium::bullet_manager *)reader;
    }
  }
}
