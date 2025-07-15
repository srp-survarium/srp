ec_group_st *__usercall ec_asn1_pkparameters2group@<eax>(int a1@<ebx>, const ecpk_parameters_st *params)
{
  int type; // ecx
  void *v4; // eax
  ec_group_st *v5; // eax
  ec_group_st *v6; // esi
  ec_group_st *v7; // eax
  ec_group_st *v8; // esi

  if ( params )
  {
    type = params->type;
    if ( params->type )
    {
      if ( type == 1 )
      {
        v7 = ec_asn1_parameters2group(params->value.parameters);
        v8 = v7;
        if ( v7 )
        {
          EC_GROUP_set_asn1_flag(v7, 0);
          return v8;
        }
        else
        {
          ERR_put_error(a1, 0x10u, 158, 16, ".\\crypto\\ec\\ec_asn1.c", 1033);
          return 0;
        }
      }
      else
      {
        if ( type != 2 )
          ERR_put_error(a1, 0x10u, 158, 115, ".\\crypto\\ec\\ec_asn1.c", 1044);
        return 0;
      }
    }
    else
    {
      v4 = OBJ_obj2nid(params->value.named_curve);
      v5 = EC_GROUP_new_by_curve_name((int)v4);
      v6 = v5;
      if ( v5 )
      {
        EC_GROUP_set_asn1_flag(v5, 1);
        return v6;
      }
      else
      {
        ERR_put_error(a1, 0x10u, 158, 119, ".\\crypto\\ec\\ec_asn1.c", 1022);
        return 0;
      }
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 158, 124, ".\\crypto\\ec\\ec_asn1.c", 1012);
    return 0;
  }
}
