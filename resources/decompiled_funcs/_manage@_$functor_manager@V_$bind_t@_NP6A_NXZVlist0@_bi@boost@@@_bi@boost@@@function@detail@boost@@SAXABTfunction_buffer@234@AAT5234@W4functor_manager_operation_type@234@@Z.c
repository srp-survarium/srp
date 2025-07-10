void __cdecl boost::detail::function::functor_manager<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>::manage(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  if ( op == get_functor_type_tag )
  {
    out_buffer->obj_ptr = (void *)&boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0> `RTTI Type Descriptor';
    WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
  }
  else
  {
    boost::detail::function::functor_manager_common<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>::manage_small(
      in_buffer,
      out_buffer,
      op);
  }
}
