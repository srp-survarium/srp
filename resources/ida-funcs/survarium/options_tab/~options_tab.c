void __thiscall survarium::options_tab::~options_tab(survarium::options_tab *this, int a2)
{
  bool v3; // zf
  vostok::memory::doug_lea_allocator *v4; // esi
  void ***v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  survarium::options_tab *v7; // ebx
  survarium::flash_function_handler *v8; // [esp-4h] [ebp-18h]
  const char *v9; // [esp+0h] [ebp-14h]
  const char *v10; // [esp+4h] [ebp-10h]
  unsigned int v11; // [esp+8h] [ebp-Ch]
  char *v12; // [esp+10h] [ebp-4h]
  unsigned __int8 v13; // [esp+1Fh] [ebp+Bh]

  v3 = *(_BYTE *)(a2 + 4) == 0;
  v13 = 0;
  if ( !v3 )
  {
    do
    {
      this = *(survarium::options_tab **)a2;
      v4 = survarium::g_allocator;
      v5 = (void ***)(*(_DWORD *)a2 + 4 * v13);
      if ( *v5 )
      {
        v12 = __RTCastToVoid(*v5);
        survarium::flash_function_handler::~flash_function_handler(v8, *v5);
        vostok::memory::doug_lea_allocator::free_impl(v6, (int)v4, v12, v9, v10, v11);
        *v5 = 0;
      }
      ++v13;
    }
    while ( v13 < *(_BYTE *)(a2 + 4) );
  }
  v7 = *(survarium::options_tab **)a2;
  if ( v7 )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)&v7[-1].m_game,
      v9,
      v10,
      v11);
}
