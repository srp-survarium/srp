void __cdecl boost::detail::function::functor_manager<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::manage(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  if ( op == get_functor_type_tag )
  {
    out_buffer->obj_ptr = (void *)&void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag) `RTTI Type Descriptor';
    WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
  }
  else
  {
    boost::detail::function::functor_manager_common<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::manage_ptr(
      in_buffer,
      out_buffer,
      op);
  }
}


void __cdecl boost::detail::function::functor_manager<void (__cdecl *)(char const *)>::manage(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  if ( op == get_functor_type_tag )
  {
    out_buffer->obj_ptr = (void *)&void (__cdecl *)(char const *) `RTTI Type Descriptor';
    WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
  }
  else
  {
    boost::detail::function::functor_manager_common<void (__cdecl *)(char const *)>::manage_ptr(
      in_buffer,
      out_buffer,
      op);
  }
}


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


void __cdecl boost::detail::function::functor_manager<bool (__cdecl *)(void)>::manage(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  if ( op == get_functor_type_tag )
  {
    out_buffer->obj_ptr = (void *)&bool (__cdecl *)(void) `RTTI Type Descriptor';
    WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
  }
  else
  {
    boost::detail::function::functor_manager_common<bool (__cdecl *)(void)>::manage_ptr(in_buffer, out_buffer, op);
  }
}


void __cdecl boost::detail::function::functor_manager<vostok::vfs::filter_by_descriptor>::manage(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  if ( op == get_functor_type_tag )
  {
    out_buffer->obj_ptr = (void *)&vostok::vfs::filter_by_descriptor `RTTI Type Descriptor';
    WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
  }
  else
  {
    boost::detail::function::functor_manager_common<vostok::vfs::filter_by_descriptor>::manage_small(
      in_buffer,
      out_buffer,
      op);
  }
}


void __cdecl boost::detail::function::functor_manager<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>::manage(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  if ( op == get_functor_type_tag )
  {
    out_buffer->obj_ptr = (void *)&boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0> `RTTI Type Descriptor';
    WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
  }
  else
  {
    boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>::manage_small(
      in_buffer,
      out_buffer,
      op);
  }
}


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
