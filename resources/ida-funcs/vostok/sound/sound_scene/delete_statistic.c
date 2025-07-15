void __thiscall vostok::sound::sound_scene::delete_statistic(vostok::memory::doug_lea_allocator *statistic, char *a2)
{
  char *v2; // ebx
  char *i; // edi
  vostok::memory::doug_lea_allocator *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ebx
  _DWORD *v7; // edx
  vostok::memory::doug_lea_allocator_vtbl *v8; // esi
  _DWORD *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // eax
  vostok::memory::doug_lea_allocator_vtbl *v11; // edx
  vostok::memory::doug_lea_allocator *v12; // eax
  const char *v13; // [esp+0h] [ebp-14h]
  const char *v14; // [esp+4h] [ebp-10h]
  unsigned int v15; // [esp+8h] [ebp-Ch]
  char *v16; // [esp+10h] [ebp-4h]

  v2 = a2;
  for ( i = (char *)*((_DWORD *)a2 + 13); i; i = v16 )
  {
    v4 = (vostok::memory::doug_lea_allocator *)*((_DWORD *)i + 9);
    v16 = *(char **)i;
    if ( v4 )
    {
      do
      {
        v5 = (vostok::memory::doug_lea_allocator *)*((_DWORD *)i + 9);
        v6 = (vostok::memory::doug_lea_allocator *)v4->__vftable;
        if ( v5 )
        {
          v7 = 0;
          while ( v5 != v4 )
          {
            v7 = &v5->__vftable;
            v5 = (vostok::memory::doug_lea_allocator *)v5->__vftable;
            if ( !v5 )
            {
              if ( v4 )
                goto LABEL_15;
              break;
            }
          }
          --*((_DWORD *)i + 7);
          v8 = v5->__vftable;
          if ( v7 )
            *v7 = v8;
          else
            *((_DWORD *)i + 9) = v8;
          if ( !v5->__vftable )
          {
            v9 = v7;
            if ( !v7 )
              v9 = (_DWORD *)*((_DWORD *)i + 9);
            *((_DWORD *)i + 10) = v9;
          }
        }
LABEL_15:
        vostok::memory::doug_lea_allocator::free_impl(v4, (int)vostok::sound::g_allocator, (char *)v4, v13, v14, v15);
        v4 = v6;
      }
      while ( v6 );
      v2 = a2;
    }
    v10 = (vostok::memory::doug_lea_allocator *)*((_DWORD *)v2 + 13);
    if ( v10 )
    {
      v4 = 0;
      while ( v10 != (vostok::memory::doug_lea_allocator *)i )
      {
        v4 = v10;
        v10 = (vostok::memory::doug_lea_allocator *)v10->__vftable;
        if ( !v10 )
          goto LABEL_29;
      }
      --*((_DWORD *)v2 + 11);
      v11 = v10->__vftable;
      if ( v4 )
        v4->__vftable = v11;
      else
        *((_DWORD *)v2 + 13) = v11;
      if ( !v10->__vftable )
      {
        v12 = v4;
        if ( !v4 )
          v12 = (vostok::memory::doug_lea_allocator *)*((_DWORD *)v2 + 13);
        *((_DWORD *)v2 + 14) = v12;
      }
    }
LABEL_29:
    vostok::memory::doug_lea_allocator::free_impl(v4, (int)vostok::sound::g_allocator, i, v13, v14, v15);
  }
  vostok::memory::doug_lea_allocator::free_impl(statistic, (int)vostok::sound::g_allocator, v2, v13, v14, v15);
}
