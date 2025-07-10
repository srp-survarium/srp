void __cdecl boost::detail::function::functor_manager_common<vostok::vfs::filter_by_descriptor>::manage_small(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  void **v3; // [esp+4h] [ebp-14h]

  if ( (unsigned int)op > move_functor_tag )
  {
    if ( op != destroy_functor_tag )
    {
      if ( op == check_functor_type_tag )
      {
        if ( type_info::operator==(out_buffer->type.type, &vostok::vfs::filter_by_descriptor `RTTI Type Descriptor') )
          out_buffer->obj_ptr = (void *)in_buffer;
        else
          out_buffer->obj_ptr = 0;
      }
      else
      {
        out_buffer->obj_ptr = (void *)&vostok::vfs::filter_by_descriptor `RTTI Type Descriptor';
        WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
      }
    }
  }
  else
  {
    v3 = (void **)operator new(4u, (void *)out_buffer);
    if ( v3 )
      *v3 = in_buffer->obj_ptr;
  }
}
