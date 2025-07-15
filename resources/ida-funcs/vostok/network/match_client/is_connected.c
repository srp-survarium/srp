BOOL __usercall vostok::network::match_client::is_connected@<eax>(
        vostok::network::match_client *this@<ecx>,
        int a2@<eax>)
{
  _DWORD *v2; // eax

  v2 = *(_DWORD **)(a2 + 240);
  return *v2 && !*(_DWORD *)((char *)&loc_55F64 + *v2);
}
