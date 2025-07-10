void __thiscall survarium::bullet_manager::update_tracer(
        survarium::bullet_manager *this,
        survarium::bullet *bullet,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        float length)
{
  survarium::bullet_manager::bullet_functor *v5; // eax
  survarium::bullet_manager::bullet_functor *v6; // [esp+18h] [ebp-ACh]
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72> *target; // [esp+20h] [ebp-A4h]
  volatile __int64 comperand; // [esp+24h] [ebp-A0h]
  survarium::bullet_manager::bullet_functor *exchange; // [esp+2Ch] [ebp-98h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::bullet_manager,unsigned short,vostok::math::float3 const &,vostok::math::float3 const &,float>,boost::_bi::list5<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned short>,boost::reference_wrapper<vostok::math::float3 const >,boost::reference_wrapper<vostok::math::float3 const >,boost::_bi::value<float> > > v11; // [esp+34h] [ebp-90h]
  boost::function0<void> v12; // [esp+6Ch] [ebp-58h] BYREF
  void *_Where; // [esp+8Ch] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::bullet_manager,unsigned short,vostok::math::float3 const &,vostok::math::float3 const &,float>,boost::_bi::list5<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned short>,boost::reference_wrapper<vostok::math::float3 const >,boost::reference_wrapper<vostok::math::float3 const >,boost::_bi::value<float> > > result; // [esp+9Ch] [ebp-28h] BYREF
  boost::reference_wrapper<vostok::math::float3 const > a3; // [esp+B4h] [ebp-10h]
  boost::reference_wrapper<vostok::math::float3 const > a4; // [esp+B8h] [ebp-Ch]
  survarium::bullet_manager::bullet_functor *v17; // [esp+BCh] [ebp-8h]
  survarium::bullet_manager::bullet_functor *functor; // [esp+C0h] [ebp-4h]

  if ( this->m_engine )
  {
    _Where = survarium::bullet_manager::bullet_functor_mt_allocator::malloc_impl(
               &this->m_mt_stack_allocator,
               (survarium::game_camera *)0x58);
    v17 = (survarium::bullet_manager::bullet_functor *)operator new(0x58u, _Where);
    if ( v17 )
    {
      survarium::bullet_manager::bullet_functor::bullet_functor(v17);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    functor = v6;
    v6->position = *position;
    functor->direction = *direction;
    a4.t_ = (const vostok::math::float3 *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)&functor->direction);
    a3.t_ = (const vostok::math::float3 *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)&functor->position);
    v11 = *boost::bind<void,survarium::bullet_manager,unsigned short,vostok::math::float3 const &,vostok::math::float3 const &,float,survarium::bullet_manager *,unsigned short,boost::reference_wrapper<vostok::math::float3 const>,boost::reference_wrapper<vostok::math::float3 const>,float>(
             &result,
             survarium::bullet_manager::update_tracer_impl,
             this,
             bullet->m_tracer_idx,
             a3,
             a4,
             length);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v11.l_.a4_.t_,
      &v12);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::bullet_manager,unsigned short,vostok::math::float3 const &,vostok::math::float3 const &,float>,boost::_bi::list5<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned short>,boost::reference_wrapper<vostok::math::float3 const>,boost::reference_wrapper<vostok::math::float3 const>,boost::_bi::value<float>>>>(
      &v12,
      v11);
    boost::function0<void>::swap(&v12, &functor->functor);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v12);
    target = &this->m_functors;
    exchange = functor;
    do
    {
      comperand = target->m_top.whole;
      exchange->next = target->m_top.m_pointer;
    }
    while ( vostok::threading::interlocked_compare_exchange(
              &target->m_top.whole,
              __SPAIR64__(HIDWORD(comperand), (unsigned int)exchange),
              comperand) != comperand );
  }
}
