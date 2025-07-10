bool __usercall try_to_allocate_arenas@<al>(
        vostok::buffer_vector<vostok::memory::platform::region> *arenas@<edi>,
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas@<esi>,
        vostok::memory::platform::region *only_resources)
{
  _SYSTEM_INFO SystemInfo; // [esp+4h] [ebp-24h] BYREF

  if ( !(_BYTE)only_resources && try_to_allocate_arenas_as_a_single_block(arenas, resource_arenas) )
    return 1;
  GetSystemInfo(&SystemInfo);
  return allocate_arenas(
           (vostok::memory::platform::region *)arenas,
           resource_arenas,
           (char *)SystemInfo.dwAllocationGranularity,
           only_resources);
}
