void __usercall survarium::stats_row::set_visible(survarium::stats_row *this@<ecx>, int *a2@<edi>)
{
  char v2; // bl
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  survarium::stats_stream *v8; // ecx
  int valuea; // [esp+Ch] [ebp-4h]

  v2 = s_show_network_statistics;
  LOBYTE(valuea) = s_show_network_statistics;
  if ( *((_BYTE *)a2 + 8) != s_show_network_statistics )
  {
    v3 = *a2;
    *((_BYTE *)a2 + 8) = s_show_network_statistics;
    (*(void (__thiscall **)(int, bool))(*(_DWORD *)v3 + 152))(v3, s_show_network_statistics);
    this = (survarium::stats_row *)a2[1];
    LOBYTE(this->caption.owner) = 1;
  }
  if ( *((_BYTE *)a2 + 20) != v2 )
  {
    v4 = a2[3];
    *((_BYTE *)a2 + 20) = v2;
    (*(void (__thiscall **)(int, _BYTE))(*(_DWORD *)v4 + 152))(v4, valuea);
    this = (survarium::stats_row *)a2[4];
    LOBYTE(this->caption.owner) = 1;
  }
  if ( *((_BYTE *)a2 + 32) != v2 )
  {
    v5 = a2[6];
    *((_BYTE *)a2 + 32) = v2;
    (*(void (__thiscall **)(int, _BYTE))(*(_DWORD *)v5 + 152))(v5, valuea);
    this = (survarium::stats_row *)a2[7];
    LOBYTE(this->caption.owner) = 1;
  }
  if ( *((_BYTE *)a2 + 44) != v2 )
  {
    v6 = a2[9];
    *((_BYTE *)a2 + 44) = v2;
    (*(void (__thiscall **)(int, _BYTE))(*(_DWORD *)v6 + 152))(v6, valuea);
    this = (survarium::stats_row *)a2[10];
    LOBYTE(this->caption.owner) = 1;
  }
  if ( *((_BYTE *)a2 + 56) != v2 )
  {
    v7 = a2[12];
    *((_BYTE *)a2 + 56) = v2;
    (*(void (__thiscall **)(int, _BYTE))(*(_DWORD *)v7 + 152))(v7, valuea);
    this = (survarium::stats_row *)a2[13];
    LOBYTE(this->caption.owner) = 1;
  }
  survarium::stats_stream::set_visible((survarium::stats_stream *)this, a2 + 15, valuea);
  survarium::stats_stream::set_visible(v8, a2 + 30, valuea);
}
