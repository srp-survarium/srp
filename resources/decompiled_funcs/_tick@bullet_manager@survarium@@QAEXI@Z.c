void __thiscall survarium::bullet_manager::tick(survarium::bullet_manager *this, unsigned int current_time_in_ms)
{
  survarium::game_camera *v2; // ecx
  survarium::bullet_manager *thisb; // [esp+0h] [ebp-1F0h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > v5; // [esp+180h] [ebp-70h]
  vostok::ai::planning::action_parameter **begin; // [esp+198h] [ebp-58h] BYREF
  vostok::ai::planning::action_parameter **end; // [esp+19Ch] [ebp-54h] BYREF
  char v8; // [esp+1A3h] [ebp-4Dh]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > result; // [esp+1A4h] [ebp-4Ch] BYREF
  boost::function0<void> v10; // [esp+1B8h] [ebp-38h] BYREF
  survarium::bullet_manager::bullet_functor *functor; // [esp+1D8h] [ebp-18h] BYREF
  unsigned int i; // [esp+1DCh] [ebp-14h]
  unsigned int granularity; // [esp+1E0h] [ebp-10h]
  unsigned int start_index; // [esp+1E4h] [ebp-Ch]
  unsigned int n; // [esp+1E8h] [ebp-8h]
  unsigned int bullets_count; // [esp+1ECh] [ebp-4h]

  bullets_count = this->m_bullets.m_end - this->m_bullets.m_begin;
  if ( bullets_count )
  {
    granularity = 256;
    n = bullets_count >> 8;
    if ( bullets_count >= 0x100 )
    {
      for ( i = 0; i < n; ++i )
      {
        v5 = *boost::bind<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int,survarium::bullet_manager *,unsigned int,unsigned int,unsigned int>(
                &result,
                survarium::bullet_manager::tick_bullets,
                this,
                16 * i,
                16 * (i + 1),
                current_time_in_ms);
        boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
          (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v5.l_.a3_.t_,
          &v10);
        boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>>(
          &v10,
          v5);
        vostok::tasks::spawn_task((const boost::function<void __cdecl(void)> *)&v10, this->m_task_type, 0);
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v10);
      }
    }
    start_index = n << 8;
    survarium::bullet_manager::tick_bullets(this, n << 8, (n << 8) + bullets_count % 0x100, current_time_in_ms);
    vostok::tasks::wait_for_all_children((vostok::tasks *)this);
    while ( thisb->m_functors.m_top.m_pointer )
    {
      functor = vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72>::try_pop(&thisb->m_functors);
      v8 = 0;
      survarium::weapon_user_dead_state::finalize(v2);
      boost::function0<void>::operator()(&functor->functor);
      vostok::memory::detail::delete_helper_impl<survarium::bullet_manager::bullet_functor_mt_allocator,survarium::bullet_manager::bullet_functor,vostok::memory::detail::call_destructor_predicate>(
        &thisb->m_mt_stack_allocator,
        (boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> **)&functor);
    }
    end = (vostok::ai::planning::action_parameter **)thisb->m_bullets.m_end;
    begin = (vostok::ai::planning::action_parameter **)stlp_std::remove_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
                                                         thisb->m_bullets.m_begin,
                                                         thisb->m_bullets.m_end,
                                                         (survarium::redundant_bullet_predicate)thisb);
    vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(
      (vostok::buffer_vector<vostok::ai::planning::action_parameter *> *)thisb,
      &begin,
      &end);
  }
}
