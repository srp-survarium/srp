BOOL __cdecl idp_check_dp(DIST_POINT_NAME_st *a)
{
  DIST_POINT_NAME_st *b; // ecx
  DIST_POINT_NAME_st *v2; // ebx
  DIST_POINT_NAME_st *v3; // edi
  X509_name_st *dpname; // eax
  X509_name_st *v5; // edi
  stack_st_GENERAL_NAME *fullname; // esi
  const X509_name_st *v8; // ebp
  int v9; // edi
  const X509_name_st **v10; // eax
  int v11; // ebp
  GENERAL_NAME_st *v12; // ebx
  int v13; // esi
  GENERAL_NAME_st *v14; // eax

  v2 = a;
  v3 = b;
  if ( a && b )
  {
    if ( a->type == 1 )
    {
      dpname = a->dpname;
      if ( !dpname )
        return 0;
      if ( b->type == 1 )
      {
        v5 = b->dpname;
        if ( v5 )
          return X509_NAME_cmp(dpname, v5) == 0;
        return 0;
      }
      fullname = b->name.fullname;
    }
    else
    {
      if ( b->type != 1 )
      {
        v11 = 0;
        if ( sk_num(&a->name.fullname->stack) > 0 )
        {
          while ( 1 )
          {
            v12 = (GENERAL_NAME_st *)sk_value(&v2->name.fullname->stack, v11);
            v13 = 0;
            if ( sk_num(&v3->name.fullname->stack) > 0 )
              break;
LABEL_24:
            if ( ++v11 >= sk_num(&a->name.fullname->stack) )
              return 0;
            v2 = a;
          }
          while ( 1 )
          {
            v14 = (GENERAL_NAME_st *)sk_value(&v3->name.fullname->stack, v13);
            if ( !GENERAL_NAME_cmp(v12, v14) )
              return 1;
            if ( ++v13 >= sk_num(&v3->name.fullname->stack) )
              goto LABEL_24;
          }
        }
        return 0;
      }
      dpname = b->dpname;
      if ( !dpname )
        return 0;
      fullname = a->name.fullname;
    }
    v8 = dpname;
    v9 = 0;
    if ( sk_num(&fullname->stack) > 0 )
    {
      while ( 1 )
      {
        v10 = (const X509_name_st **)sk_value(&fullname->stack, v9);
        if ( *v10 == (const X509_name_st *)4 && !X509_NAME_cmp(v8, v10[1]) )
          break;
        if ( ++v9 >= sk_num(&fullname->stack) )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  return 1;
}
