void __usercall vostok::render::scene::process_pending_remove_texture_instances(
        vostok::render::scene *this@<ecx>,
        int a2@<edi>)
{
  int v2; // edx
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // esi
  vostok::render::find_proxy_predicate *v6; // eax
  bool k; // zf
  vostok::render::streaming_texture_instance_proxy_base **v8; // esi
  void ***proxy; // eax
  void ***v10; // ecx
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // [esp-4h] [ebp-1Ch]
  const char *v14; // [esp+0h] [ebp-18h]
  const char *v15; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  unsigned int v17; // [esp+8h] [ebp-10h]
  _DWORD *j; // [esp+Ch] [ebp-Ch]
  _DWORD *inptr; // [esp+10h] [ebp-8h]
  void **inptra; // [esp+10h] [ebp-8h]
  _DWORD *v21; // [esp+14h] [ebp-4h]
  vostok::render::find_proxy_predicate *v22; // [esp+14h] [ebp-4h]

  v2 = *(int *)((char *)&dword_96154 + a2);
  for ( i = *(int *)((char *)&dword_96158 + a2); v2 != i; v2 += 328 )
  {
    v21 = *(_DWORD **)((char *)&loc_1C6188 + a2);
    for ( j = *(_DWORD **)((char *)&loc_1C618C + a2); v21 != j; ++v21 )
    {
      v3 = *(_DWORD **)(v2 + 272);
      v4 = 0;
      *(_DWORD *)(v2 + 272) = 0;
      inptr = 0;
      if ( v3 )
      {
        do
        {
          if ( *v21 == *(_DWORD *)(*v3 + 8) )
          {
            v5 = v3;
            v3 = (_DWORD *)v3[1];
            *v5 = *(_DWORD *)(a2 + 312);
            *(_DWORD *)(a2 + 312) = v5;
            --*(_DWORD *)(a2 + 316);
            v4 = inptr;
          }
          else
          {
            if ( v4 )
              v4[1] = v3;
            else
              *(_DWORD *)(v2 + 272) = v3;
            v4 = v3;
            v3 = (_DWORD *)v3[1];
            inptr = v4;
          }
        }
        while ( v3 );
        if ( v4 )
          v4[1] = 0;
      }
    }
  }
  v6 = *(vostok::render::find_proxy_predicate **)((char *)&loc_1C6188 + a2);
  v17 = *(_DWORD *)((char *)&loc_1C618C + a2);
  for ( k = v6 == (vostok::render::find_proxy_predicate *)v17; ; k = &v22[1] == (vostok::render::find_proxy_predicate *)v17 )
  {
    v22 = v6;
    if ( k )
      break;
    v8 = *(vostok::render::streaming_texture_instance_proxy_base ***)((char *)&loc_1BE17F + a2 + 1);
    proxy = (void ***)stlp_std::find_if<vostok::render::streaming_texture_instance_proxy_base * *,vostok::render::find_proxy_predicate>(
                        *(vostok::render::streaming_texture_instance_proxy_base ***)((char *)&loc_1BE17C + a2),
                        v8,
                        (vostok::render::find_proxy_predicate)v6->m_parent);
    if ( proxy != (void ***)v8 )
    {
      inptra = *proxy;
      v10 = proxy;
      if ( proxy + 1 != (void ***)v8 )
      {
        do
        {
          if ( v10 )
            *v10 = v10[1];
          ++v10;
        }
        while ( v10 + 1 != *(void ****)((char *)&loc_1BE17F + a2 + 1) );
      }
      *(_DWORD *)((char *)&loc_1BE17F + a2 + 1) = *(_DWORD *)((char *)&loc_1BE17C + a2)
                                                + 4
                                                * (((*(_DWORD *)((char *)&loc_1BE17F + a2 + 1)
                                                   - *(_DWORD *)((char *)&loc_1BE17C + a2)) >> 2)
                                                 - 1);
      v11 = vostok::render::g_allocator;
      if ( inptra )
      {
        v12 = __RTCastToVoid(inptra);
        vostok::memory::doug_lea_allocator::free_impl(v13, (int)v11, v12, v14, v15, v17);
      }
    }
    v6 = v22 + 1;
  }
  *(_DWORD *)((char *)&loc_1C618C + a2) = *(_DWORD *)((char *)&loc_1C6188 + a2);
}
