int __usercall nc_dn@<eax>(X509_name_st *nm@<edi>, X509_name_st *base@<ecx>)
{
  unsigned int canon_enclen; // eax
  unsigned __int8 *canon_enc; // ecx
  unsigned __int8 *v6; // esi

  if ( nm->modified && i2d_X509_NAME(nm, 0) < 0 || base->modified && i2d_X509_NAME(base, 0) < 0 )
    return 17;
  canon_enclen = base->canon_enclen;
  if ( (signed int)canon_enclen > nm->canon_enclen )
    return 47;
  canon_enc = nm->canon_enc;
  v6 = base->canon_enc;
  if ( canon_enclen >= 4 )
  {
    while ( *(_DWORD *)v6 == *(_DWORD *)canon_enc )
    {
      canon_enclen -= 4;
      canon_enc += 4;
      v6 += 4;
      if ( canon_enclen < 4 )
        goto LABEL_11;
    }
    return 47;
  }
LABEL_11:
  if ( canon_enclen
    && (*canon_enc != *v6 || canon_enclen > 1 && (canon_enc[1] != v6[1] || canon_enclen > 2 && canon_enc[2] != v6[2])) )
  {
    return 47;
  }
  return 0;
}
