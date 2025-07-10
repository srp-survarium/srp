char __usercall vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::resources_manager *m_variable; // edi
  bool *v4; // [esp+0h] [ebp-Ch]

  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 712), 0xFFFFFFFF) )
    return 0;
  m_variable = vostok::resources::g_resources_manager.m_variable;
  if ( *(_DWORD *)(a2 + 260) == 4 )
    vostok::resources::query_result::requery(0, a2);
  else
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      0,
      (void (__usercall *)(const boost::detail::function::function_buffer *@<edi>, boost::detail::function::function_buffer *@<esi>, unsigned int@<eax>))((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *>>>>::manage_small + (unsigned int)vostok::resources::g_resources_manager.m_variable),
      (vostok::resources::query_result *)a2,
      v4);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)m_variable));
  return 1;
}
