void __cdecl vostok::resources::set_associated(
        vostok::vfs::vfs_iterator it,
        vostok::resources::resource_base *resource)
{
  vostok::vfs::vfs_iterator *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1> > > v4; // [esp-8h] [ebp-48h]
  int v5; // [esp+0h] [ebp-40h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v6; // [esp+8h] [ebp-38h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+Ch] [ebp-34h] BYREF
  int v8; // [esp+10h] [ebp-30h]
  vostok::resources::resource_base *v9; // [esp+14h] [ebp-2Ch]
  int v10; // [esp+18h] [ebp-28h]
  char v11; // [esp+1Dh] [ebp-23h]
  boost::function<void __cdecl(vostok::vfs::vfs_association * &)> v12; // [esp+20h] [ebp-20h] BYREF

  v6.m_object = 0;
  v7.m_object = 0;
  v8 = 0;
  v10 = 0;
  v11 = 0;
  v9 = resource;
  v4.l_.a1_.t_ = (vostok::resources::association_callback_helper *)&v6;
  v4.f_.f_ = (void (__thiscall *)(vostok::resources::association_callback_helper *, vostok::vfs::vfs_association **))vostok::resources::association_callback_helper::set_associated;
  boost::function<void __cdecl (vostok::vfs::vfs_association * &)>::function<void __cdecl (vostok::vfs::vfs_association * &)>(
    (boost::function<void __cdecl(vostok::vfs::vfs_association * &)> *)vostok::resources::association_callback_helper::set_associated,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1> > > *)&v12,
    v4,
    v5);
  vostok::vfs::vfs_iterator::access_association(v2, (int)&it, &v12);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v12);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
}
