ec_key_st *__usercall o2i_ECPublicKey@<eax>(int a1@<ebx>, ec_key_st **a, const unsigned __int8 **in, unsigned int len)
{
  int v4; // esi
  ec_point_st *v5; // eax

  if ( a && (v4 = (int)*a) != 0 && *(_DWORD *)(v4 + 4) )
  {
    if ( *(_DWORD *)(v4 + 8) || (v5 = EC_POINT_new(*(const ec_group_st **)(v4 + 4)), (*(_DWORD *)(v4 + 8) = v5) != 0) )
    {
      if ( EC_POINT_oct2point(*(const ec_group_st **)(v4 + 4), *(ec_point_st **)(v4 + 8), *in, len, 0) )
      {
        *(_DWORD *)(v4 + 20) = **in & 0xFE;
        *in += len;
        return (ec_key_st *)v4;
      }
      else
      {
        ERR_put_error(len, 0x10u, 152, 16, ".\\crypto\\ec\\ec_asn1.c", 1382);
        return 0;
      }
    }
    else
    {
      ERR_put_error(a1, 0x10u, 152, 65, ".\\crypto\\ec\\ec_asn1.c", 1377);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 152, 67, ".\\crypto\\ec\\ec_asn1.c", 1370);
    return 0;
  }
}
