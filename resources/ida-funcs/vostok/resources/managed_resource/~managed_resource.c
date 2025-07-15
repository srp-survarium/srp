void __usercall vostok::resources::managed_resource::~managed_resource(
        vostok::resources::managed_resource *this@<ecx>,
        int a2@<edi>)
{
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v2; // ecx
  vostok::resources::resource_children *v3; // ecx

  *(_DWORD *)a2 = &vostok::resources::managed_resource::`vftable'{for `vostok::resources::resource_base'};
  *(_DWORD *)(a2 + 208) = &vostok::resources::managed_resource::`vftable'{for `vostok::memory::managed_node_owner'};
  vostok::resources::resource_children::unlink_from_children(this);
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::~child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>(
    v2,
    (vostok::resources::unmanaged_intrusive_base **)(a2 + 228));
  *(_DWORD *)(a2 + 208) = &vostok::memory::managed_node_owner::`vftable';
  *(_DWORD *)a2 = &vostok::resources::resource_base::`vftable';
  vostok::resources::resource_children::unlink_from_parents(v3);
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink((boost::intrusive::rbtree_node<void *> *)(a2 + 136));
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)a2 = &vostok::resources::resource_flags::`vftable';
  vostok::vfs::vfs_association::~vfs_association((vostok::vfs::vfs_association *)a2);
}
