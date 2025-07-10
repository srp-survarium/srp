signed int *__cdecl floor1_unpack(vorbis_info *vi, oggpack_buffer *opb)
{
  vostok::memory::doug_lea_mt_allocator *codec_setup; // ecx
  signed int v3; // esi
  signed int *v4; // ebp
  signed int v5; // eax
  signed int *v6; // ebx
  signed int v7; // eax
  int v8; // ebx
  int *v9; // esi
  signed int v10; // eax
  int v11; // ebp
  signed int *v12; // ebx
  signed int v13; // eax
  int v14; // ebx
  signed int *v15; // eax
  int v16; // ebp
  int v17; // esi
  signed int *v18; // esi
  signed int v19; // eax
  int *v20; // edx
  signed int v21; // esi
  signed int v22; // eax
  int *v23; // ecx
  int v24; // eax
  vostok::memory::doug_lea_mt_allocator *v26; // ecx
  vostok::memory *v27; // [esp+0h] [ebp-12Ch]
  bool v28; // [esp+0h] [ebp-12Ch]
  bool v29; // [esp+4h] [ebp-128h]
  bool v30; // [esp+8h] [ebp-124h]
  bool v31; // [esp+Ch] [ebp-120h]
  int maxclass; // [esp+10h] [ebp-11Ch]
  int maxclassa; // [esp+10h] [ebp-11Ch]
  _DWORD *maxclassb; // [esp+10h] [ebp-11Ch]
  signed int *v35; // [esp+14h] [ebp-118h]
  int count; // [esp+18h] [ebp-114h]
  int j; // [esp+1Ch] [ebp-110h]
  int ja; // [esp+1Ch] [ebp-110h]
  codec_setup_info *ci; // [esp+20h] [ebp-10Ch]
  int v40; // [esp+24h] [ebp-108h]
  int *sortpointer[65]; // [esp+28h] [ebp-104h] BYREF

  codec_setup = (vostok::memory::doug_lea_mt_allocator *)vi->codec_setup;
  v3 = 0;
  ci = (codec_setup_info *)codec_setup;
  count = 0;
  maxclass = -1;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v27);
  v4 = (signed int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(codec_setup, 0x460u);
  v35 = v4;
  memset((int)v4, 0, 0x460u);
  v5 = oggpack_read(opb, 5u);
  *v4 = v5;
  if ( v5 <= 0 )
  {
LABEL_9:
    v8 = maxclass + 1;
    j = 0;
    v40 = maxclass + 1;
    if ( maxclass + 1 <= 0 )
    {
LABEL_23:
      v4[208] = oggpack_read(opb, 2u) + 1;
      v14 = oggpack_read(opb, 4u);
      if ( v14 >= 0 )
      {
        v15 = v35;
        v16 = 0;
        ja = 0;
        if ( *v35 <= 0 )
        {
          v17 = 0;
LABEL_36:
          v20 = v15 + 209;
          v21 = v17 + 2;
          v15[209] = 0;
          v15[210] = 1 << v14;
          v22 = 0;
          if ( v21 > 0 )
          {
            v23 = v20;
            do
              sortpointer[v22++] = v23++;
            while ( v22 < v21 );
          }
          qsort((char *)sortpointer, v21, 4u, (int (__cdecl *)(const void *, const void *))icomp);
          v24 = 1;
          if ( v21 <= 1 )
            return v35;
          while ( *sortpointer[v24 - 1] != *sortpointer[v24] )
          {
            if ( ++v24 >= v21 )
              return v35;
          }
        }
        else
        {
          maxclassb = v35 + 1;
          while ( 1 )
          {
            count += v15[*maxclassb + 32];
            v17 = count;
            if ( count > 63 )
              break;
            if ( v16 < count )
            {
              v18 = &v35[v16 + 211];
              while ( 1 )
              {
                v19 = oggpack_read(opb, v14);
                *v18 = v19;
                if ( v19 < 0 || v19 >= 1 << v14 )
                  goto LABEL_44;
                ++v16;
                ++v18;
                if ( v16 >= count )
                {
                  v17 = count;
                  break;
                }
              }
            }
            ++maxclassb;
            if ( ++ja >= *v35 )
            {
              v15 = v35;
              goto LABEL_36;
            }
            v15 = v35;
          }
        }
LABEL_44:
        v4 = v35;
      }
    }
    else
    {
      maxclassa = (int)(v4 + 80);
      v9 = v4 + 64;
      while ( 1 )
      {
        *(v9 - 32) = oggpack_read(opb, 3u) + 1;
        v10 = oggpack_read(opb, 2u);
        *(v9 - 16) = v10;
        if ( v10 < 0 )
          break;
        if ( v10 )
          *v9 = oggpack_read(opb, 8u);
        if ( *v9 < 0 || *v9 >= ci->books )
          break;
        v11 = 0;
        if ( 1 << *(v9 - 16) > 0 )
        {
          v12 = (signed int *)maxclassa;
          while ( 1 )
          {
            v13 = oggpack_read(opb, 8u) - 1;
            *v12 = v13;
            if ( v13 < -1 || v13 >= ci->books )
              goto LABEL_44;
            ++v11;
            ++v12;
            if ( v11 >= 1 << *(v9 - 16) )
            {
              v8 = v40;
              break;
            }
          }
        }
        maxclassa += 32;
        v4 = v35;
        ++v9;
        if ( ++j >= v8 )
          goto LABEL_23;
      }
    }
  }
  else
  {
    v6 = v4 + 1;
    while ( 1 )
    {
      v7 = oggpack_read(opb, 4u);
      *v6 = v7;
      if ( v7 < 0 )
        break;
      if ( maxclass < v7 )
        maxclass = v7;
      ++v3;
      ++v6;
      if ( v3 >= *v4 )
        goto LABEL_9;
    }
  }
  memset((int)v4, 0, 0x460u);
  if ( !vostok::memory::g_crt_allocator.__vftable )
  {
    vostok::debug::preinitialize(v27);
    if ( !vostok::core::g_log_callback )
    {
      vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
      vostok::debug::set_log_callback(vostok::core::debug_log_callback);
    }
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      if ( !_InterlockedExchange((volatile __int32 *)&s_crt_allocator_creation, 1) )
      {
        vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(v26, v28, v29, v30, v31);
        (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
          s_crt_allocator_buffer,
          vostok::memory::s_CRT_arena,
          &vostok::memory::s_CRT_arena[55905848],
          0,
          "CRT allocator");
        _InterlockedExchange((volatile __int32 *)&vostok::memory::g_crt_allocator, (__int32)s_crt_allocator_buffer);
        vostok::memory::doug_lea_mt_allocator::free_impl(&vostok::memory::g_crt_allocator, v4);
        return 0;
      }
      while ( !vostok::memory::g_crt_allocator.__vftable )
        ;
    }
  }
  vostok::memory::doug_lea_mt_allocator::free_impl(v26, v4);
  return 0;
}
