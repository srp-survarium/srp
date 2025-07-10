void __thiscall vostok::sound::sound_instance_proxy_internal::stop(vostok::sound::sound_instance_proxy_internal *this)
{
  vostok::sound::sound_instance_proxy_order *v1; // eax
  vostok::sound::sound_instance_proxy_order *v2; // [esp+0h] [ebp-74h]
  vostok::memory::base_allocator *allocator; // [esp+14h] [ebp-60h]
  boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::sound::sound_scene,vostok::sound::sound_instance_proxy_internal &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal> > > v5; // [esp+18h] [ebp-5Ch]
  vostok::sound::sound_instance_proxy_order *v6; // [esp+30h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::sound_instance_proxy_internal &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal> > > result; // [esp+34h] [ebp-40h] BYREF
  void (__thiscall *f)(vostok::sound::sound_scene *, vostok::sound::sound_instance_proxy_internal *); // [esp+44h] [ebp-30h]
  int f_4; // [esp+48h] [ebp-2Ch]
  boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal> a2; // [esp+4Ch] [ebp-28h]
  vostok::sound::sound_instance_proxy_order *order; // [esp+50h] [ebp-24h]
  boost::function<void __cdecl(void)> functor; // [esp+54h] [ebp-20h] BYREF

  f = vostok::sound::sound_scene::stop_produce_sound;
  f_4 = 0;
  a2.t_ = (vostok::sound::sound_instance_proxy_internal *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)this);
  v5 = *(boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::sound::sound_scene,vostok::sound::sound_instance_proxy_internal &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal> > > *)boost::bind<void,vostok::sound::sound_scene,vostok::sound::sound_instance_proxy_internal &,vostok::sound::sound_scene *,boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal>>(&result, (void (__thiscall *__ptr64)(vostok::sound::sound_scene *, vostok::sound::sound_instance_proxy_internal *))(unsigned int)vostok::sound::sound_scene::stop_produce_sound, this->m_scene, a2);
  functor.vtable = 0;
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::sound::sound_scene,vostok::sound::sound_instance_proxy_internal &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal>>>>(
    &functor,
    v5);
  allocator = vostok::sound::world_user::get_allocator(this->m_user);
  v6 = (vostok::sound::sound_instance_proxy_order *)vostok::memory::base_allocator::malloc_impl(allocator, 0x38u);
  if ( v6 )
  {
    vostok::sound::sound_instance_proxy_order::sound_instance_proxy_order(v6, this->m_user, this, &functor);
    v2 = v1;
  }
  else
  {
    v2 = 0;
  }
  order = v2;
  vostok::sound::world_user::add_order(this->m_user, v2);
  this->m_is_playing = 0;
  this->m_is_producing_paused = 0;
  this->m_is_propagating_paused = 0;
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&functor);
}
