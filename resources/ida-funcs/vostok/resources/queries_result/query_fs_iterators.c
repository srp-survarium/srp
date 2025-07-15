void __thiscall vostok::resources::queries_result::query_fs_iterators(
        vostok::resources::queries_result *this,
        _DWORD *a2)
{
  vostok::resources::query_result *p_m_name_registry_entry; // ecx
  vostok::resources::query_result_for_user *v3; // ecx
  int v4; // ecx
  bool v5; // zf
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::resources::query_result_for_cook *v7; // [esp-4h] [ebp-174h]
  vostok::resources::query_result_for_user *v8; // [esp+10h] [ebp-160h]
  int v9; // [esp+14h] [ebp-15Ch]
  vostok::resources::recursive_bool recursive; // [esp+18h] [ebp-158h]
  char *requested_path; // [esp+1Ch] [ebp-154h]
  __int64 v12; // [esp+2Ch] [ebp-144h] BYREF
  void *v13; // [esp+34h] [ebp-13Ch]
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &)> callback; // [esp+38h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+5Ch] [ebp-114h] BYREF

  a2[13] = vostok::resources::queries_result::calculate_fs_iterator_requests_count(this, (int)a2);
  if ( a2[14] )
  {
    p_m_name_registry_entry = (vostok::resources::query_result *)(a2 + 20);
    v8 = (vostok::resources::query_result_for_user *)(a2 + 20);
    v9 = a2[14];
    do
    {
      if ( vostok::resources::query_result::is_fs_iterator_query(p_m_name_registry_entry, (int)p_m_name_registry_entry) )
      {
        requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(v3);
        v5 = *(_DWORD *)(v4 + 132) == 2;
        LODWORD(v12) = vostok::resources::queries_result::on_fs_iterator_ready;
        HIDWORD(v12) = a2;
        recursive = v5;
        v13 = (void *)v4;
        if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)v4) )
        {
          callback.vtable = 0;
        }
        else
        {
          *(_QWORD *)&callback.functor.obj_ptr = v12;
          callback.functor.vostok_pointer_size_alignment[2] = v13;
          callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::vfs::vfs_locked_iterator const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::queries_result,vostok::vfs::vfs_locked_iterator const &,vostok::resources::query_result *>,boost::_bi::list3<boost::_bi::value<vostok::resources::queries_result *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result *>>>>'::`2'::stored_vtable
                                                                   + 1);
        }
        vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)&v12, &path.m_string, requested_path);
        v7 = (vostok::resources::query_result_for_cook *)a2[8];
        path.m_separator = 47;
        vostok::resources::query_vfs_iterator(
          &path,
          (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&callback,
          &vostok::memory::g_mt_allocator,
          recursive,
          v7);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v6,
          (int *)&callback);
        v3 = v8;
      }
      p_m_name_registry_entry = (vostok::resources::query_result *)&v3[2].m_name_registry_entry;
      v5 = v9-- == 1;
      v8 = p_m_name_registry_entry;
    }
    while ( !v5 );
  }
}
