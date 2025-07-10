void __thiscall vostok::ai::ai_world::~ai_world(vostok::ai::ai_world *this)
{
  vostok::threading::mutex *v1; // ecx
  vostok::threading::mutex *v2; // ecx
  stlp_std::pair<char *,unsigned int> *mm; // [esp+8h] [ebp-44h]
  char **kk; // [esp+10h] [ebp-3Ch]
  char **jj; // [esp+18h] [ebp-34h]
  char **ii; // [esp+20h] [ebp-2Ch]
  char **n; // [esp+28h] [ebp-24h]
  char **m; // [esp+30h] [ebp-1Ch]
  char **k; // [esp+38h] [ebp-14h]
  char **j; // [esp+40h] [ebp-Ch]
  char **i; // [esp+48h] [ebp-4h]

  this->__vftable = (vostok::ai::ai_world_vtbl *)&vostok::ai::ai_world::`vftable';
  vostok::ai::ai_world::clear_dictionary(this);
  for ( i = this->m_energy_weapons.m_begin; i != this->m_energy_weapons.m_end; ++i )
    ;
  this->m_energy_weapons.m_end = this->m_energy_weapons.m_begin;
  for ( j = this->m_light_weapons.m_begin; j != this->m_light_weapons.m_end; ++j )
    ;
  this->m_light_weapons.m_end = this->m_light_weapons.m_begin;
  for ( k = this->m_heavy_weapons.m_begin; k != this->m_heavy_weapons.m_end; ++k )
    ;
  this->m_heavy_weapons.m_end = this->m_heavy_weapons.m_begin;
  for ( m = this->m_sniper_weapons.m_begin; m != this->m_sniper_weapons.m_end; ++m )
    ;
  this->m_sniper_weapons.m_end = this->m_sniper_weapons.m_begin;
  for ( n = this->m_melee_weapons.m_begin; n != this->m_melee_weapons.m_end; ++n )
    ;
  this->m_melee_weapons.m_end = this->m_melee_weapons.m_begin;
  for ( ii = this->m_npc_outfits.m_begin; ii != this->m_npc_outfits.m_end; ++ii )
    ;
  this->m_npc_outfits.m_end = this->m_npc_outfits.m_begin;
  for ( jj = this->m_npc_classes.m_begin; jj != this->m_npc_classes.m_end; ++jj )
    ;
  this->m_npc_classes.m_end = this->m_npc_classes.m_begin;
  for ( kk = this->m_npc_groups.m_begin; kk != this->m_npc_groups.m_end; ++kk )
    ;
  this->m_npc_groups.m_end = this->m_npc_groups.m_begin;
  for ( mm = this->m_npc_characters.m_begin; mm != this->m_npc_characters.m_end; ++mm )
    ;
  this->m_npc_characters.m_end = this->m_npc_characters.m_begin;
  vostok::ai::planning::search::~search(&this->m_search_service);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_brain_units.vostok::threading::mutex);
  vostok::threading::mutex::~mutex(
    v2,
    (_RTL_CRITICAL_SECTION *)&this->m_destruction_subscriptions_manager.m_subscribers.vostok::threading::mutex);
  stlp_std::priv::_Rb_tree<vostok::ai::npc *,stlp_std::less<vostok::ai::npc *>,stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::clear((stlp_std::priv::_Rb_tree<vostok::ai::npc *,stlp_std::less<vostok::ai::npc *>,stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> >,stlp_std::priv::_Select1st<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > >,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > > > *)&this->m_damage_subscriptions_manager);
  stlp_std::priv::_Rb_tree<vostok::ai::npc *,stlp_std::less<vostok::ai::npc *>,stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::clear(&this->m_sounds_subscriptions_manager.m_subscribers._M_t);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_sounds_subscriptions_manager);
}
