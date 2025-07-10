void __cdecl vostok::vfs::free_node_impl(
        vostok::vfs::virtual_file_system *file_system,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_node<1> **root_write_lock,
        unsigned int hash,
        vostok::memory::base_allocator *allocator,
        vostok::vfs::erase_from_hashset_enum erase_from_hashset)
{
  survarium::game_camera *v6; // ecx
  vostok::fixed_string<512> *v7; // ecx
  const char *v8; // eax
  survarium::game_camera *v9; // ecx
  vostok::memory::base_allocator *v10; // eax
  survarium::game_camera *v11; // ecx
  vostok::memory::base_allocator *v12; // eax
  survarium::game_camera *v13; // ecx
  vostok::memory::base_allocator *v14; // eax
  int v15; // edx
  vostok::memory::base_allocator *v16; // eax
  vostok::vfs::base_node<1> *v17; // eax
  vostok::memory::base_allocator *v18; // eax
  survarium::game_camera *v19; // ecx
  vostok::memory::base_allocator *v20; // eax
  vostok::memory::base_allocator *v21; // eax
  vostok::memory::base_allocator *v22; // eax
  int v23; // edx
  vostok::memory::base_allocator *v24; // eax
  survarium::game_camera *v25; // ecx
  vostok::memory::base_allocator *v26; // eax
  const char *v27; // [esp+0h] [ebp-464h]
  bool v28; // [esp+7h] [ebp-45Dh]
  vostok::vfs::mount_root_node_base<1> *v29; // [esp+8h] [ebp-45Ch]
  _DWORD v30[6]; // [esp+3Ch] [ebp-428h] BYREF
  vostok::memory::base_allocator *v31; // [esp+54h] [ebp-410h]
  void *v32; // [esp+58h] [ebp-40Ch]
  void *p; // [esp+5Ch] [ebp-408h]
  vostok::vfs::physical_folder_node<1> *v34; // [esp+60h] [ebp-404h]
  survarium::game_camera *m_data; // [esp+64h] [ebp-400h]
  vostok::vfs::base_node<1> *v36; // [esp+68h] [ebp-3FCh]
  vostok::vfs::mount_root_node_base<1> *v37; // [esp+6Ch] [ebp-3F8h] BYREF
  int v38; // [esp+70h] [ebp-3F4h]
  vostok::vfs::mount_root_node_base<1> **v39; // [esp+74h] [ebp-3F0h]
  vostok::memory::base_allocator *v40; // [esp+78h] [ebp-3ECh]
  void *v41; // [esp+7Ch] [ebp-3E8h]
  vostok::vfs::physical_file_node<1> *v42; // [esp+80h] [ebp-3E4h]
  vostok::flags_type<enum vostok::vfs::physical_file_node<1>::flags_enum,vostok::threading::multi_threading_policy> *p_m_file_flags; // [esp+84h] [ebp-3E0h]
  _DWORD v44[4]; // [esp+88h] [ebp-3DCh] BYREF
  vostok::memory::base_allocator *v45; // [esp+98h] [ebp-3CCh]
  void *v46; // [esp+9Ch] [ebp-3C8h]
  vostok::memory::base_allocator *v47; // [esp+A0h] [ebp-3C4h]
  void *v48; // [esp+A4h] [ebp-3C0h]
  vostok::memory::base_allocator *v49; // [esp+A8h] [ebp-3BCh]
  void *pointer; // [esp+ACh] [ebp-3B8h]
  vostok::vfs::base_node<1> *v51; // [esp+B0h] [ebp-3B4h]
  vostok::vfs::base_node<1> *v53; // [esp+B8h] [ebp-3ACh]
  char v54; // [esp+1E6h] [ebp-27Eh]
  char v55; // [esp+1E7h] [ebp-27Dh]
  char v56; // [esp+1EFh] [ebp-275h]
  vostok::vfs::vfs_reader_writer_lock *v57; // [esp+1F0h] [ebp-274h]
  vostok::vfs::vfs_reader_writer_lock *v58; // [esp+1F4h] [ebp-270h]
  const char *buffer; // [esp+1F8h] [ebp-26Ch]
  vostok::vfs::erased_node<1> *v60; // [esp+200h] [ebp-264h]
  vostok::vfs::soft_link_node<1> *soft_link; // [esp+204h] [ebp-260h]
  vostok::vfs::hard_link_node<1> *hard_link; // [esp+208h] [ebp-25Ch]
  vostok::vfs::vfs_reader_writer_lock *v63; // [esp+20Ch] [ebp-258h]
  void *children_arena; // [esp+210h] [ebp-254h] BYREF
  vostok::vfs::physical_folder_node<1> *folder; // [esp+214h] [ebp-250h]
  vostok::vfs::physical_file_node<1> *file; // [esp+218h] [ebp-24Ch]
  vostok::vfs::physical_file_mount_root_node<1> *mount_root; // [esp+21Ch] [ebp-248h]
  vostok::vfs::erased_node<1> *erase_node; // [esp+220h] [ebp-244h]
  vostok::vfs::universal_file_node<1> *uni_node; // [esp+224h] [ebp-240h]
  vostok::vfs::base_node<1> *overlapped; // [esp+228h] [ebp-23Ch]
  vostok::vfs::base_node<1> *next; // [esp+22Ch] [ebp-238h]
  vostok::vfs::base_node<1> *it_erased_node; // [esp+230h] [ebp-234h]
  vostok::vfs::vfs_iterator iterator; // [esp+234h] [ebp-230h] BYREF
  vostok::fixed_string<512> addr; // [esp+244h] [ebp-220h] BYREF
  bool node_is_erased_mount_root; // [esp+45Bh] [ebp-9h]
  vostok::vfs::mount_root_node_base<1> *mount_root_base; // [esp+45Ch] [ebp-8h]
  bool node_is_root_lock; // [esp+463h] [ebp-1h]

  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&byte_20168[(_DWORD)file_system])
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
  {
    vostok::vfs::vfs_iterator::vfs_iterator(&iterator, node, 0, &file_system->hashset, type_non_recursive);
    boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
      (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&byte_20168[(_DWORD)file_system],
      (const vostok::ai::sensors::sensed_object *)&iterator);
  }
  v56 = 0;
  survarium::weapon_user_dead_state::finalize(v6);
  vostok::fixed_string<512>::fixed_string<512>(v7, (int)&addr);
  vostok::buffer_string::assignf(&addr, "'%s' [0x%08x]", node->m_name, node);
  if ( (node->m_flags & 1) == 1 )
  {
    v8 = (const char *)vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
    vostok::buffer_string::appendf(&addr, (vostok::buffer_string *)&stru_956624, v8);
  }
  else
  {
    vostok::buffer_string::appendf(&addr, (vostok::buffer_string *)&stru_956634, v27);
  }
  if ( (node->m_flags & 8) == 8 )
  {
    vostok::buffer_string::append(&addr, (char *)&stru_956634.m_max_end);
  }
  else if ( (node->m_flags & 0x400) == 0x400 )
  {
    vostok::buffer_string::append(&addr, " mount-helper");
  }
  if ( (node->m_flags & 0x300) != 0 )
    v29 = 0;
  else
    v29 = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node);
  mount_root_base = v29;
  if ( v29 )
  {
    for ( it_erased_node = mount_root_base->first_erased.pointer; it_erased_node; it_erased_node = v53 )
    {
      v53 = it_erased_node->m_next.pointer;
      next = v53;
      vostok::vfs::free_node_impl(file_system, it_erased_node, root_write_lock, 0, allocator, erase_from_hashset_false);
    }
  }
  node_is_root_lock = node == *root_write_lock;
  if ( node_is_root_lock )
  {
    if ( node->m_next_overlapped.pointer )
    {
      v51 = node->m_next_overlapped.pointer;
      overlapped = v51;
      vostok::vfs::lock_node(v51, lock_type_write, lock_operation_lock);
      *root_write_lock = v51;
    }
    else
    {
      *root_write_lock = 0;
    }
  }
  v28 = mount_root_base && mount_root_base->erased;
  node_is_erased_mount_root = v28;
  if ( erase_from_hashset == erase_from_hashset_true && !node_is_erased_mount_root )
    vostok::vfs::vfs_hashset::erase(&file_system->hashset, hash, node);
  if ( node_is_root_lock )
    vostok::vfs::unlock_node(node, lock_type_write);
  if ( (node->m_flags & 0x2000) == 0x2000 )
  {
    uni_node = vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node);
    survarium::weapon_user_dead_state::finalize(v9);
    v49 = v10;
    if ( uni_node )
    {
      pointer = uni_node;
      vostok::memory::base_allocator::free_impl(v49, uni_node);
      uni_node = 0;
    }
  }
  else if ( (node->m_flags & 2) == 2 )
  {
    if ( (node->m_flags & 0x800) == 0x800 )
    {
      erase_node = vostok::vfs::node_cast<vostok::vfs::erased_node,vostok::vfs::base_node,1>(node);
      survarium::weapon_user_dead_state::finalize(v11);
      v47 = v12;
      if ( erase_node )
      {
        v48 = erase_node;
        vostok::memory::base_allocator::free_impl(v47, erase_node);
        erase_node = 0;
      }
    }
    else if ( (node->m_flags & 1) == 1 )
    {
      folder = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node);
      v39 = &v37;
      v38 = 0;
      v37 = 0;
      v17 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>((vostok::vfs::base_folder_node<1> *)folder);
      v36 = v17;
      v17->m_mount_root.pointer = v37;
      HIDWORD(v17->m_mount_helper_parent.max_storage) = v38;
      m_data = (survarium::game_camera *)folder->children_arena.m_data;
      children_arena = m_data;
      survarium::weapon_user_dead_state::finalize(m_data);
      vostok::memory::free_helper<vostok::memory::base_allocator,char>(v18, (char **)&children_arena);
      v34 = folder;
      folder->children_arena.m_data = 0;
      v34->children_arena.m_size = 0;
      if ( (node->m_flags & 8) == 8 )
      {
        v63 = (vostok::vfs::vfs_reader_writer_lock *)vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(node);
        p = v63;
        vostok::vfs::vfs_reader_writer_lock::~vfs_reader_writer_lock(v63 + 32);
        survarium::weapon_user_dead_state::finalize(v19);
        v31 = v20;
        if ( v63 )
        {
          v32 = v63;
          vostok::memory::base_allocator::free_impl(v31, v63);
          v63 = 0;
        }
      }
      else
      {
        v30[4] = v30;
        v30[0] = 4;
        v30[1] = 4;
        v30[2] = &folder->m_folder_flags;
        v30[3] = 4;
        if ( (folder->m_folder_flags.m_flags & 4) != 4 )
        {
          vostok::vfs::vfs_reader_writer_lock::~vfs_reader_writer_lock(&folder->folder.m_readers_writers_counters);
          survarium::weapon_user_dead_state::finalize(0);
          if ( folder )
          {
            vostok::memory::base_allocator::free_impl(v21, folder);
            folder = 0;
          }
        }
      }
    }
    else if ( (node->m_flags & 8) == 8 )
    {
      mount_root = (vostok::vfs::physical_file_mount_root_node<1> *)vostok::vfs::cast_physical_file_mount_root<1>(node);
      survarium::weapon_user_dead_state::finalize(v13);
      v45 = v14;
      if ( mount_root )
      {
        v46 = mount_root;
        vostok::memory::base_allocator::free_impl(v45, mount_root);
        mount_root = 0;
      }
    }
    else
    {
      file = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node);
      v42 = file;
      v44[2] = v44;
      v44[0] = 8;
      p_m_file_flags = &file->m_file_flags;
      v44[1] = 8;
      v15 = file->m_file_flags.m_flags & 8;
      if ( v15 != 8 )
      {
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(v15 == 8));
        v40 = v16;
        if ( file )
        {
          v41 = file;
          vostok::memory::base_allocator::free_impl(v40, file);
          file = 0;
        }
      }
    }
  }
  else if ( (node->m_flags & 4) == 4 )
  {
    if ( (node->m_flags & 0x200) == 0x200 )
    {
      hard_link = vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(node);
    }
    else if ( (node->m_flags & 0x100) == 0x100 )
    {
      soft_link = (vostok::vfs::soft_link_node<1> *)vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(node);
    }
    else if ( (node->m_flags & 0x800) == 0x800 )
    {
      v60 = vostok::vfs::node_cast<vostok::vfs::erased_node,vostok::vfs::base_node,1>(node);
    }
    else if ( (node->m_flags & 8) == 8 )
    {
      v55 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)8);
      buffer = *(const char **)&vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(node)->m_name[869];
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)buffer);
      if ( buffer )
      {
        vostok::memory::base_allocator::free_impl(v22, (void *)buffer);
        buffer = 0;
      }
    }
  }
  else
  {
    v23 = node->m_flags & 0x400;
    if ( v23 == 1024 )
    {
      v58 = (vostok::vfs::vfs_reader_writer_lock *)vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(node);
      vostok::vfs::vfs_reader_writer_lock::~vfs_reader_writer_lock(v58 + 4);
      survarium::weapon_user_dead_state::finalize(0);
      if ( v58 )
      {
        vostok::memory::base_allocator::free_impl(v24, v58);
        v58 = 0;
      }
    }
    else
    {
      v54 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(v23 == 1024));
      v57 = (vostok::vfs::vfs_reader_writer_lock *)vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
      vostok::vfs::vfs_reader_writer_lock::~vfs_reader_writer_lock(v57 + 2);
      survarium::weapon_user_dead_state::finalize(v25);
      if ( v57 )
        vostok::memory::base_allocator::free_impl(v26, v57);
    }
  }
}
