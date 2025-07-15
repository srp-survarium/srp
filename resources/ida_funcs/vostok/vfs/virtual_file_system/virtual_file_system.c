void __thiscall vostok::vfs::virtual_file_system::virtual_file_system(vostok::vfs::virtual_file_system *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v3; // ecx

  this->mount_history.m_first = 0;
  this->mount_history.m_last = 0;
  fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>(
    (vostok::animation::mixing::expression *)this,
    &this->mount_history.m_policy.m_lock);
  `vector constructor iterator'(
    (char *)&this->hashset,
    8u,
    32,
    (void *(__thiscall *)(void *))vostok::threading::reader_writer_lock::reader_writer_lock);
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>(&this->hashset.m_hashset);
  *(vostok::vfs::vfs_mount **)((char *)&this->mount_history.m_first + (_DWORD)&loc_2011E + 2) = 0;
  *(vostok::vfs::vfs_mount **)((char *)&this->mount_history.m_last + (_DWORD)&loc_2011E + 2) = 0;
  vostok::threading::mutex::mutex((vostok::threading::mutex *)((char *)&this->mount_history.m_policy.m_thread_id
                                                             + (_DWORD)&loc_2011E
                                                             + 2));
  vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>((vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)(&this->mount_history.gap0 + (_DWORD)&loc_20146 + 2));
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&byte_20168[(_DWORD)this],
    &byte_20168[(_DWORD)this]);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v1,
    &this->mount_history.gap0 + (_DWORD)&loc_20186 + 2);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, (int *)((char *)&dword_201A8 + (_DWORD)this));
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, (char *)&loc_201C8 + (_DWORD)this);
}
