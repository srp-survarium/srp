void __thiscall vostok::tasks::thread_pool::initialize(
        vostok::tasks::thread_pool *this,
        vostok::tasks::thread_pool *a2)
{
  int v2; // ecx
  unsigned int v3; // edi
  vostok::buffer_string *v4; // ecx
  vostok::tasks::thread_tls *v5; // esi
  void *v6; // ecx
  unsigned int v7; // eax
  vostok::particle::particle_action *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  vostok::timing::timer *v10; // ecx
  unsigned int v11; // edi
  int v12; // esi
  const char *v13[3]; // [esp+10h] [ebp-464h] BYREF
  _BYTE v14[512]; // [esp+1Ch] [ebp-458h] BYREF
  char v15; // [esp+21Ch] [ebp-258h] BYREF
  vostok::buffer_string v16; // [esp+220h] [ebp-254h] BYREF
  _BYTE v17[512]; // [esp+22Ch] [ebp-248h] BYREF
  char v18; // [esp+42Ch] [ebp-48h] BYREF
  boost::function<void __cdecl(void)> v19; // [esp+430h] [ebp-44h] BYREF
  vostok::tasks::thread_tls *v20; // [esp+450h] [ebp-24h]
  vostok::tasks::thread_tls *v21; // [esp+454h] [ebp-20h]
  __int64 v22; // [esp+458h] [ebp-1Ch]
  unsigned int v23; // [esp+460h] [ebp-14h]
  const char *v24; // [esp+464h] [ebp-10h]
  unsigned int v25; // [esp+468h] [ebp-Ch]
  char v26; // [esp+46Fh] [ebp-5h]

  v2 = 360;
  v3 = 0;
  v23 = a2->m_task_thread_tls.m_end - a2->m_task_thread_tls.m_begin;
  if ( v23 )
  {
    v25 = 0;
    do
    {
      v13[0] = v14;
      v13[1] = v14;
      v13[2] = &v15;
      v24 = (const char *)(v3 + 1);
      v14[0] = 0;
      vostok::fs_new::path_string_impl::assignf(
        v13,
        (vostok::buffer_string *)v2,
        (vostok::buffer_string *)"task #%d",
        (const char *)(v3 + 1));
      v16.m_begin = v17;
      v16.m_end = v17;
      v16.m_max_end = &v18;
      v17[0] = 0;
      vostok::fs_new::path_string_impl::assignf(&v16, v4, (vostok::buffer_string *)"task #%d", v24);
      v5 = &a2->m_task_thread_tls.m_begin[v25 / 0x168];
      v5->pool = a2;
      v5->thread_index = v3;
      v7 = vostok::threading::core_count(v6);
      v5->thread_type = type_task_thread;
      v5->hardware_thread = v3 % v7;
      v5->state = 1;
      vostok::buffer_string::operator=(&v16, &v5->thread_name);
      LODWORD(v22) = vostok::tasks::thread_tls::thread_proc;
      v21 = v5;
      v20 = v5;
      HIDWORD(v22) = v5;
      if ( Scaleform::Render::RenderEvent::GetListenerStatus(v8) )
      {
        v19.vtable = 0;
      }
      else
      {
        v26 = 0;
        *(_QWORD *)&v19.functor.obj_ptr = v22;
        v19.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::tasks::thread_tls>,boost::_bi::list1<boost::_bi::value<vostok::tasks::thread_tls *>>>>'::`2'::stored_vtable
                                                            + 1);
      }
      v5->thread_id = vostok::threading::spawn(&v19, v16.m_begin, v13[0], v5->hardware_thread, 0);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v9,
        (int *)&v19);
      v3 = (unsigned int)v24;
      v25 += 360;
    }
    while ( (unsigned int)v24 < v23 );
  }
  vostok::tasks::thread_pool::log_columns_header(a2);
  vostok::timing::timer::start(v10, (LARGE_INTEGER *)&a2->m_timer);
  v11 = v23;
  if ( v23 )
  {
    v12 = 0;
    do
    {
      SetEvent(*(HANDLE *)a2->m_task_thread_tls.m_begin[v12++].event_start_thread_work.m_event);
      --v11;
    }
    while ( v11 );
  }
  WaitForSingleObject(*(HANDLE *)a2->m_all_task_threads_started.m_event, 0xFFFFFFFF);
  a2->m_initialized = 1;
}
