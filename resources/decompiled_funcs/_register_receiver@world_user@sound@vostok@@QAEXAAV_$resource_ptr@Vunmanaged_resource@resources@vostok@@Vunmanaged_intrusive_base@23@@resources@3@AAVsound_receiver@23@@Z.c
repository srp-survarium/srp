void __thiscall vostok::sound::world_user::register_receiver(
        vostok::sound::world_user *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::sound::sound_receiver *receiver)
{
  vostok::sound::functor_command<vostok::sound::sound_order> *v3; // [esp+0h] [ebp-D4h]
  boost::function0<void> *p_m_next_for_orders; // [esp+28h] [ebp-ACh]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_scene,vostok::sound::sound_receiver *,vostok::sound::atomic_half3 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_scene *>,boost::_bi::value<vostok::sound::sound_receiver *>,boost::_bi::value<vostok::sound::atomic_half3 *> > > v6; // [esp+2Ch] [ebp-A8h]
  char v7; // [esp+58h] [ebp-7Ch]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v8; // [esp+5Ch] [ebp-78h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > result; // [esp+7Ch] [ebp-58h] BYREF
  void (__thiscall *f)(vostok::sound::sound_scene *, vostok::sound::sound_receiver *, vostok::sound::atomic_half3 *); // [esp+94h] [ebp-40h]
  int f_4; // [esp+98h] [ebp-3Ch]
  boost::function0<void> v12; // [esp+9Ch] [ebp-38h] BYREF
  vostok::sound::sound_order *v13; // [esp+C0h] [ebp-14h]
  vostok::sound::sound_scene *m_object; // [esp+C4h] [ebp-10h]
  vostok::sound::atomic_half3 *pos; // [esp+C8h] [ebp-Ch]
  vostok::sound::functor_command<vostok::sound::sound_order> *order; // [esp+CCh] [ebp-8h]
  vostok::sound::sound_scene *scn; // [esp+D0h] [ebp-4h]

  v7 = 0;
  m_object = (vostok::sound::sound_scene *)scene->m_object;
  scn = m_object;
  pos = vostok::sound::sound_scene::create_receiver_position(m_object);
  vostok::sound::sound_receiver::on_register_receiver_order_created(receiver, pos);
  v13 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(this->m_allocator, 0x30u);
  if ( v13 )
  {
    f = vostok::sound::sound_scene::register_receiver;
    f_4 = 0;
    v6 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_scene,vostok::sound::sound_receiver *,vostok::sound::atomic_half3 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_scene *>,boost::_bi::value<vostok::sound::sound_receiver *>,boost::_bi::value<vostok::sound::atomic_half3 *> > > *)boost::bind<void,vostok::sound::sound_scene,vostok::sound::sound_receiver *,vostok::sound::atomic_half3 *,vostok::sound::sound_scene *,vostok::sound::sound_receiver *,vostok::sound::atomic_half3 *>(&result, (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::sound::sound_instance_proxy_internal *, vostok::memory::reader *))(unsigned int)vostok::sound::sound_scene::register_receiver, (vostok::sound::sound_world *)scn, (vostok::sound::sound_instance_proxy_internal *)receiver, (vostok::memory::reader *)pos);
    v12.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_scene,vostok::sound::sound_receiver *,vostok::sound::atomic_half3 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_scene *>,boost::_bi::value<vostok::sound::sound_receiver *>,boost::_bi::value<vostok::sound::atomic_half3 *>>>>(
      &v12,
      v6);
    v7 = 1;
    vostok::sound::sound_order::sound_order(v13);
    v13->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
    p_m_next_for_orders = (boost::function0<void> *)&v13[1].m_next_for_orders;
    v13[1].m_next_for_orders = 0;
    boost::function0<void>::assign_to_own(p_m_next_for_orders, &v12);
    v3 = (vostok::sound::functor_command<vostok::sound::sound_order> *)v13;
  }
  else
  {
    v3 = 0;
  }
  order = v3;
  if ( (v7 & 1) != 0 )
  {
    v7 &= ~1u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v12);
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
      0x60u,
      "void __thiscall vostok::sound::world_user::register_receiver(class vostok::resources::resource_ptr<class vostok::r"
      "esources::unmanaged_resource,class vostok::resources::unmanaged_intrusive_base> &,class vostok::sound::sound_receiver &)",
      "sound:",
      info,
      "register_receiver: 0x%8x",
      order);
  }
  if ( (v7 & 2) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v8);
  vostok::sound::world_user::add_order(this, order);
}
