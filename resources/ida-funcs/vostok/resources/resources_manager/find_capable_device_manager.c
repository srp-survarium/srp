vostok::resources::device_manager *__thiscall vostok::resources::resources_manager::find_capable_device_manager(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *file_path,
        const char *file_patha)
{
  _DWORD *v3; // esi
  unsigned __int8 (__thiscall ***v4)(_DWORD, const char *); // edi

  v3 = *(_DWORD **)((char *)&file_path->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_201FF + 1);
  if ( v3 == *(_DWORD **)((char *)&loc_20204 + (_DWORD)file_path) )
    return 0;
  while ( 1 )
  {
    v4 = (unsigned __int8 (__thiscall ***)(_DWORD, const char *))*v3;
    if ( (**(unsigned __int8 (__thiscall ***)(_DWORD, const char *))*v3)(*v3, file_patha) )
      break;
    if ( ++v3 == *(_DWORD **)((char *)&loc_20204 + (_DWORD)file_path) )
      return 0;
  }
  return (vostok::resources::device_manager *)v4;
}
