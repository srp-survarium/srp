void __thiscall vostok::vfs::mounter::finish(
        vostok::vfs::mounter *this,
        vostok::vfs::mount_result *result,
        bool reused_from_history)
{
  vostok::vfs::vfs_mount *v3; // eax
  const vostok::variant<32> *v4; // esi
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  vostok::vfs::vfs_mount *v6; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v9; // ecx
  vostok::vfs::base_node<1> *submount_node; // edx
  vostok::vfs::mount_result v11[2]; // [esp-8h] [ebp-2BCh] BYREF
  bool v12; // [esp+Bh] [ebp-2A9h]
  vostok::vfs::mounter *thisa; // [esp+Ch] [ebp-2A8h]
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v14; // [esp+13Ch] [ebp-178h]
  vostok::vfs::mount_root_node_base<1> *node; // [esp+140h] [ebp-174h]
  const vostok::variant<32> **v16; // [esp+144h] [ebp-170h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v17; // [esp+264h] [ebp-50h]
  vostok::vfs::base_node<1> *mount_root; // [esp+2A8h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> parent_mount; // [esp+2ACh] [ebp-8h] BYREF
  bool is_lazy_mount; // [esp+2B3h] [ebp-1h]

  thisa = this;
  if ( this->m_args.unlock_after_mount )
    vostok::vfs::unlock_branch(thisa->m_args.root_write_lock, lock_type_write);
  if ( !reused_from_history && thisa->m_args.submount_node && result->result == result_error )
  {
    v3 = vostok::vfs::mount_of_node<1>(thisa->m_args.submount_node);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &parent_mount,
      v3);
    if ( vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator!=(
           (const stlp_std::reverse_iterator<unsigned int *> *)&parent_mount,
           (const stlp_std::reverse_iterator<unsigned int *> *)&thisa->m_mount_ptr) )
    {
      v4 = (const vostok::variant<32> *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&parent_mount);
      stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
        v5,
        (int)&thisa->m_mount_ptr)[12] = v4;
      v11[0].result = result_undefined;
      v11[0].mount.m_object = v6;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v11[0].mount,
        &thisa->m_mount_ptr);
      v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&parent_mount);
      vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy>::push_back(
        (vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy> *)(v8 + 7),
        v11[0].mount,
        (bool *)v11[0].result);
    }
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&parent_mount);
  }
  v9 = !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_args.callback)
     ? (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
     : 0;
  if ( v9 )
  {
    v17 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v11;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v11[0].mount,
      &result->mount);
    v17[1].m_object = (vostok::vfs::vfs_mount *)result->result;
    boost::function1<void,vostok::vfs::mount_result>::operator()(&thisa->m_args.callback, v11[0]);
  }
  v12 = thisa->m_args.type == mount_type_physical_path
     && thisa->m_args.submount_node
     && (submount_node = thisa->m_args.submount_node,
         (v9 = (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((submount_node->m_flags & 1) == 1)) != 0);
  is_lazy_mount = v12;
  if ( !v12
    && vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
         v9,
         result)
    && !reused_from_history )
  {
    v16 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(0, (int)result);
    node = (vostok::vfs::mount_root_node_base<1> *)v16[13];
    mount_root = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(node);
    v14 = (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_201C8 + (unsigned int)thisa->m_file_system);
    if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(v14)
        ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
        : 0) != 0 )
      boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
        (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)((char *)&loc_201C8
                                                                            + (unsigned int)thisa->m_file_system),
        (const vostok::ai::sensors::sensed_object *)mount_root);
  }
}
