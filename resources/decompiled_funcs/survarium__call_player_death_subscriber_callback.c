void __cdecl survarium::call_player_death_subscriber_callback(
        const survarium::player_death_subscriber *const subscriber)
{
  boost::function0<void>::operator()(&subscriber->subscription_callback);
}
