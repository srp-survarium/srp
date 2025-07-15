void __cdecl boost::detail::function::void_function_obj_invoker0<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>,void>::invoke(
        boost::detail::function::function_buffer *function_ptr)
{
  function_ptr->func_ptr();
}


void __cdecl boost::detail::function::void_function_obj_invoker0<boost::_bi::bind_t<void,void (__cdecl *)(bool),boost::_bi::list1<boost::_bi::value<bool>>>,void>::invoke(
        boost::detail::function::function_buffer *function_obj_ptr)
{
  ((void (__cdecl *)(bool))function_obj_ptr->obj_ptr)(function_obj_ptr->type.const_qualified);
}
