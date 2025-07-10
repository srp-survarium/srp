bool __thiscall vostok::vfs::virtual_file_system::convert_virtual_to_physical_path(
        vostok::vfs::virtual_file_system *this,
        vostok::fs_new::native_path_string *out_path,
        const vostok::fs_new::virtual_path_string *path,
        char *mount_descriptor)
{
  boost::function<bool __cdecl(char const *,char const *,char const *)> v6; // [esp+2Ch] [ebp-28h] BYREF
  bool v7; // [esp+4Fh] [ebp-5h]
  vostok::vfs::filter_by_descriptor filter; // [esp+50h] [ebp-4h]

  filter.descriptor = mount_descriptor;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)mount_descriptor,
    &v6);
  if ( boost::detail::function::basic_vtable3<bool,char const *,char const *,char const *>::assign_to<vostok::vfs::filter_by_descriptor>(
         (boost::detail::function::basic_vtable3<bool,char const *,char const *,char const *> *)&`boost::function3<bool,char const *,char const *,char const *>::assign_to<vostok::vfs::filter_by_descriptor>'::`2'::stored_vtable,
         (vostok::vfs::filter_by_descriptor)mount_descriptor,
         &v6.functor) )
  {
    v6.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function3<bool,char const *,char const *,char const *>::assign_to<vostok::vfs::filter_by_descriptor>'::`2'::stored_vtable.base.manager
                                                       + 1);
  }
  else
  {
    v6.vtable = 0;
  }
  v7 = vostok::vfs::convert_virtual_to_physical_path(&this->mount_history, out_path, path, &v6, 0);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v6);
  return v7 || vostok::vfs::convert_virtual_to_physical_path(&this->mount_history, out_path, path, 0, 0);
}
