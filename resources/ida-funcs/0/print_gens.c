int __usercall print_gens@<eax>(bio_st *out@<edi>, stack_st_GENERAL_NAME *gens@<ebx>, int indent)
{
  int v3; // esi
  char *v4; // eax
  const stack_st *v6; // [esp+0h] [ebp-8h]

  v3 = 0;
  if ( sk_num(v6) > 0 )
  {
    do
    {
      BIO_printf(out, "%*s", indent + 2, uri);
      v4 = sk_value(&gens->stack, v3);
      GENERAL_NAME_print(out, (GENERAL_NAME_st *)v4);
      BIO_puts((int)gens, out, "\n");
      ++v3;
    }
    while ( v3 < sk_num(&gens->stack) );
  }
  return 1;
}
