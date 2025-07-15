survarium::anomaly_state *__fastcall survarium::generic_anomaly_core::select_state(
        survarium::generic_anomaly_core *this,
        int a2)
{
  survarium::anomaly_state *result; // eax
  int v3; // edi
  int v4; // esi
  int i; // [esp+10h] [ebp-4h]

  result = *(survarium::anomaly_state **)(a2 + 388);
  if ( !result || !result->m_finish_time_ms )
  {
    v3 = *(_DWORD *)(a2 + 376);
    for ( i = 0; ; ++i )
    {
      v4 = *(_DWORD *)(v3 + 4 * i);
      if ( *(_BYTE *)v4 && (!*(_BYTE *)(v4 + 13) || *(_BYTE *)(a2 + 392)) )
      {
        *(_BYTE *)(a2 + 392) = 0;
        if ( !*(_BYTE *)(v4 + 12) || *(_BYTE *)(a2 + 393) )
        {
          *(_BYTE *)(a2 + 393) = 0;
          if ( *(float *)(a2 + 332) >= (double)*(unsigned int *)(v4 + 8) )
            break;
        }
      }
    }
    return (survarium::anomaly_state *)v4;
  }
  return result;
}
