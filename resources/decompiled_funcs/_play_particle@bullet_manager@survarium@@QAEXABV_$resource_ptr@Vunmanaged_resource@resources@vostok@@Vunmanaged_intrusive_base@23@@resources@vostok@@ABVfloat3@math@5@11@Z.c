void __thiscall survarium::bullet_manager::play_particle(
        survarium::bullet_manager *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *sound,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        const vostok::math::float3 *normal)
{
  survarium::bullet_manager::bullet_functor *v5; // eax
  survarium::bullet_manager::bullet_functor *v6; // eax
  survarium::bullet_manager::bullet_functor *v7; // [esp+14h] [ebp-C0h]
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72> *target; // [esp+1Ch] [ebp-B8h]
  volatile __int64 comperand; // [esp+20h] [ebp-B4h]
  survarium::bullet_manager::bullet_functor *exchange; // [esp+28h] [ebp-ACh]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::bullet_manager,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float3 const &,vostok::math::float3 const &,vostok::math::float3 const &>,boost::_bi::list5<boost::_bi::value<survarium::bullet_manager *>,boost::reference_wrapper<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const >,boost::reference_wrapper<vostok::math::float3 const >,boost::reference_wrapper<vostok::math::float3 const >,boost::reference_wrapper<vostok::math::float3 const > > > v12; // [esp+30h] [ebp-A4h]
  boost::function0<void> v13; // [esp+68h] [ebp-6Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::bullet_manager,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float3 const &,vostok::math::float3 const &,vostok::math::float3 const &>,boost::_bi::list5<boost::_bi::value<survarium::bullet_manager *>,boost::reference_wrapper<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const >,boost::reference_wrapper<vostok::math::float3 const >,boost::reference_wrapper<vostok::math::float3 const >,boost::reference_wrapper<vostok::math::float3 const > > > result; // [esp+A4h] [ebp-30h] BYREF
  boost::reference_wrapper<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const > a2; // [esp+BCh] [ebp-18h]
  boost::reference_wrapper<vostok::math::float3 const > a3; // [esp+C0h] [ebp-14h]
  boost::reference_wrapper<vostok::math::float3 const > a4; // [esp+C4h] [ebp-10h]
  boost::reference_wrapper<vostok::math::float3 const > a5; // [esp+C8h] [ebp-Ch]
  survarium::bullet_manager::bullet_functor *v19; // [esp+CCh] [ebp-8h]
  survarium::bullet_manager::bullet_functor *functor; // [esp+D0h] [ebp-4h]

  if ( this->m_engine )
  {
    v5 = vostok::memory::new_helper<survarium::bullet_manager::bullet_functor>::call<survarium::bullet_manager::bullet_functor_mt_allocator>(&this->m_mt_stack_allocator);
    v19 = (survarium::bullet_manager::bullet_functor *)operator new(0x58u, v5);
    if ( v19 )
    {
      survarium::bullet_manager::bullet_functor::bullet_functor(v19);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    functor = v7;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      &v7->resource,
      sound);
    v7->position = *position;
    functor->direction = *direction;
    vostok::math::float3_pod::normalize(&functor->direction);
    functor->normal = *normal;
    vostok::math::float3_pod::normalize(&functor->normal);
    a5.t_ = (const vostok::math::float3 *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)&functor->normal);
    a4.t_ = (const vostok::math::float3 *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)&functor->direction);
    a3.t_ = (const vostok::math::float3 *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)&functor->position);
    a2.t_ = (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)&functor->resource);
    v12 = *boost::bind<void,survarium::bullet_manager,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float3 const &,vostok::math::float3 const &,vostok::math::float3 const &,survarium::bullet_manager *,boost::reference_wrapper<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const>,boost::reference_wrapper<vostok::math::float3 const>,boost::reference_wrapper<vostok::math::float3 const>,boost::reference_wrapper<vostok::math::float3 const>>(
             &result,
             survarium::bullet_manager::play_particle_impl,
             this,
             a2,
             a3,
             a4,
             a5);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v12.l_.a3_.t_,
      &v13);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::bullet_manager,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float3 const &,vostok::math::float3 const &,vostok::math::float3 const &>,boost::_bi::list5<boost::_bi::value<survarium::bullet_manager *>,boost::reference_wrapper<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const>,boost::reference_wrapper<vostok::math::float3 const>,boost::reference_wrapper<vostok::math::float3 const>,boost::reference_wrapper<vostok::math::float3 const>>>>(
      &v13,
      v12);
    boost::function0<void>::swap(&v13, &functor->functor);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v13);
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
