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
    boost::detail::function::functor_manager<void (__cdecl *)(char const *)>::manager(in_buffer, out_buffer, op);
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
    boost::detail::function::functor_manager<void (__cdecl *)(void)>::manager(in_buffer, out_buffer, op);
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
    boost::detail::function::functor_manager<bool (__cdecl *)(void)>::manager(in_buffer, out_buffer, op);
  }
}


void __cdecl boost::detail::function::functor_manager<survarium::zero_time_calculator>::manage(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        unsigned int op)
{
  if ( op == 4 )
    goto LABEL_5;
  if ( op <= 2 )
    return;
  if ( op != 3 )
  {
LABEL_5:
    WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
    out_buffer->obj_ptr = (void *)&survarium::zero_time_calculator `RTTI Type Descriptor';
  }
  else
  {
    out_buffer->obj_ptr = type_info::operator==(
                            out_buffer->type.type,
                            &survarium::zero_time_calculator `RTTI Type Descriptor')
                        ? (void *)in_buffer
                        : 0;
  }
}
