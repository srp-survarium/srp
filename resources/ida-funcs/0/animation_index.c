unsigned int __cdecl animation_index(vostok::math::random32 *random, unsigned int animations_count)
{
  unsigned int v2; // eax
  unsigned int result; // eax
  void *v4; // esp
  unsigned int v5; // ecx
  int v6; // edx
  _DWORD *v7; // eax
  vostok::buffer_vector<unsigned int> *v8; // [esp-4h] [ebp-24h]
  _DWORD v9[4]; // [esp+0h] [ebp-20h] BYREF
  _DWORD *v10; // [esp+10h] [ebp-10h] BYREF
  _DWORD *v11; // [esp+14h] [ebp-Ch]
  _DWORD *v12; // [esp+18h] [ebp-8h]
  unsigned int v13; // [esp+1Ch] [ebp-4h] BYREF

  if ( animations_count > 3 )
  {
    v4 = alloca(4 * animations_count);
    v13 = 0;
    v10 = v9;
    v11 = v9;
    v12 = &v9[animations_count];
    do
    {
      if ( stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
             (char *)s_previous_animation_indices,
             (int *)&v13,
             (char *)affects_captions_100) == (char *)affects_captions_100 )
        vostok::buffer_vector<unsigned int>::push_back(v8, (int)&v10, &v13);
      ++v13;
    }
    while ( v13 < animations_count );
    v5 = 134775813 * random->m_seed + 1;
    v6 = (v5 * (unsigned __int64)(unsigned int)(v11 - v10)) >> 32;
    v7 = v10;
    random->m_seed = v5;
    result = v7[v6];
    s_previous_animation_indices[0] = s_previous_animation_indices[1];
    s_previous_animation_indices[1] = s_previous_animation_indices[2];
    s_previous_animation_indices[2] = result;
  }
  else
  {
    v2 = 134775813 * random->m_seed + 1;
    random->m_seed = v2;
    return (animations_count * (unsigned __int64)v2) >> 32;
  }
  return result;
}
