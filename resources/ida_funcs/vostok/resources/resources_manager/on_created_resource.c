void __usercall vostok::resources::resources_manager::on_created_resource(
        vostok::resources::resources_manager *this@<edi>,
        vostok::resources::query_result *query@<eax>,
        vostok::resources::query_result *a3@<ecx>)
{
  bool *v3; // [esp+0h] [ebp-4h]

  if ( query->m_create_resource_result == result_requery )
    vostok::resources::query_result::requery(a3);
  else
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)a3,
      (void (__usercall *)(const boost::detail::function::function_buffer *@<edi>, boost::detail::function::function_buffer *@<esi>, unsigned int@<eax>))((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *>>>>::manage_small + (_DWORD)this),
      query,
      v3);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
}
