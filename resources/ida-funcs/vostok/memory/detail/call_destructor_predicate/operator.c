void __usercall vostok::memory::detail::call_destructor_predicate::operator()<vostok::physics::bt_ghost_object>(
        vostok::physics::bt_ghost_object *const pointer@<eax>)
{
  btPairCachingGhostObject *m_bt_object; // eax
  vostok::memory::base_allocator *v3; // edi
  _BYTE *v4; // ebx
  vostok::physics::loose_ptr_base *v5; // ecx

  pointer->__vftable = (vostok::physics::bt_ghost_object_vtbl *)&vostok::physics::bt_ghost_object::`vftable';
  m_bt_object = pointer->m_bt_object;
  v3 = vostok::physics::g_allocator;
  if ( m_bt_object )
  {
    v4 = __RTCastToVoid((void **)&m_bt_object->__vftable);
    ((void (__thiscall *)(btPairCachingGhostObject *, _DWORD))pointer->m_bt_object->~btPairCachingGhostObject)(
      pointer->m_bt_object,
      0);
    v3->call_free(v3, v4, "vostok::physics::bt_ghost_object::~bt_ghost_object", ".\\ghost_object.cpp", 29u);
    pointer->m_bt_object = 0;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&pointer->m_shape);
  vostok::physics::loose_ptr_base::~loose_ptr_base(v5, &pointer->vostok::physics::loose_ptr_base_a);
}


void __userpurge vostok::memory::detail::call_destructor_predicate::operator()<vostok::network_core::http_client>(
        vostok::network_core::http_client *const pointer@<edi>,
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *a2@<ecx>,
        vostok::memory::detail::call_destructor_predicate *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::asio::basic_streambuf<stlp_std::allocator<char> > *v4; // ecx
  boost::asio::basic_streambuf<stlp_std::allocator<char> > *v5; // ecx
  boost::asio::basic_datagram_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *v6; // ecx
  boost::shared_ptr<void> *v7; // ecx

  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    a2,
    (int *)&pointer->m_on_error);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&pointer->m_on_content_downloaded);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&pointer->m_result_content);
  boost::asio::basic_streambuf<stlp_std::allocator<char>>::~basic_streambuf<stlp_std::allocator<char>>(
    v4,
    (int)&pointer->m_response_buff);
  boost::asio::basic_streambuf<stlp_std::allocator<char>>::~basic_streambuf<stlp_std::allocator<char>>(
    v5,
    (int)&pointer->m_request_buff);
  boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::~basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    v6,
    (int)&pointer->m_socket);
  boost::shared_ptr<void>::reset(v7, &pointer->m_resolver.implementation.px);
  JUMPOUT(0x26D36);
}


void __usercall vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::lights_db>(
        vostok::render::lights_db *const pointer@<edi>,
        vostok::render::light *a2@<ecx>)
{
  int *m_begin; // esi
  vostok::render::light_data **p_m_end; // ebx
  vostok::collision::space_partitioning_tree *m_lights_tree; // ecx
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+4h] [ebp-8h]
  unsigned int v7; // [esp+8h] [ebp-4h]

  m_begin = (int *)pointer->m_lights.m_begin;
  p_m_end = &pointer->m_lights.m_end;
  while ( m_begin != (int *)*p_m_end )
  {
    vostok::render::light::remove_collision(a2, *m_begin);
    m_begin += 2;
  }
  m_lights_tree = pointer->m_lights_tree;
  if ( m_lights_tree )
    ((void (__thiscall *)(vostok::collision::space_partitioning_tree *, _DWORD))m_lights_tree->~vostok::collision::space_partitioning_tree)(
      m_lights_tree,
      0);
  if ( pointer->m_lights_tree )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)m_lights_tree,
      (int)vostok::render::g_allocator,
      (char *)pointer->m_lights_tree,
      v5,
      v6,
      v7);
    pointer->m_lights_tree = 0;
  }
  vostok::buffer_vector<vostok::render::light_data>::destroy(pointer->m_lights.m_begin, &pointer->m_lights.m_end);
  *p_m_end = pointer->m_lights.m_begin;
}


void __usercall vostok::memory::detail::call_destructor_predicate::operator()<vostok::network::login_client_impl>(
        vostok::network::login_client_impl *const pointer@<eax>,
        vostok::network::login_client_impl *a2@<ecx>)
{
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *v3; // ecx
  boost::asio::basic_datagram_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *v4; // ecx
  boost::asio::ssl::detail::stream_core *v5; // ecx
  boost::asio::ssl::context *v6; // ecx
  boost::asio::basic_datagram_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *v7; // ecx

  pointer->m_in_destructor = 1;
  vostok::network::login_client_impl::close_connection(a2, (int)pointer, 1);
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::~basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    v3,
    (int *)&pointer->m_ping_timer);
  boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::~basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    v4,
    (int)&pointer->m_ping_socket);
  boost::asio::ssl::detail::stream_core::~stream_core(v5, (int)&pointer->m_ssl_stream.core_);
  boost::asio::ssl::context::~context(v6, (int)&pointer->m_ssl_context);
  boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::~basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    v7,
    (int)pointer);
}


void __usercall vostok::memory::detail::call_destructor_predicate::operator()<vostok::sound::sound_buffer_factory>(
        vostok::sound::sound_buffer_factory *const pointer@<eax>,
        boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > *a2@<ecx>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  vostok::sound::sound_buffer *i; // edi
  vostok::sound::sound_buffer *v5; // ebx
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > *v6; // ecx
  boost::intrusive::set<vostok::sound::sound_buffer,boost::intrusive::compare<vostok::sound::sound_buffer_compare_predicate>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> *p_m_cached_sound_buffers; // [esp+8h] [ebp-8h]

  p_m_cached_sound_buffers = &pointer->m_cached_sound_buffers;
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>::clear_and_dispose<boost::intrusive::detail::null_disposer>(
    a2,
    &pointer->m_cached_sound_buffers.tree_.data_.node_plus_pred_.header_plus_size_.size_,
    0);
  for ( i = pointer->m_lru_sound_buffers.m_first; i; --pointer->m_sound_buffers_allocator.m_allocated_count )
  {
    v5 = i;
    i = i->m_next;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v5->m_encoded_sound);
    v5->parent_ = (boost::intrusive::rbtree_node<void *> *)pointer->m_sound_buffers_allocator.m_free_list_head.pointer;
    pointer->m_sound_buffers_allocator.m_free_list_head.pointer = (vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>::node *)v5;
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&pointer->m_sound_buffers_allocator);
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>::clear_and_dispose<boost::intrusive::detail::null_disposer>(
    v6,
    p_m_cached_sound_buffers,
    0);
}


void __usercall vostok::memory::detail::call_destructor_predicate::operator()<survarium::stats_graph>(
        survarium::stats_graph *const pointer@<edi>)
{
  unsigned int i; // ebx
  char *m_newest_value; // eax
  survarium::stats_graph::stats_value *next; // ecx
  survarium::stats_graph::stats_value *m_values_pool; // eax
  survarium::stats_graph::stats_value *v5; // ecx
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+4h] [ebp-8h]
  unsigned int v8; // [esp+8h] [ebp-4h]

  for ( i = 0; i < pointer->m_count; ++i )
  {
    m_newest_value = (char *)pointer->m_newest_value;
    next = pointer->m_newest_value->next;
    pointer->m_newest_value = next;
    if ( m_newest_value )
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)next,
        (int)survarium::g_allocator,
        m_newest_value,
        v6,
        v7,
        v8);
  }
  while ( pointer->m_values_pool )
  {
    m_values_pool = pointer->m_values_pool;
    v5 = m_values_pool->next;
    pointer->m_values_pool = m_values_pool->next;
    if ( m_values_pool )
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)v5,
        (int)survarium::g_allocator,
        (char *)m_values_pool,
        v6,
        v7,
        v8);
  }
}


void __thiscall vostok::memory::detail::call_destructor_predicate::operator()<vostok::sound::voice_factory>(
        vostok::memory::detail::call_destructor_predicate *this,
        vostok::sound::voice_factory *const pointer)
{
  unsigned int v2; // ebp
  vostok::sound::voice_bridge **m_mono_voices; // edi
  unsigned int v4; // ebp
  vostok::sound::voice_bridge **m_stereo_voices; // edi

  v2 = 0;
  if ( pointer->m_pool_params.mono_voices_count )
  {
    m_mono_voices = pointer->m_mono_voices;
    do
    {
      vostok::memory::delete_helper<vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>,vostok::sound::voice_bridge>(
        &pointer->m_voices_allocator,
        m_mono_voices);
      ++v2;
      ++m_mono_voices;
    }
    while ( v2 < pointer->m_pool_params.mono_voices_count );
  }
  v4 = 0;
  if ( pointer->m_pool_params.stereo_voices_count )
  {
    m_stereo_voices = pointer->m_stereo_voices;
    do
    {
      vostok::memory::delete_helper<vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>,vostok::sound::voice_bridge>(
        &pointer->m_voices_allocator,
        m_stereo_voices);
      ++v4;
      ++m_stereo_voices;
    }
    while ( v4 < pointer->m_pool_params.stereo_voices_count );
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&pointer->m_voices_allocator);
}
