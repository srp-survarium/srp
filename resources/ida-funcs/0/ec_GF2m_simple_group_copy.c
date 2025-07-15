bignum_st *__cdecl ec_GF2m_simple_group_copy(ec_group_st *dest, const ec_group_st *src)
{
  bignum_st *result; // eax
  int v3; // kr00_4
  bignum_st *v4; // eax
  int v5; // kr04_4
  bignum_st *p_b; // eax
  int i; // eax
  int j; // eax

  result = BN_copy(&dest->field, &src->field);
  if ( result )
  {
    result = BN_copy(&dest->a, &src->a);
    if ( result )
    {
      if ( !BN_copy(&dest->b, &src->b) )
        return 0;
      dest->poly[0] = src->poly[0];
      dest->poly[1] = src->poly[1];
      dest->poly[2] = src->poly[2];
      dest->poly[3] = src->poly[3];
      dest->poly[4] = src->poly[4];
      dest->poly[5] = src->poly[5];
      v3 = dest->poly[0] + 31;
      v4 = v3 / 32 > dest->a.dmax ? bn_expand2(&dest->a, v3 / 32) : &dest->a;
      if ( v4
        && ((v5 = dest->poly[0] + 31, v5 / 32 > dest->b.dmax) ? (p_b = bn_expand2(&dest->b, v5 / 32)) : (p_b = &dest->b),
            p_b) )
      {
        for ( i = dest->a.top; i < dest->a.dmax; ++i )
          dest->a.d[i] = 0;
        for ( j = dest->b.top; j < dest->b.dmax; ++j )
          dest->b.d[j] = 0;
        return (bignum_st *)1;
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
