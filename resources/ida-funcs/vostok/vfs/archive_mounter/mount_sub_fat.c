void __thiscall vostok::vfs::archive_mounter::mount_sub_fat(
        vostok::vfs::archive_mounter *this,
        vostok::vfs::archive_mounter *a2)
{
  unsigned int file; // eax
  char *v3; // eax
  vostok::vfs::mounter *v4; // ecx
  boost::function<bool __cdecl(vostok::fs_new::synchronous_device_interface &)> *v5; // ecx
  vostok::fs_new::query_custom_operation_args *v6; // ecx
  vostok::vfs::mounter *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  char sub_fat; // al
  boost::_bi::bind_t<bool,boost::_mfi::mf1<bool,vostok::vfs::archive_mounter,vostok::fs_new::synchronous_device_interface &>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1> > > v10; // [esp-58h] [ebp-DCh]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v11; // [esp-44h] [ebp-C8h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v12; // [esp-24h] [ebp-A8h] BYREF
  vostok::threading::event *v13; // [esp-4h] [ebp-88h]
  vostok::fs_new::query_custom_operation_args args; // [esp+10h] [ebp-74h] BYREF
  char (__thiscall *v15)(vostok::vfs::archive_mounter *, vostok::fs_new::synchronous_device_interface *); // [esp+60h] [ebp-24h]
  __int64 v16; // [esp+64h] [ebp-20h]
  int v17; // [esp+6Ch] [ebp-18h]
  void (__thiscall *v18)(vostok::vfs::archive_mounter *, bool); // [esp+70h] [ebp-14h]
  int v19; // [esp+74h] [ebp-10h]
  vostok::vfs::archive_mounter *v20; // [esp+78h] [ebp-Ch]
  int v21; // [esp+7Ch] [ebp-8h]

  file = vostok::vfs::get_file_size<1>(a2->m_args.submount_node);
  v3 = (char *)a2->m_args.allocator->call_malloc(
                 a2->m_args.allocator,
                 file,
                 "sub-fat nodes",
                 "vostok::vfs::archive_mounter::mount_sub_fat",
                 ".\\mount_subfat.cpp",
                 31);
  a2->m_nodes_buffer = v3;
  if ( v3 )
  {
    if ( a2->m_args.asynchronous_device )
    {
      v13 = 0;
      v18 = vostok::vfs::archive_mounter::on_read_sub_fat;
      LODWORD(v16) = 0;
      v19 = 0;
      v20 = a2;
      v11.functor.vostok_pointer_size_alignment[2] = vostok::vfs::archive_mounter::on_read_sub_fat;
      v11.functor.vostok_pointer_size_alignment[3] = 0;
      v11.functor.bound_memfunc_ptr.obj_ptr = a2;
      v11.functor.vostok_pointer_size_alignment[1] = &v12;
      v15 = vostok::vfs::archive_mounter::read_sub_fat;
      HIDWORD(v16) = a2;
      boost::function<void __cdecl (bool)>::function<void __cdecl (bool)>(
        0,
        *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1> > > *)((char *)&v11.functor.bound_memfunc_ptr.memfunc_ptr + 4),
        v21);
      HIDWORD(v10.f_.f_) = v15;
      *(_QWORD *)&v10.l_.a1_.t_ = v16;
      LODWORD(v10.f_.f_) = &v11;
      boost::function<bool __cdecl (vostok::fs_new::synchronous_device_interface &)>::function<bool __cdecl (vostok::fs_new::synchronous_device_interface &)>(
        v5,
        v10,
        v17);
      vostok::fs_new::query_custom_operation_args::query_custom_operation_args(v6, (int)&args, v11, v12, v13);
      if ( !vostok::fs_new::asynchronous_device_interface::query_custom_operation(
              a2->m_args.allocator,
              a2->m_args.asynchronous_device,
              (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&args) )
        vostok::vfs::mounter::finish_with_out_of_memory(v7, (int)a2);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&args.callback);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v8,
        (int *)&args);
    }
    else
    {
      sub_fat = vostok::vfs::archive_mounter::read_sub_fat(a2, a2->m_args.synchronous_device);
      vostok::vfs::archive_mounter::on_read_sub_fat(a2, sub_fat);
    }
  }
  else
  {
    vostok::vfs::mounter::finish_with_out_of_memory(v4, (int)a2);
  }
}
