int __usercall do_indent@<eax>(void *arg@<ebx>, int indent@<edi>, int (__cdecl *io_ch)(void *, const void *, int))
{
  int v3; // esi

  v3 = 0;
  if ( indent <= 0 )
    return 1;
  while ( io_ch(arg, " ", 1) )
  {
    if ( ++v3 >= indent )
      return 1;
  }
  return 0;
}
