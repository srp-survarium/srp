void __userpurge survarium::player::insert(
        survarium::player *this@<ecx>,
        long double a2@<esi:edi>,
        __m128i a3@<xmm0>,
        bool real_insert)
{
  survarium::player *v5; // ecx
  vostok::math::float4x4 *v6; // eax
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *v7; // ecx
  unsigned int v8; // eax
  int v9; // eax
  survarium::game_effect_player *v10; // ecx
  int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  int v15; // [esp+4h] [ebp-58h]
  unsigned int time_in_ms; // [esp+10h] [ebp-4Ch] BYREF
  survarium::zero_time_calculator f[4]; // [esp+14h] [ebp-48h]
  unsigned int v18; // [esp+18h] [ebp-44h]
  vostok::math::float4x4 v19; // [esp+1Ch] [ebp-40h] BYREF

  survarium::base_player::insert(this, real_insert);
  if ( this->m_is_alive )
  {
    HIDWORD(a2) = *(survarium::player_vtbl **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                             + (_DWORD)&loc_11403
                                             + 5);
    if ( HIDWORD(a2) )
    {
      v6 = vostok::math::create_rotation_y(a2, a3, &v19, this->m_rotation_y);
      survarium::game_camera::set_position_direction(
        (const vostok::math::float3 *)&v6->lines[2],
        (survarium::game_camera *)(HIDWORD(a2) + 4),
        (const vostok::math::float3 *)&byte_10E5C[(_DWORD)this]);
    }
  }
  *((_BYTE *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
  + (_DWORD)&loc_11437
  + 1) = 1;
  if ( real_insert )
  {
    survarium::player::add_models_to_scene(
      v5,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
    v8 = *(_DWORD *)(*(int *)((char *)&dword_11414 + (_DWORD)this) + 1328);
    time_in_ms = 0;
    v18 = v8;
    if ( v8 )
    {
      do
      {
        f[0] = 0;
        boost::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>(
          v7,
          &v19,
          0,
          v15);
        v9 = *(int *)((char *)&dword_11414 + (_DWORD)this);
        v10 = *(survarium::game_effect_player **)(v9 + 13968);
        v11 = *(_DWORD *)(v9 + 1324);
        v12 = time_in_ms;
        time_in_ms = 0;
        v13 = *(_DWORD *)(v11 + 4 * v12);
        if ( v13 )
        {
          ++*(_DWORD *)(v13 + 24);
          time_in_ms = v13;
        }
        survarium::game_effect_player::add(
          v10,
          (const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&this->m_effect_player,
          (vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&time_in_ms,
          (unsigned int)v10,
          (const boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *)1,
          (const boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *)&v19);
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&time_in_ms);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v14,
          (int *)&v19);
        time_in_ms = v12 + 1;
      }
      while ( v12 + 1 < v18 );
    }
  }
}
