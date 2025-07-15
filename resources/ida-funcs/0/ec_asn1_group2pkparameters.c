ecpk_parameters_st *__usercall ec_asn1_group2pkparameters@<eax>(
        const ssl_st *group@<edi>,
        ecpk_parameters_st *params@<ecx>,
        int a3@<ebx>)
{
  struct ASN1_VALUE_st *v3; // esi
  int type; // ecx
  struct ASN1_VALUE_st *v6; // eax
  unsigned int shutdown; // eax
  void *v8; // eax

  v3 = (struct ASN1_VALUE_st *)params;
  if ( params )
  {
    type = params->type;
    if ( *(_DWORD *)v3 || !*((_DWORD *)v3 + 1) )
    {
      if ( type == 1 )
      {
        v6 = (struct ASN1_VALUE_st *)*((_DWORD *)v3 + 1);
        if ( v6 )
          ASN1_item_free(v6, &local_it_63);
      }
    }
    else
    {
      ASN1_OBJECT_free(*((asn1_object_st **)v3 + 1));
    }
  }
  else
  {
    v3 = ASN1_item_new(&local_it_64);
    if ( !v3 )
    {
      ERR_put_error(a3, 0x10u, 156, 65, ".\\crypto\\ec\\ec_asn1.c", 695);
      return 0;
    }
  }
  if ( SSL_state(group) )
  {
    shutdown = SSL_get_shutdown(group);
    if ( !shutdown )
    {
LABEL_15:
      ASN1_item_free(v3, &local_it_64);
      return 0;
    }
    *(_DWORD *)v3 = 0;
    v8 = OBJ_nid2obj(a3, shutdown);
  }
  else
  {
    *(_DWORD *)v3 = 1;
    v8 = ec_asn1_group2parameters(0);
  }
  *((_DWORD *)v3 + 1) = v8;
  if ( !v8 )
    goto LABEL_15;
  return (ecpk_parameters_st *)v3;
}
