void __thiscall survarium::player_params_modifiers_container::player_params_modifiers_container(
        survarium::player_params_modifiers_container *this,
        char *a2)
{
  vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v2; // esi
  int i; // edi

  v2 = (vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(a2 + 80);
  for ( i = 19; i >= 0; --i )
    vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(v2++);
  memset(a2, 0, 0x50u);
}
