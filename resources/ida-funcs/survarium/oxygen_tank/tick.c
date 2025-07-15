void __thiscall survarium::oxygen_tank::tick(
        survarium::oxygen_tank *this,
        const unsigned int time_delta_ms,
        const unsigned int current_time_ms)
{
  int v4; // edx
  bool v5; // zf

  if ( !*(_BYTE *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this[-1].m_amount_ms + 376) + 12))(*(_DWORD *)(this[-1].m_amount_ms + 376))
                 + 764)
    || (v4 = time_delta_ms
           + (LODWORD(this->m_reconstruction_info_actuality_tick) < time_delta_ms
            ? LODWORD(this->m_reconstruction_info_actuality_tick) - time_delta_ms
            : 0),
        v5 = LODWORD(this->m_reconstruction_info_actuality_tick) == v4,
        LODWORD(this->m_reconstruction_info_actuality_tick) -= v4,
        v5) )
  {
    survarium::oxygen_tank::set_active((survarium::oxygen_tank *)((char *)this - 288), 0);
  }
}
