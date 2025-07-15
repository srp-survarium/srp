ecpk_parameters_st *__usercall ec_asn1_group2pkparameters@<eax>(
        const ssl_st *group@<edi>,
        ecpk_parameters_st *params@<ecx>)
{
  struct ASN1_VALUE_st *v2; // esi
  int type; // ecx
  struct ASN1_VALUE_st *v5; // eax
  unsigned int shutdown; // eax
  void *v7; // eax

  v2 = (struct ASN1_VALUE_st *)params;
  if ( params )
  {
    type = params->type;
    if ( *(_DWORD *)v2 || !*((_DWORD *)v2 + 1) )
    {
      if ( type == 1 )
      {
        v5 = (struct ASN1_VALUE_st *)*((_DWORD *)v2 + 1);
        if ( v5 )
          ASN1_item_free(v5, &local_it_63);
      }
    }
    else
    {
      ASN1_OBJECT_free(*((asn1_object_st **)v2 + 1));
    }
  }
  else
  {
    v2 = ASN1_item_new(&local_it_64);
    if ( !v2 )
    {
      ERR_put_error(0x10u, 156, 65, ".\\crypto\\ec\\ec_asn1.c", 695);
      return 0;
    }
  }
  if ( SSL_state(group) )
  {
    shutdown = SSL_get_shutdown(group);
    if ( !shutdown )
    {
LABEL_15:
      ASN1_item_free(v2, &local_it_64);
      return 0;
    }
    *(_DWORD *)v2 = 0;
    v7 = OBJ_nid2obj(shutdown);
  }
  else
  {
    *(_DWORD *)v2 = 1;
    v7 = ec_asn1_group2parameters(0);
  }
  *((_DWORD *)v2 + 1) = v7;
  if ( !v7 )
    goto LABEL_15;
  return (ecpk_parameters_st *)v2;
}
