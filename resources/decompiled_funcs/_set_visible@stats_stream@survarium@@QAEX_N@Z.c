void __userpurge survarium::stats_stream::set_visible(survarium::stats_stream *this@<ecx>, int *a2@<esi>, int value)
{
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx

  if ( *((_BYTE *)a2 + 8) != (_BYTE)value )
  {
    v3 = *a2;
    *((_BYTE *)a2 + 8) = value;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 152))(v3, value);
    *(_BYTE *)(a2[1] + 4) = 1;
  }
  if ( *((_BYTE *)a2 + 20) != (_BYTE)value )
  {
    v4 = a2[3];
    *((_BYTE *)a2 + 20) = value;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 152))(v4, value);
    *(_BYTE *)(a2[4] + 4) = 1;
  }
  if ( *((_BYTE *)a2 + 32) != (_BYTE)value )
  {
    v5 = a2[6];
    *((_BYTE *)a2 + 32) = value;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 152))(v5, value);
    *(_BYTE *)(a2[7] + 4) = 1;
  }
  if ( *((_BYTE *)a2 + 44) != (_BYTE)value )
  {
    v6 = a2[9];
    *((_BYTE *)a2 + 44) = value;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 152))(v6, value);
    *(_BYTE *)(a2[10] + 4) = 1;
  }
}
