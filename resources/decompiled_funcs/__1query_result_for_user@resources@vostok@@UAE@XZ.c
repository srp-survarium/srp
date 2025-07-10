void __thiscall vostok::resources::query_result_for_user::~query_result_for_user(
        vostok::resources::query_result_for_user *this)
{
  bool v2; // zf
  char *m_requery_path; // eax
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::resource_children *v5; // ecx

  v2 = this->m_requery_path == 0;
  this->__vftable = (vostok::resources::query_result_for_user_vtbl *)&vostok::resources::query_result_for_user::`vftable';
  if ( !v2 )
  {
    m_requery_path = this->m_requery_path;
    if ( m_requery_path )
    {
      pt3free(m_requery_path);
      this->m_requery_path = 0;
    }
  }
  vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&this->m_result_iterator);
  m_object = this->m_unmanaged_resource.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_unmanaged_resource.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_unmanaged_resource.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&this->m_managed_resource);
  this->__vftable = (vostok::resources::query_result_for_user_vtbl *)&vostok::resources::resource_base::`vftable';
  vostok::resources::resource_children::unlink_from_parents(v5);
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink(&this->grm_satisfaction_tree_hook.boost::intrusive::rbtree_node<void *>);
  this->grm_satisfaction_tree_hook.parent_ = 0;
  this->grm_satisfaction_tree_hook.left_ = 0;
  this->grm_satisfaction_tree_hook.right_ = 0;
  this->__vftable = (vostok::resources::query_result_for_user_vtbl *)&vostok::resources::resource_flags::`vftable';
  vostok::vfs::vfs_association::~vfs_association(this);
}
