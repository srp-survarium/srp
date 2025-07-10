int __cdecl boost::detail::function::function_invoker0<bool (__cdecl *)(void),bool>::invoke(
        boost::detail::function::function_buffer *function_ptr)
{
  return ((int (__cdecl *)(void *))function_ptr->obj_ptr)(function_ptr->obj_ptr);
}
