int __usercall vostok::console_commands::bool_from_string@<eax>(char *args@<esi>, bool *v@<edi>)
{
  if ( !_stricmp(args, "on")
    || !_stricmp(args, "true")
    || !_stricmp(args, "yes")
    || !vostok::strings::compare(args, "1") )
  {
    *v = 1;
  }
  else
  {
    if ( _stricmp(args, "off") && _stricmp(args, "false") && _stricmp(args, "no") && vostok::strings::compare(args, "0") )
      return -1;
    *v = 0;
  }
  return 0;
}
