void __thiscall vostok::render::render_model_cook::translate_query(
        vostok::render::render_model_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  int v3; // eax
  int v4; // eax
  vostok::render::cook_intermediate_data *v5; // esi
  survarium::animated_model_instance_cook *v6; // eax
  survarium::animated_model_instance_cook *v7; // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v9; // [esp-8h] [ebp-390h]
  char *m_begin; // [esp+8h] [ebp-380h] BYREF
  char *other; // [esp+Ch] [ebp-37Ch] BYREF
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &)> callback; // [esp+10h] [ebp-378h] BYREF
  void (__thiscall *v13)(vostok::render::render_model_cook *, vostok::render::cook_intermediate_data *, const vostok::vfs::vfs_locked_iterator *); // [esp+34h] [ebp-354h]
  char *v14; // [esp+38h] [ebp-350h]
  vostok::fs_new::virtual_path_string render_path; // [esp+40h] [ebp-348h] BYREF
  vostok::fs_new::virtual_path_string model_path; // [esp+158h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+274h] [ebp-114h] BYREF

  m_requery_path = parent->m_requery_path;
  m_begin = (char *)this;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  other = m_requery_path;
  vostok::fs_new::virtual_path_string::virtual_path_string(&model_path, (const char **)&other);
  strstr((unsigned __int8 *)model_path.m_string.m_begin, aRen);
  if ( v3 )
    v4 = v3 - (unsigned int)model_path.m_string.m_begin;
  else
    v4 = -1;
  model_path.m_string.m_end = &model_path.m_string.m_begin[v4];
  *model_path.m_string.m_end = 0;
  v5 = (vostok::render::cook_intermediate_data *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                   0x138u);
  if ( v5 )
  {
    vostok::render::cook_intermediate_data::cook_intermediate_data(v5, &model_path, parent);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  render_path.m_string.m_begin = render_path.m_string.m_buffer;
  render_path.m_string.m_end = render_path.m_string.m_buffer;
  render_path.m_string.m_max_end = &render_path.m_separator;
  render_path.m_string.m_buffer[0] = 0;
  render_path.m_separator = 47;
  vostok::fs_new::path_string_impl::assignf(&render_path, "resources/models/%s/render", model_path.m_string.m_begin);
  v14 = m_begin;
  v13 = vostok::render::render_model_cook::on_fs_iterator_ready_submeshes;
  v9.f_.f_ = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *))m_begin;
  callback.vtable = 0;
  v9.l_.a1_.t_ = v7;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::render_model_cook::on_fs_iterator_ready_submeshes,
         v9) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::vfs::vfs_locked_iterator const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::render::cook_intermediate_data *,vostok::vfs::vfs_locked_iterator const &>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::_bi::value<vostok::render::cook_intermediate_data *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  m_begin = render_path.m_string.m_begin;
  vostok::fs_new::virtual_path_string::virtual_path_string(&path, (const char **)&m_begin);
  vostok::resources::query_vfs_iterator(
    &path,
    &callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    recursive_true,
    parent);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v8 )
      v8(&callback.functor, &callback.functor, 2);
  }
}
