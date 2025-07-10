void __usercall boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>::manage_small(
        const boost::detail::function::function_buffer *in_buffer@<edi>,
        boost::detail::function::function_buffer *out_buffer@<esi>,
        unsigned int op@<eax>)
{
  if ( op < 2 )
  {
    if ( out_buffer )
      *(_QWORD *)&out_buffer->obj_ptr = *(_QWORD *)&in_buffer->obj_ptr;
  }
  else if ( op != 2 )
  {
    if ( op == 3 )
    {
      out_buffer->obj_ptr = type_info::operator==(
                              out_buffer->type.type,
                              &boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0> `RTTI Type Descriptor')
                          ? (void *)in_buffer
                          : 0;
    }
    else
    {
      out_buffer->obj_ptr = (void *)&boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0> `RTTI Type Descriptor';
      WORD2(out_buffer->bound_memfunc_ptr.memfunc_ptr) = 0;
    }
  }
}
