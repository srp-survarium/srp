void __usercall vostok::animation::animation_player::clear_callbacks(
        vostok::animation::animation_player *this@<ecx>,
        _DWORD *a2@<eax>)
{
  _DWORD *v3; // esi

  v3 = a2 + 16434;
  vostok::animation::animation_player::destroy_subscriptions((const vostok::animation::subscribed_channel *)a2[16434]);
  *v3 = 0;
  if ( a2 != (_DWORD *)-65740 )
  {
    a2[16435] = a2 + 16438;
    a2[16436] = 2560;
  }
}
