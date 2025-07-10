void __thiscall vostok::resources::resource_base::~resource_base(vostok::resources::resource_base *this)
{
  this->__vftable = (vostok::resources::resource_base_vtbl *)&vostok::resources::resource_base::`vftable';
  vostok::resources::resource_children::unlink_from_parents(this);
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink(&this->grm_satisfaction_tree_hook.boost::intrusive::rbtree_node<void *>);
  this->grm_satisfaction_tree_hook.parent_ = 0;
  this->grm_satisfaction_tree_hook.left_ = 0;
  this->grm_satisfaction_tree_hook.right_ = 0;
  this->__vftable = (vostok::resources::resource_base_vtbl *)&vostok::resources::resource_flags::`vftable';
  vostok::vfs::vfs_association::~vfs_association(this);
}
