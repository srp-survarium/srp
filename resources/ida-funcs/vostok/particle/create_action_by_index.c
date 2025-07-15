void __usercall vostok::particle::create_action_by_index(
        vostok::mutable_buffer *buffer@<edi>,
        vostok::particle::particle_emitter *emitter@<eax>,
        int index@<edx>)
{
  char *v4; // eax
  char *v5; // esi
  char *v6; // esi
  char *v7; // eax
  char *m_data; // eax
  char *v9; // esi
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax

  switch ( index )
  {
    case 3:
      m_data = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)m_data + 3) = 0;
        *((_DWORD *)m_data + 2) = 0;
        *(_DWORD *)m_data = &vostok::particle::particle_action_source::`vftable';
      }
      else
      {
        m_data = 0;
      }
      buffer->m_data += 256;
      buffer->m_size -= 256;
      emitter->m_source_action.pointer = (vostok::particle::particle_action_source *)m_data;
      return;
    case 4:
      v4 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v4 + 3) = 0;
        *((_DWORD *)v4 + 2) = 0;
        *(_DWORD *)v4 = &vostok::particle::particle_action_initial_color::`vftable';
        *((_DWORD *)v4 + 16) = 0;
        *((_DWORD *)v4 + 17) = 0;
      }
      buffer->m_data += 88;
      buffer->m_size -= 88;
      return;
    case 5:
      v6 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_12;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 2) = 0;
      *(_DWORD *)v6 = &vostok::particle::particle_action_initial_velocity::`vftable';
      goto LABEL_11;
    case 6:
      v5 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_8;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *(_DWORD *)v5 = &vostok::particle::particle_action_initial_size::`vftable';
      goto LABEL_7;
    case 7:
      v6 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_12;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 2) = 0;
      *(_DWORD *)v6 = &vostok::particle::particle_action_initial_rotation::`vftable';
      goto LABEL_11;
    case 8:
      v6 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_12;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 2) = 0;
      *(_DWORD *)v6 = &vostok::particle::particle_action_initial_rotation_rate::`vftable';
      goto LABEL_11;
    case 9:
      if ( buffer->m_data )
        vostok::particle::particle_action_billboard::particle_action_billboard(0, buffer->m_data);
      else
        v11 = 0;
      buffer->m_data += 216;
      buffer->m_size -= 216;
      goto LABEL_42;
    case 10:
      v11 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_45;
      *((_DWORD *)v11 + 3) = 0;
      *((_DWORD *)v11 + 2) = 0;
      *(_DWORD *)v11 = &vostok::particle::particle_action_mesh::`vftable';
      goto LABEL_46;
    case 11:
      v11 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v11 + 3) = 0;
        *((_DWORD *)v11 + 2) = 0;
        *(_DWORD *)v11 = &vostok::particle::particle_action_trail::`vftable';
      }
      else
      {
        v11 = 0;
      }
      buffer->m_data += 48;
      buffer->m_size -= 48;
      goto LABEL_42;
    case 12:
      v11 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v11 + 3) = 0;
        *((_DWORD *)v11 + 2) = 0;
        *(_DWORD *)v11 = &vostok::particle::particle_action_beam::`vftable';
      }
      else
      {
        v11 = 0;
      }
      buffer->m_data += 56;
      buffer->m_size -= 56;
      goto LABEL_42;
    case 13:
      v11 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v11 + 3) = 0;
        *((_DWORD *)v11 + 2) = 0;
        *(_DWORD *)v11 = &vostok::particle::particle_action_decal::`vftable';
      }
      else
      {
LABEL_45:
        v11 = 0;
      }
LABEL_46:
      buffer->m_data += 24;
      buffer->m_size -= 24;
LABEL_42:
      emitter->m_data_type_action.pointer = (vostok::particle::particle_action_data_type *)v11;
      return;
    case 15:
      v7 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v7 + 3) = 0;
        *((_DWORD *)v7 + 2) = 0;
        *(_DWORD *)v7 = &vostok::particle::particle_action_color_over_lifetime::`vftable';
        *((_DWORD *)v7 + 6) = 0;
        *((_DWORD *)v7 + 7) = 0;
      }
      buffer->m_data += 48;
      buffer->m_size -= 48;
      return;
    case 17:
      v6 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_12;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 2) = 0;
      *(_DWORD *)v6 = &vostok::particle::particle_action_velocity_over_lifetime::`vftable';
      goto LABEL_11;
    case 18:
      v16 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v16 + 3) = 0;
        *((_DWORD *)v16 + 2) = 0;
        *(_DWORD *)v16 = &vostok::particle::particle_action_random_velocity::`vftable';
      }
      else
      {
        v16 = 0;
      }
      buffer->m_data += 264;
      buffer->m_size -= 264;
      emitter->m_target_action.pointer = (vostok::particle::particle_action_random_velocity *)v16;
      return;
    case 20:
      v6 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_12;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 2) = 0;
      *(_DWORD *)v6 = &vostok::particle::particle_action_rotation_over_lifetime::`vftable';
      goto LABEL_11;
    case 21:
      v5 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_8;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *(_DWORD *)v5 = &vostok::particle::particle_action_rotation_over_velocity::`vftable';
      goto LABEL_7;
    case 23:
      v5 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_8;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *(_DWORD *)v5 = &vostok::particle::particle_action_size_over_lifetime::`vftable';
