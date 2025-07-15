void __thiscall vostok::ai::working_memory::working_memory(
        vostok::ai::working_memory *this,
        unsigned int objects_count,
        vostok::ai::ai_world *world)
{
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > f; // [esp+38h] [ebp-30h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+40h] [ebp-28h] BYREF
  boost::function1<void,vostok::ai::game_object const &> v8; // [esp+48h] [ebp-20h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  `vector constructor iterator'(
    (char *)this,
    0x30u,
    6,
    (void *(__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
  f = *boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
         (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
         (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::ai::working_memory::forget_all_about_object,
         (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &v8);
  boost::function1<void,vostok::ai::game_object const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1>>>>(
    &v8,
    f);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_subscription);
  boost::function1<void,bool>::function1<void,bool>(
    (boost::function1<void,bool> *)&this->m_subscription,
    (const boost::function1<void,bool> *)&v8);
  this->m_subscription.m_next = 0;
  boost::function1<void,vostok::ai::game_object const &>::clear(&v8);
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_memory = vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(v4, 44 * objects_count);
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>(
    &this->m_allocator,
    (vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *)this->m_memory,
    44 * objects_count);
  this->m_world = world;
  vostok::intrusive_list<vostok::ai::game_object_subscriber,vostok::ai::game_object_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back_unique(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_world->m_destruction_subscriptions_manager,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_subscription,
    0);
}
