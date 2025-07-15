void __userpurge vostok::render::texture_streaming_async_worker::start(
        const vostok::fixed_vector<vostok::render::streamable_texture_info,1024> *streaming_textures@<eax>,
        const vostok::math::float4x4 *projection_matrix@<edx>,
        vostok::render::texture_streaming_async_worker *this,
        const vostok::math::float3 *viewer_position,
        unsigned int screen_size_x,
        unsigned __int32 screen_size_y,
        char async)
{
  bool v7; // zf
  vostok::tasks::task_manager *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::texture_streaming_async_worker>,boost::_bi::list1<boost::_bi::value<vostok::render::texture_streaming_async_worker *> > > v10; // [esp-8h] [ebp-3Ch]
  int v11; // [esp+0h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::texture_streaming_async_worker>,boost::_bi::list1<boost::_bi::value<vostok::render::texture_streaming_async_worker *> > > v12[4]; // [esp+10h] [ebp-24h] BYREF

  this->m_streaming_textures = streaming_textures;
  _InterlockedExchangeAdd(&this->m_work_finished_counter, 1u);
  v7 = async == 0;
  qmemcpy(&this->m_projection_matrix, projection_matrix, sizeof(this->m_projection_matrix));
  this->m_viewer_position = *viewer_position;
  this->m_screen_size_x = screen_size_x;
  this->m_screen_size_y = screen_size_y;
  if ( v7 )
  {
    vostok::render::texture_streaming_async_worker::do_work(this);
  }
  else
  {
    this->m_task_spawned = 1;
    _InterlockedExchange((volatile __int32 *)&async, screen_size_y);
    v10.l_.a1_.t_ = this;
    v10.f_.f_ = vostok::render::texture_streaming_async_worker::do_work;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v12, v10, v11);
    vostok::tasks::task_manager::spawn_task(
      v8,
      (vostok::tasks::task *)v12,
      (boost::function<void __cdecl(void)> *)this->m_task_type,
      &this->m_parent_task);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)v12);
  }
}