LABEL_7:
      vostok::math::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(0, (_DWORD *)v5 + 6);
LABEL_8:
      buffer->m_data += 232;
      buffer->m_size -= 232;
      return;
    case 24:
      v6 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_12;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 2) = 0;
      *(_DWORD *)v6 = &vostok::particle::particle_action_size_over_velocity::`vftable';
      goto LABEL_11;
    case 25:
      v14 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v14 + 3) = 0;
        *((_DWORD *)v14 + 2) = 0;
        *(_DWORD *)v14 = &vostok::particle::particle_event_on_death::`vftable';
      }
      goto LABEL_37;
    case 26:
      v13 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v13 + 3) = 0;
        *((_DWORD *)v13 + 2) = 0;
        *(_DWORD *)v13 = &vostok::particle::particle_event_on_birth::`vftable';
      }
      goto LABEL_37;
    case 27:
      v15 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v15 + 3) = 0;
        *((_DWORD *)v15 + 2) = 0;
        *(_DWORD *)v15 = &vostok::particle::particle_event_on_collide::`vftable';
      }
      goto LABEL_37;
    case 28:
      v12 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v12 + 3) = 0;
        *((_DWORD *)v12 + 2) = 0;
        *(_DWORD *)v12 = &vostok::particle::particle_event_on_play::`vftable';
      }
      goto LABEL_37;
    case 29:
      if ( buffer->m_data )
        vostok::particle::particle_action_orbit::particle_action_orbit(0, buffer->m_data);
      buffer->m_data += 896;
      buffer->m_size -= 896;
      return;
    case 30:
      v6 = buffer->m_data;
      if ( !buffer->m_data )
        goto LABEL_12;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 2) = 0;
      *(_DWORD *)v6 = &vostok::particle::particle_action_acceleration::`vftable';
LABEL_11:
      vostok::math::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(0, (_DWORD *)v6 + 6);
LABEL_12:
      buffer->m_data += 224;
      buffer->m_size -= 224;
      break;
    case 31:
      v18 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v18 + 3) = 0;
        *((_DWORD *)v18 + 2) = 0;
        *(_DWORD *)v18 = &vostok::particle::particle_action_kill_volume::`vftable';
      }
      goto LABEL_71;
    case 32:
      v19 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v19 + 3) = 0;
        *((_DWORD *)v19 + 2) = 0;
        *(_DWORD *)v19 = &vostok::particle::particle_action_gravity::`vftable';
      }
      goto LABEL_37;
    case 33:
      v20 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v20 + 3) = 0;
        *((_DWORD *)v20 + 2) = 0;
        *(_DWORD *)v20 = &vostok::particle::particle_action_turbulence::`vftable';
      }
      buffer->m_data += 288;
      buffer->m_size -= 288;
      return;
    case 34:
      if ( buffer->m_data )
        vostok::particle::particle_action_light::particle_action_light(0, buffer->m_data);
      buffer->m_data += 472;
      buffer->m_size -= 472;
      return;
    case 35:
      v9 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v9 + 3) = 0;
        *((_DWORD *)v9 + 2) = 0;
        *(_DWORD *)v9 = &vostok::particle::particle_action_animated_source::`vftable';
        vostok::math::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(0, (_DWORD *)v9 + 6);
      }
      buffer->m_data += 336;
      buffer->m_size -= 336;
      return;
    case 36:
      v10 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v10 + 3) = 0;
        *((_DWORD *)v10 + 2) = 0;
        *(_DWORD *)v10 = &vostok::particle::particle_action_animation_impulse::`vftable';
      }
LABEL_37:
      buffer->m_data += 32;
      buffer->m_size -= 32;
      break;
    case 37:
      v17 = buffer->m_data;
      if ( buffer->m_data )
      {
        *((_DWORD *)v17 + 3) = 0;
        *((_DWORD *)v17 + 2) = 0;
        *(_DWORD *)v17 = &vostok::particle::particle_action_random_direction::`vftable';
      }
LABEL_71:
      buffer->m_data += 264;
      buffer->m_size -= 264;
      break;
    default:
      return;
  }
}
