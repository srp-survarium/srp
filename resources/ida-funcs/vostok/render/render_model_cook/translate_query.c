void __thiscall vostok::render::render_model_cook::translate_query(
        vostok::render::render_model_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  __int64 v2; // rdi
  char *requested_path; // eax
  vostok::fixed_string<260> *v4; // ecx
  int v5; // eax
  int v6; // eax
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // ecx
  int v11; // eax
  vostok::particle::particle_action *v12; // ecx
  vostok::fixed_string<260> *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  const char *v15; // [esp+0h] [ebp-388h]
  const char *v16; // [esp+4h] [ebp-384h]
  unsigned int v17; // [esp+8h] [ebp-380h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v18; // [esp+20h] [ebp-368h] BYREF
  char *v19[3]; // [esp+40h] [ebp-348h] BYREF
  _BYTE v20[260]; // [esp+4Ch] [ebp-33Ch] BYREF
  char v21; // [esp+150h] [ebp-238h] BYREF
  vostok::fs_new::virtual_path_string str1; // [esp+158h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string v23; // [esp+274h] [ebp-114h] BYREF

  LODWORD(v2) = this;
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fixed_string<260>::fixed_string<260>(v4, &str1.m_string, requested_path);
  str1.m_separator = 47;
  strstr((unsigned __int8 *)str1.m_string.m_begin, "/render");
  if ( v5 )
    v6 = v5 - (unsigned int)str1.m_string.m_begin;
  else
    v6 = -1;
  v7 = vostok::render::g_allocator;
  str1.m_string.m_end = &str1.m_string.m_begin[v6];
  *str1.m_string.m_end = 0;
  v8 = type_info::raw_name(&vostok::render::cook_intermediate_data `RTTI Type Descriptor');
  v10 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 0x338u, v8, v15, v16, v17);
  if ( v10 )
  {
    vostok::render::cook_intermediate_data::cook_intermediate_data(
      (vostok::render::cook_intermediate_data *)v10,
      &str1,
      parent);
    HIDWORD(v2) = v11;
  }
  else
  {
    HIDWORD(v2) = 0;
  }
  v19[0] = v20;
  v19[1] = v20;
  v19[2] = &v21;
  v20[0] = 0;
  v21 = 47;
  vostok::fs_new::path_string_impl::assignf(
    v19,
    (vostok::buffer_string *)v10,
    (vostok::buffer_string *)"resources/models/%s/render",
    str1.m_string.m_begin);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v12) )
  {
    v18.vtable = 0;
  }
  else
  {
    v18.functor.obj_ptr = vostok::render::render_model_cook::on_fs_iterator_ready_submeshes;
    *(_QWORD *)((char *)&v18.functor.bound_memfunc_ptr.memfunc_ptr + 4) = v2;
    v18.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::vfs::vfs_locked_iterator const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::render::cook_intermediate_data *,vostok::vfs::vfs_locked_iterator const &>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::_bi::value<vostok::render::cook_intermediate_data *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  vostok::fixed_string<260>::fixed_string<260>(v13, &v23.m_string, v19[0]);
  v23.m_separator = 47;
  vostok::resources::query_vfs_iterator(&v23, &v18, vostok::render::g_allocator, recursive_true, parent);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)&v18);
}
