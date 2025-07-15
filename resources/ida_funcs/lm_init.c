void __usercall lm_init(internal_state *s@<esi>)
{
  int dummy; // ecx
  int v2; // edx
  int v3; // eax
  int max_chain; // edx

  dummy = s[19].dummy;
  v2 = s[17].dummy;
  s[15].dummy = 2 * s[11].dummy;
  *(_WORD *)(v2 + 2 * dummy - 2) = 0;
  memset(s[17].dummy, 0, 2 * s[19].dummy - 2);
  v3 = s[33].dummy;
  s[32].dummy = configuration_table[v3].max_lazy;
  s[35].dummy = configuration_table[v3].good_length;
  s[36].dummy = configuration_table[v3].nice_length;
  max_chain = configuration_table[v3].max_chain;
  s[27].dummy = 0;
  s[23].dummy = 0;
  s[29].dummy = 0;
  s[26].dummy = 0;
  s[18].dummy = 0;
  s[31].dummy = max_chain;
  s[30].dummy = 2;
  s[24].dummy = 2;
}
