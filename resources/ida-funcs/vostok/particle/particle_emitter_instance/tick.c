void __thiscall vostok::particle::particle_emitter_instance::tick(
        vostok::particle::particle_emitter_instance *this,
        int time_delta,
        bool create_new_particles,
        float alpha)
{
  vostok::particle::particle_emitter_instance *v4; // esi
  vostok::math::aabb *v5; // ecx
  int p_m_emitter_time; // ecx
  float v7; // xmm0_4
  vostok::particle::particle_emitter *m_emitter; // eax
  float m_duration; // xmm0_4
  unsigned int *p_m_num_loops; // eax
  vostok::particle::particle_emitter *v11; // eax
  unsigned int v12; // ebx
  int v13; // edx
  vostok::particle::burst_entry *v14; // eax
  unsigned int m_num_loops; // eax
  vostok::particle::base_particle *m_first; // ebx
  vostok::particle::particle_emitter_instance *v17; // edx
  vostok::particle::particle_action *i; // esi
  float y; // xmm1_4
  float z; // xmm2_4
  float *p_x; // esi
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  double v26; // st7
  vostok::particle::particle_system_instance_impl *m_particle_system_instance; // esi
  unsigned __int16 surface_id; // ax
  unsigned int surface_bone_index; // eax
  int v30; // edx
  int *v31; // ecx
  int v32; // edx
  float v33; // xmm1_4
  float x; // xmm2_4
  float v35; // xmm0_4
  vostok::particle::engine *m_engine; // ecx
  vostok::particle::particle_system_instance_impl *v37; // eax
  vostok::particle::engine_vtbl *v38; // edx
  float v39; // xmm1_4
  float v40; // xmm4_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm1_4
  float v46; // xmm4_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm0_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm4_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm1_4
  float v59; // xmm4_4
  float v60; // xmm3_4
  float v61; // xmm0_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm2_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm0_4
  float v70; // ecx
  float v71; // xmm1_4
  float v72; // xmm1_4
  float v73; // xmm0_4
  float v74; // xmm4_4
  float v75; // xmm5_4
  float v76; // xmm5_4
  float *v77; // eax
  float v78; // xmm2_4
  float v79; // xmm4_4
  float v80; // xmm5_4
  float v81; // xmm0_4
  float v82; // xmm5_4
  float v83; // xmm1_4
  float v84; // xmm4_4
  float v85; // xmm2_4
  float v86; // xmm3_4
  float v87; // xmm0_4
  double v88; // st7
  float v89; // xmm0_4
  float v90; // xmm0_4
  vostok::math::aabb *p_m_aabbox; // edi
  vostok::particle::particle_emitter_instance *v92; // ecx
  vostok::particle::particle_emitter_instance *v93; // edi
  vostok::particle::particle_action *j; // esi
  float v95; // xmm0_4
  float duration; // xmm1_4
  float v97; // xmm1_4
  vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v98; // ecx
  vostok::particle::base_particle *v99; // eax
  vostok::particle::particle_world *v100; // ecx
  vostok::particle::particle_emitter_instance *v101; // [esp+30h] [ebp-2A4h]
  int v102; // [esp+40h] [ebp-294h] BYREF
  vostok::particle::particle_emitter_instance *v103; // [esp+44h] [ebp-290h]
  float v104; // [esp+48h] [ebp-28Ch]
  float v105; // [esp+4Ch] [ebp-288h]
  vostok::math::float3 old_position; // [esp+50h] [ebp-284h]
  vostok::math::float4x4 v107; // [esp+5Ch] [ebp-278h] BYREF
  vostok::math::float3 max; // [esp+A0h] [ebp-234h]
  vostok::math::float4x4 v109; // [esp+ACh] [ebp-228h] BYREF
  float v110; // [esp+F0h] [ebp-1E4h]
  float v111; // [esp+F4h] [ebp-1E0h]
  float gravity_accumulation; // [esp+F8h] [ebp-1DCh]
  float v113; // [esp+FCh] [ebp-1D8h] BYREF
  float v114; // [esp+100h] [ebp-1D4h]
  float v115; // [esp+104h] [ebp-1D0h]
  float v116; // [esp+10Ch] [ebp-1C8h]
  float v117; // [esp+110h] [ebp-1C4h]
  float v118; // [esp+114h] [ebp-1C0h]
  float v119; // [esp+11Ch] [ebp-1B8h]
  float v120; // [esp+120h] [ebp-1B4h]
  float v121; // [esp+124h] [ebp-1B0h]
  float v122; // [esp+12Ch] [ebp-1A8h]
  float v123; // [esp+130h] [ebp-1A4h]
  float v124; // [esp+134h] [ebp-1A0h]
  vostok::math::float3 v125; // [esp+140h] [ebp-194h]
  vostok::math::aabb v126; // [esp+14Ch] [ebp-188h] BYREF
  __int64 v127; // [esp+164h] [ebp-170h]
  float v128; // [esp+16Ch] [ebp-168h]
  float v129; // [esp+170h] [ebp-164h]
  float v130; // [esp+174h] [ebp-160h]
  float v131; // [esp+178h] [ebp-15Ch]
  vostok::math::aabb v132; // [esp+17Ch] [ebp-158h] BYREF
  vostok::math::aabb v133; // [esp+194h] [ebp-140h] BYREF
  float v134; // [esp+1ACh] [ebp-128h]
  float v135; // [esp+1B0h] [ebp-124h]
  float v136; // [esp+1B4h] [ebp-120h]
  vostok::math::aabb v137; // [esp+1B8h] [ebp-11Ch] BYREF
  float v138; // [esp+1D4h] [ebp-100h]
  float v139; // [esp+1D8h] [ebp-FCh]
  float v140; // [esp+1DCh] [ebp-F8h]
  float v141; // [esp+1E4h] [ebp-F0h]
  float v142; // [esp+1E8h] [ebp-ECh]
  float v143; // [esp+1ECh] [ebp-E8h]
  float v144; // [esp+1F4h] [ebp-E0h]
  float v145; // [esp+1F8h] [ebp-DCh]
  float v146; // [esp+1FCh] [ebp-D8h]
  vostok::math::float4x4 v147; // [esp+204h] [ebp-D0h] BYREF
  vostok::math::float4x4 v148; // [esp+244h] [ebp-90h] BYREF
  vostok::math::float4x4 v149; // [esp+284h] [ebp-50h] BYREF
  char v150[12]; // [esp+2C8h] [ebp-Ch] BYREF

  v4 = this;
  v103 = this;
  if ( this->m_data_type_action )
  {
    vostok::particle::particle_emitter_instance::get_transform(this, this, &v107);
    v4->m_instance_color.w = alpha;
    vostok::math::aabb::zero(v5, &v4->m_aabbox);
    if ( v4->m_delayed )
    {
      v7 = v4->m_delay_time + *(float *)&time_delta;
      v4->m_delay_time = v7;
      if ( v7 <= v4->m_emitter->m_delay )
        return;
      v4->m_delayed = 0;
    }
    m_emitter = v4->m_emitter;
    if ( !m_emitter->m_user_controls_the_time )
    {
      p_m_emitter_time = (int)&v4->m_emitter_time;
      v4->m_emitter_time = v4->m_emitter_time + *(float *)&time_delta;
    }
    m_duration = m_emitter->m_duration;
    if ( m_duration > 0.001 )
    {
      m_duration = v4->m_emitter_time;
      if ( m_duration > v4->m_current_duration )
      {
        p_m_num_loops = &m_emitter->m_num_loops;
        if ( *p_m_num_loops )
        {
          ++v4->m_current_loop;
          vostok::math::clamp<unsigned int>(0, *p_m_num_loops);
          vostok::particle::particle_emitter_instance::recalc_duration(v101, (int)v4);
        }
        vostok::particle::particle_emitter_instance::recalc_duration(
          (vostok::particle::particle_emitter_instance *)p_m_emitter_time,
          (int)v4);
        m_duration = 0.0;
        v11 = v4->m_emitter;
        v4->m_emitter_time = 0.0;
        v12 = 0;
        if ( v11->m_num_burst_entries )
        {
          v13 = 0;
          do
          {
            v14 = &v4->m_emitter->m_burst_entries.pointer[v13];
            p_m_emitter_time = v14->count;
            if ( p_m_emitter_time < 0 )
            {
              p_m_emitter_time = -p_m_emitter_time;
              v14->count = p_m_emitter_time;
            }
            ++v12;
            ++v13;
          }
          while ( v12 < v4->m_emitter->m_num_burst_entries );
        }
      }
    }
    m_num_loops = v4->m_emitter->m_num_loops;
    if ( m_num_loops && v4->m_current_loop == m_num_loops )
      v4->m_waiting_for_end = 1;
    if ( v4->m_waiting_for_end && !v4->m_num_live_particles )
      v4->m_waiting_for_end = 0;
    if ( create_new_particles )
      vostok::particle::particle_emitter_instance::append_particles(
        (vostok::particle::particle_emitter_instance *)p_m_emitter_time,
        m_duration,
        (char *)v4,
        time_delta);
    v4->m_aabbox.min.x = v4->m_aabbox.min.x + v107.c.x;
    v4->m_aabbox.min.y = v107.c.y + v4->m_aabbox.min.y;
    v4->m_aabbox.min.z = v4->m_aabbox.min.z + v107.c.z;
    v4->m_aabbox.max.x = v107.c.x + v4->m_aabbox.max.x;
    v4->m_aabbox.max.y = v107.c.y + v4->m_aabbox.max.y;
    v4->m_aabbox.max.z = v107.c.z + v4->m_aabbox.max.z;
    m_first = v4->m_particle_list.m_first;
    if ( m_first )
    {
      do
      {
        m_first->rotation_rate.x = m_first->start_rotation_rate.x;
        m_first->rotation_rate.y = m_first->start_rotation_rate.y;
        m_first->rotation_rate.z = m_first->start_rotation_rate.z;
        m_first->size.x = m_first->start_size.x;
        m_first->size.y = m_first->start_size.y;
        m_first->size.z = m_first->start_size.z;
        v17 = v103;
        m_first->velocity.x = m_first->start_velocity.x;
        m_first->velocity.y = m_first->start_velocity.y;
        m_first->velocity.z = m_first->start_velocity.z;
        m_first->old_position.x = m_first->position.x;
        m_first->old_position.y = m_first->position.y;
        m_first->old_position.z = m_first->position.z;
        for ( i = v17->m_emitter->m_actions.pointer; i; i = i->m_next.pointer )
        {
          if ( i->m_visibility )
          {
            ((void (__thiscall *)(vostok::particle::particle_action *, vostok::particle::particle_emitter_instance *, vostok::particle::base_particle *, int))i->update)(
              i,
              v17,
              m_first,
              time_delta);
            v17 = v103;
          }
        }
        y = m_first->velocity.y;
        z = m_first->velocity.z;
        p_x = &m_first->position.x;
        m_first->position.x = (float)(m_first->velocity.x * *(float *)&time_delta) + m_first->position.x;
        m_first->position.y = (float)(y * *(float *)&time_delta) + m_first->position.y;
        m_first->position.z = (float)(z * *(float *)&time_delta) + m_first->position.z;
        v22 = (float)(m_first->rotation_rate.y * *(float *)&time_delta) * 6.2831855;
        v23 = (float)(m_first->rotation_rate.z * *(float *)&time_delta) * 6.2831855;
        m_first->rotation = m_first->rotation
                          + (float)((float)(m_first->rotation_rate.x * *(float *)&time_delta) * 6.2831855);
        m_first->rotationY = m_first->rotationY + v22;
        m_first->rotationZ = m_first->rotationZ + v23;
        if ( v17->m_world_space )
        {
          v24 = m_first->position.y;
          LODWORD(v25) = COERCE_UNSIGNED_INT(m_first->gravity * *(float *)&time_delta) ^ _mask__NegFloat_;
          *p_x = *p_x;
          v26 = m_first->position.z;
          m_first->position.y = v24 + v25;
          m_first->position.z = v26;
          m_first->render_position.x = *p_x;
          m_first->render_position.y = m_first->position.y;
          m_first->render_position.z = m_first->position.z;
          m_first->render_old_position.x = m_first->old_position.x;
          m_first->render_old_position.y = m_first->old_position.y;
          m_first->render_old_position.z = m_first->old_position.z;
          v111 = s_bm_current_air_resistance
               - fsqrt(
                   (float)((float)(m_first->direction.z * m_first->direction.z)
                         + (float)(m_first->direction.x * m_first->direction.x))
                 + (float)(m_first->direction.y * m_first->direction.y));
          v102 = LODWORD(v111) & 0x7FFFFFFF;
          if ( COERCE_FLOAT(LODWORD(v111) & 0x7FFFFFFF) < 0.0000099999997 )
          {
            v126.max.x = m_first->render_position.x - m_first->direction.x;
            v126.max.y = m_first->render_position.y - m_first->direction.y;
            v126.max.z = m_first->render_position.z - m_first->direction.z;
            m_first->render_old_position = v126.max;
          }
        }
        else
        {
          max.x = *p_x;
          *(_QWORD *)&max.elements[1] = *(_QWORD *)&m_first->position.elements[1];
          old_position = m_first->old_position;
          m_particle_system_instance = v17->m_particle_system_instance;
          if ( m_particle_system_instance->m_damage_model.m_object )
          {
            surface_id = m_first->surface_id;
            if ( surface_id != 0xFFFF )
            {
              surface_bone_index = vostok::collision::animated_object::get_surface_bone_index(
                                     m_particle_system_instance->m_damage_model.m_object,
                                     surface_id);
              v31 = *(int **)(v30 + 428);
              v32 = *v31;
              v102 = surface_bone_index;
              (*(void (__thiscall **)(int *, float *, vostok::resources::resource_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base> *, unsigned int))(v32 + 24))(
                v31,
                &v113,
                &m_particle_system_instance->m_skeleton_model,
                surface_bone_index);
              vostok::physics::bt_animated_rigid_body::get_surface_point_transform(
                v103->m_particle_system_instance->m_damage_model.m_object->m_body,
                m_first->surface_id,
                &v109);
              vostok::math::create_scale(&m_first->surface_scale, (vostok::math::float4x4 *)&v137.max);
              vostok::math::create_scale(&m_first->old_surface_scale, &v149);
              vostok::math::create_translation(&m_first->position, &v147);
              vostok::math::create_translation(&m_first->old_position, &v148);
              v33 = m_first->surface_position.y;
              x = m_first->surface_position.x;
              v35 = m_first->surface_position.z;
              m_engine = v103->m_engine;
              v37 = v103->m_particle_system_instance;
              v129 = (float)((float)((float)(v109.i.x * x) + (float)(v109.j.x * v33)) + (float)(v109.k.x * v35))
                   + v109.c.x;
              v38 = m_engine->__vftable;
              v130 = (float)((float)((float)(v109.i.y * x) + (float)(v109.j.y * v33)) + (float)(v109.k.y * v35))
                   + v109.c.y;
              v131 = (float)((float)((float)(v109.i.z * x) + (float)(v109.j.z * v33)) + (float)(v109.k.z * v35))
                   + v109.c.z;
              ((void (__thiscall *)(vostok::particle::engine *, char *, float, float, float, vostok::resources::resource_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base> *, int))v38->get_bone_direction)(
                m_engine,
                v150,
                COERCE_FLOAT(LODWORD(v129)),
                COERCE_FLOAT(LODWORD(v130)),
                COERCE_FLOAT(LODWORD(v131)),
                &v37->m_skeleton_model,
                v102);
              v39 = m_first->surface_position.z;
              v40 = m_first->surface_position.y;
              v41 = m_first->surface_position.x;
              v42 = (float)((float)((float)(v138 * v40) + (float)(v141 * v39)) + (float)(v137.max.x * v41)) + v144;
              v43 = (float)((float)((float)(v142 * v39) + (float)(v137.max.y * v41)) + (float)(v139 * v40)) + v145;
              v44 = (float)((float)((float)(v137.max.z * v41) + (float)(v140 * v40)) + (float)(v143 * v39)) + v146;
              v45 = (float)((float)((float)(v42 * v109.i.x) + (float)(v44 * v109.k.x)) + (float)(v43 * v109.j.x))
                  + v109.c.x;
              v46 = (float)(v42 * v109.i.y) + (float)(v44 * v109.k.y);
              v47 = (float)((float)((float)(v42 * v109.i.z) + (float)(v44 * v109.k.z)) + (float)(v43 * v109.j.z))
                  + v109.c.z;
              v48 = (float)(v46 + (float)(v43 * v109.j.y)) + v109.c.y;
              v49 = (float)((float)((float)(v113 * v45) + (float)(v119 * v47)) + (float)(v116 * v48)) + v122;
              v50 = (float)((float)((float)(v45 * v114) + (float)(v120 * v47)) + (float)(v117 * v48)) + v123;
              v51 = (float)((float)((float)(v45 * v115) + (float)(v121 * v47)) + (float)(v118 * v48)) + v124;
              v132.max.x = (float)((float)((float)(v147.i.x * v49) + (float)(v147.k.x * v51)) + (float)(v147.j.x * v50))
                         + v147.c.x;
              v52 = m_first->surface_position.y;
              v132.max.y = (float)((float)((float)(v49 * v147.i.y) + (float)(v147.k.y * v51)) + (float)(v147.j.y * v50))
                         + v147.c.y;
              v53 = (float)((float)((float)(v49 * v147.i.z) + (float)(v147.k.z * v51)) + (float)(v147.j.z * v50))
                  + v147.c.z;
              v54 = m_first->surface_position.z;
              v132.max.z = v53;
              v55 = (float)((float)((float)(v149.k.x * v54) + (float)(v149.i.x * v41)) + (float)(v149.j.x * v52))
                  + v149.c.x;
              v56 = (float)((float)((float)(v149.i.y * v41) + (float)(v149.j.y * v52)) + (float)(v149.k.y * v54))
                  + v149.c.y;
              v57 = (float)((float)((float)(v149.i.z * v41) + (float)(v149.j.z * v52)) + (float)(v149.k.z * v54))
                  + v149.c.z;
              max = v132.max;
              v58 = (float)((float)((float)(v55 * v109.i.x) + (float)(v57 * v109.k.x)) + (float)(v56 * v109.j.x))
                  + v109.c.x;
              v59 = (float)((float)((float)(v55 * v109.i.y) + (float)(v57 * v109.k.y)) + (float)(v56 * v109.j.y))
                  + v109.c.y;
              v60 = (float)((float)((float)(v55 * v109.i.z) + (float)(v57 * v109.k.z)) + (float)(v56 * v109.j.z))
                  + v109.c.z;
              v61 = (float)((float)((float)(v58 * v113) + (float)(v60 * v119)) + (float)(v59 * v116)) + v122;
              v62 = v58 * v114;
              v63 = (float)((float)((float)(v58 * v115) + (float)(v60 * v121)) + (float)(v59 * v118)) + v124;
              v17 = v103;
              v64 = (float)((float)(v62 + (float)(v60 * v120)) + (float)(v59 * v117)) + v123;
              v133.max.x = (float)((float)((float)(v148.i.x * v61) + (float)(v148.k.x * v63)) + (float)(v148.j.x * v64))
                         + v148.c.x;
              v133.max.y = (float)((float)((float)(v61 * v148.i.y) + (float)(v148.k.y * v63)) + (float)(v148.j.y * v64))
                         + v148.c.y;
              v133.max.z = (float)((float)((float)(v61 * v148.i.z) + (float)(v148.k.z * v63)) + (float)(v148.j.z * v64))
                         + v148.c.z;
              old_position = v133.max;
            }
          }
          v125.x = (float)((float)((float)(v107.i.x * old_position.x) + (float)(v107.k.x * old_position.z))
                         + (float)(v107.j.x * old_position.y))
                 + v107.c.x;
          v65 = m_first->direction.z;
          v125.y = (float)((float)((float)(old_position.x * v107.i.y) + (float)(v107.k.y * old_position.z))
                         + (float)(v107.j.y * old_position.y))
                 + v107.c.y;
          v66 = m_first->direction.x;
          v125.z = (float)((float)((float)(old_position.x * v107.i.z) + (float)(v107.k.z * old_position.z))
                         + (float)(v107.j.z * old_position.y))
                 + v107.c.z;
          v67 = fsqrt(
                  (float)((float)(v65 * v65) + (float)(v66 * v66))
                + (float)(m_first->direction.y * m_first->direction.y));
          old_position = v125;
          v68 = s_bm_current_air_resistance - v67;
          v69 = max.y;
          v110 = v68;
          v70 = v68;
          v71 = max.z;
          v102 = LODWORD(v70) & 0x7FFFFFFF;
          if ( COERCE_FLOAT(LODWORD(v70) & 0x7FFFFFFF) < 0.0000099999997 )
          {
            v72 = max.z - m_first->direction.z;
            v73 = max.y - m_first->direction.y;
            v74 = max.x - m_first->direction.x;
            *(float *)&v127 = (float)((float)((float)(v107.i.x * v74) + (float)(v72 * v107.k.x))
                                    + (float)(v73 * v107.j.x))
                            + v107.c.x;
            *((float *)&v127 + 1) = (float)((float)((float)(v107.i.y * v74) + (float)(v72 * v107.k.y))
                                          + (float)(v73 * v107.j.y))
                                  + v107.c.y;
            v75 = (float)(v107.i.z * v74) + (float)(v72 * v107.k.z);
            v71 = max.z;
            v76 = (float)(v75 + (float)(v73 * v107.j.z)) + v107.c.z;
            v69 = max.y;
            v128 = v76;
            *(_QWORD *)&old_position.x = v127;
            old_position.z = v76;
          }
          v134 = (float)((float)((float)(max.x * v107.i.x) + (float)(v71 * v107.k.x)) + (float)(v69 * v107.j.x))
               + v107.c.x;
          gravity_accumulation = m_first->gravity_accumulation;
          v102 = LODWORD(gravity_accumulation) & 0x7FFFFFFF;
          v135 = (float)((float)((float)(max.x * v107.i.y) + (float)(v71 * v107.k.y)) + (float)(v69 * v107.j.y))
               + v107.c.y;
          v136 = (float)((float)((float)(max.x * v107.i.z) + (float)(v71 * v107.k.z)) + (float)(v69 * v107.j.z))
               + v107.c.z;
          if ( COERCE_FLOAT(LODWORD(gravity_accumulation) & 0x7FFFFFFF) >= 0.0000099999997 )
          {
            v78 = m_first->velocity.x * *(float *)&time_delta;
            v79 = (float)((float)(v107.i.y * v78)
                        + (float)((float)(m_first->velocity.z * *(float *)&time_delta) * v107.k.y))
                + (float)((float)(m_first->velocity.y * *(float *)&time_delta) * v107.j.y);
            v80 = (float)((float)(v107.i.z * v78)
                        + (float)((float)(m_first->velocity.z * *(float *)&time_delta) * v107.k.z))
                + (float)((float)(m_first->velocity.y * *(float *)&time_delta) * v107.j.z);
            m_first->render_position.x = m_first->render_position.x
                                       + (float)((float)((float)(v107.i.x * v78)
                                                       + (float)((float)(m_first->velocity.z * *(float *)&time_delta)
                                                               * v107.k.x))
                                               + (float)((float)(m_first->velocity.y * *(float *)&time_delta) * v107.j.x));
            m_first->render_position.y = m_first->render_position.y + v79;
            v81 = m_first->render_position.z + v80;
            v82 = v107.i.x;
            m_first->render_position.z = v81;
            v83 = m_first->velocity.z * *(float *)&time_delta;
            v84 = m_first->velocity.x * *(float *)&time_delta;
            v77 = &m_first->render_old_position.x;
            v85 = (float)((float)((float)(v107.i.y * v84) + (float)(v83 * v107.k.y))
                        + (float)((float)(m_first->velocity.y * *(float *)&time_delta) * v107.j.y))
                + m_first->render_old_position.y;
            v86 = (float)((float)((float)(v107.i.z * v84) + (float)(v83 * v107.k.z))
                        + (float)((float)(m_first->velocity.y * *(float *)&time_delta) * v107.j.z))
                + m_first->render_old_position.z;
            m_first->render_old_position.x = m_first->render_old_position.x
                                           + (float)((float)((float)(v82 * v84) + (float)(v83 * v107.k.x))
                                                   + (float)((float)(m_first->velocity.y * *(float *)&time_delta)
                                                           * v107.j.x));
            m_first->render_old_position.y = v85;
            m_first->render_old_position.z = v86;
          }
          else
          {
            m_first->render_position.x = v134;
            m_first->render_position.y = v135;
            m_first->render_position.z = v136;
            v77 = &m_first->render_old_position.x;
            m_first->render_old_position = old_position;
          }
          LODWORD(v87) = LODWORD(m_first->gravity) ^ _mask__NegFloat_;
          m_first->gravity_accumulation = v87;
          m_first->render_position.x = m_first->render_position.x;
          v88 = m_first->render_position.z;
          m_first->render_position.y = (float)(v87 * *(float *)&time_delta) + m_first->render_position.y;
          m_first->render_position.z = v88;
          v89 = *(float *)&time_delta * m_first->gravity_accumulation;
          *v77 = *v77;
          v90 = v89 + v77[1];
          v77[2] = v77[2];
          v77[1] = v90;
        }
        p_m_aabbox = &v17->m_aabbox;
        v105 = m_first->size.x * 0.5;
        v104 = v105;
        vostok::math::aabb::modify((vostok::math::aabb *)&m_first->render_position, &v17->m_aabbox);
        v132.min.x = m_first->render_position.x + v105;
        v132.min.y = m_first->render_position.y + v105;
        v132.min.z = m_first->render_position.z + v105;
        vostok::math::aabb::modify(&v132, p_m_aabbox);
        v137.min.x = m_first->render_position.x - v105;
        v137.min.y = m_first->render_position.y - v105;
        v137.min.z = m_first->render_position.z - v105;
        vostok::math::aabb::modify(&v137, p_m_aabbox);
        v133.min.x = m_first->render_position.x + v104;
        v133.min.y = m_first->render_position.y + v104;
        v133.min.z = m_first->render_position.z + v104;
        vostok::math::aabb::modify(&v133, p_m_aabbox);
        v126.min.x = m_first->render_position.x - v104;
        v126.min.y = m_first->render_position.y - v104;
        v126.min.z = m_first->render_position.z - v104;
        vostok::math::aabb::modify(&v126, p_m_aabbox);
        v93 = v103;
        for ( j = v103->m_emitter->m_actions.pointer; j; j = j->m_next.pointer )
        {
          if ( j->m_visibility )
            ((void (__thiscall *)(vostok::particle::particle_action *, vostok::particle::particle_emitter_instance *, vostok::particle::base_particle *, int))j->update_when_position_ready)(
              j,
              v93,
              m_first,
              time_delta);
        }
        v95 = m_first->lifetime + *(float *)&time_delta;
        m_first->lifetime = v95;
        if ( ++m_first->m_tick_count < 3u && (duration = m_first->duration, duration > 0.001) && v95 > duration
          || (v97 = m_first->duration, v97 <= 0.001)
          || v95 <= v97 )
        {
          m_first = m_first->next;
        }
        else
        {
          v102 = 1;
          vostok::particle::particle_emitter_instance::process_event(
            v92,
            (vostok::particle::particle_event *)v93,
            (vostok::math::float4x4 *)&v102,
            &m_first->position);
          if ( m_first->particle_light_id )
            v93->m_engine->remove_light(v93->m_engine, m_first->particle_light_id);
          vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
            v98,
            (int)&v93->m_particle_list,
            m_first);
          v99 = m_first;
          m_first = m_first->next;
          vostok::particle::particle_world::deallocate_particle(v100, (int)v93->m_particle_world, v99);
          --v93->m_num_live_particles;
        }
      }
      while ( m_first );
      v4 = v93;
    }
    v4->m_render_instance->set_aabb(v4->m_render_instance, &v4->m_aabbox);
    qmemcpy(&v4->m_old_transform, &v107, sizeof(v4->m_old_transform));
  }
}
