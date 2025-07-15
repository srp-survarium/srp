void __thiscall vostok::resources::queries_result::mark_inconsistent_qualities_as_failed(
        vostok::resources::queries_result *this,
        _DWORD *a2)
{
  void *v3; // esp
  unsigned int v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  unsigned int i; // esi
  int v7; // ecx
  _DWORD *j; // eax
  unsigned int v9; // edi
  _DWORD *v10; // esi
  unsigned int v11[3]; // [esp+0h] [ebp-Ch] BYREF
  unsigned int v12; // [esp+14h] [ebp+8h]

  v3 = alloca(4 * a2[14]);
  v4 = 0;
  if ( a2[14] )
  {
    this = (vostok::resources::queries_result *)(a2 + 194);
    do
    {
      v11[v4++] = (unsigned int)this->m_callback.vtable;
      this = (vostok::resources::queries_result *)((char *)this + 736);
    }
    while ( v4 < a2[14] );
  }
  stlp_std::sort<unsigned int *>(v11, &v11[a2[14]], (stlp_std::less<unsigned int>)this);
  v12 = -1;
  for ( i = a2[14]; ; v12 = i )
  {
    if ( (--i & 0x80000000) == 0 )
    {
      v7 = 0;
      for ( j = a2 + 194; *j != v11[i]; j += 184 )
        ++v7;
      if ( vostok::resources::query_result_for_user::is_successful(
             (vostok::resources::query_result_for_user *)(736 * v7),
             (int)&a2[184 * v7 + 20]) )
      {
        continue;
      }
    }
    break;
  }
  v9 = 0;
  if ( a2[14] )
  {
    v10 = a2 + 84;
    do
    {
      if ( v10[110] < v12 )
      {
        if ( vostok::resources::query_result_for_user::is_successful(v5, (int)(v10 - 64)) )
          *v10 = 13;
      }
      ++v9;
      v10 += 184;
    }
    while ( v9 < a2[14] );
  }
}
