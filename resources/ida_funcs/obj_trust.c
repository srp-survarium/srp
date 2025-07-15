int __cdecl obj_trust(int id, x509_st *x)
{
  x509_cert_aux_st *aux; // esi
  const stack_st *p_stack; // eax
  int v5; // edi
  char *v6; // eax
  int v7; // edi
  char *v8; // eax

  aux = x->aux;
  if ( !aux )
    return 3;
  p_stack = &aux->reject->stack;
  if ( p_stack && (v5 = 0, sk_num(p_stack) > 0) )
  {
    while ( 1 )
    {
      v6 = sk_value(&aux->reject->stack, v5);
      if ( OBJ_obj2nid((const asn1_object_st *)v6) == id )
        return 2;
      if ( ++v5 >= sk_num(&aux->reject->stack) )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    if ( aux->trust && (v7 = 0, sk_num(&aux->trust->stack) > 0) )
    {
      while ( 1 )
      {
        v8 = sk_value(&aux->trust->stack, v7);
        if ( OBJ_obj2nid((const asn1_object_st *)v8) == id )
          break;
        if ( ++v7 >= sk_num(&aux->trust->stack) )
          return 3;
      }
      return 1;
    }
    else
    {
      return 3;
    }
  }
}
