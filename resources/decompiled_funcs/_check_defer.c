void __cdecl check_defer(int nid)
{
  if ( !obj_cleanup_defer )
    obj_cleanup_defer = nid >= 893;
}
