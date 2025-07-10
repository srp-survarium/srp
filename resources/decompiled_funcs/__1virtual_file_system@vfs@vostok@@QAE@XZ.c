void __thiscall vostok::vfs::virtual_file_system::~virtual_file_system(vostok::vfs::virtual_file_system *this)
{
  survarium::game_camera *v1; // ecx
  vostok::threading::mutex *v2; // ecx
  survarium::game_camera *v3; // ecx

  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)((char *)&loc_201C8 + (_DWORD)this));
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)((char *)&dword_201A8 + (_DWORD)this));
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->on_node_hides);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&byte_20168[(_DWORD)this]);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&this->scheduled_to_unmount.m_last);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&this->scheduled_to_unmount.m_first);
  survarium::weapon_user_dead_state::finalize(v1);
  vostok::threading::mutex::~mutex(v2, (_RTL_CRITICAL_SECTION *)&this->pending_mounts.m_policy);
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::~hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>(&this->hashset.m_hashset);
  `vector destructor iterator'(
    (char *)&this->hashset,
    8u,
    32,
    (void (__thiscall *)(void *))vostok::threading::reader_writer_lock::~reader_writer_lock);
  survarium::weapon_user_dead_state::finalize(v3);
}
