int __usercall nref_nos@<eax>(stack_st_ASN1_INTEGER *nnums@<ebx>, stack_st_CONF_VALUE *nos@<edi>)
{
  int v2; // esi
  char *v3; // eax
  char *v4; // eax
  const stack_st *v6; // [esp+0h] [ebp-8h]

  v2 = 0;
  if ( sk_num(v6) <= 0 )
    return 1;
  while ( 1 )
  {
    v3 = sk_value(&nos->stack, v2);
    v4 = (char *)s2i_ASN1_INTEGER(0, *((char **)v3 + 1));
    if ( !v4 )
    {
      ERR_put_error(0x22u, 133, 140, ".\\crypto\\x509v3\\v3_cpols.c", 349);
      goto LABEL_8;
    }
    if ( !sk_push(&nnums->stack, v4) )
      break;
    if ( ++v2 >= sk_num(&nos->stack) )
      return 1;
  }
  ERR_put_error(0x22u, 133, 65, ".\\crypto\\x509v3\\v3_cpols.c", 357);
LABEL_8:
  sk_pop_free(&nnums->stack, (void (__cdecl *)(void *))ASN1_STRING_free);
  return 0;
}
