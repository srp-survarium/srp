void __thiscall vostok::sound::world_user::set_active_sound_scene(
        vostok::sound::world_user *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *scene,
        unsigned int fade_in_time,
        unsigned int fade_out_old_scene_time)
{
  vostok::sound::functor_command<vostok::sound::sound_order> *v4; // [esp+0h] [ebp-D8h]
  boost::function0<void> *p_m_next_for_orders; // [esp+10h] [ebp-C8h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > v7; // [esp+14h] [ebp-C4h]
  char v8; // [esp+7Ch] [ebp-5Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::sound_world,vostok::sound::sound_scene &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_world *>,boost::reference_wrapper<vostok::sound::sound_scene>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > result; // [esp+80h] [ebp-58h] BYREF
  void (__thiscall *f)(vostok::sound::sound_world *, vostok::sound::sound_scene *, unsigned int, unsigned int); // [esp+9Ch] [ebp-3Ch]
  int f_4; // [esp+A0h] [ebp-38h]
  boost::reference_wrapper<vostok::sound::sound_scene> a2; // [esp+A4h] [ebp-34h]
  boost::function0<void> v13; // [esp+A8h] [ebp-30h] BYREF
  vostok::sound::sound_order *v14; // [esp+CCh] [ebp-Ch]
  vostok::sound::functor_command<vostok::sound::sound_order> *order; // [esp+D0h] [ebp-8h]
  vostok::sound::sound_scene *scn; // [esp+D4h] [ebp-4h]

  v8 = 0;
  scn = (vostok::sound::sound_scene *)scene->m_object;
  v14 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(this->m_allocator, 0x30u);
  if ( v14 )
  {
    f = vostok::sound::sound_world::set_active_sound_scene_impl;
    f_4 = 0;
    a2.t_ = (vostok::sound::sound_scene *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)scn);
    v7 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > *)boost::bind<void,vostok::sound::sound_world,vostok::sound::sound_scene &,unsigned int,unsigned int,vostok::sound::sound_world *,boost::reference_wrapper<vostok::sound::sound_scene>,unsigned int,unsigned int>(&result, (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::sound::sound_scene *, unsigned int, unsigned int))(unsigned int)vostok::sound::sound_world::set_active_sound_scene_impl, this->m_owner_world, a2, fade_in_time, fade_out_old_scene_time);
    v13.vtable = 0;
    if ( boost::detail::function::basic_vtable0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64>>>>(
           &`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::sound_world,vostok::sound::sound_scene &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_world *>,boost::reference_wrapper<vostok::sound::sound_scene>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable,
           v7,
           &v13.functor) )
    {
      v13.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::sound_world,vostok::sound::sound_scene &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_world *>,boost::reference_wrapper<vostok::sound::sound_scene>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable.base.manager
                                                          + 1);
    }
    else
    {
      v13.vtable = 0;
    }
    v8 = 1;
    vostok::sound::sound_order::sound_order(v14);
    v14->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
    p_m_next_for_orders = (boost::function0<void> *)&v14[1].m_next_for_orders;
    v14[1].m_next_for_orders = 0;
    boost::function0<void>::assign_to_own(p_m_next_for_orders, &v13);
    v4 = (vostok::sound::functor_command<vostok::sound::sound_order> *)v14;
  }
  else
  {
    v4 = 0;
  }
  order = v4;
  if ( (v8 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v13);
  vostok::sound::world_user::add_order(this, order);
}
