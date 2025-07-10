int __usercall vostok::render::speedtree_subsurface_name_to_vertex_input_type@<eax>(
        const vostok::fs_new::virtual_path_string *subsurface_name@<esi>)
{
  if ( vostok::fs_new::path_string_impl::operator==(&subsurface_name->vostok::fs_new::path_string_impl, "branch")
    || vostok::fs_new::path_string_impl::operator==(&subsurface_name->vostok::fs_new::path_string_impl, "frond")
    || vostok::fs_new::path_string_impl::operator==(&subsurface_name->vostok::fs_new::path_string_impl, "leafmesh")
    || vostok::fs_new::path_string_impl::operator==(&subsurface_name->vostok::fs_new::path_string_impl, "leafcard") )
  {
    return 16;
  }
  else
  {
    return vostok::fs_new::path_string_impl::operator==(&subsurface_name->vostok::fs_new::path_string_impl, "billboard")
         ? 0x10
         : 0;
  }
}
