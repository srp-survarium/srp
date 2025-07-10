void __cdecl boost::detail::function::functor_manager<void (__cdecl *)(void)>::manage(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  if ( op == get_functor_type_tag )
  {
    out_buffer->obj_ptr = (void *)&void (__cdecl *)(void) `RTTI Type Descriptor';
    WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
  }
  else
  {
    boost::detail::function::functor_manager_common<void (__cdecl *)(void)>::manage_ptr(in_buffer, out_buffer, op);
  }
}
