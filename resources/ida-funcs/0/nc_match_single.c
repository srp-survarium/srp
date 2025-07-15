void __usercall nc_match_single(GENERAL_NAME_st *gen@<edx>, int a2@<ebx>, int a3@<edi>, GENERAL_NAME_st *base)
{
  switch ( base->type )
  {
    case 1:
      nc_email(gen->d.rfc822Name, base->d.rfc822Name);
      break;
    case 2:
      nc_dns((int *)base->d.ptr, a2, a3, gen->d.rfc822Name);
      break;
    case 4:
      nc_dn(gen->d.directoryName, base->d.directoryName);
      break;
    case 6:
      nc_uri(a2, gen->d.rfc822Name, base->d.rfc822Name);
      break;
    default:
      return;
  }
}
