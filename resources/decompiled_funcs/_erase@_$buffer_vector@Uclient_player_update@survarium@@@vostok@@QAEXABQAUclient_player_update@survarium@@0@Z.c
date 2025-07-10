void __thiscall vostok::buffer_vector<survarium::client_player_update>::erase(
        vostok::buffer_vector<survarium::client_player_update> *this,
        vostok::buffer_vector<survarium::client_player_update> *begin,
        survarium::client_player_update *const *end,
        survarium::client_player_update *const *enda)
{
  unsigned int v4; // edx
  survarium::client_player_update *v5; // eax

  v4 = (unsigned int)*end;
  v5 = *enda;
  if ( *end != *enda )
  {
    for ( ; v5 != begin->m_end; v4 += 92 )
    {
      if ( v4 )
      {
        *(float *)v4 = v5->input.angular_velocity.x;
        *(float *)(v4 + 4) = v5->input.angular_velocity.y;
        *(float *)(v4 + 8) = v5->input.angular_acceleration.x;
        *(float *)(v4 + 12) = v5->input.angular_acceleration.y;
        *(_DWORD *)(v4 + 16) = v5->input.actions_mask;
        qmemcpy((void *)(v4 + 20), &v5->state, 0x48u);
      }
      ++v5;
    }
    begin->m_end = &begin->m_begin[begin->m_end - begin->m_begin - (*enda - *end)];
  }
}
