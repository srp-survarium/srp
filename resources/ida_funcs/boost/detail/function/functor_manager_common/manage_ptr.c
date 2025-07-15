void __usercall boost::detail::function::functor_manager_common<void (__cdecl *)(char const *)>::manage_ptr(
        const boost::detail::function::function_buffer *in_buffer@<edi>,
        boost::detail::function::function_buffer *out_buffer@<esi>,
        boost::detail::function::functor_manager_operation_type op@<eax>)
{
  if ( op )
  {
    switch ( op )
    {
      case move_functor_tag:
        out_buffer->obj_ptr = in_buffer->obj_ptr;
        in_buffer->obj_ptr = 0;
        break;
      case destroy_functor_tag:
        out_buffer->obj_ptr = 0;
        break;
      case check_functor_type_tag:
        out_buffer->obj_ptr = type_info::operator==(
                                out_buffer->type.type,
                                &void (__cdecl *)(char const *) `RTTI Type Descriptor')
                            ? (void *)in_buffer
                            : 0;
        break;
      default:
        out_buffer->obj_ptr = (void *)&void (__cdecl *)(char const *) `RTTI Type Descriptor';
        WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
        break;
    }
  }
  else
  {
    out_buffer->obj_ptr = in_buffer->obj_ptr;
  }
}


void __usercall boost::detail::function::functor_manager_common<void (__cdecl *)(void)>::manage_ptr(
        const boost::detail::function::function_buffer *in_buffer@<edi>,
        boost::detail::function::function_buffer *out_buffer@<esi>,
        boost::detail::function::functor_manager_operation_type op@<eax>)
{
  if ( op )
  {
    switch ( op )
    {
      case move_functor_tag:
        out_buffer->obj_ptr = in_buffer->obj_ptr;
        in_buffer->obj_ptr = 0;
        break;
      case destroy_functor_tag:
        out_buffer->obj_ptr = 0;
        break;
      case check_functor_type_tag:
        out_buffer->obj_ptr = type_info::operator==(
                                out_buffer->type.type,
                                &void (__cdecl *)(void) `RTTI Type Descriptor')
                            ? (void *)in_buffer
                            : 0;
        break;
      default:
        out_buffer->obj_ptr = (void *)&void (__cdecl *)(void) `RTTI Type Descriptor';
        WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
        break;
    }
  }
  else
  {
    out_buffer->obj_ptr = in_buffer->obj_ptr;
  }
}


void __cdecl boost::detail::function::functor_manager_common<bool (__cdecl *)(void)>::manage_ptr(
        const boost::detail::function::function_buffer *in_buffer,
        boost::detail::function::function_buffer *out_buffer,
        boost::detail::function::functor_manager_operation_type op)
{
  if ( op )
  {
    switch ( op )
    {
      case move_functor_tag:
        out_buffer->obj_ptr = in_buffer->obj_ptr;
        in_buffer->obj_ptr = 0;
        break;
      case destroy_functor_tag:
        out_buffer->obj_ptr = 0;
        break;
      case check_functor_type_tag:
        if ( type_info::operator==(out_buffer->type.type, &bool (__cdecl *)(void) `RTTI Type Descriptor') )
          out_buffer->obj_ptr = (void *)in_buffer;
        else
          out_buffer->obj_ptr = 0;
        break;
      default:
        out_buffer->obj_ptr = (void *)&bool (__cdecl *)(void) `RTTI Type Descriptor';
        WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
        break;
    }
  }
  else
  {
    out_buffer->obj_ptr = in_buffer->obj_ptr;
  }
}
