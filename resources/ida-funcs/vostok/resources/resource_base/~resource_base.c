void __thiscall vostok::resources::resource_base::~resource_base(vostok::resources::resource_base *this)
{
  boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0> *v2; // ecx

  this->__vftable = (vostok::resources::resource_base_vtbl *)&vostok::resources::resource_base::`vftable';
  vostok::resources::resource_children::unlink_from_parents(this, this);
  boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0>::~generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0>(
    v2,
    &this->grm_satisfaction_tree_hook.boost::intrusive::rbtree_node<void *>);
  this->__vftable = (vostok::resources::resource_base_vtbl *)&vostok::vfs::vfs_association::`vftable';
}
