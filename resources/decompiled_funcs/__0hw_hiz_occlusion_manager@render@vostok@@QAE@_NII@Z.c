void __userpurge vostok::render::hw_hiz_occlusion_manager::hw_hiz_occlusion_manager(
        vostok::render::hw_hiz_occlusion_manager *this@<ecx>,
        int a2@<esi>,
        unsigned int use_scene_depth_buffer,
        unsigned int rasterize_width,
        const unsigned int rasterize_height)
{
  unsigned int v5; // ebx
  vostok::render::hw_hiz_point_list *v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // edi
  unsigned int v9; // ebx
  vostok::render::render_target *render_target; // eax
  vostok::render::resource_manager *v11; // ecx
  vostok::strings::shared::profile *m_object; // edi
  const char *m_reference_count; // eax
  int v14; // eax
  const vostok::render::res_texture *v15; // ebx
  const vostok::render::res_texture *v16; // eax
  volatile int v17; // ecx
  unsigned int v18; // eax
  survarium::options_tab *v19; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v20; // eax
  survarium::options_tab *v21; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v22; // eax
  vostok::render::res_texture *texture2d; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v24; // ecx
  unsigned int v25; // eax
  survarium::options_tab *v26; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v27; // eax
  vostok::render::res_texture *v28; // eax
  vostok::render::res_texture *v29; // ecx
  unsigned int v30; // eax
  survarium::options_tab *v31; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v32; // eax
  void *(__thiscall *v33)(void *); // edi
  unsigned int v34; // ebx
  int v35; // eax
  vostok::render::render_target *v36; // eax
  vostok::render::resource_manager *v37; // ecx
  vostok::strings::shared::profile *v38; // ebx
  const char *v39; // eax
  vostok::render::render_target *v40; // eax
  vostok::render::resource_manager *v41; // ecx
  const char *v42; // eax
  vostok::strings::shared::profile *v44; // eax
  vostok::render::backend *v45; // ecx
  void *(__thiscall *v46)(void *); // edi
  vostok::strings::shared::profile *v47; // eax
  vostok::render::backend *v48; // ecx
  void *(__thiscall *v49)(void *); // edi
  vostok::strings::shared::profile *v50; // eax
  vostok::render::backend *v51; // ecx
  void *(__thiscall *v52)(void *); // edi
  vostok::strings::shared::profile *v53; // eax
  vostok::render::backend *v54; // ecx
  void *(__thiscall *v55)(void *); // edi
  vostok::strings::shared::profile *v56; // eax
  vostok::render::backend *v57; // ecx
  void *(__thiscall *v58)(void *); // edi
  const vostok::render::res_texture *v59; // [esp-8h] [ebp-C0h]
  void *(__thiscall *v60)(void *); // [esp-4h] [ebp-BCh] BYREF
  vostok::render::resource_manager *v61; // [esp+0h] [ebp-B8h]
  unsigned int v62; // [esp+4h] [ebp-B4h]
  vostok::shared_string name; // [esp+Ch] [ebp-ACh] BYREF
  unsigned int current_rasterize_height; // [esp+10h] [ebp-A8h]
  unsigned int mip_index; // [esp+14h] [ebp-A4h]
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > v66; // [esp+18h] [ebp-A0h] BYREF
  char *v67; // [esp+30h] [ebp-88h]
  _BYTE v68[128]; // [esp+34h] [ebp-84h] BYREF
  char v69; // [esp+B4h] [ebp-4h] BYREF

  v60 = (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>;
  *(_BYTE *)a2 = 1;
  *(_DWORD *)(a2 + 4) = 0;
  `vector constructor iterator'((char *)(a2 + 8), 4u, 16, v60);
  `vector constructor iterator'(
    (char *)(a2 + 72),
    4u,
    16,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)(a2 + 136),
    4u,
    16,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  v5 = use_scene_depth_buffer;
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 204) = 0;
  *(_DWORD *)(a2 + 208) = 0;
  *(_DWORD *)(a2 + 212) = 0;
  *(_DWORD *)(a2 + 216) = use_scene_depth_buffer;
  *(_DWORD *)(a2 + 220) = rasterize_width;
  v60 = (void *(__thiscall *)(void *))(a2 + 228);
  name.m_pointer.m_object = (vostok::strings::shared::profile *)((unsigned __int16)mip_index | 0xC00);
  *(_QWORD *)&v66._M_header._M_data._M_color = (__int64)(__FYL2X__(
                                                           (double)(rasterize_width
                                                                  + (use_scene_depth_buffer < rasterize_width
                                                                   ? use_scene_depth_buffer - rasterize_width
                                                                   : 0)),
                                                           0.6931471805599453094)
                                                       / __FYL2X__(2.0, 0.6931471805599453094));
  *(_DWORD *)(a2 + 224) = *(_DWORD *)&v66._M_header._M_data._M_color + 1;
  vostok::render::sphere_occluder_geometry::sphere_occluder_geometry((vostok::render::sphere_occluder_geometry *)(a2 + 228));
  *(_DWORD *)(a2 + 252) = 0;
  *(_DWORD *)(a2 + 256) = 0;
  *(_DWORD *)(a2 + 260) = 0;
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  vostok::render::hw_hiz_point_list::hw_hiz_point_list(v6);
  v7 = 0;
  mip_index = 0;
  if ( *(_DWORD *)(a2 + 224) )
  {
    name.m_pointer.m_object = (vostok::strings::shared::profile *)(a2 + 8);
    while ( 1 )
    {
      *(_DWORD *)&v66._M_key_compare.stlp_std::binary_function<char *,char *,bool> = v68;
      v66._M_node_count = (unsigned int)v68;
      v8 = v5 >> v7;
      v9 = rasterize_width >> v7;
      v67 = &v69;
      v68[0] = 0;
      vostok::buffer_string::assignf(
        (vostok::buffer_string *)&v66._M_node_count,
        "%s_work_%d",
        "$user$hiz_occlusion_depth_mips",
        v7);
      render_target = vostok::render::resource_manager::create_render_target(
                        (vostok::render::resource_manager *)v66._M_node_count,
                        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                        (const char *)v66._M_node_count,
                        (vostok::render::res_texture *)v8,
                        (ID3D11Texture2D **)v9,
                        (const char *)0x29,
                        enum_rt_usage_render_target,
                        0,
                        0,
                        (unsigned int)v61,
                        v62);
      v11 = 0;
      if ( render_target )
      {
        ++render_target->m_reference_count;
        v11 = (vostok::render::resource_manager *)render_target;
      }
      m_object = name.m_pointer.m_object;
      m_reference_count = (const char *)name.m_pointer.m_object->m_reference_count;
      name.m_pointer.m_object->m_reference_count = (volatile int)v11;
      if ( m_reference_count )
      {
        if ( !--*(_DWORD *)m_reference_count )
          vostok::render::resource_manager::release(
            v11,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            m_reference_count);
      }
      v14 = *(_DWORD *)(m_object->m_reference_count + 24);
      v15 = 0;
      if ( v14 )
      {
        v15 = *(const vostok::render::res_texture **)(m_object->m_reference_count + 24);
        ++*(_DWORD *)(v14 + 4);
      }
      v16 = 0;
      if ( v15 )
      {
        ++v15->m_reference_count;
        v16 = v15;
      }
      v17 = (volatile int)v16;
      current_rasterize_height = m_object[4].m_reference_count;
      v18 = current_rasterize_height;
      m_object[4].m_reference_count = v17;
      if ( v18 )
      {
        if ( !--*(_DWORD *)(v18 + 4) )
        {
          if ( *(_BYTE *)(v18 + 439) )
          {
            v19 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
            v66._M_header._M_data._M_right = *(stlp_std::priv::_Rb_tree_node_base **)(v18 + 144);
            v20 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                    (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v66._M_header._M_data._M_right,
                    (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                    (const char **)&v66._M_header._M_data._M_right);
            if ( v20 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v19 )
            {
              stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
                (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v60,
                (int)v19,
                (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v20);
              vostok::render::resource_manager::release_impl(
                (const vostok::render::res_texture *)current_rasterize_height,
                v61);
            }
          }
        }
      }
      if ( v15 )
      {
        if ( !--v15->m_reference_count && v15->m_is_registered )
        {
          v21 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          *(_DWORD *)&v66._M_header._M_data._M_color = v15->m_name.m_string.m_begin;
          v22 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                  &v66,
                  (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                  (const char **)&v66);
          if ( v22 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v21 )
          {
            stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
              (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v60,
              (int)v21,
              (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v22);
            vostok::render::resource_manager::release_impl(v15, v61);
          }
        }
      }
      name.m_pointer.m_object = (vostok::strings::shared::profile *)((char *)name.m_pointer.m_object + 4);
      v5 = use_scene_depth_buffer;
      if ( ++mip_index >= *(_DWORD *)(a2 + 224) )
        break;
      v7 = mip_index;
    }
  }
  texture2d = vostok::render::resource_manager::create_texture2d(
                D3D11_USAGE_DEFAULT,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                "$user$hiz_occlusion_depth_mips",
                (vostok::render::resource_manager *)v5,
                rasterize_width,
                (ID3D11Texture2D *)0x29,
                *(const D3D11_SUBRESOURCE_DATA **)(a2 + 224),
                DXGI_FORMAT_R32G32B32A32_TYPELESS,
                (unsigned int)v61,
                v62);
  v24 = 0;
  if ( texture2d )
  {
    ++texture2d->m_reference_count;
    v24 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)texture2d;
  }
  current_rasterize_height = *(_DWORD *)(a2 + 204);
  v25 = current_rasterize_height;
  *(_DWORD *)(a2 + 204) = v24;
  if ( v25 )
  {
    if ( !--*(_DWORD *)(v25 + 4) )
    {
      if ( *(_BYTE *)(v25 + 439) )
      {
        v26 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
        *(_DWORD *)&v66._M_header._M_data._M_color = *(_DWORD *)(v25 + 144);
        v27 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                v24,
                (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                (const char **)&v66);
        if ( v27 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v26 )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v60,
            (int)v26,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v27);
          vostok::render::resource_manager::release_impl(
            (const vostok::render::res_texture *)current_rasterize_height,
            v61);
        }
      }
    }
  }
  v28 = vostok::render::resource_manager::create_texture2d(
          D3D11_USAGE_STAGING,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          "$user$hiz_occlusion_depth_mips_lockable",
          (vostok::render::resource_manager *)v5,
          rasterize_width,
          (ID3D11Texture2D *)0x29,
          (const D3D11_SUBRESOURCE_DATA *)1,
          DXGI_FORMAT_UNKNOWN,
          (unsigned int)v61,
          v62);
  v29 = 0;
  if ( v28 )
  {
    ++v28->m_reference_count;
    v29 = v28;
  }
  current_rasterize_height = *(_DWORD *)(a2 + 212);
  v30 = current_rasterize_height;
  *(_DWORD *)(a2 + 212) = v29;
  if ( v30 )
  {
    if ( !--*(_DWORD *)(v30 + 4) )
    {
      if ( *(_BYTE *)(v30 + 439) )
      {
        v31 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
        *(_DWORD *)&v66._M_header._M_data._M_color = *(_DWORD *)(v30 + 144);
        v32 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                &v66,
                (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                (const char **)&v66);
        if ( v32 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v31 )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v60,
            (int)v31,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v32);
          vostok::render::resource_manager::release_impl(
            (const vostok::render::res_texture *)current_rasterize_height,
            v61);
        }
      }
    }
  }
  v33 = 0;
  if ( *(_DWORD *)(a2 + 224) )
  {
    name.m_pointer.m_object = (vostok::strings::shared::profile *)(a2 + 136);
    do
    {
      current_rasterize_height = rasterize_width >> (char)v33;
      v66._M_node_count = (unsigned int)v68;
      v34 = v5 >> (char)v33;
      *(_DWORD *)&v66._M_key_compare.stlp_std::binary_function<char *,char *,bool> = v68;
      v67 = &v69;
      v68[0] = 0;
      vostok::buffer_string::assignf(
        (vostok::buffer_string *)&v66._M_node_count,
        "%s_%d",
        "$user$hiz_occlusion_depth_mips",
        v33);
      v60 = v33;
      v59 = 0;
      v35 = *(_DWORD *)(a2 + 204);
      if ( v35 )
      {
        v59 = *(const vostok::render::res_texture **)(a2 + 204);
        ++*(_DWORD *)(v35 + 4);
      }
      v36 = vostok::render::resource_manager::create_render_target(
              (vostok::render::resource_manager *)v66._M_node_count,
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v66._M_node_count,
              (vostok::render::res_texture *)v34,
              (ID3D11Texture2D **)current_rasterize_height,
              (const char *)0x29,
              enum_rt_usage_render_target,
              v59,
              (unsigned int)v60,
              (unsigned int)v61,
              v62);
      v37 = 0;
      if ( v36 )
      {
        ++v36->m_reference_count;
        v37 = (vostok::render::resource_manager *)v36;
      }
      v38 = name.m_pointer.m_object;
      v39 = (const char *)name.m_pointer.m_object->m_reference_count;
      name.m_pointer.m_object->m_reference_count = (volatile int)v37;
      if ( v39 )
      {
        if ( !--*(_DWORD *)v39 )
          vostok::render::resource_manager::release(
            v37,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v39);
      }
      v33 = (void *(__thiscall *)(void *))((char *)v33 + 1);
      name.m_pointer.m_object = (vostok::strings::shared::profile *)&v38->next_in_hashset;
      v5 = use_scene_depth_buffer;
    }
    while ( (unsigned int)v33 < *(_DWORD *)(a2 + 224) );
  }
  v40 = vostok::render::resource_manager::create_render_target(
          (vostok::render::resource_manager *)rasterize_width,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          "$user$hiz_occlusion_depth_mips_ds",
          (vostok::render::res_texture *)v5,
          (ID3D11Texture2D **)rasterize_width,
          (const char *)0x2C,
          enum_rt_usage_depth_stencil,
          0,
          0,
          (unsigned int)v61,
          v62);
  v41 = 0;
  if ( v40 )
  {
    ++v40->m_reference_count;
    v41 = (vostok::render::resource_manager *)v40;
  }
  v42 = *(const char **)(a2 + 200);
  *(_DWORD *)(a2 + 200) = v41;
  if ( v42 )
  {
    if ( (*(_DWORD *)v42)-- == 1 )
      vostok::render::resource_manager::release(
        v41,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v42);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4));
  v60 = (void *(__thiscall *)(void *))"source_mip_level";
  v44 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v46 = 0;
  name.m_pointer.m_object = 0;
  if ( v44 )
  {
    v46 = (void *(__thiscall *)(void *))v44;
    name.m_pointer.m_object = v44;
    _InterlockedExchangeAdd(&v44->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 232) = vostok::render::backend::register_constant_host(
                            v45,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_int);
  if ( v46 && !_InterlockedExchangeAdd((volatile signed __int32 *)v46, 0xFFFFFFFF) )
  {
    v60 = v46;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v46,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v60 = (void *(__thiscall *)(void *))"draw_color";
  v47 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v49 = 0;
  name.m_pointer.m_object = 0;
  if ( v47 )
  {
    v49 = (void *(__thiscall *)(void *))v47;
    name.m_pointer.m_object = v47;
    _InterlockedExchangeAdd(&v47->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 236) = vostok::render::backend::register_constant_host(
                            v48,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v49 && !_InterlockedExchangeAdd((volatile signed __int32 *)v49, 0xFFFFFFFF) )
  {
    v60 = v49;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v49,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v60 = (void *(__thiscall *)(void *))"render_target_size";
  v50 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v52 = 0;
  name.m_pointer.m_object = 0;
  if ( v50 )
  {
    v52 = (void *(__thiscall *)(void *))v50;
    name.m_pointer.m_object = v50;
    _InterlockedExchangeAdd(&v50->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 240) = vostok::render::backend::register_constant_host(
                            v51,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v52 && !_InterlockedExchangeAdd((volatile signed __int32 *)v52, 0xFFFFFFFF) )
  {
    v60 = v52;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v52,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v60 = (void *(__thiscall *)(void *))"rasterize_size";
  v53 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v55 = 0;
  name.m_pointer.m_object = 0;
  if ( v53 )
  {
    v55 = (void *(__thiscall *)(void *))v53;
    name.m_pointer.m_object = v53;
    _InterlockedExchangeAdd(&v53->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 244) = vostok::render::backend::register_constant_host(
                            v54,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v55 && !_InterlockedExchangeAdd((volatile signed __int32 *)v55, 0xFFFFFFFF) )
  {
    v60 = v55;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v55,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v60 = (void *(__thiscall *)(void *))"prev_texture_size";
  v56 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v58 = 0;
  name.m_pointer.m_object = 0;
  if ( v56 )
  {
    v58 = (void *(__thiscall *)(void *))v56;
    name.m_pointer.m_object = v56;
    _InterlockedExchangeAdd(&v56->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 248) = vostok::render::backend::register_constant_host(
                            v57,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v58 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v58, 0xFFFFFFFF) )
    {
      v60 = v58;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v58,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
}
