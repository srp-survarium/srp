void __usercall vostok::resources::queries_result::call_user_callback(
        vostok::resources::queries_result *this@<ecx>,
        char *a2@<edi>)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::thread_local_data *thread_local_data; // esi
  boost::function1<void,char const *> *v5; // ecx

  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v3,
                        vostok::resources::g_resources_manager.m_variable,
                        CurrentThreadId,
                        1);
  ++thread_local_data->disable_translate_query_counter_check;
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(v5, a2, a2);
  --thread_local_data->disable_translate_query_counter_check;
}
