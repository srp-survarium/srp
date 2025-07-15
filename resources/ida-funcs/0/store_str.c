void __usercall store_str(char *in@<edx>, char **out@<ecx>, unsigned int *count@<eax>)
{
  for ( ; *count; --*count )
  {
    if ( !*in )
      break;
    *(*out)++ = *in++;
  }
}
