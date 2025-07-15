unsigned int __usercall vostok::strings::detail::tuples::helper<1>::length@<eax>(const char *string@<eax>)
{
  if ( string )
    return strlen(string);
  else
    return 0;
}
