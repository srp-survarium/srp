void __usercall survarium::game_statistics_handler::recalculate_scores(
        survarium::game_statistics_handler *this@<ecx>,
        int a2@<esi>)
{
  _WORD *v2; // edi
  __int16 *v3; // ebx
  float v4; // xmm0_4
  survarium::game_statistics_handler *v5; // [esp+0h] [ebp-1Ch]
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *score; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *player; // [esp+17h] [ebp-5h]
  char v9; // [esp+1Bh] [ebp-1h]

  LOBYTE(player) = 0;
  while ( (_BYTE)player != *(_BYTE *)(a2 + 6248) )
  {
    score = 0;
    v2 = (_WORD *)(a2 + 2 * (unsigned __int8)player + 6168);
    v7 = 212 * (unsigned __int8)player + a2 + 8 - (*(_DWORD *)(a2 + 6244) + 29820);
    v9 = 0;
    v3 = (__int16 *)(*(_DWORD *)(a2 + 6244) + 29820);
    do
    {
      if ( v9 == 6 || v9 == 17 || v9 == 18 )
        v4 = FLOAT_0_0099999998;
      else
        v4 = s_bm_current_air_resistance;
      score = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)((char *)score + vostok::math::floor((float)((float)((float)*(unsigned __int16 *)((char *)v3 + v7) * (float)*v3) * v4) + 0.5));
      ++v9;
      ++v3;
    }
    while ( v9 != 21 );
    if ( (_WORD)score != *v2 )
    {
      *v2 = (_WORD)score;
      survarium::game_statistics_handler::emit_score_changed_event(v5, a2, player, score);
    }
    LOBYTE(player) = (_BYTE)player + 1;
  }
}
