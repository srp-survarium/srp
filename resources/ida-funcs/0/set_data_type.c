void __fastcall set_data_type(int a1, internal_state *s)
{
  int v2; // eax
  internal_state *v3; // ecx
  internal_state *i; // ecx

  v2 = 0;
  v3 = s + 37;
  do
  {
    if ( LOWORD(v3->dummy) )
      break;
    ++v2;
    ++v3;
  }
  while ( v2 < 9 );
  if ( v2 == 9 )
  {
    v2 = 14;
    for ( i = s + 52; !LOWORD(i[-1].dummy); i += 6 )
    {
      if ( LOWORD(i->dummy) )
      {
        *(_DWORD *)(s->dummy + 44) = v2 == 31;
        return;
      }
      if ( LOWORD(i[1].dummy) )
      {
        *(_DWORD *)(s->dummy + 44) = v2 == 30;
        return;
      }
      if ( LOWORD(i[2].dummy) )
      {
        *(_DWORD *)(s->dummy + 44) = v2 == 29;
        return;
      }
      if ( LOWORD(i[3].dummy) )
      {
        *(_DWORD *)(s->dummy + 44) = v2 == 28;
        return;
      }
      if ( LOWORD(i[4].dummy) )
      {
        v2 += 5;
        break;
      }
      v2 += 6;
      if ( v2 >= 32 )
      {
        *(_DWORD *)(s->dummy + 44) = v2 == 32;
        return;
      }
    }
  }
  *(_DWORD *)(s->dummy + 44) = v2 == 32;
}
