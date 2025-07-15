void __usercall boost::detail::function::functor_manager<void (__cdecl *)(char const *)>::manager(
        const boost::detail::function::function_buffer *in_buffer@<edi>,
        boost::detail::function::function_buffer *out_buffer@<esi>,
        boost::detail::function::functor_manager_operation_type op@<eax>)
{
  const boost::detail::function::function_buffer *obj_ptr; // eax

  switch ( op )
  {
    case clone_functor_tag:
      obj_ptr = (const boost::detail::function::function_buffer *)in_buffer->obj_ptr;
LABEL_9:
      out_buffer->obj_ptr = (void *)obj_ptr;
      return;
    case move_functor_tag:
      out_buffer->obj_ptr = in_buffer->obj_ptr;
      in_buffer->obj_ptr = 0;
      return;
    case destroy_functor_tag:
      out_buffer->obj_ptr = 0;
      return;
    case check_functor_type_tag:
      obj_ptr = type_info::operator==(out_buffer->type.type, &void (__cdecl *)(char const *) `RTTI Type Descriptor')
              ? in_buffer
              : 0;
      goto LABEL_9;
  }
  out_buffer->obj_ptr = (void *)&void (__cdecl *)(char const *) `RTTI Type Descriptor';
  WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
}


void __usercall boost::detail::function::functor_manager<void (__cdecl *)(void)>::manager(
        const boost::detail::function::function_buffer *in_buffer@<edi>,
        boost::detail::function::function_buffer *out_buffer@<esi>,
        boost::detail::function::functor_manager_operation_type op@<eax>)
{
  const boost::detail::function::function_buffer *obj_ptr; // eax

  switch ( op )
  {
    case clone_functor_tag:
      obj_ptr = (const boost::detail::function::function_buffer *)in_buffer->obj_ptr;
LABEL_9:
      out_buffer->obj_ptr = (void *)obj_ptr;
      return;
    case move_functor_tag:
      out_buffer->obj_ptr = in_buffer->obj_ptr;
      in_buffer->obj_ptr = 0;
      return;
    case destroy_functor_tag:
      out_buffer->obj_ptr = 0;
      return;
    case check_functor_type_tag:
      obj_ptr = type_info::operator==(out_buffer->type.type, &void (__cdecl *)(void) `RTTI Type Descriptor')
              ? in_buffer
              : 0;
      goto LABEL_9;
  }
  out_buffer->obj_ptr = (void *)&void (__cdecl *)(void) `RTTI Type Descriptor';
  WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
}


void __usercall boost::detail::function::functor_manager<bool (__cdecl *)(void)>::manager(
        const boost::detail::function::function_buffer *in_buffer@<edi>,
        boost::detail::function::function_buffer *out_buffer@<esi>,
        boost::detail::function::functor_manager_operation_type op@<eax>)
{
  const boost::detail::function::function_buffer *obj_ptr; // eax

  switch ( op )
  {
    case clone_functor_tag:
      obj_ptr = (const boost::detail::function::function_buffer *)in_buffer->obj_ptr;
LABEL_9:
      out_buffer->obj_ptr = (void *)obj_ptr;
      return;
    case move_functor_tag:
      out_buffer->obj_ptr = in_buffer->obj_ptr;
      in_buffer->obj_ptr = 0;
      return;
    case destroy_functor_tag:
      out_buffer->obj_ptr = 0;
      return;
    case check_functor_type_tag:
      obj_ptr = type_info::operator==(out_buffer->type.type, &bool (__cdecl *)(void) `RTTI Type Descriptor')
              ? in_buffer
              : 0;
      goto LABEL_9;
  }
  out_buffer->obj_ptr = (void *)&bool (__cdecl *)(void) `RTTI Type Descriptor';
  WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
}
