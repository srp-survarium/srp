void __usercall vostok::animation::anm_track::anm_track(
        vostok::animation::anm_track *this@<ecx>,
        unsigned __int8 **a2@<esi>)
{
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::memory::doug_lea_allocator *v3; // edi
  char *v4; // eax
  _DWORD *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // edi
  unsigned int v8; // [esp-4h] [ebp-Ch]

  v2 = survarium::g_allocator;
  a2[3] = (unsigned __int8 *)survarium::g_allocator;
  a2[4] = (unsigned __int8 *)6;
  v3 = v2;
  v4 = type_info::raw_name(&vostok::animation::EtCurve * `RTTI Type Descriptor');
  v5 = v3->call_malloc(v3, 32u, v4, "vostok::animation::anm_track::anm_track", ".\\anim_track.cpp", 182u);
  *v5++ = 6;
  *v5 = 4;
  v6 = (unsigned __int8 *)(v5 + 1);
  v7 = v6;
  do
  {
    if ( v7 )
      *(_DWORD *)v7 = 0;
    v7 += 4;
  }
  while ( v7 != v6 + 24 );
  v8 = 4 * (_DWORD)a2[4];
  *a2 = v6;
  memset((int)v6, 0, v8);
}
