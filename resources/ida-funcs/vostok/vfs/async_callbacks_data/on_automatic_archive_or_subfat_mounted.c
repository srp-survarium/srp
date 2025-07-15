void __thiscall vostok::vfs::async_callbacks_data::on_automatic_archive_or_subfat_mounted(
        vostok::vfs::async_callbacks_data *this,
        vostok::vfs::mount_result mount,
        unsigned int increment)
{
  const vostok::variant<32> **v4; // [esp+Ch] [ebp-Ch]
  vostok::vfs::base_node<1> *mount_root; // [esp+14h] [ebp-4h]

  if ( mount.result == result_error )
  {
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
           (int)&mount);
    mount_root = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>((vostok::vfs::mount_root_node_base<1> *)v4[13]);
    vostok::vfs::change_subfat_ref_for_node(increment, mount_root, &this->env.mount_operation_id);
  }
  vostok::vfs::async_callbacks_data::on_callback_may_destroy_this(this, mount.result);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&mount.mount);
}
