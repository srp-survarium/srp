void __thiscall vostok::render::particle_shader_constants::set(
        vostok::render::particle_shader_constants *this,
        const vostok::math::float3 up_vector,
        vostok::math::float3 right_vector,
        vostok::math::float3 view_location,
        vostok::particle::enum_particle_locked_axis locked_axis,
        const vostok::math::float4x4 *screen_alignment,
        vostok::particle::enum_particle_screen_alignment screen_alignmenta)
{
  float x; // ebx
  _WORD *v8; // eax
  vostok::particle::enum_particle_screen_alignment v9; // ebp
  const char *m_conflicted_key_name; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  const vostok::math::float4x4 *v16; // xmm0_4
  vostok::particle::enum_particle_screen_alignment v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // ecx
  float f_use_fixed_axis; // [esp+10h] [ebp-1Ch] BYREF
  vostok::math::float3 rotation_fixed_axis; // [esp+14h] [ebp-18h] BYREF
  vostok::math::float3 v28; // [esp+20h] [ebp-Ch]

  x = up_vector.x;
  v8 = *(_WORD **)LODWORD(up_vector.x);
  v9 = (vostok::particle::enum_particle_screen_alignment)screen_alignment;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *(_DWORD *)(*(_DWORD *)LODWORD(up_vector.x) + 36) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                            + 572) )
  {
    v11 = (unsigned __int16)v8[6];
    if ( v11 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        (unsigned __int16)v8[7],
        (unsigned __int8)v8[4],
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * v11),
        (const char *)&right_vector.elements[1]);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  v12 = *(_DWORD *)(LODWORD(x) + 4);
  if ( *(_DWORD *)(v12 + 36) == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v13 = *(unsigned __int16 *)(v12 + 12);
    if ( v13 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(v12 + 14),
        (unsigned __int8)*(_WORD *)(v12 + 8),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v13),
        (const char *)&up_vector.elements[1]);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  v14 = *(_DWORD *)(LODWORD(x) + 12);
  if ( *(_DWORD *)(v14 + 36) == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v15 = *(unsigned __int16 *)(v14 + 12);
    if ( v15 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(v14 + 14),
        (unsigned __int8)*(_WORD *)(v14 + 8),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v15),
        (const char *)&view_location.elements[1]);
  }
  v16 = 0;
  v17 = screen_alignmenta;
  ++*((_DWORD *)m_conflicted_key_name + 23);
  screen_alignment = 0;
  f_use_fixed_axis = 0.0;
  up_vector.x = -1.0;
  memset(&rotation_fixed_axis, 0, sizeof(rotation_fixed_axis));
  if ( v17 == particle_screen_alignment_to_axis )
  {
    v28.x = (float)(v9 == 6);
    v28.y = (float)(v9 == (particle_screen_alignment_to_axis|0x4));
    v28.z = (float)(v9 == 8);
    rotation_fixed_axis = v28;
    if ( v9 == 6 || v9 == (particle_screen_alignment_to_axis|0x4) || v9 == 8 )
      LODWORD(f_use_fixed_axis) = clear_value;
    else
      up_vector.x = (float)v9;
  }
  else
  {
    if ( v17 == particle_screen_alignment_to_path )
      v16 = clear_value;
    screen_alignment = v16;
  }
  v18 = *(_DWORD *)(LODWORD(x) + 24);
  if ( *(_DWORD *)(v18 + 36) == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v19 = *(unsigned __int16 *)(v18 + 12);
    if ( v19 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(v18 + 14),
        (unsigned __int8)*(_WORD *)(v18 + 8),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v19),
        (const char *)&rotation_fixed_axis);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  v20 = *(_DWORD *)(LODWORD(x) + 28);
  if ( *(_DWORD *)(v20 + 36) == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v21 = *(unsigned __int16 *)(v20 + 12);
    if ( v21 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(v20 + 14),
        (unsigned __int8)*(_WORD *)(v20 + 8),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v21),
        (const char *)&up_vector);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  v22 = *(_DWORD *)(LODWORD(x) + 8);
  if ( *(_DWORD *)(v22 + 36) == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v23 = *(unsigned __int16 *)(v22 + 12);
    if ( v23 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(v22 + 14),
        (unsigned __int8)*(_WORD *)(v22 + 8),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v23),
        (const char *)&screen_alignment);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  v24 = *(_DWORD *)(LODWORD(x) + 20);
  if ( *(_DWORD *)(v24 + 36) != *((_DWORD *)m_conflicted_key_name + 572)
    || (v25 = *(unsigned __int16 *)(v24 + 12), v25 == 0xFFFF) )
  {
    ++*((_DWORD *)m_conflicted_key_name + 23);
  }
  else
  {
    vostok::render::shader_constant_buffer::set_memory(
      *(unsigned __int16 *)(v24 + 14),
      (unsigned __int8)*(_WORD *)(v24 + 8),
      *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v25),
      (const char *)&f_use_fixed_axis);
    ++*((_DWORD *)m_conflicted_key_name + 23);
  }
}
