void __usercall survarium::client_player_state::~client_player_state(
        survarium::client_player_state *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  vostok::animation::mixing::n_ary_tree *v4; // ecx
  _DWORD *v5; // esi

  v3 = *(_DWORD *)(a2 + 34248);
  if ( v3 )
  {
    this = (survarium::client_player_state *)_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 34248) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 34248));
  }
  vostok::animation::animation_player::reset(&this->animation_player, a2);
  vostok::animation::mixing::n_ary_tree::destroy(v4);
  v5 = *(_DWORD **)(a2 + 34048);
  if ( v5 )
    --*v5;
}
