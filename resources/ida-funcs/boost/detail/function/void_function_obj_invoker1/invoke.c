void __cdecl boost::detail::function::void_function_obj_invoker1<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>,void,char const *>::invoke(
        boost::detail::function::function_buffer *function_obj_ptr,
        const char *a0)
{
  vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate> v2; // [esp+0h] [ebp-4h] BYREF

  boost::_bi::list1<vostok::fs_new::synchronous_device_interface &>::list1<vostok::fs_new::synchronous_device_interface &>(
    &v2,
    (vostok::sound::compare_receivers_predicate *)&a0);
  function_obj_ptr->func_ptr();
}
