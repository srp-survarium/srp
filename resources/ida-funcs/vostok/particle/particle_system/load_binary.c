void __thiscall vostok::particle::particle_system::load_binary(
        vostok::particle::particle_system *this,
        vostok::particle::particle_emitter *buffer,
        vostok::mutable_buffer *buffera)
{
  vostok::particle::particle_emitter *v3; // ecx
  vostok::platform_pointer_selector<vostok::particle::particle_action_source,1>::helper *p_m_source_action; // eax
  char *m_data; // edx
  unsigned int v7; // edi
  char *v8; // esi
  char *v9; // edx
  int v10; // edx
  char *v11; // esi
  int v12; // eax
  vostok::math::curve_line_points<float,0> *v13; // ecx
  int v14; // eax
  vostok::particle::particle_action_source *v15; // esi
  int v16; // eax
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ebx
  _DWORD *v20; // esi
  int v21; // esi
  int v22; // [esp+10h] [ebp-14h]
  _DWORD *v23; // [esp+10h] [ebp-14h]
  char *v24; // [esp+14h] [ebp-10h]
  vostok::particle::particle_action_source *v25; // [esp+14h] [ebp-10h]
  vostok::particle::particle_action_source *v26; // [esp+18h] [ebp-Ch]
  int v27; // [esp+18h] [ebp-Ch]
  int v28; // [esp+1Ch] [ebp-8h]
  unsigned int v29; // [esp+1Ch] [ebp-8h]
  vostok::particle::particle_action_source *v30; // [esp+20h] [ebp-4h]
  unsigned int v31; // [esp+20h] [ebp-4h]
  int v32; // [esp+20h] [ebp-4h]
  vostok::particle::particle_emitter *v33; // [esp+2Ch] [ebp+8h]
  vostok::mutable_buffer *bufferb; // [esp+30h] [ebp+Ch]
  vostok::mutable_buffer *bufferc; // [esp+30h] [ebp+Ch]
  vostok::mutable_buffer *bufferd; // [esp+30h] [ebp+Ch]
  vostok::mutable_buffer *buffere; // [esp+30h] [ebp+Ch]
  vostok::mutable_buffer *bufferf; // [esp+30h] [ebp+Ch]

  v3 = buffer;
  p_m_source_action = &buffer->m_source_action;
  buffer->m_source_action.pointer = *(vostok::particle::particle_action_source **)buffera->m_data;
  buffera->m_data += 4;
  m_data = buffera->m_data;
  buffera->m_size -= 4;
  v7 = 0;
  buffer->m_particle_spawn_rate_curve.m_evaluate_type = (vostok::math::enum_evaluate_type)m_data;
  v8 = m_data;
  bufferb = 0;
  if ( buffer->m_source_action.pointer )
  {
    do
    {
      v9 = v8;
      v8 += 32;
      if ( v9 )
      {
        *(_DWORD *)v9 = 0;
        *((_DWORD *)v9 + 1) = 0;
        *((_DWORD *)v9 + 2) = 0;
        *((_DWORD *)v9 + 3) = 0;
      }
      bufferb = (vostok::mutable_buffer *)((char *)bufferb + 1);
    }
    while ( (vostok::particle::particle_action_source *)bufferb < p_m_source_action->pointer );
  }
  v10 = 32 * (int)p_m_source_action->pointer;
  buffera->m_data += v10;
  buffera->m_size -= v10;
  v30 = 0;
  if ( p_m_source_action->pointer )
  {
    bufferc = 0;
    do
    {
      v11 = (char *)bufferc + v3->m_particle_spawn_rate_curve.m_evaluate_type;
      *((_DWORD *)v11 + 2) = buffera->m_data;
      if ( *((_DWORD *)v11 + 4) )
      {
        do
        {
          if ( buffera->m_data )
          {
            vostok::particle::particle_emitter::particle_emitter(v3, buffera->m_data);
            v3 = buffer;
          }
          buffera->m_data += 384;
          buffera->m_size -= 384;
          ++v7;
        }
        while ( v7 < *((_DWORD *)v11 + 4) );
      }
      v30 = (vostok::particle::particle_action_source *)((char *)v30 + 1);
      bufferc += 4;
      p_m_source_action = &v3->m_source_action;
      v7 = 0;
    }
    while ( v30 < v3->m_source_action.pointer );
  }
  v26 = 0;
  if ( p_m_source_action->pointer )
  {
    v28 = 0;
    do
    {
      v12 = v28 + v3->m_particle_spawn_rate_curve.m_evaluate_type;
      v31 = 0;
      v22 = v12;
      if ( *(_DWORD *)(v12 + 16) )
      {
        bufferd = 0;
        while ( 1 )
        {
          v24 = (char *)bufferd + *(_DWORD *)(v12 + 8);
          vostok::math::curve_line_ranged_base::load_binary(
            (vostok::math::curve_line_ranged_base *)v24 + 2,
            buffera,
            (vostok::math::curve_line_points<float,0> *)v3);
          vostok::math::curve_line_ranged_base::load_binary(
            (vostok::math::curve_line_ranged_base *)(v24 + 200),
            buffera,
            v13);
          bufferd += 48;
          *((_DWORD *)v24 + 80) = buffera->m_data;
          v14 = 12 * *((_DWORD *)v24 + 85);
          buffera->m_data += v14;
          buffera->m_size -= v14;
          v3 = (vostok::particle::particle_emitter *)++v31;
          if ( v31 >= *(_DWORD *)(v22 + 16) )
            break;
          v12 = v22;
        }
        v3 = buffer;
      }
      v26 = (vostok::particle::particle_action_source *)((char *)v26 + 1);
      v28 += 32;
      p_m_source_action = &v3->m_source_action;
    }
    while ( v26 < v3->m_source_action.pointer );
  }
  v15 = 0;
  if ( p_m_source_action->pointer )
  {
    buffere = 0;
    do
    {
      vostok::particle::particle_system::load_lod_actions_binary(
        (vostok::particle::particle_system *)v3,
        (vostok::particle::particle_system *)v3,
        (vostok::mutable_buffer *)((char *)buffere + v3->m_particle_spawn_rate_curve.m_evaluate_type),
        buffera);
      buffere += 4;
      v3 = buffer;
      v15 = (vostok::particle::particle_action_source *)((char *)v15 + 1);
    }
    while ( v15 < buffer->m_source_action.pointer );
  }
  v25 = 0;
  if ( v3->m_source_action.pointer )
  {
    v32 = 0;
    do
    {
      v16 = v32 + v3->m_particle_spawn_rate_curve.m_evaluate_type;
      v29 = 0;
      v17 = *(_DWORD *)(v16 + 16);
      if ( v17 )
      {
        v27 = 0;
        do
        {
          v18 = *(_DWORD *)(v16 + 8);
          v19 = v27 + v18;
          if ( *(_WORD *)(v27 + v18 + 380) && (v33 = 0, bufferf = 0, v17) )
          {
            v20 = (_DWORD *)(v18 + 296);
            v23 = v20;
            while ( 1 )
            {
              v21 = *v20;
              if ( v21 )
                break;
LABEL_33:
              bufferf = (vostok::mutable_buffer *)((char *)bufferf + 1);
              v20 = v23 + 96;
              v23 += 96;
              if ( (unsigned int)bufferf >= v17 )
                goto LABEL_34;
            }
            while ( v33 != (vostok::particle::particle_emitter *)(*(unsigned __int16 *)(v19 + 380) - 1) )
            {
              v21 = *(_DWORD *)(v21 + 8);
              v33 = (vostok::particle::particle_emitter *)((char *)v33 + 1);
              if ( !v21 )
                goto LABEL_33;
            }
          }
          else
          {
LABEL_34:
            v21 = 0;
          }
          ++v29;
          v27 += 384;
          *(_DWORD *)(v19 + 328) = v21;
          v17 = *(_DWORD *)(v16 + 16);
        }
        while ( v29 < v17 );
      }
      v25 = (vostok::particle::particle_action_source *)((char *)v25 + 1);
      v32 += 32;
    }
    while ( v25 < v3->m_source_action.pointer );
  }
}
