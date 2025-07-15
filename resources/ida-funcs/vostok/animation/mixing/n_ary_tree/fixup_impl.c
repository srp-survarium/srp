void __userpurge vostok::animation::mixing::n_ary_tree::fixup_impl(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::managed_resource *offset)
{
  int v3; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // edi
  int v5; // eax
  char *v6; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  char *v14; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // edx
  char *v17; // ecx
  _DWORD *v18; // eax
  _DWORD *v19; // edx
  char *v20; // ecx

  v3 = a2[1];
  a2[7] = 0;
  *a2 = 0;
  if ( v3 )
    v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)offset + v3);
  else
    v4 = 0;
  v5 = a2[2];
  a2[1] = v4;
  if ( v5 )
    v6 = (char *)offset + v5;
  else
    v6 = 0;
  a2[2] = v6;
  v7 = a2[3];
  if ( v7 )
    v8 = (char *)offset + v7;
  else
    v8 = 0;
  a2[3] = v8;
  v9 = a2[4];
  if ( v9 )
    v10 = (char *)offset + v9;
  else
    v10 = 0;
  a2[4] = v10;
  v11 = a2[5];
  if ( v11 )
    v12 = (char *)offset + v11;
  else
    v12 = 0;
  a2[5] = v12;
  v13 = a2[6];
  if ( v13 )
    v14 = (char *)offset + v13;
  else
    v14 = 0;
  a2[6] = v14;
  while ( v4 )
  {
    vostok::animation::mixing::n_ary_tree_animation_node::fixup(v4, offset);
    v4 = v4->m_next_weight_animation;
  }
  v15 = (_DWORD *)a2[3];
  v16 = &v15[a2[10]];
  while ( v15 != v16 )
  {
    if ( *v15 )
      v17 = (char *)offset + *v15;
    else
      v17 = 0;
    *v15++ = v17;
  }
  v18 = (_DWORD *)a2[5];
  v19 = &v18[a2[8]];
  while ( v18 != v19 )
  {
    if ( *v18 )
      v20 = (char *)offset + *v18;
    else
      v20 = 0;
    *v18++ = v20;
  }
}
