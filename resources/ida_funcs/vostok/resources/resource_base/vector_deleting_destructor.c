vostok::resources::resource_base *__thiscall vostok::resources::resource_base::`vector deleting destructor'(
        vostok::resources::resource_base *this,
        char a2)
{
  this->__vftable = (vostok::resources::resource_base_vtbl *)&vostok::resources::resource_base::`vftable';
  vostok::resources::resource_children::unlink_from_parents(this);
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink(&this->grm_satisfaction_tree_hook.boost::intrusive::rbtree_node<void *>);
  this->grm_satisfaction_tree_hook.parent_ = 0;
  this->grm_satisfaction_tree_hook.left_ = 0;
  this->grm_satisfaction_tree_hook.right_ = 0;
  this->__vftable = (vostok::resources::resource_base_vtbl *)&vostok::resources::resource_flags::`vftable';
  vostok::vfs::vfs_association::~vfs_association(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
