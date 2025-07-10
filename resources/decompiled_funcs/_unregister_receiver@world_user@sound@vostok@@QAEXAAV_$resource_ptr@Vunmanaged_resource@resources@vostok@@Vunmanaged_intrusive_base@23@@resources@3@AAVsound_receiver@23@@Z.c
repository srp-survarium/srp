void __thiscall vostok::sound::world_user::unregister_receiver(
        vostok::sound::world_user *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::sound::sound_receiver *receiver)
{
  vostok::sound::functor_command<vostok::sound::sound_order> *v3; // [esp+0h] [ebp-D8h]
  boost::function0<void> *p_m_next_for_orders; // [esp+28h] [ebp-B0h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_scene,vostok::sound::world_user &,vostok::sound::sound_receiver *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::world_user>,boost::_bi::value<vostok::sound::sound_receiver *> > > v6; // [esp+2Ch] [ebp-ACh]
  char v7; // [esp+5Ch] [ebp-7Ch]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v8; // [esp+60h] [ebp-78h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_scene,vostok::sound::world_user &,vostok::sound::sound_receiver *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::world_user>,boost::_bi::value<vostok::sound::sound_receiver *> > > result; // [esp+80h] [ebp-58h] BYREF
  void (__thiscall *f)(vostok::sound::sound_scene *, vostok::sound::world_user *, vostok::sound::sound_receiver *); // [esp+9Ch] [ebp-3Ch]
  int f_4; // [esp+A0h] [ebp-38h]
  boost::reference_wrapper<vostok::sound::world_user> a2; // [esp+A4h] [ebp-34h]
  boost::function0<void> v13; // [esp+A8h] [ebp-30h] BYREF
  vostok::sound::sound_order *v14; // [esp+CCh] [ebp-Ch]
  vostok::sound::functor_command<vostok::sound::sound_order> *order; // [esp+D0h] [ebp-8h]
  vostok::sound::sound_scene *scn; // [esp+D4h] [ebp-4h]

  v7 = 0;
  scn = (vostok::sound::sound_scene *)scene->m_object;
  if ( !this->m_owner_world->m_is_destroying )
    vostok::sound::world_user::mark_receiver_as_deleted(this, (int)receiver);
  v14 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(this->m_allocator, 0x30u);
  if ( v14 )
  {
    f = vostok::sound::sound_scene::unregister_receiver;
    f_4 = 0;
    a2.t_ = (vostok::sound::world_user *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)this);
    v6 = *boost::bind<void,vostok::sound::sound_scene,vostok::sound::world_user &,vostok::sound::sound_receiver *,vostok::sound::sound_scene *,boost::reference_wrapper<vostok::sound::world_user>,vostok::sound::sound_receiver *>(
            &result,
            (void (__thiscall *__ptr64)(vostok::sound::sound_scene *, vostok::sound::world_user *, vostok::sound::sound_receiver *))(unsigned int)vostok::sound::sound_scene::unregister_receiver,
            scn,
            a2,
            receiver);
    v13.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_scene,vostok::sound::world_user &,vostok::sound::sound_receiver *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::world_user>,boost::_bi::value<vostok::sound::sound_receiver *>>>>(
      &v13,
      v6);
    v7 = 1;
    vostok::sound::sound_order::sound_order(v14);
    v14->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
    p_m_next_for_orders = (boost::function0<void> *)&v14[1].m_next_for_orders;
    v14[1].m_next_for_orders = 0;
    boost::function0<void>::assign_to_own(p_m_next_for_orders, &v13);
    v3 = (vostok::sound::functor_command<vostok::sound::sound_order> *)v14;
  }
  else
  {
    v3 = 0;
  }
  order = v3;
  if ( (v7 & 1) != 0 )
  {
    v7 &= ~1u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v13);
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
  {
    v8.vtable = 0;
    boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      &v8,
      vostok::core::g_log_callback);
    v7 |= 2u;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v8,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\world_user.cpp",
      0x70u,
      "void __thiscall vostok::sound::world_user::unregister_receiver(class vostok::resources::resource_ptr<class vostok:"
      ":resources::unmanaged_resource,class vostok::resources::unmanaged_intrusive_base> &,class vostok::sound::sound_receiver &)",
      "sound:",
      info,
      "unregister_receiver: 0x%8x",
      order);
  }
  if ( (v7 & 2) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v8);
  vostok::sound::world_user::add_order(this, order);
}
