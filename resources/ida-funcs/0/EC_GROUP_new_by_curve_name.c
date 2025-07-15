ec_group_st *__usercall EC_GROUP_new_by_curve_name@<eax>(int a1@<ebx>, int nid)
{
  int v3; // ecx
  unsigned int v4; // eax
  ec_group_st *v5; // eax
  ec_group_st *v6; // esi

  if ( nid <= 0 )
    return 0;
  v3 = 0;
  v4 = 0;
  while ( curve_list[v4].nid != nid )
  {
    ++v4;
    ++v3;
    if ( v4 >= 67 )
      goto LABEL_8;
  }
  v5 = ec_group_new_from_data(a1, curve_list[v3].data);
  v6 = v5;
  if ( !v5 )
  {
LABEL_8:
    ERR_put_error(a1, 0x10u, 174, 129, ".\\crypto\\ec\\ec_curve.c", 2034);
    return 0;
  }
  EC_GROUP_set_curve_name(v5, nid);
  return v6;
}
