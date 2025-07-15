void __cdecl vostok::animation::animation_player::destroy_subscriptions(
        const vostok::animation::subscribed_channel *channels_head)
{
  const vostok::animation::subscribed_channel *i; // ebx
  vostok::animation::animation_callback *first_callback; // edi
  vostok::animation::animation_callback *v3; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx

  for ( i = channels_head; i; i = i->next )
  {
    first_callback = i->first_callback;
    while ( first_callback )
    {
      v3 = first_callback;
      first_callback = first_callback->next;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v3->animation);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v4,
        (int *)v3);
    }
  }
}
