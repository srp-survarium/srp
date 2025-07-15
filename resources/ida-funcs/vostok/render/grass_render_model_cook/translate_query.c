void __thiscall vostok::render::grass_render_model_cook::translate_query(
        vostok::render::grass_render_model_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  __int64 v3; // rdi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // ecx
  int v7; // eax
  vostok::particle::particle_action *v8; // ecx
  vostok::fixed_string<260> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  const char *v11; // [esp+0h] [ebp-388h]
  const char *v12; // [esp+4h] [ebp-384h]
  unsigned int v13; // [esp+8h] [ebp-380h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v14; // [esp+20h] [ebp-368h] BYREF
  vostok::fs_new::virtual_path_string v15; // [esp+40h] [ebp-348h] BYREF
  char *v16[3]; // [esp+158h] [ebp-230h] BYREF
  _BYTE v17[260]; // [esp+164h] [ebp-224h] BYREF
  char v18; // [esp+268h] [ebp-120h] BYREF
  vostok::fs_new::virtual_path_string v19; // [esp+274h] [ebp-114h] BYREF

  LODWORD(v3) = this;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  v15.m_string.m_begin = v15.m_string.m_buffer;
  v15.m_string.m_end = v15.m_string.m_buffer;
  v15.m_string.m_max_end = &v15.m_separator;
  v15.m_string.m_buffer[0] = 0;
  v15.m_separator = 47;
  vostok::fs_new::path_string_impl::assignf(
    &v15,
    (vostok::buffer_string *)&v15.m_separator,
    (vostok::buffer_string *)"%s.model",
    requested_path);
  HIDWORD(v3) = vostok::render::g_allocator;
  v4 = type_info::raw_name(&vostok::render::cook_intermediate_data `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, SHIDWORD(v3), 0x338u, v4, v11, v12, v13);
  if ( v6 )
  {
    vostok::render::cook_intermediate_data::cook_intermediate_data(
      (vostok::render::cook_intermediate_data *)v6,
      &v15,
      parent);
    HIDWORD(v3) = v7;
  }
  else
  {
    HIDWORD(v3) = 0;
  }
  v16[0] = v17;
  v16[1] = v17;
  v16[2] = &v18;
  v17[0] = 0;
  v18 = 47;
  vostok::fs_new::path_string_impl::assignf(
    v16,
    (vostok::buffer_string *)v6,
    (vostok::buffer_string *)"resources/models/%s/render",
    v15.m_string.m_begin);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v8) )
  {
    v14.vtable = 0;
  }
  else
  {
    v14.functor.obj_ptr = vostok::render::render_model_cook::on_fs_iterator_ready_submeshes;
    *(_QWORD *)((char *)&v14.functor.bound_memfunc_ptr.memfunc_ptr + 4) = v3;
    v14.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::vfs::vfs_locked_iterator const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::render::cook_intermediate_data *,vostok::vfs::vfs_locked_iterator const &>,boost::_bi::list3<boost::_bi::value<vostok::render::grass_render_model_cook *>,boost::_bi::value<vostok::render::cook_intermediate_data *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  vostok::fixed_string<260>::fixed_string<260>(v9, &v19.m_string, v16[0]);
  v19.m_separator = 47;
  vostok::resources::query_vfs_iterator(&v19, &v14, vostok::render::g_allocator, recursive_true, parent);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&v14);
}
