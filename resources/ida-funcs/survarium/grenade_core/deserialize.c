void __thiscall survarium::grenade_core::deserialize(
        survarium::grenade_core *this,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  vostok::network_core::buffer_reader *v4; // eax
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v6; // esi
  int v7; // edx
  unsigned int v8; // edx
  bool v9; // zf
  unsigned __int8 *v10; // esi
  const unsigned __int8 *v11; // ecx
  int v12; // edi
  int v13; // eax
  vostok::physics::bt_dynamic_rigid_body **v14; // ecx
  unsigned __int8 v15; // [esp+Fh] [ebp-69h]
  char v16; // [esp+Fh] [ebp-69h]
  vostok::math::float3 v; // [esp+14h] [ebp-64h] BYREF
  vostok::math::float3 v18; // [esp+20h] [ebp-58h] BYREF
  vostok::math::float3 v19; // [esp+2Ch] [ebp-4Ch]
  unsigned __int8 dst[64]; // [esp+38h] [ebp-40h] BYREF

  survarium::grenade_set_core::current_time_in_ms((survarium::grenade_set_core *)this, *(_DWORD *)&this->m_exploded);
  v4 = reader;
  m_pointer = reader->m_pointer;
  v15 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  LOBYTE(this->vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags) = (v15 & 4) != 0;
  if ( (v15 & 2) != 0 )
  {
    v6 = reader->m_pointer;
    v7 = *(_DWORD *)v6;
    reader->m_pointer = v6 + 4;
    v8 = time_offset + v7;
    if ( this->m_deallocation_thread_id != -1 )
    {
      this->m_deallocation_thread_id = v8;
      goto LABEL_8;
    }
    (*(void (__thiscall **)(unsigned __int16 *, unsigned int))(*(_DWORD *)&this[-1].m_game_material_id + 8))(
      &this[-1].m_game_material_id,
      v8);
  }
  else
  {
    if ( this->m_deallocation_thread_id == -1 )
      goto LABEL_8;
    (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)&this[-1].m_game_material_id + 12))(&this[-1].m_game_material_id);
  }
  v4 = reader;
LABEL_8:
  v9 = (v15 & 1) == 0;
  memset(&v, 0, sizeof(v));
  memset(&v18, 0, sizeof(v18));
  v16 = v15 & 1;
  if ( !v9 )
  {
    v10 = (unsigned __int8 *)v4->m_pointer;
    memcpy(dst, v10, sizeof(dst));
    reader->m_pointer = v10 + 64;
    qmemcpy(&this->m_physics_world, dst, 0x40u);
    v11 = reader->m_pointer;
    v19 = *(vostok::math::float3 *)v11;
    v = v19;
    v11 += 12;
    reader->m_pointer = v11;
    v19 = *(vostok::math::float3 *)v11;
    *(_QWORD *)&v18.x = *(_QWORD *)&v19.x;
    reader->m_pointer = v11 + 12;
    v18.z = v19.z;
  }
  if ( v16 )
  {
    if ( *(_DWORD *)&this->m_inlined_in_fat )
    {
      (*(void (__thiscall **)(_DWORD, vostok::physics::world **))(*(_DWORD *)LODWORD(this->m_render_transform.c.z) + 24))(
        LODWORD(this->m_render_transform.c.z),
        &this->m_physics_world);
      v12 = **(_DWORD **)&this->m_inlined_in_fat;
      v13 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(this->m_render_transform.c.z) + 4))(LODWORD(this->m_render_transform.c.z));
      (*(void (__thiscall **)(_DWORD, int))(v12 + 32))(*(_DWORD *)&this->m_inlined_in_fat, v13);
    }
    else
    {
      (*(void (__stdcall **)(vostok::physics::world **, vostok::math::float3 *))(*(_DWORD *)&this[-1].m_game_material_id
                                                                               + 16))(
        &this->m_physics_world,
        &v);
    }
    vostok::physics::bt_dynamic_rigid_body::set_linear_velocity(
      &v,
      (vostok::physics::bt_dynamic_rigid_body *)LODWORD(this->m_render_transform.c.z));
    vostok::physics::bt_dynamic_rigid_body::set_angular_velocity(*v14, &v18);
  }
  else if ( *(_DWORD *)&this->m_inlined_in_fat )
  {
    (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)&this[-1].m_game_material_id + 20))(&this[-1].m_game_material_id);
  }
}
