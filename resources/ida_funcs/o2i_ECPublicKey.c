ec_key_st *__cdecl o2i_ECPublicKey(ec_key_st **a, const unsigned __int8 **in, unsigned int len)
{
  int v3; // esi
  ec_point_st *v4; // eax

  if ( a && (v3 = (int)*a) != 0 && *(_DWORD *)(v3 + 4) )
  {
    if ( *(_DWORD *)(v3 + 8) || (v4 = EC_POINT_new(*(const ec_group_st **)(v3 + 4)), (*(_DWORD *)(v3 + 8) = v4) != 0) )
    {
      if ( EC_POINT_oct2point(*(const ec_group_st **)(v3 + 4), *(ec_point_st **)(v3 + 8), *in, len, 0) )
      {
        *(_DWORD *)(v3 + 20) = **in & 0xFE;
        *in += len;
        return (ec_key_st *)v3;
      }
      else
      {
        ERR_put_error(0x10u, 152, 16, ".\\crypto\\ec\\ec_asn1.c", 1382);
        return 0;
      }
    }
    else
    {
      ERR_put_error(0x10u, 152, 65, ".\\crypto\\ec\\ec_asn1.c", 1377);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 152, 67, ".\\crypto\\ec\\ec_asn1.c", 1370);
    return 0;
  }
}
