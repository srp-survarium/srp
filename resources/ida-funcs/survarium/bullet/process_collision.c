void __userpurge survarium::bullet::process_collision(
        survarium::bullet *this@<ecx>,
        int a2@<edi>,
        const vostok::physics::closest_ray_result *ray_result,
        const vostok::math::float3 *direction,
        survarium::hit_receiver *const hit_target)
{
  int v6; // eax
  survarium::game_material_manager *v7; // ecx
  const survarium::material_pair *pair; // eax
  survarium::material_pair *v9; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v10; // esi
  bool has_passed_filters; // al
  double v12; // st7
  unsigned __int8 triangle_index; // al
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v14; // eax
  survarium::bullet_manager *v15; // ecx
  float v16; // [esp+0h] [ebp-48h]
  float v17; // [esp+4h] [ebp-44h]
  survarium::material_pair *v18; // [esp+18h] [ebp-30h]
  int m_object; // [esp+18h] [ebp-30h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v20; // [esp+24h] [ebp-24h] BYREF
  char v21; // [esp+50h] [ebp+8h]

  v21 = 0;
  if ( (_S22 & 1) == 0 )
  {
    _S22 |= 1u;
    survarium::player_shootmarks_storage::player_shootmarks_storage(
      (survarium::player_shootmarks_storage *)this,
      (int)&shootmarks_storage);
    atexit((int (__cdecl *)())survarium::bullet::process_collision_::_2_::_dynamic_atexit_destructor_for__shootmarks_storage__);
  }
  v6 = *(_DWORD *)(a2 + 72);
  if ( v6
    && *(_DWORD *)(*(_DWORD *)(a2 + 60) + 136)
    && survarium::player_shootmarks_storage::add_shootmark(
         *(_DWORD *)a2,
         &shootmarks_storage,
         (survarium::player_shootmarks_storage::sm *)*(unsigned __int8 *)(a2 + 132),
         *(_BYTE *)(v6 + 4)) == 1 )
  {
    pair = survarium::game_material_manager::get_pair(
             v7,
             *(_DWORD *)(*(_DWORD *)(a2 + 60) + 140),
             *(_WORD *)(*(_DWORD *)(a2 + 64) + 100),
             *(_WORD *)(*(_DWORD *)(a2 + 68) + 100));
    v10 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)pair;
    if ( pair )
    {
      if ( pair->m_collision_decal.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v12 = survarium::material_pair::collision_decal_size(v9, (int)pair);
        triangle_index = 0;
        if ( hit_target )
          triangle_index = ray_result->triangle_index;
        v17 = v12;
        v16 = v12;
        survarium::bullet_manager::add_decal(
          v10 + 5,
          *(survarium::bullet_manager::bullet_functor **)(a2 + 60),
          v16,
          v17,
          &ray_result->hit_point_world,
          direction,
          &ray_result->hit_normal_world,
          hit_target,
          triangle_index);
      }
      if ( v10[8].m_object )
      {
        v9 = (survarium::material_pair *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          if ( !*(_BYTE *)(a2 + 128) && !*(_DWORD *)(a2 + 132) )
            survarium::bullet_manager::play_sound(
              (survarium::bullet_manager *)&ray_result->hit_point_world,
              *(const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 60),
              v10 + 8,
              &ray_result->hit_point_world.x);
        }
      }
      if ( v10[21].m_object != v10[22].m_object )
      {
        m_object = (int)v10[29].m_object;
        v14 = survarium::material_pair::collision_particle(v9, v10);
        survarium::bullet_manager::play_particle(
          v15,
          *(const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 60),
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v14,
          &ray_result->hit_point_world,
          direction,
          &ray_result->hit_normal_world.x,
          m_object);
      }
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game_core",
                                   (const char *)3),
            v9 = v18,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v9,
          &v20);
        v21 = 1;
        vostok::logging::append(
          &v20,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\bullet.cpp",
          0x3A1u,
          "void __thiscall survarium::bullet::process_collision(const struct vostok::physics::closest_ray_result &,const "
          "class vostok::math::float3 &,struct survarium::hit_receiver *const )",
          "game_core",
          warning,
          "material pair not exists [%s]-[%s]",
          **(const char ***)(a2 + 64),
          **(const char ***)(a2 + 68));
      }
      if ( (v21 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
          (int *)&v20);
    }
  }
}
