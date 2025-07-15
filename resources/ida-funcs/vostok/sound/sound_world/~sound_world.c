void __usercall vostok::sound::sound_world::~sound_world(vostok::sound::sound_world *this@<ecx>, char *a2@<ebx>)
{
  vostok::sound::sound_world *v2; // edi
  vostok::sound::sound_order *m_tail; // eax
  vostok::sound::sound_order *m_next_for_orders; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  vostok::sound::voice_factory *m_voice_factory; // ebx
  vostok::memory::doug_lea_allocator *v7; // ecx
  vostok::sound::sound_buffer_factory *m_sound_buffer_factory; // esi
  vostok::memory::doug_lea_allocator *v9; // ecx
  IXAudio2MasteringVoice *m_master_voice; // eax
  unsigned int m_head; // eax
  vostok::sound::sound_world *v12; // [esp-4h] [ebp-10h]
  char *v13; // [esp-4h] [ebp-10h]
  const char *v14; // [esp-4h] [ebp-10h]
  const char *v15; // [esp+0h] [ebp-Ch]
  const char *v16; // [esp+4h] [ebp-8h]
  vostok::sound::sound_order *pointer; // [esp+8h] [ebp-4h] BYREF

  v2 = this;
  this->__vftable = (vostok::sound::sound_world_vtbl *)&vostok::sound::sound_world::`vftable';
  while ( 1 )
  {
    m_tail = v2->m_xaudio_callback_orders.m_tail;
    if ( !m_tail->m_next_for_orders )
      break;
    m_next_for_orders = m_tail->m_next_for_orders;
    if ( m_next_for_orders )
    {
      pointer = v2->m_xaudio_callback_orders.m_tail;
      v2->m_xaudio_callback_orders.m_tail = m_next_for_orders;
    }
    m_next_for_orders->execute(m_next_for_orders);
    vostok::memory::delete_helper<vostok::memory::pthreads3_allocator,vostok::sound::sound_order>(
      &vostok::memory::g_mt_allocator,
      &pointer,
      v15,
      v16,
      (const unsigned int)pointer);
    this = v12;
  }
  v5 = vostok::sound::g_allocator;
  v13 = a2;
  m_voice_factory = v2->m_voice_factory;
  if ( m_voice_factory )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<vostok::sound::voice_factory>(
      (vostok::memory::detail::call_destructor_predicate *)this,
      v2->m_voice_factory);
    vostok::memory::doug_lea_allocator::free_impl(v7, (int)v5, m_voice_factory, v13, v15, (const unsigned int)v16);
    v2->m_voice_factory = 0;
  }
  m_sound_buffer_factory = v2->m_sound_buffer_factory;
  pointer = (vostok::sound::sound_order *)vostok::sound::g_allocator;
  if ( m_sound_buffer_factory )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<vostok::sound::sound_buffer_factory>(
      m_sound_buffer_factory,
      (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > *)this,
      (vostok::memory::detail::call_destructor_predicate *)v13);
    vostok::memory::doug_lea_allocator::free_impl(
      v9,
      (int)pointer,
      m_sound_buffer_factory,
      v14,
      v15,
      (const unsigned int)v16);
    v2->m_sound_buffer_factory = 0;
  }
  m_master_voice = v2->m_master_voice;
  if ( m_master_voice )
    m_master_voice->DestroyVoice(v2->m_master_voice);
  v2->m_xaudio->Release(v2->m_xaudio);
  m_head = (unsigned int)v2->m_xaudio_callback_orders.m_head;
  v2->m_xaudio_callback_orders.m_tail = 0;
  v2->m_xaudio_callback_orders.m_head = 0;
  vostok::memory::delete_helper<vostok::memory::pthreads3_allocator,vostok::sound::sound_order>(
    &vostok::memory::g_mt_allocator,
    &pointer,
    v15,
    v16,
    m_head);
  v2->m_panning_lut.__vftable = (vostok::sound::panning_lut_vtbl *)&vostok::sound::panning_lut::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2->m_unmanaged_resources_ptr);
  v2->__vftable = (vostok::sound::sound_world_vtbl *)&vostok::sound::world::`vftable';
}
