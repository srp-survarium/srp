void __usercall scan_tree(ct_data_s *tree@<eax>, int max_code@<ecx>, internal_state *s)
{
  int dad; // edi
  int v4; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // ebp
  int v9; // eax
  $2467CA9704E0472D4CCF1296A763D23A *p_dl; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]

  dad = tree->dl.dad;
  v4 = 0;
  v6 = 7;
  v7 = 4;
  if ( !tree->dl.dad )
  {
    v6 = 138;
    v7 = 3;
  }
  tree[max_code + 1].dl.dad = -1;
  if ( max_code >= 0 )
  {
    v8 = -1;
    v11 = max_code + 1;
    p_dl = &tree[1].dl;
    do
    {
      v9 = dad;
      dad = p_dl->dad;
      if ( ++v4 >= v6 || v9 != dad )
      {
        if ( v4 >= v7 )
        {
          if ( v9 )
          {
            if ( v9 != v8 )
              ++LOWORD(s[v9 + 671].dummy);
            ++LOWORD(s[687].dummy);
          }
          else if ( v4 > 10 )
          {
            ++LOWORD(s[689].dummy);
          }
          else
          {
            ++LOWORD(s[688].dummy);
          }
        }
        else
        {
          LOWORD(s[v9 + 671].dummy) += v4;
        }
        v4 = 0;
        v8 = v9;
        if ( dad )
        {
          if ( v9 == dad )
          {
            v6 = 6;
            v7 = 3;
          }
          else
          {
            v6 = 7;
            v7 = 4;
          }
        }
        else
        {
          v6 = 138;
          v7 = 3;
        }
      }
      p_dl += 2;
      --v11;
    }
    while ( v11 );
  }
}
