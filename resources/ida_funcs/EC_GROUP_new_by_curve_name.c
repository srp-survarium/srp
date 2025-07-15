ec_group_st *__cdecl EC_GROUP_new_by_curve_name(int nid)
{
  int v2; // ecx
  unsigned int v3; // eax
  ec_group_st *v4; // eax
  ec_group_st *v5; // esi

  if ( nid <= 0 )
    return 0;
  v2 = 0;
  v3 = 0;
  while ( curve_list[v3].nid != nid )
  {
    ++v3;
    ++v2;
    if ( v3 >= 67 )
      goto LABEL_8;
  }
  v4 = ec_group_new_from_data(curve_list[v2].data);
  v5 = v4;
  if ( !v4 )
  {
LABEL_8:
    ERR_put_error(0x10u, 174, 129, ".\\crypto\\ec\\ec_curve.c", 2034);
    return 0;
  }
  EC_GROUP_set_curve_name(v4, nid);
  return v5;
}
