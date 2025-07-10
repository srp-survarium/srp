void __thiscall vostok::resources::fs_task_iterator::try_async_query(vostok::resources::fs_task_iterator *this)
{
  vostok::vfs::virtual_file_system *v2; // ebx
  bool v3; // zf
  boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::fs_task_iterator,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::resources::fs_task_iterator *>,boost::arg<1>,boost::arg<2> > > v5; // [esp-30h] [ebp-158h]
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> v6; // [esp-28h] [ebp-150h] BYREF
  vostok::vfs::find_enum v7; // [esp-8h] [ebp-130h]
  vostok::memory::doug_lea_allocator *v8; // [esp-4h] [ebp-12Ch]
  char *other; // [esp+10h] [ebp-118h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+14h] [ebp-114h] BYREF

  v2 = (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                          + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  other = this->m_virtual_path.m_string.m_begin;
  vostok::fs_new::virtual_path_string::virtual_path_string(&path, (const char **)&other);
  v3 = this->m_recursive == recursive_false;
  v8 = &vostok::memory::g_resources_unmanaged_allocator;
  v7 = !v3;
  v5.l_.a1_.t_ = this;
  v5.f_.f_ = vostok::resources::fs_task_iterator::on_vfs_iterator_ready;
  v6.vtable = 0;
  boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::fs_task_iterator,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::resources::fs_task_iterator *>,boost::arg<1>,boost::arg<2>>>>(
    v4,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::fs_task_iterator,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::resources::fs_task_iterator *>,boost::arg<1>,boost::arg<2> > > *)&v6,
    v5);
  vostok::vfs::virtual_file_system::try_find_async(
    v2,
    (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&path,
    v6,
    v7,
    v8);
}
