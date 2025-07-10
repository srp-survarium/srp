void __thiscall survarium::base_player::on_player_death(survarium::base_player *this)
{
  vostok::intrusive_list<survarium::player_death_subscriber,survarium::player_death_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::void_predicate_ref<void __cdecl(survarium::player_death_subscriber const *)> pred; // [esp+10h] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = (void (__cdecl *)(const survarium::player_death_subscriber *))survarium::call_player_death_subscriber_callback;
  vostok::intrusive_list<survarium::player_death_subscriber,survarium::player_death_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::player_death_subscriber,survarium::player_death_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::void_predicate_ref<void __cdecl (survarium::player_death_subscriber const *)>>(
    &this->m_player_death_subscribers,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
}
