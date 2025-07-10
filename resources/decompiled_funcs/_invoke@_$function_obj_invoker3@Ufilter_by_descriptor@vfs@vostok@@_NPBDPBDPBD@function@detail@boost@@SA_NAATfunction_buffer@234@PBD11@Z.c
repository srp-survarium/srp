bool __cdecl boost::detail::function::function_obj_invoker3<vostok::vfs::filter_by_descriptor,bool,char const *,char const *,char const *>::invoke(
        boost::detail::function::function_buffer *function_obj_ptr,
        const char *a0,
        const char *a1,
        survarium::game_camera *a2)
{
  return vostok::vfs::filter_by_descriptor::operator()(
           (vostok::vfs::filter_by_descriptor *)function_obj_ptr,
           a0,
           a1,
           a2);
}
