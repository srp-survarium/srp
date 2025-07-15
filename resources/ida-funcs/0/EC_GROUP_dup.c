ec_group_st *__usercall EC_GROUP_dup@<eax>(int a1@<ebx>, const ec_group_st *a)
{
  ec_group_st *v3; // eax
  ec_group_st *v4; // esi

  if ( !a )
    return 0;
  v3 = EC_GROUP_new(a->meth);
  v4 = v3;
  if ( !v3 )
    return 0;
  if ( !EC_GROUP_copy(a1, v3, a) )
  {
    EC_GROUP_free(v4);
    return 0;
  }
  return v4;
}
