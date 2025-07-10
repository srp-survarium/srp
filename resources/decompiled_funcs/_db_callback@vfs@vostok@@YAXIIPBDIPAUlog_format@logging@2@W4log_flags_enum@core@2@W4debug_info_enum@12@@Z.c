void __cdecl vostok::vfs::db_callback(
        unsigned int num_nodes,
        unsigned int whole_nodes,
        const char *name,
        char flags,
        vostok::logging::log_format *log_format,
        vostok::core::log_flags_enum log_flags,
        vostok::vfs::debug_info_enum debug_info)
{
  int v7; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  int v9; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::variant<32> **v11; // eax
  char v12; // [esp+1Ch] [ebp-254h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+20h] [ebp-250h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+40h] [ebp-230h] BYREF
  vostok::fixed_string<512> flags_string; // [esp+60h] [ebp-210h] BYREF

  v12 = 0;
  if ( debug_info == debug_info_detail )
  {
    vostok::fixed_string<512>::fixed_string<512>((vostok::fixed_string<512> *)v7, (int)&flags_string);
    if ( (flags & 0x40) != 0 )
      vostok::buffer_string::operator+=(&flags_string, "inlined+");
    if ( (flags & 0x10) != 0 )
      vostok::buffer_string::operator+=(&flags_string, "compressed+");
    if ( vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)&flags_string) )
    {
      v9 = vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)&flags_string);
      vostok::fs_new::path_string_impl::set_length((vostok::fs_new::path_string_impl *)&flags_string, v9 - 1);
    }
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "pack:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v8);
      v12 = 1;
      v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              v10,
              (int)&flags_string);
      vostok::logging::append(
        &log_callback,
        (void *const)log_flags,
        log_format,
        ".\\pack_archive_utils.cpp",
        0x2Cu,
        "void __cdecl vostok::vfs::db_callback(unsigned int,unsigned int,const char *,unsigned int,struct vostok::logging"
        "::log_format *,enum vostok::core::log_flags_enum,enum vostok::vfs::debug_info_enum)",
        "pack:",
        info,
        "%d of %d files proceeded: %s %s",
        num_nodes,
        whole_nodes,
        name,
        (const char *)v11);
    }
    if ( (v12 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v12 & 1),
        (int *)&log_callback);
  }
  else if ( debug_info == debug_info_normal )
  {
    if ( num_nodes == whole_nodes || (v7 = 25, !(num_nodes % 0x19)) )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "pack:", info) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7);
        v12 = 2;
        vostok::logging::append(
          &v13,
          (void *const)log_flags,
          log_format,
          ".\\pack_archive_utils.cpp",
          0x32u,
          "void __cdecl vostok::vfs::db_callback(unsigned int,unsigned int,const char *,unsigned int,struct vostok::loggi"
          "ng::log_format *,enum vostok::core::log_flags_enum,enum vostok::vfs::debug_info_enum)",
          "pack:",
          info,
          "%d of %d files proceeded",
          num_nodes,
          whole_nodes);
      }
      if ( (v12 & 2) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v7,
          (int *)&v13);
    }
  }
}
