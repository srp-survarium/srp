void __userpurge survarium::bullet::process_back_face_piercing(
        survarium::bullet *this@<ecx>,
        int a2@<edi>,
        const vostok::physics::closest_ray_result *ray_result,
        const vostok::math::float3 *direction,
        survarium::hit_receiver *const hit_target)
{
  int v6; // eax
  survarium::game_material_manager *v7; // ecx
  const survarium::material_pair *pair; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  const survarium::material_pair *v10; // esi
  bool has_passed_filters; // al
  double v12; // st7
  unsigned __int8 triangle_index; // al
  double v14; // st7
  unsigned int *p_m_current_particle_out_idx; // ecx
  unsigned int v16; // eax
  float v17; // [esp+0h] [ebp-48h]
  float v18; // [esp+4h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v19; // [esp+18h] [ebp-30h]
  int m_particle_orientation; // [esp+18h] [ebp-30h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v21; // [esp+24h] [ebp-24h] BYREF
  char v22; // [esp+50h] [ebp+8h]

  v22 = 0;
  if ( (_S20_0 & 1) == 0 )
  {
    _S20_0 |= 1u;
    survarium::player_shootmarks_storage::player_shootmarks_storage(
      (survarium::player_shootmarks_storage *)this,
      (int)&shootmarks_storage_1);
    atexit((int (__cdecl *)())survarium::bullet::process_back_face_piercing_::_2_::_dynamic_atexit_destructor_for__shootmarks_storage__);
  }
  v6 = *(_DWORD *)(a2 + 72);
  if ( v6
    && *(_DWORD *)(*(_DWORD *)(a2 + 60) + 136)
    && *(_DWORD *)(a2 + 68)
    && survarium::player_shootmarks_storage::add_shootmark(
         *(_DWORD *)a2,
         &shootmarks_storage_1,
         (survarium::player_shootmarks_storage::sm *)*(unsigned __int8 *)(a2 + 132),
         *(_BYTE *)(v6 + 4)) == 1 )
  {
    pair = survarium::game_material_manager::get_pair(
             v7,
             *(_DWORD *)(*(_DWORD *)(a2 + 60) + 140),
             *(_WORD *)(*(_DWORD *)(a2 + 64) + 100),
             *(_WORD *)(*(_DWORD *)(a2 + 68) + 100));
    v10 = pair;
    if ( pair )
    {
      if ( pair->m_decal_out.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v12 = vostok::math::random32::random_f(
                &size_random,
                COERCE_CONST_FLOAT(LODWORD(pair->m_decal_scale_delta) ^ _mask__NegFloat_),
                pair->m_decal_scale_delta);
        triangle_index = 0;
        v14 = (v12 + s_bm_current_air_resistance) * v10->m_decal_out_size;
        if ( hit_target )
          triangle_index = ray_result->triangle_index;
        v18 = v14;
        v17 = v14;
        survarium::bullet_manager::add_decal(
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v10->m_decal_out,
          *(survarium::bullet_manager::bullet_functor **)(a2 + 60),
          v17,
          v18,
          &ray_result->hit_point_world,
          direction,
          &ray_result->hit_normal_world,
          hit_target,
          triangle_index);
      }
      if ( v10->m_particles_out._M_impl._M_start != v10->m_particles_out._M_impl._M_finish )
      {
        p_m_current_particle_out_idx = &v10->m_current_particle_out_idx;
        if ( v10->m_current_particle_out_idx == v10->m_particles_out._M_impl._M_finish
                                              - v10->m_particles_out._M_impl._M_start )
          *p_m_current_particle_out_idx = 0;
        v16 = *p_m_current_particle_out_idx;
        m_particle_orientation = v10->m_particle_orientation;
        ++*p_m_current_particle_out_idx;
        survarium::bullet_manager::play_particle(
          (survarium::bullet_manager *)v10->m_particles_out._M_impl._M_start,
          *(const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 60),
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v10->m_particles_out._M_impl._M_start[v16],
          &ray_result->hit_point_world,
          direction,
          &ray_result->hit_normal_world.x,
          m_particle_orientation);
      }
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game_core",
                                   (const char *)3),
            v9 = v19,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v9,
          &v21);
        v22 = 1;
        vostok::logging::append(
          &v21,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\bullet.cpp",
          0x342u,
          "void __thiscall survarium::bullet::process_back_face_piercing(const struct vostok::physics::closest_ray_result"
          " &,const class vostok::math::float3 &,struct survarium::hit_receiver *const )",
          "game_core",
          warning,
          "material pair not exists [%s]-[%s]",
          **(const char ***)(a2 + 64),
          **(const char ***)(a2 + 68));
      }
      if ( (v22 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
          (int *)&v21);
    }
  }
}
