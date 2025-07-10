ec_group_st *__cdecl ec_asn1_pkparameters2group(const ecpk_parameters_st *params)
{
  int type; // ecx
  int v3; // eax
  ec_group_st *v4; // eax
  ec_group_st *v5; // esi
  ec_group_st *v6; // eax
  ec_group_st *v7; // esi

  if ( params )
  {
    type = params->type;
    if ( params->type )
    {
      if ( type == 1 )
      {
        v6 = ec_asn1_parameters2group(params->value.parameters);
        v7 = v6;
        if ( v6 )
        {
          EC_GROUP_set_asn1_flag(v6, 0);
          return v7;
        }
        else
        {
          ERR_put_error(0x10u, 158, 16, ".\\crypto\\ec\\ec_asn1.c", 1033);
          return 0;
        }
      }
      else
      {
        if ( type != 2 )
          ERR_put_error(0x10u, 158, 115, ".\\crypto\\ec\\ec_asn1.c", 1044);
        return 0;
      }
    }
    else
    {
      v3 = OBJ_obj2nid(params->value.named_curve);
      v4 = EC_GROUP_new_by_curve_name(v3);
      v5 = v4;
      if ( v4 )
      {
        EC_GROUP_set_asn1_flag(v4, 1);
        return v5;
      }
      else
      {
        ERR_put_error(0x10u, 158, 119, ".\\crypto\\ec\\ec_asn1.c", 1022);
        return 0;
      }
    }
  }
  else
  {
    ERR_put_error(0x10u, 158, 124, ".\\crypto\\ec\\ec_asn1.c", 1012);
    return 0;
  }
}
