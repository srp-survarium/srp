int __usercall print_distpoint@<eax>(bio_st *out@<edx>, DIST_POINT_NAME_st *dpn@<ecx>, int indent@<esi>)
{
  X509_name_st nm; // [esp+8h] [ebp-14h] BYREF

  if ( dpn->type )
  {
    nm.entries = dpn->name.relativename;
    BIO_printf(out, "%*sRelative Name:\n%*s", indent, (const char *)&buf, indent + 2, (const char *)&buf);
    X509_NAME_print_ex(out, &nm, 0, (unsigned int)&unk_82031F);
    BIO_puts(out, "\n");
  }
  else
  {
    BIO_printf(out, "%*sFull Name:\n", indent, (const char *)&buf);
    print_gens(out, dpn->name.fullname, indent);
  }
  return 1;
}
