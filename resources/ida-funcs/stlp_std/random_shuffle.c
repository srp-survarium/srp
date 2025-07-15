void __usercall stlp_std::random_shuffle<vostok::render::render_surface_instance * *,vostok::math::random32>(
        vostok::math::random32 *__rand@<edi>,
        vostok::render::render_surface_instance **__first,
        vostok::render::render_surface_instance **__last)
{
  vostok::render::render_surface_instance **v3; // ecx
  int v4; // esi
  unsigned int v5; // edx
  int v6; // edx
  vostok::render::render_surface_instance *v7; // ebp
  vostok::render::render_surface_instance **v8; // eax
  vostok::render::render_surface_instance *v9; // edx

  if ( __first != __last )
  {
    v3 = __first + 1;
    if ( __first + 1 != __last )
    {
      v4 = 4;
      do
      {
        v5 = 134775813 * __rand->m_seed + 1;
        __rand->m_seed = v5;
        v6 = (v5 * (unsigned __int64)(unsigned int)((v4 >> 2) + 1)) >> 32;
        v7 = __first[v6];
        v8 = &__first[v6];
        v9 = *v3;
        *v3++ = v7;
        v4 += 4;
        *v8 = v9;
      }
      while ( v3 != __last );
    }
  }
}


void __cdecl stlp_std::random_shuffle<survarium::artefact_container_core * *>(
        survarium::artefact_container_core **__first,
        survarium::artefact_container_core **__last)
{
  int v2; // eax
  survarium::artefact_container_core **__i; // [esp+18h] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v2 = rand();
      stlp_std::iter_swap<vostok::ai::sound_item const * *,vostok::ai::sound_item const * *>(
        (const vostok::ai::movement_target **)__i,
        (const vostok::ai::movement_target **)&__first[v2 % (__i - __first + 1)]);
    }
  }
}
