void __usercall print_qualifiers(bio_st *out@<esi>, int indent@<ebx>, stack_st_POLICYQUALINFO *quals)
{
  int i; // ebp
  char *v4; // edi
  char *v5; // eax

  for ( i = 0; i < sk_num(&quals->stack); ++i )
  {
    v4 = sk_value(&quals->stack, i);
    v5 = (char *)OBJ_obj2nid(*(const asn1_object_st **)v4) - 164;
    if ( v5 )
    {
      if ( v5 == (char *)1 )
      {
        BIO_printf(out, "%*sUser Notice:\n", indent, uri);
        print_notice(indent, out, *((USERNOTICE_st **)v4 + 1), indent + 2);
      }
      else
      {
        BIO_printf(out, "%*sUnknown Qualifier: ", indent + 2, uri);
        i2a_ASN1_OBJECT(indent, out, *(asn1_object_st **)v4);
        BIO_puts(indent, out, "\n");
      }
    }
    else
    {
      BIO_printf(out, "%*sCPS: %s\n", indent, uri, *(const char **)(*((_DWORD *)v4 + 1) + 8));
    }
  }
}
