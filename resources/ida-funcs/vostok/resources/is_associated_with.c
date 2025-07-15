char __cdecl vostok::resources::is_associated_with(vostok::vfs::vfs_iterator it)
{
  vostok::vfs::vfs_iterator *v1; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  char v3; // bl
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1> > > v5; // [esp-8h] [ebp-4Ch]
  int v6; // [esp+0h] [ebp-44h]
  boost::function<void __cdecl(vostok::vfs::vfs_association * &)> v7; // [esp+8h] [ebp-3Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v8; // [esp+28h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+2Ch] [ebp-18h] BYREF
  int v10; // [esp+30h] [ebp-14h]
  vostok::vfs::vfs_hashset *m_hashset; // [esp+34h] [ebp-10h]
  int v12; // [esp+38h] [ebp-Ch]
  char v13; // [esp+3Dh] [ebp-7h]

  v8.m_object = 0;
  v9.m_object = 0;
  v10 = 0;
  v12 = 0;
  v13 = 0;
  m_hashset = it.m_hashset;
  v5.l_.a1_.t_ = (vostok::resources::association_callback_helper *)&v8;
  v5.f_.f_ = (void (__thiscall *)(vostok::resources::association_callback_helper *, vostok::vfs::vfs_association **))vostok::resources::association_callback_helper::is_associated;
  boost::function<void __cdecl (vostok::vfs::vfs_association * &)>::function<void __cdecl (vostok::vfs::vfs_association * &)>(
    (boost::function<void __cdecl(vostok::vfs::vfs_association * &)> *)vostok::resources::association_callback_helper::is_associated,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1> > > *)&v7,
    v5,
    v6);
  vostok::vfs::vfs_iterator::access_association(v1, (int)&it.m_node, &v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v7);
  v3 = v13;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
  return v3;
}
