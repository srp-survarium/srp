vostok::resources::device_manager *__thiscall vostok::resources::resources_manager::find_capable_device_manager(
        vostok::resources::resources_manager *this,
        const char *file_path,
        int a3)
{
  _DWORD *i; // esi
  unsigned __int8 (__thiscall ***v4)(_DWORD, int); // edi

  for ( i = *(_DWORD **)&file_path[(_DWORD)&loc_20205 + 3]; ; ++i )
  {
    if ( i == *(_DWORD **)&file_path[(_DWORD)&loc_2020A + 2] )
      return 0;
    v4 = (unsigned __int8 (__thiscall ***)(_DWORD, int))*i;
    if ( (**(unsigned __int8 (__thiscall ***)(_DWORD, int))*i)(*i, a3) )
      break;
  }
  return (vostok::resources::device_manager *)v4;
}
