void __thiscall vostok::vfs::transfer_children::transfer_child(
        vostok::vfs::transfer_children *this,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *const child)
{
  survarium::game_camera *v4; // ecx
  unsigned int v5; // eax
  vostok::vfs::base_node<1> *v6; // eax
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  int v9; // [esp-Ch] [ebp-1C0h] BYREF
  vostok::vfs::transfer_children *thisa; // [esp+0h] [ebp-1B4h]
  int *v11; // [esp+3Ch] [ebp-178h]
  vostok::vfs::base_node<1> *pointer; // [esp+40h] [ebp-174h]
  vostok::vfs::base_node<1> *v13; // [esp+44h] [ebp-170h]
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *p_m_next_overlapped; // [esp+48h] [ebp-16Ch]
  vostok::vfs::transfer_children v15; // [esp+4Ch] [ebp-168h] BYREF
  char v16; // [esp+197h] [ebp-1Dh]
  vostok::vfs::base_folder_node<1> *parent_to_link_folder; // [esp+198h] [ebp-1Ch]
  vostok::vfs::base_node<1> *it_parent; // [esp+19Ch] [ebp-18h]
  vostok::vfs::base_folder_node<1> *dest_folder; // [esp+1A0h] [ebp-14h]
  vostok::vfs::base_node<1> *first_overlapper; // [esp+1A4h] [ebp-10h] BYREF
  unsigned int last_overlapper_mount_id; // [esp+1A8h] [ebp-Ch]
  vostok::vfs::base_node<1> *last_overlapper; // [esp+1ACh] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *parent_to_link; // [esp+1B0h] [ebp-4h]

  thisa = this;
  first_overlapper = 0;
  last_overlapper = 0;
  vostok::vfs::transfer_children::find_first_and_last_overlapper(
    this,
    &first_overlapper,
    &last_overlapper,
    path,
    hash,
    child);
  if ( last_overlapper )
  {
    v16 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    v13 = last_overlapper;
    p_m_next_overlapped = &last_overlapper->m_next_overlapped;
    last_overlapper->m_next_overlapped.pointer = child;
    last_overlapper_mount_id = vostok::vfs::mount_id_of_node<1>(last_overlapper);
    parent_to_link = 0;
    for ( it_parent = thisa->m_dest_start; it_parent; it_parent = pointer )
    {
      v5 = vostok::vfs::mount_id_of_node<1>(it_parent);
      if ( v5 < last_overlapper_mount_id )
      {
        parent_to_link = it_parent;
        break;
      }
      pointer = it_parent->m_next_overlapped.pointer;
    }
    if ( (parent_to_link->m_flags & 1) == 1
      && (v6 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(thisa->m_source_folder),
          parent_to_link != v6) )
    {
      parent_to_link_folder = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(parent_to_link);
      vostok::vfs::base_folder_node<1>::prepend_child(parent_to_link_folder, child);
    }
    else
    {
      v11 = &v9;
      vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        &thisa->m_new_source_nodes,
        (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)child,
        0);
    }
    if ( (child->m_flags & 1) == 1 )
    {
      if ( first_overlapper )
      {
        vostok::vfs::transfer_children::transfer_children(
          &v15,
          thisa->m_hashset,
          (const vostok::fs_new::virtual_path_string *)path,
          hash,
          first_overlapper,
          child);
        survarium::weapon_user_dead_state::finalize(v7);
        survarium::weapon_user_dead_state::finalize(v8);
      }
    }
  }
  else
  {
    dest_folder = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(thisa->m_dest_start);
    vostok::vfs::base_folder_node<1>::prepend_child(dest_folder, child);
  }
}
