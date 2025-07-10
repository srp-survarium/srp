void __usercall vostok::resources::resource_children::resource_children(
        vostok::resources::resource_children *this@<esi>,
        volatile int flags@<edi>)
{
  vostok::vfs::vfs_association::vfs_association(this, flags & 7);
  this->__vftable = (vostok::resources::resource_children_vtbl *)&vostok::resources::resource_flags::`vftable';
  this->m_flags.m_flags = flags;
  this->m_reconstruction_info_actuality_tick = 0;
  this->m_reconstruction_size = -1;
  this->m_uid = _InterlockedIncrement((volatile signed __int32 *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[1]);
  this->__vftable = (vostok::resources::resource_children_vtbl *)&vostok::resources::resource_children::`vftable';
  this->m_children_resources.m_size = 0;
  this->m_children_resources.m_lock = 0;
  this->m_children_resources.m_thread_id = 0;
  this->m_children_resources.m_first = 0;
  this->m_children_resources.m_last = 0;
  this->m_parent_resources.m_size = 0;
  this->m_parent_resources.m_lock = 0;
  this->m_parent_resources.m_thread_id = 0;
  this->m_parent_resources.m_first = 0;
  this->m_parent_resources.m_last = 0;
}
