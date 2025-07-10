void __cdecl _tr_init(internal_state *s)
{
  s[710].dummy = (int)&s[37];
  s[713].dummy = (int)&s[610];
  s[712].dummy = (int)&static_l_desc;
  s[715].dummy = (int)&static_d_desc;
  s[716].dummy = (int)&s[671];
  s[718].dummy = (int)&static_bl_desc;
  LOWORD(s[1454].dummy) = 0;
  s[1455].dummy = 0;
  s[1453].dummy = 8;
  init_block(0, s);
}
