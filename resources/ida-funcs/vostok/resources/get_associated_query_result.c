vostok::resources::query_result *__cdecl vostok::resources::get_associated_query_result(vostok::vfs::vfs_iterator it)
{
  vostok::vfs::vfs_iterator *v1; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  int v3; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1> > > v5; // [esp-8h] [ebp-48h]
  int v6; // [esp+0h] [ebp-40h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v7; // [esp+8h] [ebp-38h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+Ch] [ebp-34h] BYREF
  int v9; // [esp+10h] [ebp-30h]
  int v10; // [esp+14h] [ebp-2Ch]
  int v11; // [esp+18h] [ebp-28h]
  char v12; // [esp+1Dh] [ebp-23h]
  boost::function<void __cdecl(vostok::vfs::vfs_association * &)> v13; // [esp+20h] [ebp-20h] BYREF

  v7.m_object = 0;
  v8.m_object = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v5.l_.a1_.t_ = (vostok::resources::association_callback_helper *)&v7;
  v5.f_.f_ = (void (__thiscall *)(vostok::resources::association_callback_helper *, vostok::vfs::vfs_association **))vostok::resources::association_callback_helper::get_query;
  boost::function<void __cdecl (vostok::vfs::vfs_association * &)>::function<void __cdecl (vostok::vfs::vfs_association * &)>(
    (boost::function<void __cdecl(vostok::vfs::vfs_association * &)> *)vostok::resources::association_callback_helper::get_query,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1> > > *)&v13,
    v5,
    v6);
  vostok::vfs::vfs_iterator::access_association(v1, (int)&it, &v13);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v13);
  v3 = v9;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  return (vostok::resources::query_result *)v3;
}
