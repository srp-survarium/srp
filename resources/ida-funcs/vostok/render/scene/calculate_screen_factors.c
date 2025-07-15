void __thiscall vostok::render::scene::calculate_screen_factors(
        vostok::render::scene *this,
        const vostok::math::float4x4 *projection_matrix,
        const vostok::math::float3 *viewer_position,
        _DWORD *end)
{
  float v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edi
  float v8; // eax
  vostok::tasks::task_manager *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  bool v11; // zf
  _DWORD *j; // esi
  float z; // edi
  int v14; // esi
  unsigned __int8 v15; // cl
  _BYTE v16[92]; // [esp-5Ch] [ebp-148h] BYREF
  _DWORD v17[22]; // [esp+Ch] [ebp-E0h] BYREF
  _DWORD v18[21]; // [esp+64h] [ebp-88h] BYREF
  int v19[9]; // [esp+B8h] [ebp-34h] BYREF
  float v20; // [esp+DCh] [ebp-10h]
  unsigned int v21; // [esp+E0h] [ebp-Ch]
  float w; // [esp+E4h] [ebp-8h]
  unsigned int v23; // [esp+F4h] [ebp+8h]
  float i; // [esp+F4h] [ebp+8h]

  if ( vostok::threading::core_count(this) == 1 || s_calc_screen_factors_0 )
  {
    z = projection_matrix[142805].c.z;
    for ( i = projection_matrix[142805].c.w; LODWORD(z) != LODWORD(i); LODWORD(z) += 4 )
    {
      v14 = *(_DWORD *)LODWORD(z);
      v15 = *(_BYTE *)(*(_DWORD *)LODWORD(z) + 604);
      *(_BYTE *)(*(_DWORD *)LODWORD(z) + 604) = v15 + 1;
      if ( !(v15 % 5u) )
        (*(void (__thiscall **)(int, const vostok::math::float3 *, _DWORD *))(*(_DWORD *)v14 + 88))(
          v14,
          viewer_position,
          end);
    }
  }
  else
  {
    v5 = projection_matrix[142805].c.z;
    w = projection_matrix[142805].c.w;
    v6 = (LODWORD(w) - LODWORD(v5)) >> 2;
    if ( v6 )
    {
      v7 = v6 >> 4;
      v21 = v6 >> 4;
      if ( v6 >> 4 )
      {
        v8 = v5;
        v23 = v7;
        do
        {
          qmemcpy(v18, viewer_position, 0x40u);
          v18[16] = *end;
          v18[17] = end[1];
          v18[18] = end[2];
          *(float *)&v18[19] = v8;
          v18[20] = LODWORD(v8) + 64;
          v17[0] = vostok::render::calculate_screen_factors_task;
          qmemcpy(&v17[1], v18, 0x54u);
          LODWORD(v20) = LODWORD(v8) + 64;
          *(_DWORD *)v16 = v19;
          qmemcpy(&v16[4], v17, 0x58u);
          boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
            0,
            *(boost::_bi::bind_t<void,void (__cdecl*)(vostok::math::float4x4 const &,vostok::math::float3 const &,vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *),boost::_bi::list4<boost::_bi::value<vostok::math::float4x4>,boost::_bi::value<vostok::math::float3>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *> > > *)v16,
            *(int *)&v16[88]);
          vostok::tasks::task_manager::spawn_task(
            v9,
            (vostok::tasks::task *)v19,
            (boost::function<void __cdecl(void)> *)LODWORD(projection_matrix[140948].c.y),
            (vostok::tasks::task *)((char *)projection_matrix + (_DWORD)&loc_1CE1B5 + 3));
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            v10,
            v19);
          v11 = v23-- == 1;
          v8 = v20;
        }
        while ( !v11 );
        v7 = v21;
      }
      for ( j = (_DWORD *)(LODWORD(projection_matrix[142805].c.z) + (v7 << 6)); j != (_DWORD *)LODWORD(w); ++j )
        (*(void (__thiscall **)(_DWORD, const vostok::math::float3 *, _DWORD *))(*(_DWORD *)*j + 88))(
          *j,
          viewer_position,
          end);
      if ( v7 )
        vostok::tasks::thread_pool::wait_for_task_list(
          (vostok::tasks::task *)((char *)projection_matrix + (_DWORD)&loc_1CE1B5 + 3),
          s_thread_pool.m_variable);
    }
  }
}
