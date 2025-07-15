void __thiscall vostok::resources::fs_task_iterator::try_async_query(vostok::resources::fs_task_iterator *this)
{
  vostok::particle::particle_action *v2; // ecx
  bool ListenerStatus; // al
  vostok::vfs::virtual_file_system *v4; // ecx
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> v5; // [esp-2Ch] [ebp-154h] BYREF
  vostok::vfs::find_enum v6; // [esp-Ch] [ebp-134h]
  vostok::memory::base_allocator *v7; // [esp-8h] [ebp-130h]
  int v8; // [esp-4h] [ebp-12Ch]
  __int64 v9; // [esp+Ch] [ebp-11Ch] BYREF
  vostok::buffer_string v10[22]; // [esp+14h] [ebp-114h] BYREF
  char v11; // [esp+124h] [ebp-4h]

  vostok::fixed_string<260>::fixed_string<260>(
    (vostok::fixed_string<260> *)this,
    v10,
    this->m_virtual_path.m_string.m_begin);
  LODWORD(v9) = vostok::resources::fs_task_iterator::on_vfs_iterator_ready;
  v11 = 47;
  v5.functor.vostok_pointer_size_alignment[1] = 0;
  HIDWORD(v9) = this;
  ListenerStatus = Scaleform::Render::RenderEvent::GetListenerStatus(v2);
  v4 = (vostok::vfs::virtual_file_system *)&v9;
  if ( ListenerStatus )
  {
    v5.functor.vostok_pointer_size_alignment[1] = 0;
  }
  else
  {
    if ( (__int128 *)((char *)&v5.functor.bound_memfunc_ptr.memfunc_ptr + 4) != (__int128 *)-8 )
    {
      *(_QWORD *)(&v5.functor.data + 12) = v9;
      v4 = (vostok::vfs::virtual_file_system *)HIDWORD(v9);
    }
    v5.functor.vostok_pointer_size_alignment[1] = (char *)&`boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::fs_task_iterator,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::resources::fs_task_iterator *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
                                                + 1;
  }
  v5.functor.obj_ptr = &vostok::memory::g_resources_unmanaged_allocator;
  (&v5.vtable)[1] = (boost::detail::function::vtable_base *)(this->m_recursive != recursive_false);
  v5.vtable = (boost::detail::function::vtable_base *)v10;
  vostok::vfs::virtual_file_system::try_find_async(v4, &s_resources_manager_buffer.m_vfs, v5, v6, v7, v8);
}
