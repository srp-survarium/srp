void __thiscall survarium::bullet_manager::tick(
        survarium::bullet_manager *this,
        survarium::redundant_bullet_predicate current_time_in_ms,
        unsigned int current_time_in_msa)
{
  unsigned int v3; // edx
  vostok::buffer_vector<vostok::render::ambient_light *> *p_m_bullets; // esi
  unsigned int v5; // eax
  unsigned int v6; // ecx
  vostok::render::ambient_light **v7; // eax
  bool ListenerStatus; // al
  vostok::tasks::task_manager *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  bool v11; // zf
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *v12; // ecx
  boost::function0<bool> *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *v15; // ecx
  vostok::render::ambient_light **v16; // edi
  survarium::bullet **m_begin; // eax
  vostok::render::ambient_light **v18; // eax
  survarium::bullet **v19; // ebx
  _DWORD *p_vtable; // ecx
  survarium::bullet_manager::bullet_functor *value; // [esp+Ch] [ebp-6Ch]
  survarium::bullet_manager::bullet_functor *valuea; // [esp+Ch] [ebp-6Ch]
  survarium::bullet_manager::bullet_functor *valueb; // [esp+Ch] [ebp-6Ch]
  unsigned int v24; // [esp+14h] [ebp-64h]
  vostok::render::ambient_light **end; // [esp+18h] [ebp-60h] BYREF
  vostok::render::ambient_light **begin; // [esp+1Ch] [ebp-5Ch] BYREF
  survarium::bullet_manager *bullet_manager; // [esp+20h] [ebp-58h]
  vostok::render::ambient_light **v28; // [esp+24h] [ebp-54h]
  vostok::render::ambient_light **v29; // [esp+28h] [ebp-50h]
  unsigned int v30; // [esp+2Ch] [ebp-4Ch]
  _DWORD v31[5]; // [esp+30h] [ebp-48h] BYREF
  _BYTE v32[20]; // [esp+44h] [ebp-34h] BYREF
  int v33[2]; // [esp+58h] [ebp-20h] BYREF
  _BYTE v34[20]; // [esp+60h] [ebp-18h] BYREF

  v3 = current_time_in_msa;
  p_m_bullets = (vostok::buffer_vector<vostok::render::ambient_light *> *)&current_time_in_ms.bullet_manager->m_bullets;
  current_time_in_ms.bullet_manager->m_current_time_in_ms = current_time_in_msa;
  v5 = current_time_in_ms.bullet_manager->m_bullets.m_end - current_time_in_ms.bullet_manager->m_bullets.m_begin;
  v24 = v5;
  if ( v5 )
  {
    v6 = v5 >> 8;
    begin = (vostok::render::ambient_light **)(v5 >> 8);
    if ( v5 >= 0x100 && v6 )
    {
      bullet_manager = current_time_in_ms.bullet_manager;
      v30 = current_time_in_msa;
      v7 = 0;
      value = (survarium::bullet_manager::bullet_functor *)v6;
      do
      {
        v28 = v7;
        v29 = v7 + 4;
        v31[0] = survarium::bullet_manager::tick_bullets;
        v31[1] = bullet_manager;
        v31[2] = v7;
        v31[3] = v7 + 4;
        end = v7 + 4;
        v31[4] = v30;
        qmemcpy(v32, v31, sizeof(v32));
        ListenerStatus = Scaleform::Render::RenderEvent::GetListenerStatus(0);
        v9 = (vostok::tasks::task_manager *)v32;
        if ( ListenerStatus )
        {
          v33[0] = 0;
        }
        else
        {
          qmemcpy(v34, v32, sizeof(v34));
          v9 = 0;
          v33[0] = (int)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable
                 + 1;
        }
        vostok::tasks::task_manager::spawn_task(
          v9,
          (vostok::tasks::task *)v33,
          (boost::function<void __cdecl(void)> *)current_time_in_ms.bullet_manager->m_task_type,
          0);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v10,
          v33);
        v11 = value == (survarium::bullet_manager::bullet_functor *)1;
        value = (survarium::bullet_manager::bullet_functor *)((char *)value - 1);
        v7 = end;
      }
      while ( !v11 );
      v3 = current_time_in_msa;
      LOBYTE(v5) = v24;
      v6 = (unsigned int)begin;
      p_m_bullets = (vostok::buffer_vector<vostok::render::ambient_light *> *)&current_time_in_ms.bullet_manager->m_bullets;
    }
    survarium::bullet_manager::tick_bullets(
      current_time_in_ms.bullet_manager,
      v6 << 8,
      (v6 << 8) + (unsigned __int8)v5,
      v3);
    if ( v24 >= 0x100 )
      vostok::tasks::wait_for_all_children();
    while ( current_time_in_ms.bullet_manager->m_functors.m_top.m_pointer )
    {
      valuea = vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76>::try_pop(
                 v12,
                 &current_time_in_ms.bullet_manager->m_functors.m_top.whole);
      boost::function0<void>::operator()(v13, valuea);
      if ( valuea )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&valuea->resource);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v14,
          (int *)valuea);
        vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76>::push(
          v15,
          (int)&current_time_in_ms.bullet_manager->m_mt_stack_allocator,
          valuea);
        p_m_bullets = (vostok::buffer_vector<vostok::render::ambient_light *> *)&current_time_in_ms.bullet_manager->m_bullets;
      }
    }
    m_begin = (survarium::bullet **)p_m_bullets->m_begin;
    end = (vostok::render::ambient_light **)current_time_in_ms.bullet_manager->m_bullets.m_end;
    v16 = end;
    v18 = (vostok::render::ambient_light **)stlp_std::priv::__find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
                                              m_begin,
                                              (survarium::bullet **)end,
                                              current_time_in_ms);
    if ( v18 != end )
    {
      begin = (vostok::render::ambient_light **)current_time_in_ms.bullet_manager;
      v19 = (survarium::bullet **)(v18 + 1);
      valueb = (survarium::bullet_manager::bullet_functor *)v18;
      if ( v18 + 1 != end )
      {
        do
        {
          if ( !survarium::redundant_bullet_predicate::operator()(*v19, (survarium::redundant_bullet_predicate *)&begin) )
          {
            p_vtable = &valueb->functor.vtable;
            valueb = (survarium::bullet_manager::bullet_functor *)((char *)valueb + 4);
            *p_vtable = *v19;
          }
          ++v19;
        }
        while ( v19 != (survarium::bullet **)v16 );
        p_m_bullets = (vostok::buffer_vector<vostok::render::ambient_light *> *)&current_time_in_ms.bullet_manager->m_bullets;
      }
      v18 = (vostok::render::ambient_light **)valueb;
    }
    begin = v18;
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(p_m_bullets, &begin, &end);
  }
}
