void __thiscall vostok::render::grass_render_model_cook::translate_query(
        vostok::render::grass_render_model_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  __int64 v3; // rdi
  vostok::render::cook_intermediate_data *v4; // esi
  int v5; // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v7; // [esp-8h] [ebp-390h]
  char *other; // [esp+Ch] [ebp-37Ch] BYREF
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &)> callback; // [esp+10h] [ebp-378h] BYREF
  void (__thiscall *v10)(vostok::render::render_model_cook *, vostok::render::cook_intermediate_data *, const vostok::vfs::vfs_locked_iterator *); // [esp+34h] [ebp-354h]
  int v11; // [esp+38h] [ebp-350h]
  vostok::fs_new::virtual_path_string model_path; // [esp+40h] [ebp-348h] BYREF
  vostok::fs_new::virtual_path_string render_path; // [esp+158h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+274h] [ebp-114h] BYREF

  m_requery_path = parent->m_requery_path;
  LODWORD(v3) = this;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  model_path.m_string.m_end = model_path.m_string.m_buffer;
  model_path.m_string.m_begin = model_path.m_string.m_buffer;
  model_path.m_string.m_max_end = &model_path.m_separator;
  model_path.m_string.m_buffer[0] = 0;
  model_path.m_separator = 47;
  vostok::fs_new::path_string_impl::assignf(&model_path, "%s.model", m_requery_path);
  v4 = (vostok::render::cook_intermediate_data *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                   0x138u);
  if ( v4 )
  {
    vostok::render::cook_intermediate_data::cook_intermediate_data(v4, &model_path, parent);
    HIDWORD(v3) = v5;
  }
  else
  {
    HIDWORD(v3) = 0;
  }
  render_path.m_string.m_begin = render_path.m_string.m_buffer;
  render_path.m_string.m_end = render_path.m_string.m_buffer;
  render_path.m_string.m_max_end = &render_path.m_separator;
  render_path.m_string.m_buffer[0] = 0;
  render_path.m_separator = 47;
  vostok::fs_new::path_string_impl::assignf(&render_path, "resources/models/%s/render", model_path.m_string.m_begin);
  v11 = v3;
  v10 = vostok::render::render_model_cook::on_fs_iterator_ready_submeshes;
  *(_QWORD *)&v7.f_.f_ = v3;
  callback.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::render_model_cook::on_fs_iterator_ready_submeshes,
         v7) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::vfs::vfs_locked_iterator const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::render::cook_intermediate_data *,vostok::vfs::vfs_locked_iterator const &>,boost::_bi::list3<boost::_bi::value<vostok::render::grass_render_model_cook *>,boost::_bi::value<vostok::render::cook_intermediate_data *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  other = render_path.m_string.m_begin;
  vostok::fs_new::virtual_path_string::virtual_path_string(&path, (const char **)&other);
  vostok::resources::query_vfs_iterator(
    &path,
    &callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    recursive_true,
    parent);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v6 )
      v6(&callback.functor, &callback.functor, 2);
  }
}
