void __thiscall survarium::game_effect_player::tick(
        survarium::game_effect_player *this,
        unsigned int *current_time_in_ms,
        unsigned int a3)
{
  unsigned int *v3; // edi
  unsigned int v4; // ebx
  unsigned int v5; // edi
  const std::exception *v6; // eax
  int v7; // eax
  float v8; // xmm0_4
  float v9; // [esp+10h] [ebp-134h]
  float v10; // [esp+10h] [ebp-134h]
  float v11; // [esp+18h] [ebp-12Ch]
  int v12; // [esp+1Ch] [ebp-128h]
  float v13; // [esp+20h] [ebp-124h]
  int v14; // [esp+24h] [ebp-120h]
  _BYTE v15[12]; // [esp+28h] [ebp-11Ch] BYREF
  stlp_std::out_of_range v16; // [esp+34h] [ebp-110h] BYREF

  v3 = current_time_in_ms;
  if ( *current_time_in_ms == -1 )
    *current_time_in_ms = a3;
  if ( a3 >= *current_time_in_ms )
  {
    v4 = current_time_in_ms[11];
    while ( v4 )
    {
      v5 = *v3;
      if ( !*(_DWORD *)(v4 + 56) )
      {
        boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v16);
        boost::throw_exception(v6);
        stlp_std::__Named_exception::~__Named_exception(&v16);
      }
      v7 = (*(int (__cdecl **)(_BYTE *, unsigned int, unsigned int, unsigned int, unsigned int))((*(_DWORD *)(v4 + 56)
                                                                                                & 0xFFFFFFFE)
                                                                                               + 4))(
             v15,
             v4 + 64,
             v4,
             v5,
             a3);
      this = *(survarium::game_effect_player **)(v4 + 4);
      v12 = *(_DWORD *)v7;
      v13 = *(float *)(v7 + 4);
      v14 = *(_DWORD *)(v7 + 8);
      *(_DWORD *)(v4 + 24) = *(_DWORD *)v7;
      *(float *)(v4 + 28) = v13;
      *(float *)(v4 + 32) = *((float *)&this->m_current_time_in_ms + 4 * v12) + v13;
      if ( (_BYTE)v14 )
      {
        *(float *)(v4 + 36) = *(float *)(v4 + 40);
        *(_DWORD *)(v4 + 44) = 0;
        *(_DWORD *)(v4 + 20) = a3;
      }
      if ( *(float *)(v4 + 40) != *(float *)(v4 + 44) )
      {
        v11 = (double)(a3 - *(_DWORD *)(v4 + 20)) * 0.001;
        v9 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(v4 + 12) + 16))(*(_DWORD *)(v4 + 12));
        if ( v9 <= (double)v11 )
          v8 = v9;
        else
          v8 = v11;
        v10 = ((double (__stdcall *)(_DWORD))***(_DWORD ***)(v4 + 12))(LODWORD(v8));
        *(float *)(v4 + 40) = (float)((float)(*(float *)(v4 + 44) - *(float *)(v4 + 36)) * v10) + *(float *)(v4 + 36);
      }
      v4 = *(_DWORD *)(v4 + 88);
      v3 = current_time_in_ms;
    }
    vostok::intrusive_list<survarium::game_effect_node,survarium::game_effect_node *,88,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::remove_if<survarium::game_effect_transited_to_zero_predicate>(
      (vostok::intrusive_list<survarium::game_effect_node,survarium::game_effect_node *,88,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
      (int)(v3 + 2));
    *v3 = a3;
  }
}
