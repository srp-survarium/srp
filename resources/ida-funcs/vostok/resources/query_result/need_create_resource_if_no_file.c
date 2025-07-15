BOOL __usercall vostok::resources::query_result::need_create_resource_if_no_file@<eax>(
        vostok::resources::query_result *this@<ecx>,
        _DWORD *a2@<eax>)
{
  return !a2[41] && !a2[52] && !a2[53] && (a2[176] & 0x2000) == 0;
}
