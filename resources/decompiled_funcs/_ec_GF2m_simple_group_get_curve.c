int __cdecl ec_GF2m_simple_group_get_curve(const ec_group_st *group, bignum_st *p, bignum_st *a, bignum_st *b)
{
  int v4; // edi
  int result; // eax

  v4 = 0;
  if ( !p || (result = (int)BN_copy(p, &group->field)) != 0 )
  {
    if ( (!a || BN_copy(a, &group->a)) && (!b || BN_copy(b, &group->b)) )
      return 1;
    return v4;
  }
  return result;
}
