stlp_std::priv::_Rb_tree_node_base *__thiscall vostok::render::resource_manager::load_texture(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *texture_name,
        vostok::resources::query_result_for_cook *parent,
        vostok::resources::query_result_for_cook *mip_level_cut,
        vostok::render::resource_manager *use_pool,
        bool load_async,
        bool use_converter,
        bool num_last_mips_used,
        unsigned int num_last_mips_useda)
{
  char *m_buffer; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v10; // ecx
  bool v11; // zf
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v12; // eax
  void *v13; // eax
  vostok::render::res_texture *v14; // ecx
  stlp_std::priv::_Rb_tree_node_base *v15; // eax
  stlp_std::priv::_Rb_tree_node_base *M_parent; // edi
  vostok::resources::query_result_for_cook *v17; // eax
  unsigned int v18; // edx
  int v19; // eax
  vostok::fs_new::virtual_path_string *v20; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int>,boost::_bi::list5<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool>,boost::_bi::value<unsigned int> > > *v21; // eax
  __int64 v22; // xmm0_8
  void *t; // eax
  void *v25; // eax
  vostok::render::res_texture *v26; // ecx
  vostok::render::res_texture *v27; // eax
  vostok::render::res_texture *v28; // edi
  vostok::resources::query_result_for_cook *m_begin; // eax
  vostok::fs_new::virtual_path_string *p_m_name; // esi
  void (__cdecl *v31)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> v32; // [esp-14h] [ebp-2A4h] BYREF
  __int128 other; // [esp+14h] [ebp-27Ch] BYREF
  vostok::render::res_texture *tex; // [esp+24h] [ebp-26Ch] BYREF
  vostok::resources::class_id_enum class_id; // [esp+28h] [ebp-268h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int>,boost::_bi::list5<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool>,boost::_bi::value<unsigned int> > > requests; // [esp+2Ch] [ebp-264h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+40h] [ebp-250h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+60h] [ebp-230h] BYREF
  stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> v39; // [esp+178h] [ebp-118h] BYREF

  path.m_string.m_begin = path.m_string.m_buffer;
  class_id = 4 * num_last_mips_used + 3;
  m_buffer = path.m_string.m_buffer;
  path.m_string.m_end = path.m_string.m_buffer;
  path.m_string.m_max_end = &path.m_separator;
  path.m_string.m_buffer[0] = 0;
  v10 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)"resources/textures/";
  if ( aResourcesTextu_0[0] )
  {
    do
    {
      if ( m_buffer >= path.m_string.m_max_end )
        break;
      *m_buffer = v10->_M_header._M_data._M_color;
      m_buffer = path.m_string.m_end + 1;
      v10 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)((char *)v10 + 1);
      v11 = !v10->_M_header._M_data._M_color;
      ++path.m_string.m_end;
    }
    while ( !v11 );
  }
  v11 = !load_async;
  *m_buffer = 0;
  path.m_separator = 47;
  if ( v11 )
  {
    v12 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
            v10,
            &texture_name->m_texture_registry._M_t,
            (const char **)&parent);
    if ( v12 == (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&texture_name->m_texture_registry )
    {
      v13 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0x1BCu);
      if ( v13 )
      {
        vostok::render::res_texture::res_texture(v14, (int)v13, 0);
        M_parent = v15;
      }
      else
      {
        M_parent = 0;
      }
      v17 = *(vostok::resources::query_result_for_cook **)&M_parent[9]._M_color;
      if ( v17 != parent )
      {
        v32.functor.vostok_pointer_size_alignment[2] = parent;
        M_parent[9]._M_parent = (stlp_std::priv::_Rb_tree_node_base *)v17;
        LOBYTE(v17->__vftable) = 0;
        vostok::buffer_string::operator+=(
          (vostok::buffer_string *)&M_parent[9],
          (const char *)v32.functor.vostok_pointer_size_alignment[2]);
      }
      v18 = *(_DWORD *)&M_parent[9]._M_color;
      v32.functor.vostok_pointer_size_alignment[2] = &other;
      HIBYTE(M_parent[27]._M_parent) = 1;
      *(_QWORD *)&other = __PAIR64__((unsigned int)M_parent, v18);
      vostok::fs_new::virtual_path_string::virtual_path_string(
        (vostok::fs_new::virtual_path_string *)&v39.first,
        (const char **)v32.functor.vostok_pointer_size_alignment[2]);
      v39.second = (vostok::render::render_target *)DWORD1(other);
      stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *>>>::insert_unique(
        &v39,
        (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&texture_name->m_texture_registry,
        (stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >,bool> *)&requests);
    }
    else
    {
      M_parent = v12[12]._M_header._M_data._M_parent;
    }
    strstr(*(unsigned __int8 **)&M_parent[9]._M_color, "$user$");
    if ( !v19 && parent && LOBYTE(parent->__vftable) && num_last_mips_useda )
    {
      tex = *(vostok::render::res_texture **)&M_parent[9]._M_color;
      vostok::fs_new::path_string_impl::append<char const *>(&path, (char **)&tex);
      vostok::fs_new::virtual_path_string::operator+=<char const [5]>(v20, (int)&path);
      v21 = boost::bind<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int,vostok::render::resource_manager *,boost::arg<1>,unsigned int,bool,unsigned int>(
              texture_name,
              &requests,
              (void (__thiscall *)(vostok::render::resource_manager *, vostok::resources::queries_result *, unsigned int, bool, unsigned int))*(unsigned __int8 *)&1_269,
              (unsigned int)use_pool,
              num_last_mips_used,
              num_last_mips_useda);
      *(_QWORD *)&v32.vtable = *(_QWORD *)&v21->f_.f_;
      v22 = *(_QWORD *)&v21->l_.a3_.t_;
      t = (void *)v21->l_.a5_.t_;
      *(_QWORD *)&v32.functor.obj_ptr = v22;
      v32.functor.vostok_pointer_size_alignment[2] = t;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        &v32,
        &callback,
        *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int>,boost::_bi::list5<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool>,boost::_bi::value<unsigned int> > > *)&v32.vtable,
        (int)v32.functor.vostok_pointer_size_alignment[3]);
      if ( !use_converter )
      {
        vostok::resources::query_resource_and_wait(
          path.m_string.m_begin,
          class_id,
          &callback,
          (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
          0,
          0,
          assert_on_fail_true);
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
        return M_parent;
      }
      vostok::resources::query_resource(
        path.m_string.m_begin,
        class_id,
        &callback,
        (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
        0,
        mip_level_cut,
        assert_on_fail_false);
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
    }
    return M_parent;
  }
  else
  {
    v25 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
            0x1BCu);
    if ( v25 )
    {
      vostok::render::res_texture::res_texture(v26, (int)v25, 1);
      v28 = v27;
      tex = v27;
    }
    else
    {
      tex = 0;
      v28 = 0;
    }
    v28->m_is_registered = 1;
    m_begin = (vostok::resources::query_result_for_cook *)v28->m_name.m_string.m_begin;
    p_m_name = &v28->m_name;
    if ( m_begin != parent )
    {
      v32.functor.vostok_pointer_size_alignment[2] = parent;
      v28->m_name.m_string.m_end = (char *)m_begin;
      LOBYTE(m_begin->__vftable) = 0;
      vostok::buffer_string::operator+=(
        &v28->m_name.m_string,
        (const char *)v32.functor.vostok_pointer_size_alignment[2]);
    }
    LODWORD(other) = p_m_name->m_string.m_begin;
    DWORD1(other) = v28;
    vostok::fs_new::virtual_path_string::virtual_path_string(
      (vostok::fs_new::virtual_path_string *)&v39.first,
      (const char **)&other);
    v39.second = (vostok::render::render_target *)DWORD1(other);
    stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *>>>::insert_unique(
      &v39,
      (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&texture_name->m_texture_registry,
      (stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >,bool> *)&requests);
    LODWORD(other) = p_m_name->m_string.m_begin;
    vostok::fs_new::path_string_impl::append<char const *>(&path, (char **)&other);
    *(_DWORD *)path.m_string.m_end = *(_DWORD *)".dds";
    v11 = !use_converter;
    path.m_string.m_end += 4;
    *path.m_string.m_end = 0;
    requests.f_.f_ = (void (__thiscall *)(vostok::render::resource_manager *, vostok::resources::queries_result *, unsigned int, bool, unsigned int))texture_name;
    LODWORD(other) = vostok::render::resource_manager::on_texture_loaded_staging;
    if ( v11 )
    {
      LOBYTE(requests.l_.a3_.t_) = num_last_mips_used;
      requests.l_.a1_.t_ = use_pool;
      HIDWORD(other) = requests.l_.a3_.t_;
      *(_QWORD *)((char *)&other + 4) = *(_QWORD *)&requests.f_.f_;
      *(_QWORD *)&(&v32.vtable)[1] = other;
      *(_QWORD *)((char *)&v32.functor.bound_memfunc_ptr.memfunc_ptr + 4) = *((_QWORD *)&other + 1);
      boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
        (boost::function1<void,vostok::resources::queries_result &> *)use_pool,
        (int)&callback,
        (int)p_m_name,
        *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > *)&(&v32.vtable)[1],
        (int)v32.functor.vostok_pointer_size_alignment[3]);
      requests.f_.f_ = (void (__thiscall *)(vostok::render::resource_manager *, vostok::resources::queries_result *, unsigned int, bool, unsigned int))path.m_string.m_begin;
      requests.l_.a1_.t_ = (vostok::render::resource_manager *)class_id;
      LODWORD(other) = 0;
      vostok::resources::query_resources_and_wait(
        (const vostok::resources::request *)&requests,
        (unsigned int)vostok::render::g_allocator.m_object,
        &callback,
        (vostok::memory::base_allocator *)&other,
        0,
        (vostok::resources::query_result_for_cook *)1,
        (assert_on_fail_bool)v32.functor.vostok_pointer_size_alignment[3]);
    }
    else
    {
      requests.l_.a1_.t_ = use_pool;
      LOBYTE(requests.l_.a3_.t_) = num_last_mips_used;
      *(_QWORD *)((char *)&other + 4) = *(_QWORD *)&requests.f_.f_;
      *(_QWORD *)&(&v32.vtable)[1] = other;
      HIDWORD(other) = requests.l_.a3_.t_;
      *(_QWORD *)((char *)&v32.functor.bound_memfunc_ptr.memfunc_ptr + 4) = *((_QWORD *)&other + 1);
      boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
        (boost::function1<void,vostok::resources::queries_result &> *)requests.l_.a3_.t_,
        (int)&callback,
        (int)p_m_name,
        *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > *)&(&v32.vtable)[1],
        (int)v32.functor.vostok_pointer_size_alignment[3]);
      requests.f_.f_ = (void (__thiscall *)(vostok::render::resource_manager *, vostok::resources::queries_result *, unsigned int, bool, unsigned int))path.m_string.m_begin;
      requests.l_.a1_.t_ = (vostok::render::resource_manager *)class_id;
      LODWORD(other) = 0;
      vostok::resources::query_resources(
        (const vostok::resources::request *)&requests,
        1u,
        &callback,
        (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
        (const vostok::variant<32> **)&other,
        0,
        assert_on_fail_true);
    }
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v31 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v31 )
          v31(&callback.functor, &callback.functor, 2);
      }
    }
    return (stlp_std::priv::_Rb_tree_node_base *)tex;
  }
}
