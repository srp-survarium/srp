void __thiscall vostok::vfs::unmounter::recursive_traverse_folder<vostok::vfs::is_exact_node>(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        const vostok::vfs::is_exact_node *predicate,
        vostok::vfs::base_folder_node<1> *parent_to_traverse)
{
  const char *v5; // eax
  survarium::game_camera *v6; // ecx
  vostok::platform_pointer_selector<vostok::vfs::base_folder_node<1>,1>::helper *v7; // eax
  vostok::vfs::base_node<1> *v8; // ecx
  int v9; // [esp-Ch] [ebp-360h] BYREF
  unsigned int v10; // [esp-8h] [ebp-35Ch]
  unsigned int v11; // [esp-4h] [ebp-358h]
  vostok::vfs::unmounter *thisa; // [esp+0h] [ebp-354h]
  unsigned __int64 v13; // [esp+4h] [ebp-350h]
  int *v14; // [esp+34h] [ebp-320h]
  int *v15; // [esp+64h] [ebp-2F0h]
  vostok::vfs::base_folder_node<1> *v16; // [esp+68h] [ebp-2ECh] BYREF
  int v17; // [esp+6Ch] [ebp-2E8h]
  vostok::platform_pointer_selector<vostok::vfs::base_folder_node<1>,1>::helper *p_m_parent; // [esp+70h] [ebp-2E4h]
  vostok::vfs::base_folder_node<1> **v19; // [esp+74h] [ebp-2E0h]
  vostok::vfs::base_folder_node<1> *v20; // [esp+78h] [ebp-2DCh]
  vostok::vfs::base_node<1> *v21; // [esp+7Ch] [ebp-2D8h]
  vostok::vfs::base_node<1> *v22; // [esp+80h] [ebp-2D4h]
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *p_m_next_overlapped; // [esp+84h] [ebp-2D0h]
  vostok::vfs::base_node<1> *v24; // [esp+88h] [ebp-2CCh]
  vostok::vfs::base_node<1> *pointer; // [esp+1E0h] [ebp-174h]
  unsigned __int64 max_storage; // [esp+1E4h] [ebp-170h]
  char v27; // [esp+1FBh] [ebp-159h]
  char *s; // [esp+1FCh] [ebp-158h] BYREF
  char *src; // [esp+200h] [ebp-154h] BYREF
  vostok::fs_new::path_string_impl v30; // [esp+204h] [ebp-150h] BYREF
  vostok::vfs::base_folder_node<1> *old_parent; // [esp+318h] [ebp-3Ch]
  vostok::vfs::base_node<1> *overlapped_child; // [esp+31Ch] [ebp-38h]
  vostok::vfs::base_node<1> *overlap_of_child_to_unmount; // [esp+320h] [ebp-34h] BYREF
  vostok::vfs::base_node<1> *child_to_unmount; // [esp+324h] [ebp-30h] BYREF
  vostok::vfs::base_node<1> *next_child; // [esp+328h] [ebp-2Ch]
  unsigned int child_hash; // [esp+32Ch] [ebp-28h]
  vostok::fs_new::virtual_path_string *child_path; // [esp+330h] [ebp-24h]
  vostok::vfs::base_node<1> *child; // [esp+334h] [ebp-20h]
  unsigned int saved_path_length; // [esp+338h] [ebp-1Ch]
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> new_children; // [esp+33Ch] [ebp-18h] BYREF

  thisa = this;
  saved_path_length = vostok::fs_new::path_string_impl::length(path);
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(&new_children);
  for ( child = parent_to_traverse->m_first_child.pointer; child; child = next_child )
  {
    pointer = child->m_next.pointer;
    next_child = pointer;
    src = child->m_name;
    vostok::fs_new::path_string_impl::path_string_impl(&v30, 47, (const char **)&src);
    v11 = hash;
    v10 = vostok::fs_new::path_string_impl::length(&v30);
    v5 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v30);
    child_hash = vostok::fs_new::path_crc32(v5, v10, v11);
    child_path = path;
    s = child->m_name;
    vostok::fs_new::path_string_impl::append_path<char const *>(path, &s);
    if ( child == predicate->helper_node )
    {
      child_to_unmount = 0;
      overlap_of_child_to_unmount = 0;
      vostok::vfs::unmounter::recursive_unmount_node<vostok::vfs::is_exact_node const>(
        thisa,
        child_path,
        child_hash,
        predicate,
        &child_to_unmount,
        &overlap_of_child_to_unmount);
      v27 = 0;
      survarium::weapon_user_dead_state::finalize(v6);
      if ( overlap_of_child_to_unmount )
      {
        v24 = child_to_unmount->m_next_overlapped.pointer;
        v22 = overlap_of_child_to_unmount;
        p_m_next_overlapped = &overlap_of_child_to_unmount->m_next_overlapped;
        overlap_of_child_to_unmount->m_next_overlapped.pointer = v24;
      }
      v21 = child_to_unmount->m_next_overlapped.pointer;
      overlapped_child = v21;
      if ( v21 )
      {
        v20 = overlapped_child->m_parent.pointer;
        old_parent = v20;
        vostok::vfs::base_folder_node<1>::unlink_child(v20, overlapped_child, 1);
        v19 = &v16;
        v17 = 0;
        v16 = parent_to_traverse;
        p_m_parent = &overlapped_child->m_parent;
        v7 = &overlapped_child->m_parent;
        overlapped_child->m_parent.pointer = parent_to_traverse;
        HIDWORD(v7->max_storage) = v17;
        v15 = &v9;
        vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
          &new_children,
          (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)overlapped_child,
          0);
      }
      if ( thisa->m_args->submount_type == submount_type_hot_unmount )
        vostok::vfs::unmounter::hot_unmount_node(thisa, child_to_unmount, child_hash);
      else
        vostok::vfs::free_node(
          thisa->m_file_system,
          child_to_unmount,
          &thisa->m_args->root_write_lock,
          child_hash,
          thisa->m_args->allocator);
    }
    else
    {
      v14 = &v9;
      vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        &new_children,
        (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)child,
        0);
    }
    vostok::fs_new::path_string_impl::set_length(path, saved_path_length);
  }
  max_storage = new_children.m_first.max_storage;
  v13 = new_children.m_first.max_storage;
  v8 = new_children.m_first.pointer;
  parent_to_traverse->m_first_child.pointer = new_children.m_first.pointer;
  HIDWORD(parent_to_traverse->m_first_child.max_storage) = HIDWORD(v13);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v8);
}
