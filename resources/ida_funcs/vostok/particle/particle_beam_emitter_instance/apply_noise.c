void __thiscall vostok::particle::particle_beam_emitter_instance::apply_noise(
        vostok::particle::particle_beam_emitter_instance *this,
        unsigned int beam_index,
        const vostok::math::float3 *up_vector,
        const vostok::math::float3 *right_vector,
        float __formal,
        unsigned int a6,
        bool a7,
        vostok::particle::base_particle *P,
        unsigned int num_particles)
{
  vostok::math::float3 *v9; // eax
  vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // eax
  vostok::math::float3 *v12; // eax
  unsigned int *v13; // eax
  __int64 *v14; // eax
  vostok::math::float3 *v15; // eax
  vostok::math::float3 time; // [esp+0h] [ebp-154h]
  vostok::math::float3 timea; // [esp+0h] [ebp-154h]
  vostok::math::float3 v18; // [esp+Ch] [ebp-148h]
  vostok::math::float3 v19; // [esp+Ch] [ebp-148h]
  float other_z; // [esp+18h] [ebp-13Ch]
  float other_za; // [esp+18h] [ebp-13Ch]
  vostok::particle::curve_line_points<vostok::math::float3_pod,0> *v23; // [esp+48h] [ebp-10Ch]
  vostok::particle::curve_line_points<vostok::math::float3_pod,0> *v24; // [esp+50h] [ebp-104h]
  _BYTE v25[56]; // [esp+58h] [ebp-FCh] BYREF
  vostok::math::float3_pod v26; // [esp+90h] [ebp-C4h] BYREF
  vostok::math::float3_pod m_beams_source_position; // [esp+9Ch] [ebp-B8h]
  vostok::math::float3 v28; // [esp+A8h] [ebp-ACh] BYREF
  vostok::math::float3 v29; // [esp+B4h] [ebp-A0h]
  vostok::math::float3 v30; // [esp+C0h] [ebp-94h] BYREF
  __int64 v31; // [esp+CCh] [ebp-88h]
  unsigned int v32; // [esp+D4h] [ebp-80h]
  vostok::math::float3 v33; // [esp+D8h] [ebp-7Ch] BYREF
  unsigned int v34; // [esp+E4h] [ebp-70h]
  __int64 v35; // [esp+E8h] [ebp-6Ch]
  vostok::math::float3 v36; // [esp+F0h] [ebp-64h] BYREF
  vostok::math::float3 v37; // [esp+FCh] [ebp-58h] BYREF
  vostok::math::float3 v38; // [esp+108h] [ebp-4Ch] BYREF
  vostok::math::float3 v39; // [esp+114h] [ebp-40h] BYREF
  vostok::math::float3 result; // [esp+120h] [ebp-34h] BYREF
  vostok::math::float3 v41; // [esp+12Ch] [ebp-28h] BYREF
  float v42; // [esp+138h] [ebp-1Ch]
  unsigned int j; // [esp+13Ch] [ebp-18h]
  float alpha; // [esp+140h] [ebp-14h]
  vostok::math::float3 p; // [esp+144h] [ebp-10h] BYREF
  unsigned int i; // [esp+150h] [ebp-4h]

  if ( num_particles >= 2 )
  {
    for ( i = 0; i < 0xF; ++i )
    {
      alpha = (double)i / 14.0;
      vostok::particle::linear_interpolation<vostok::math::float3>(
        &p,
        this->m_beams_source_position,
        this->m_beams_end_position,
        alpha);
      if ( i )
      {
        if ( i != 14 )
        {
          other_z = this->m_random_offsets[beam_index][i].x;
          v18 = *up_vector;
          time = *vostok::math::float3_pod::operator-(&up_vector->vostok::math::float3_pod, &v41);
          v9 = vostok::particle::linear_interpolation<vostok::math::float3>(&result, time, v18, other_z);
          v10 = vostok::math::operator*(v9, &v39, &this->m_particle_action_beam->m_noise);
          vostok::math::float3_pod::operator+=(v10, &p);
          other_za = this->m_random_offsets[beam_index][i].y;
          v19 = *right_vector;
          timea = *vostok::math::float3_pod::operator-(&right_vector->vostok::math::float3_pod, &v38);
          v11 = vostok::particle::linear_interpolation<vostok::math::float3>(&v37, timea, v19, other_za);
          v12 = vostok::math::operator*(v11, &v36, &this->m_particle_action_beam->m_noise);
          vostok::math::float3_pod::operator+=(v12, &p);
        }
      }
      vostok::math::float3::float3(&v33, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
      v34 = *v13;
      v35 = *(_QWORD *)(v13 + 1);
      vostok::math::float3::float3(&v30, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
      v31 = *v14;
      v32 = *((_DWORD *)v14 + 2);
      v29 = p;
      v24 = &this->m_curve_line[beam_index];
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v24);
      *(vostok::math::float3 *)v25 = v29;
      *(vostok::math::float3 *)&v25[12] = v29;
      *(_QWORD *)&v25[24] = v31;
      *(_QWORD *)&v25[32] = __PAIR64__(v34, v32);
      *(_QWORD *)&v25[40] = v35;
      *(_QWORD *)&v25[48] = LODWORD(alpha) | 0x100000000LL;
      qmemcpy(&v24->points.pointer[i], v25, sizeof(v24->points.pointer[i]));
      v23 = &this->m_curve_line[beam_index];
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      v23->points.pointer[i].interp_type = curve_interp_type;
    }
    vostok::particle::curve_line_points<vostok::math::float3_pod,0>::recalculate_ranges(&this->m_curve_line[beam_index]);
    vostok::particle::curve_line_points<vostok::math::float3_pod,0>::calc_tangents(&this->m_curve_line[beam_index]);
    for ( j = 0; j < num_particles; ++j )
    {
      v42 = (double)j / (double)(num_particles - 1);
      m_beams_source_position = (vostok::math::float3_pod)this->m_beams_source_position;
      v15 = (vostok::math::float3 *)vostok::particle::curve_line_points<vostok::math::float3_pod,0>::evaluate(
                                      &this->m_curve_line[beam_index],
                                      &v26,
                                      v42,
                                      m_beams_source_position,
                                      range_time_type,
                                      0.0,
                                      0.0);
      vostok::math::float3::float3(v15, &v28);
      P->position = v28;
      P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(P);
    }
  }
}
