void __cdecl vostok::fs_new::convert_to_relative_path<vostok::fs_new::virtual_path_string,vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *out_relative_path,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *absolute_path,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *root_to_relate)
{
  survarium::game_camera *v3; // ecx
  vostok::render::skeleton_model_instance *v4; // eax
  unsigned int v5; // [esp+4h] [ebp-174h]
  unsigned int v6; // [esp+8h] [ebp-170h]
  unsigned int v7; // [esp+Ch] [ebp-16Ch]
  unsigned int v8; // [esp+10h] [ebp-168h]
  unsigned int i; // [esp+18h] [ebp-160h]
  unsigned int v10; // [esp+1Ch] [ebp-15Ch]
  vostok::render::skeleton_model_instance *v11; // [esp+20h] [ebp-158h]
  int v12; // [esp+24h] [ebp-154h]
  vostok::render::skeleton_model_instance *v13; // [esp+30h] [ebp-148h]
  int v14; // [esp+34h] [ebp-144h]
  vostok::render::skeleton_model_instance *v15; // [esp+38h] [ebp-140h]
  int v16; // [esp+3Ch] [ebp-13Ch]
  char *s; // [esp+40h] [ebp-138h] BYREF
  char v18; // [esp+47h] [ebp-131h]
  unsigned int parts_in_root; // [esp+48h] [ebp-130h]
  unsigned int parts_in_common; // [esp+4Ch] [ebp-12Ch]
  vostok::fs_new::virtual_path_string common_path; // [esp+50h] [ebp-128h] BYREF
  unsigned int up_count; // [esp+168h] [ebp-10h]
  unsigned int skip; // [esp+16Ch] [ebp-Ch]
  char up[4]; // [esp+170h] [ebp-8h] BYREF
  unsigned int parts_in_absolute; // [esp+174h] [ebp-4h]

  v18 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)root_to_relate) )
  {
    v15 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(root_to_relate);
    v16 = 0;
    while ( LOBYTE(v15->__vftable) )
    {
      if ( LOBYTE(v15->__vftable) == 47 )
        ++v16;
      v15 = (vostok::render::skeleton_model_instance *)((char *)v15 + 1);
    }
    v8 = v16 + 1;
  }
  else
  {
    v8 = 0;
  }
  parts_in_root = v8;
  if ( vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)absolute_path) )
  {
    v13 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(absolute_path);
    v14 = 0;
    while ( LOBYTE(v13->__vftable) )
    {
      if ( LOBYTE(v13->__vftable) == 47 )
        ++v14;
      v13 = (vostok::render::skeleton_model_instance *)((char *)v13 + 1);
    }
    v7 = v14 + 1;
  }
  else
  {
    v7 = 0;
  }
  parts_in_absolute = v7;
  vostok::fs_new::virtual_path_string::virtual_path_string(&common_path);
  vostok::fs_new::common_prefix_path<vostok::fs_new::virtual_path_string>(
    &common_path,
    (const vostok::fs_new::virtual_path_string *)absolute_path,
    (const vostok::fs_new::virtual_path_string *)root_to_relate);
  if ( vostok::fs_new::path_string_impl::length(&common_path) )
  {
    v11 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&common_path);
    v12 = 0;
    while ( LOBYTE(v11->__vftable) )
    {
      if ( LOBYTE(v11->__vftable) == 47 )
        ++v12;
      v11 = (vostok::render::skeleton_model_instance *)((char *)v11 + 1);
    }
    v6 = v12 + 1;
  }
  else
  {
    v6 = 0;
  }
  parts_in_common = v6;
  if ( parts_in_absolute == v6 )
  {
    vostok::fs_new::path_string_impl::operator=<char const [1]>(out_relative_path, (const char (*)[1])&buf);
  }
  else
  {
    up_count = parts_in_root - parts_in_common;
    strcpy(up, "../");
    v10 = vostok::strings::length(up);
    for ( i = 0; i < up_count; ++i )
      vostok::buffer_string::append(&out_relative_path->m_string, up, &up[v10]);
    if ( vostok::fs_new::path_string_impl::length(&common_path) )
      v5 = vostok::fs_new::path_string_impl::length(&common_path) + 1;
    else
      v5 = 0;
    skip = v5;
    v4 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(absolute_path);
    s = (char *)v4 + skip;
    vostok::fs_new::path_string_impl::append_with_conversion<char const *>(out_relative_path, (const char **)&s);
  }
}
