void __fastcall init_block(int a1, internal_state *s)
{
  internal_state *v2; // eax
  int v3; // ecx
  internal_state *v4; // eax
  int v5; // ecx
  internal_state *v6; // eax
  int v7; // ecx

  v2 = s + 37;
  v3 = 286;
  do
  {
    LOWORD(v2->dummy) = 0;
    ++v2;
    --v3;
  }
  while ( v3 );
  v4 = s + 610;
  v5 = 30;
  do
  {
    LOWORD(v4->dummy) = 0;
    ++v4;
    --v5;
  }
  while ( v5 );
  v6 = s + 671;
  v7 = 19;
  do
  {
    LOWORD(v6->dummy) = 0;
    ++v6;
    --v7;
  }
  while ( v7 );
  LOWORD(s[293].dummy) = 1;
  s[1451].dummy = 0;
  s[1450].dummy = 0;
  s[1452].dummy = 0;
  s[1448].dummy = 0;
}
