void __thiscall survarium::lobby_client::clear_profile_info(survarium::lobby_client *this, int a2)
{
  unsigned __int8 *v2; // eax
  vostok::memory::doug_lea_allocator *v3; // ecx
  const char *v4; // [esp+0h] [ebp-1Ch]
  const char *v5; // [esp+4h] [ebp-18h]
  unsigned int v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+18h] [ebp-4h]

  *(_BYTE *)(a2 + 608) = 0;
  v2 = *(unsigned __int8 **)(a2 + 12716);
  v3 = *(vostok::memory::doug_lea_allocator **)(a2 + 12712);
  if ( v3 != (vostok::memory::doug_lea_allocator *)v2 )
    *(_DWORD *)(a2 + 12716) = stlp_std::priv::__copy_trivial(v2, v2, *(unsigned __int8 **)(a2 + 12712));
  LOBYTE(v7) = 0;
  *(_DWORD *)(a2 + 12872) = 0;
  *(_DWORD *)(a2 + 12876) = 0;
  *(_DWORD *)(a2 + 12880) = v7;
  if ( *(_DWORD *)(a2 + 12728) )
  {
    vostok::memory::doug_lea_allocator::free_impl(v3, (int)survarium::g_allocator, *(char **)(a2 + 12728), v4, v5, v6);
    *(_DWORD *)(a2 + 12728) = 0;
  }
  *(_BYTE *)(a2 + 12732) = 0;
  if ( *(_DWORD *)(a2 + 12736) )
  {
    vostok::memory::doug_lea_allocator::free_impl(v3, (int)survarium::g_allocator, *(char **)(a2 + 12736), v4, v5, v6);
    *(_DWORD *)(a2 + 12736) = 0;
  }
  *(_BYTE *)(a2 + 12740) = 0;
  if ( *(_DWORD *)(a2 + 13144) )
  {
    vostok::memory::doug_lea_allocator::free_impl(v3, (int)survarium::g_allocator, *(char **)(a2 + 13144), v4, v5, v6);
    *(_DWORD *)(a2 + 13144) = 0;
  }
  *(_BYTE *)(a2 + 13148) = 0;
}
