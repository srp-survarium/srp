void __thiscall vostok::ai::ai_world::ai_world(vostok::ai::ai_world *this, vostok::ai::engine *engine)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_sounds_subscriptions_manager);
  this->__vftable = (vostok::ai::ai_world_vtbl *)&vostok::ai::ai_world::`vftable';
  stlp_std::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>((stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *)&this->m_sounds_subscriptions_manager);
  stlp_std::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>((stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *)&this->m_damage_subscriptions_manager);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v2,
    &this->m_destruction_subscriptions_manager.m_subscribers.m_size);
  vostok::threading::mutex::mutex(&this->m_destruction_subscriptions_manager.m_subscribers.vostok::threading::mutex);
  this->m_destruction_subscriptions_manager.m_subscribers.m_first = 0;
  this->m_destruction_subscriptions_manager.m_subscribers.m_last = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_destruction_subscriptions_manager,
    &this->m_brain_units.m_size);
  vostok::threading::mutex::mutex(&this->m_brain_units.vostok::threading::mutex);
  this->m_brain_units.m_first = 0;
  this->m_brain_units.m_last = 0;
  vostok::ai::planning::search::search(&this->m_search_service);
  this->m_engine = engine;
  vostok::fixed_vector<vostok::console_commands::command_token,12>::fixed_vector<vostok::console_commands::command_token,12>(&this->m_npc_characters);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_npc_groups);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_npc_classes);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_npc_outfits);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_melee_weapons);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_sniper_weapons);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_heavy_weapons);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_light_weapons);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_energy_weapons);
  vostok::ai::ai_world::register_cooks(this);
}
