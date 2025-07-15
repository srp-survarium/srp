void __usercall gen_bitlen(internal_state *s@<eax>, tree_desc_s *desc@<ecx>)
{
  int v2; // edx
  ct_data_s *dyn_tree; // ebx
  static_tree_desc_s *stat_desc; // ecx
  int dummy; // ebp
  int v6; // esi
  int v7; // edi
  int v8; // ecx
  internal_state *v9; // edx
  int v10; // edi
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int freq; // edi
  int v15; // ebp
  char *v16; // esi
  int v17; // ecx
  _WORD *i; // edx
  int v19; // edx
  int v20; // esi
  internal_state *v21; // ebp
  int v22; // ecx
  int dad; // edi
  int h; // [esp+10h] [ebp-20h]
  internal_state *v25; // [esp+14h] [ebp-1Ch]
  int overflow; // [esp+18h] [ebp-18h]
  int n; // [esp+1Ch] [ebp-14h]
  int na; // [esp+1Ch] [ebp-14h]
  int v29; // [esp+20h] [ebp-10h]
  char *v30; // [esp+20h] [ebp-10h]
  int max_code; // [esp+24h] [ebp-Ch]
  int base; // [esp+28h] [ebp-8h]
  const int *extra; // [esp+2Ch] [ebp-4h]

  v2 = desc->max_code;
  dyn_tree = desc->dyn_tree;
  stat_desc = desc->stat_desc;
  max_code = v2;
  dummy = stat_desc->dummy;
  extra = (const int *)stat_desc[1].dummy;
  v6 = stat_desc[4].dummy;
  base = stat_desc[2].dummy;
  s[719].dummy = 0;
  s[720].dummy = 0;
  s[721].dummy = 0;
  s[722].dummy = 0;
  s[723].dummy = 0;
  s[724].dummy = 0;
  s[725].dummy = 0;
  s[726].dummy = 0;
  dyn_tree[s[s[1301].dummy + 727].dummy].dl.dad = 0;
  v7 = s[1301].dummy + 1;
  n = v6;
  overflow = 0;
  if ( v7 < 573 )
  {
    v8 = 573 - v7;
    v9 = &s[v7 + 727];
    v10 = 573;
    v25 = v9;
    v29 = v8;
    h = 573;
    while ( 1 )
    {
      v11 = v25->dummy;
      v12 = dyn_tree[dyn_tree[v25->dummy].dl.dad].dl.dad + 1;
      if ( v12 > v6 )
      {
        ++overflow;
        v12 = v6;
      }
      dyn_tree[v11].dl.dad = v12;
      if ( v11 <= max_code )
      {
        ++*((_WORD *)&s[719].dummy + v12);
        v13 = 0;
        if ( v11 >= base )
          v13 = extra[v11 - base];
        freq = dyn_tree[v11].fc.freq;
        s[1450].dummy += freq * (v13 + v12);
        if ( dummy )
          s[1451].dummy += freq * (v13 + *(unsigned __int16 *)(dummy + 4 * v11 + 2));
        v10 = 573;
      }
      ++v25;
      if ( !--v29 )
        break;
      v6 = n;
    }
    v15 = overflow;
    if ( overflow )
    {
      v16 = (char *)&s[719] + 2 * n;
      do
      {
        v17 = n - 1;
        for ( i = (_WORD *)&s[718].dummy + n + 1; !*i; --v17 )
          --i;
        *((_WORD *)&s[719].dummy + v17 + 1) += 2;
        --*((_WORD *)&s[719].dummy + v17);
        --*(_WORD *)v16;
        v15 -= 2;
      }
      while ( v15 > 0 );
      v19 = n;
      if ( n )
      {
        v30 = (char *)&s[719] + 2 * n;
        do
        {
          v20 = *(unsigned __int16 *)v16;
          na = v20;
          if ( v20 )
          {
            v21 = &s[v10 + 727];
            do
            {
              v22 = v21[-1].dummy;
              --h;
              --v21;
              if ( v22 <= max_code )
              {
                dad = dyn_tree[v22].dl.dad;
                if ( dad != v19 )
                {
                  s[1450].dummy += dyn_tree[v22].fc.freq * (v19 - dad);
                  dyn_tree[v22].dl.dad = v19;
                }
                v20 = --na;
              }
            }
            while ( v20 );
            v10 = h;
          }
          --v19;
          v16 = v30 - 2;
          v30 -= 2;
        }
        while ( v19 );
      }
    }
  }
}
