void __userpurge vostok::render::decal_instance::decal_instance(
        vostok::render::decal_instance *this@<ecx>,
        int a2@<esi>,
        vostok::collision::space_partitioning_tree *tree,
        const vostok::render::decal_properties *properties,
        unsigned int id)
{
  const vostok::math::float4x4 *v5; // xmm0_4
  const vostok::math::float4x4 *v6; // edx
  int v7; // eax
  __int64 v8; // [esp+4h] [ebp-124h]
  char *other; // [esp+10h] [ebp-118h] BYREF
  vostok::fs_new::virtual_path_string in_material_name; // [esp+14h] [ebp-114h] BYREF

  *(_DWORD *)a2 = 0;
  vostok::render::decal_properties::decal_properties(
    (vostok::render::decal_properties *)this,
    (vostok::render::decal_properties *)(a2 + 4));
  *(_QWORD *)(a2 + 104) = 0xBF800000BF800000uLL;
  v5 = clear_value;
  v6 = clear_value;
  *(_DWORD *)(a2 + 112) = -1082130432;
  LODWORD(v8) = v5;
  HIDWORD(v8) = v5;
  *(_QWORD *)(a2 + 116) = v8;
  *(_DWORD *)(a2 + 124) = v6;
  *(_DWORD *)(a2 + 128) = id;
  *(_DWORD *)(a2 + 132) = tree;
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = -1;
  *(_DWORD *)(a2 + 148) = 0;
  *(_BYTE *)(a2 + 152) = 0;
  vostok::render::decal_instance::set_properties(
    (vostok::render::decal_instance *)tree,
    (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2,
    properties);
  v7 = *(_DWORD *)(a2 + 68);
  if ( v7 )
  {
    other = *(char **)(v7 + 1176);
    vostok::fs_new::virtual_path_string::virtual_path_string(&in_material_name, (const char **)&other);
    vostok::render::material_manager::add_material_effects(
      (vostok::render::material_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y,
      (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)(a2 + 68),
      &in_material_name);
  }
}
