int __usercall vostok::animation::anm_track::get_channel_id@<eax>(char *name@<esi>)
{
  char *v2; // [esp+0h] [ebp-4h]

  if ( !_stricmp("translateY", v2) )
    return 1;
  if ( !_stricmp("translateZ", name) )
    return 2;
  if ( !_stricmp("rotateX", name) )
    return 3;
  if ( !_stricmp("rotateY", name) )
    return 4;
  if ( !_stricmp("rotateZ", name) )
    return 5;
  if ( !_stricmp("scaleX", name) )
    return 6;
  if ( !_stricmp("scaleY", name) )
    return 7;
  if ( !_stricmp("scaleZ", name) )
    return 8;
  return (_stricmp("time", name) != 0) + 9;
}
