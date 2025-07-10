void __thiscall vostok::vfs::mounter::~mounter(vostok::vfs::mounter *this)
{
  vostok::threading::mutex *v1; // ecx
  survarium::game_camera *v2; // ecx
  vostok::vfs::mount_referer *next_referer; // [esp+44h] [ebp-8h]
  vostok::vfs::mount_referer *referer; // [esp+48h] [ebp-4h]

  this->__vftable = (vostok::vfs::mounter_vtbl *)&vostok::vfs::mounter::`vftable';
  vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
    (vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *)((char *)&loc_2011E + (unsigned int)this->m_file_system + 2),
    this);
  for ( referer = vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                    &this->m_referers,
                    0); referer; referer = next_referer )
  {
    next_referer = referer->next;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
      &referer->result,
      &this->m_mount_ptr);
    vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      referer->ready_list,
      referer,
      0);
  }
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_args.callback);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&this->m_mount_ptr);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_referers.vostok::threading::mutex);
  survarium::weapon_user_dead_state::finalize(v2);
}
