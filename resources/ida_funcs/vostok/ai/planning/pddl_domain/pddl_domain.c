void __thiscall vostok::ai::planning::pddl_domain::pddl_domain(vostok::ai::planning::pddl_domain *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  stlp_std::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>(&this->m_registered_types);
  stlp_std::map<unsigned int,vostok::ai::planning::pddl_predicate *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::pddl_predicate *>>>::map<unsigned int,vostok::ai::planning::pddl_predicate *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::pddl_predicate *>>>((stlp_std::map<unsigned int,vostok::ai::planning::oracle *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::oracle *> > > *)&this->m_predicates);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_actions,
    &this->m_actions.m_size);
  survarium::weapon_user_dead_state::finalize(v1);
  this->m_actions.m_first = 0;
  this->m_actions.m_last = 0;
}
