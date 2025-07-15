int __cdecl X509_NAME_print_ex(bio_st *out, X509_name_st *nm, int indent, unsigned int flags)
{
  if ( flags )
    return do_name_ex((int (__cdecl *)(void *, const void *, int))send_bio_chars, nm, indent, flags);
  else
    return X509_NAME_print(out, nm, indent);
}
