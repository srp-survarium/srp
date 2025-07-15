vostok::render::res_texture *__thiscall vostok::render::resource_manager::load_texture(
        vostok::render::resource_manager *this,
        char *texture_name,
        const vostok::variant<32> **parent,
        unsigned int mip_level_cut,
        int use_pool,
        bool load_async,
        bool use_converter,
        unsigned int num_last_mips_used,
        bool query_texture,
        bool streamed)
{
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v11; // ecx
  stlp_std::priv::_Rb_tree_node_base *v12; // eax
  void *v13; // eax
  vostok::render::res_texture *v14; // ecx
  vostok::render::res_texture *M_parent; // ebx
  vostok::render::res_texture *v16; // eax
  bool v17; // al
  vostok::fixed_string<260> *v18; // ecx
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v19; // ecx
  int v20; // eax
  vostok::buffer_string *v21; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v22; // ecx
  vostok::command_line::key *v23; // ecx
  void *v24; // eax
  vostok::render::res_texture *v25; // ecx
  vostok::render::res_texture *v26; // eax
  char *v27; // edx
  vostok::fixed_string<260> *v28; // ecx
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v29; // ecx
  vostok::buffer_string *v30; // ecx
  vostok::buffer_string *v31; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v32; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v33; // ecx
  int *v34; // esi
  _BYTE v36[288]; // [esp-1Ch] [ebp-430h] BYREF
  char v37; // [esp+120h] [ebp-2F4h]
  vostok::render::res_texture *v38; // [esp+124h] [ebp-2F0h]
  vostok::buffer_string v39[22]; // [esp+128h] [ebp-2ECh] BYREF
  char v40; // [esp+238h] [ebp-1DCh]
  vostok::render::res_texture *v41; // [esp+23Ch] [ebp-1D8h]
  vostok::buffer_string v42[22]; // [esp+240h] [ebp-1D4h] BYREF
  char v43; // [esp+350h] [ebp-C4h]
  _BYTE v44[32]; // [esp+358h] [ebp-BCh] BYREF
  int f[8]; // [esp+378h] [ebp-9Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > v46; // [esp+398h] [ebp-7Ch] BYREF
  char v47; // [esp+3BCh] [ebp-58h] BYREF
  char v48; // [esp+3C4h] [ebp-50h] BYREF
  vostok::render::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred> *p_m_texture_registry; // [esp+3CCh] [ebp-48h]
  _DWORD v50[5]; // [esp+3D0h] [ebp-44h] BYREF
  _DWORD v51[7]; // [esp+3E4h] [ebp-30h] BYREF
  vostok::render::resource_manager *v52; // [esp+400h] [ebp-14h]
  unsigned int v53; // [esp+404h] [ebp-10h]
  int v54; // [esp+408h] [ebp-Ch]
  vostok::variant<32> *v55; // [esp+40Ch] [ebp-8h]

  v55 = (vostok::variant<32> *)(4 * use_converter + 3);
  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)this, v42, "resources/textures/");
  v43 = 47;
  if ( (_BYTE)use_pool )
  {
    v24 = vostok::memory::new_helper<vostok::render::res_texture>::call<vostok::memory::doug_lea_allocator>(
            vostok::render::g_allocator,
            *(const char *const *)&v36[28],
            *(const char *const *)&v36[32],
            *(const unsigned int *)&v36[36]);
    if ( v24 )
    {
      vostok::render::res_texture::res_texture(v25, (int)v24, 1);
      M_parent = v26;
    }
    else
    {
      M_parent = 0;
    }
    v27 = texture_name;
    M_parent->m_is_registered = 1;
    vostok::render::res_texture::set_name(M_parent, v27);
    vostok::fixed_string<260>::fixed_string<260>(
      v28,
      (vostok::buffer_string *)&v36[44],
      M_parent->m_name.m_string.m_begin);
    *(_DWORD *)&v36[24] = &v36[44];
    v37 = 47;
    v38 = M_parent;
    stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::insert_unique(
      v29,
      &this->m_texture_registry._M_t._M_header._M_data,
      (const stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> *)&v47,
      *(stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&v36[24]);
    vostok::buffer_string::append(v30, (int)v42, M_parent->m_name.m_string.m_begin);
    vostok::buffer_string::append(v31, (int)v42, ".dds");
    if ( load_async )
    {
      v51[3] = this;
      v51[4] = mip_level_cut;
      v51[6] = btBU_Simplex1to4::getPlane;
      LOBYTE(v51[5]) = use_converter;
      v52 = this;
      v53 = mip_level_cut;
      v54 = v51[5];
      *(_DWORD *)&v36[12] = btBU_Simplex1to4::getPlane;
      *(_DWORD *)&v36[16] = this;
      *(_DWORD *)&v36[20] = mip_level_cut;
      *(_DWORD *)&v36[8] = v44;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        v32,
        *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > *)&v36[8],
        v51[5]);
      vostok::resources::query_resource(v42[0].m_begin, v55, vostok::render::g_allocator, 0, 0, assert_on_fail_true);
      v34 = (int *)v44;
    }
    else
    {
      v52 = this;
      v53 = mip_level_cut;
      v51[2] = btBU_Simplex1to4::getPlane;
      LOBYTE(v54) = use_converter;
      v51[3] = this;
      v51[4] = mip_level_cut;
      v51[5] = v54;
      *(_DWORD *)&v36[12] = btBU_Simplex1to4::getPlane;
      *(_DWORD *)&v36[16] = this;
      *(_DWORD *)&v36[20] = mip_level_cut;
      *(_DWORD *)&v36[8] = &v46;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        v32,
        *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > *)&v36[8],
        v54);
      vostok::resources::query_resource_and_wait(
        v42[0].m_begin,
        v55,
        vostok::render::g_allocator,
        0,
        (vostok::resources::query_result_for_cook *)1);
      v34 = (int *)&v46;
    }
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v33, v34);
  }
  else
  {
    v12 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
            v11,
            (const char *const *)&this->m_texture_registry,
            (const char **)&texture_name);
    p_m_texture_registry = &this->m_texture_registry;
    if ( v12 == (stlp_std::priv::_Rb_tree_node_base *)&this->m_texture_registry )
    {
      v13 = vostok::memory::new_helper<vostok::render::res_texture>::call<vostok::memory::doug_lea_allocator>(
              vostok::render::g_allocator,
              *(const char *const *)&v36[28],
              *(const char *const *)&v36[32],
              *(const unsigned int *)&v36[36]);
      M_parent = 0;
      if ( v13 )
      {
        vostok::render::res_texture::res_texture(v14, (int)v13, 0);
        M_parent = v16;
      }
      vostok::render::res_texture::set_name(M_parent, texture_name);
      v17 = streamed;
      *(_DWORD *)&v36[24] = M_parent->m_name.m_string.m_begin;
      M_parent->m_is_registered = 1;
      M_parent->m_streamed = v17;
      vostok::fixed_string<260>::fixed_string<260>(v18, v39, *(char **)&v36[24]);
      *(_DWORD *)&v36[24] = v39;
      v40 = 47;
      v41 = M_parent;
      stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::insert_unique(
        v19,
        &this->m_texture_registry._M_t._M_header._M_data,
        (const stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> *)&v48,
        *(stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&v36[24]);
    }
    else
    {
      M_parent = (vostok::render::res_texture *)v12[18]._M_parent;
    }
    if ( query_texture )
    {
      strstr((unsigned __int8 *)M_parent->m_name.m_string.m_begin, "$user$");
      if ( !v20 )
      {
        if ( texture_name )
        {
          if ( *texture_name )
          {
            if ( num_last_mips_used )
            {
              vostok::buffer_string::append(
                *(vostok::buffer_string **)&v36[24],
                (int)v42,
                M_parent->m_name.m_string.m_begin);
              vostok::buffer_string::append(v21, (int)v42, ".dds");
              v50[3] = -1;
              v50[1] = mip_level_cut;
              LOBYTE(v50[2]) = use_converter;
              v50[0] = this;
              v50[4] = !load_async ? &use_pool : 0;
              v51[0] = vostok::render::resource_manager::on_texture_loaded;
              qmemcpy(&v51[1], v50, 0x14u);
              *(_DWORD *)v36 = f;
              use_pool = 0;
              qmemcpy(&v36[4], v51, 0x18u);
              boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
                0,
                *(boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int,long volatile *>,boost::_bi::list6<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool>,boost::_bi::value<unsigned int>,boost::_bi::value<long volatile *> > > *)v36,
                *(int *)&v36[24]);
              vostok::resources::query_resource(
                v42[0].m_begin,
                v55,
                vostok::render::g_allocator,
                0,
                parent,
                assert_on_fail_false);
              boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
                v22,
                f);
              if ( !load_async )
              {
                while ( !use_pool )
                {
                  vostok::resources::dispatch_callbacks(v23);
                  vostok::threading::yield(0);
                }
              }
            }
          }
        }
      }
    }
  }
  return M_parent;
}
