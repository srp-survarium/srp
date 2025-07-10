void __userpurge vostok::render::clouds::set_time(
        vostok::render::clouds *this@<ecx>,
        const vostok::render::cloud_key_parameters *a2@<edi>,
        float a3@<xmm0>,
        vostok::render::clouds *thisa)
{
  unsigned int m_num_keys; // edx
  float v5; // xmm0_4
  bool v6; // zf
  vostok::render::cloud_simulation *v7; // ecx
  unsigned int m_current_key_0; // eax
  vostok::render::cloud_key_parameters *v9; // esi
  unsigned int m_current_key_1; // eax
  bool v11; // cc
  const vostok::math::float4x4 *v12; // xmm1_4
  const vostok::render::cloud_key_parameters *p_m_interp_alpha; // edi
  unsigned int v14; // eax
  float *p_linear_time; // edx
  vostok::tasks::thread_pool *v16; // ecx
  unsigned int v17; // edx
  boost::function<void __cdecl(void)> *v18; // ecx
  unsigned int v19; // edx
  float linear_time; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm2_4
  int v23; // edx
  vostok::render::cloud_simulation *m_variable; // ecx
  unsigned int v25; // eax
  vostok::render::cloud_simulation *v26; // ecx
  vostok::render::cloud_simulation *v27; // ecx
  vostok::render::cloud_simulation *v28; // ecx
  float m_interp_alpha; // xmm0_4
  float *p_cloud_generate_octaves; // eax
  float v31; // xmm1_4
  float v32; // xmm2_4
  float *v33; // ebx
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::clouds,unsigned int>,boost::_bi::list2<boost::_bi::value<vostok::render::clouds *>,boost::_bi::value<unsigned int> > > v45; // [esp-Ch] [ebp-E4h]
  const vostok::render::cloud_key_parameters *v46; // [esp-4h] [ebp-DCh]
  const vostok::render::cloud_key_parameters *v47; // [esp-4h] [ebp-DCh]
  int v48; // [esp+0h] [ebp-D8h]
  vostok::math::float3 sun_direction; // [esp+Ch] [ebp-CCh] BYREF
  bool async; // [esp+1Bh] [ebp-BDh]
  unsigned int v51; // [esp+1Ch] [ebp-BCh]
  unsigned int v52; // [esp+20h] [ebp-B8h]
  vostok::render::cloud_key_parameters *p_m_interp_key; // [esp+24h] [ebp-B4h]
  vostok::render::cloud_key_parameters key_1; // [esp+28h] [ebp-B0h] BYREF
  int v55; // [esp+6Ch] [ebp-6Ch] BYREF
  boost::function<void __cdecl(void)> function; // [esp+70h] [ebp-68h] BYREF
  vostok::render::cloud_key_parameters key_0; // [esp+90h] [ebp-48h] BYREF

  m_num_keys = thisa->m_num_keys;
  if ( !m_num_keys )
    return;
  v51 = LODWORD(a3) & 0x7FFFFFFF;
  async = !thisa->m_is_editor_mode;
  v5 = COERCE_FLOAT(LODWORD(a3) & 0x7FFFFFFF) - (float)(((int)a3 >> 31) ^ (((int)a3 >> 31) + (int)a3));
  if ( m_num_keys != 1 )
  {
    qmemcpy(&key_1, thisa, sizeof(key_1));
    m_current_key_0 = thisa->m_current_key_0;
    qmemcpy(&key_0, &thisa->m_keys[m_num_keys - 1], sizeof(key_0));
    v9 = &thisa->m_keys[m_current_key_0];
    v51 = m_current_key_0;
    m_current_key_1 = thisa->m_current_key_1;
    p_m_interp_key = &thisa->m_interp_key;
    v11 = key_1.linear_time <= v5;
    v12 = clear_value;
    qmemcpy(&thisa->m_interp_key, v9, sizeof(thisa->m_interp_key));
    p_m_interp_alpha = (const vostok::render::cloud_key_parameters *)&thisa->m_interp_alpha;
    v52 = m_current_key_1;
    if ( v11 && v5 <= key_0.linear_time )
    {
      v14 = 0;
      p_linear_time = &thisa->m_keys[1].linear_time;
      do
      {
        if ( v5 > *(p_linear_time - 17) && *p_linear_time > v5 )
        {
          thisa->m_current_key_1 = v14 + 1;
          thisa->m_current_key_0 = v14;
          qmemcpy(&key_0, p_linear_time - 33, sizeof(key_0));
          qmemcpy(&key_1, p_linear_time - 16, sizeof(key_1));
          p_m_interp_alpha = (const vostok::render::cloud_key_parameters *)&v55;
          thisa->m_interp_alpha = (float)(v5 - key_0.linear_time) / (float)(key_1.linear_time - key_0.linear_time);
        }
        ++v14;
        p_linear_time += 17;
      }
      while ( v14 < thisa->m_num_keys - 1 );
      m_current_key_1 = v52;
    }
    else
    {
      v19 = m_num_keys - 1;
      thisa->m_current_key_0 = v19;
      thisa->m_current_key_1 = 0;
      qmemcpy(&key_0, &thisa->m_keys[v19], sizeof(key_0));
      linear_time = key_0.linear_time;
      qmemcpy(&key_1, thisa, sizeof(key_1));
      p_m_interp_alpha = (const vostok::render::cloud_key_parameters *)&v55;
      v21 = key_1.linear_time;
      v22 = (float)(*(float *)&v12 - key_0.linear_time) + key_1.linear_time;
      if ( v5 > key_0.linear_time )
        thisa->m_interp_alpha = (float)(v5 - key_0.linear_time) / v22;
      if ( v21 > v5 )
        thisa->m_interp_alpha = (float)((float)(v5 + *(float *)&v12) - linear_time) / v22;
    }
    v6 = !async;
    v16 = (vostok::tasks::thread_pool *)thisa->m_current_key_0;
    v17 = v51;
    thisa->m_is_updated = 0;
    if ( !v6 )
    {
      if ( (vostok::tasks::thread_pool *)v17 == v16 && m_current_key_1 == thisa->m_current_key_1 )
        goto LABEL_36;
      if ( v16 == (vostok::tasks::thread_pool *)m_current_key_1 )
      {
        vostok::tasks::thread_pool::wait_for_task_list(v16, &thisa->m_parent_task);
        memcpy(
          (unsigned __int8 *)thisa->m_cloud_simulation_0.m_variable->m_voxels,
          (unsigned __int8 *)thisa->m_cloud_simulation_1.m_variable->m_voxels,
          4
        * thisa->m_cloud_simulation_0.m_variable->m_clouds_size_x
        * thisa->m_cloud_simulation_0.m_variable->m_clouds_size_y
        * thisa->m_cloud_simulation_0.m_variable->m_clouds_size_z);
        memcpy(
          (unsigned __int8 *)thisa->m_cloud_simulation_1.m_variable->m_voxels,
          (unsigned __int8 *)thisa->m_cloud_simulation_2.m_variable->m_voxels,
          4
        * thisa->m_cloud_simulation_1.m_variable->m_clouds_size_x
        * thisa->m_cloud_simulation_1.m_variable->m_clouds_size_y
        * thisa->m_cloud_simulation_1.m_variable->m_clouds_size_z);
        v18 = (boost::function<void __cdecl(void)> *)thisa->m_current_key_1;
        LODWORD(sun_direction.x) = vostok::render::clouds::generate_cloud_right;
        LODWORD(sun_direction.y) = thisa;
        *(_QWORD *)&v45.f_.f_ = *(_QWORD *)&sun_direction.x;
        v45.l_.a2_.t_ = (unsigned int)v18;
        boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
          v18,
          (int)&function,
          (unsigned int)&thisa->m_parent_task,
          v45,
          v48);
        vostok::tasks::task_manager::spawn_task(
          (vostok::tasks::task_manager *)&function,
          &function,
          thisa->m_tasks_type,
          &thisa->m_parent_task);
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&function);
LABEL_35:
        v12 = clear_value;
        thisa->m_is_updated = 1;
        goto LABEL_36;
      }
      if ( thisa->m_current_key_1 == v17 )
      {
LABEL_36:
        m_interp_alpha = thisa->m_interp_alpha;
        p_cloud_generate_octaves = &thisa->m_keys[thisa->m_current_key_1].cloud_generate_octaves;
        v31 = *(float *)&v12 - m_interp_alpha;
        v32 = (float)(thisa->m_keys[thisa->m_current_key_0].cloud_base * v31)
            + (float)(p_cloud_generate_octaves[7] * m_interp_alpha);
        v33 = &thisa->m_keys[thisa->m_current_key_0].cloud_generate_octaves;
        v34 = p_cloud_generate_octaves[8] * m_interp_alpha;
        qmemcpy(&key_1, v33, sizeof(key_1));
        key_1.cloud_base = v32;
        v35 = (float)(v33[8] * v31) + v34;
        v36 = p_cloud_generate_octaves[9];
        key_1.layer_height = v35;
        v37 = (float)(v33[9] * v31) + (float)(v36 * m_interp_alpha);
        v38 = p_cloud_generate_octaves[10];
        key_1.detail_noise_wave_lenght = v37;
        v39 = (float)(v33[10] * v31) + (float)(v38 * m_interp_alpha);
        v40 = p_cloud_generate_octaves[11];
        key_1.detail_noise_amplitude = v39;
        v41 = (float)(v33[11] * v31) + (float)(v40 * m_interp_alpha);
        v42 = p_cloud_generate_octaves[2];
        key_1.wind_speed = v41;
        v43 = (float)(v33[2] * v31) + (float)(v42 * m_interp_alpha);
        v44 = p_cloud_generate_octaves[3];
        key_1.direct_light = v43;
        key_1.indirect_light = (float)(v33[3] * v31) + (float)(v44 * m_interp_alpha);
        key_1.ambient = (float)(v33[4] * v31) + (float)(p_cloud_generate_octaves[4] * m_interp_alpha);
        qmemcpy(p_m_interp_key, &key_1, sizeof(vostok::render::cloud_key_parameters));
        return;
      }
      sun_direction.x = -thisa->m_sun_direction.x;
      v23 = (int)v16;
      m_variable = thisa->m_cloud_simulation_0.m_variable;
      sun_direction.y = -thisa->m_sun_direction.y;
      sun_direction.z = -thisa->m_sun_direction.z;
      vostok::render::cloud_simulation::generate(m_variable, &sun_direction, p_m_interp_alpha, &thisa->m_keys[v23]);
      v25 = thisa->m_current_key_1;
      sun_direction.x = -thisa->m_sun_direction.x;
      sun_direction.y = -thisa->m_sun_direction.y;
      v26 = thisa->m_cloud_simulation_1.m_variable;
      sun_direction.z = -thisa->m_sun_direction.z;
      vostok::render::cloud_simulation::generate(v26, &sun_direction, p_m_interp_alpha, &thisa->m_keys[v25]);
      v27 = thisa->m_cloud_simulation_2.m_variable;
      v46 = &thisa->m_keys[thisa->m_current_key_1 + 1 < thisa->m_num_keys ? thisa->m_current_key_1 + 1 : 0];
LABEL_34:
      sun_direction.x = -thisa->m_sun_direction.x;
      sun_direction.y = -thisa->m_sun_direction.y;
      sun_direction.z = -thisa->m_sun_direction.z;
      vostok::render::cloud_simulation::generate(v27, &sun_direction, p_m_interp_alpha, v46);
      goto LABEL_35;
    }
    if ( (vostok::tasks::thread_pool *)v17 == v16 && m_current_key_1 == thisa->m_current_key_1 )
      goto LABEL_36;
    thisa->m_is_updated = 0;
    if ( v16 == (vostok::tasks::thread_pool *)m_current_key_1 )
    {
      memcpy(
        (unsigned __int8 *)thisa->m_cloud_simulation_0.m_variable->m_voxels,
        (unsigned __int8 *)thisa->m_cloud_simulation_1.m_variable->m_voxels,
        4
      * thisa->m_cloud_simulation_0.m_variable->m_clouds_size_x
      * thisa->m_cloud_simulation_0.m_variable->m_clouds_size_y
      * thisa->m_cloud_simulation_0.m_variable->m_clouds_size_z);
      v46 = &thisa->m_keys[thisa->m_current_key_1];
    }
    else
    {
      if ( thisa->m_current_key_1 == v17 )
      {
        vostok::render::cloud_simulation::copy_from(
          thisa->m_cloud_simulation_1.m_variable,
          thisa->m_cloud_simulation_0.m_variable);
        v27 = thisa->m_cloud_simulation_0.m_variable;
        v46 = &thisa->m_keys[thisa->m_current_key_0];
        goto LABEL_34;
      }
      sun_direction.x = -thisa->m_sun_direction.x;
      sun_direction.y = -thisa->m_sun_direction.y;
      v47 = &thisa->m_keys[(_DWORD)v16];
      v28 = thisa->m_cloud_simulation_0.m_variable;
      sun_direction.z = -thisa->m_sun_direction.z;
      vostok::render::cloud_simulation::generate(v28, &sun_direction, p_m_interp_alpha, v47);
      v46 = &thisa->m_keys[thisa->m_current_key_1];
    }
    v27 = thisa->m_cloud_simulation_1.m_variable;
    goto LABEL_34;
  }
  v6 = thisa->m_current_key_0 == 0;
  thisa->m_is_updated = 0;
  if ( !v6 )
  {
    v7 = thisa->m_cloud_simulation_0.m_variable;
    sun_direction.x = -thisa->m_sun_direction.x;
    sun_direction.y = -thisa->m_sun_direction.y;
    sun_direction.z = -thisa->m_sun_direction.z;
    vostok::render::cloud_simulation::generate(v7, &sun_direction, a2, thisa->m_keys);
    memcpy(
      (unsigned __int8 *)thisa->m_cloud_simulation_1.m_variable->m_voxels,
      (unsigned __int8 *)thisa->m_cloud_simulation_0.m_variable->m_voxels,
      4
    * thisa->m_cloud_simulation_1.m_variable->m_clouds_size_x
    * thisa->m_cloud_simulation_1.m_variable->m_clouds_size_y
    * thisa->m_cloud_simulation_1.m_variable->m_clouds_size_z);
    thisa->m_is_updated = 1;
  }
  thisa->m_interp_alpha = 0.0;
  thisa->m_current_key_0 = 0;
  thisa->m_current_key_1 = 0;
  qmemcpy(&thisa->m_interp_key, thisa, sizeof(thisa->m_interp_key));
}
