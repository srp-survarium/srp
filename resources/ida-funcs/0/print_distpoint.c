int __usercall print_distpoint@<eax>(bio_st *out@<edx>, DIST_POINT_NAME_st *dpn@<ecx>, int indent@<esi>)
{
  X509_name_st nm; // [esp+8h] [ebp-14h] BYREF

  if ( dpn->type )
  {
    nm.entries = dpn->name.relativename;
    BIO_printf(out, "%*sRelative Name:\n%*s", indent, uri, indent + 2, uri);
    X509_NAME_print_ex(out, &nm, 0, 0x82031Fu);
    BIO_puts((int)dpn, out, "\n");
  }
  else
  {
    BIO_printf(out, "%*sFull Name:\n", indent, uri);
    print_gens(out, dpn->name.fullname, indent);
  }
  return 1;
}
