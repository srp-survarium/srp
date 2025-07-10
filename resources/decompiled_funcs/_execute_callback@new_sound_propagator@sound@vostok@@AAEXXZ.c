void __thiscall vostok::sound::new_sound_propagator::execute_callback(vostok::sound::new_sound_propagator *this)
{
  vostok::sound::functor_command<vostok::sound::sound_response> *v1; // [esp+0h] [ebp-98h]
  boost::function0<void> *v3; // [esp+14h] [ebp-84h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal>,boost::_bi::value<unsigned int> > > v4; // [esp+18h] [ebp-80h]
  vostok::sound::world_user *channel; // [esp+3Ch] [ebp-5Ch]
  char v6; // [esp+4Ch] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal>,boost::_bi::value<unsigned int> > > result; // [esp+50h] [ebp-48h] BYREF
  void (__thiscall *f)(vostok::sound::sound_instance_proxy_internal *, unsigned int); // [esp+64h] [ebp-34h]
  int f_4; // [esp+68h] [ebp-30h]
  boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal> a1; // [esp+6Ch] [ebp-2Ch]
  boost::function0<void> v11; // [esp+70h] [ebp-28h] BYREF
  vostok::sound::sound_response *v12; // [esp+90h] [ebp-8h]
  vostok::sound::functor_command<vostok::sound::sound_response> *response; // [esp+94h] [ebp-4h]

  v6 = 0;
  _InterlockedExchange(&this->m_proxy->m_callback_pending, 1);
  channel = vostok::sound::world_user::get_channel(this->m_proxy->m_user);
  v12 = (vostok::sound::sound_response *)vostok::memory::base_allocator::malloc_impl(
                                           channel->m_channel.responses.m_owner_allocator,
                                           0x28u);
  if ( v12 )
  {
    f = vostok::sound::sound_instance_proxy_internal::execute_callback;
    f_4 = 0;
    a1.t_ = (vostok::sound::sound_instance_proxy_internal *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)this->m_proxy);
    v4 = *boost::bind<void,vostok::sound::sound_instance_proxy_internal,unsigned int,boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal>,unsigned int>(
            &result,
            (void (__thiscall *__ptr64)(vostok::sound::sound_instance_proxy_internal *, unsigned int))(unsigned int)vostok::sound::sound_instance_proxy_internal::execute_callback,
            a1,
            this->m_playback_id);
    v11.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal>,boost::_bi::value<unsigned int>>>>(
      &v11,
      v4);
    v6 = 1;
    vostok::sound::sound_response::sound_response(v12);
    v12->__vftable = (vostok::sound::sound_response_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_response>::`vftable';
    v3 = (boost::function0<void> *)&v12[1];
    v12[1].__vftable = 0;
    boost::function0<void>::assign_to_own(v3, &v11);
    v1 = (vostok::sound::functor_command<vostok::sound::sound_response> *)v12;
  }
  else
  {
    v1 = 0;
  }
  response = v1;
  if ( (v6 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v11);
  vostok::sound::world_user::add_response(this->m_proxy->m_user, response);
}
