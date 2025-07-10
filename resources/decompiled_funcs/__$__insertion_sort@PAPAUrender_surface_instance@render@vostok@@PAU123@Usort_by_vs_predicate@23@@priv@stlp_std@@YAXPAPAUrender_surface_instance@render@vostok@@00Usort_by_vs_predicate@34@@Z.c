void __cdecl stlp_std::priv::__insertion_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first,
        vostok::render::render_surface_instance **__last,
        vostok::render::render_surface_instance **a3)
{
  const vostok::render::render_surface_instance **v3; // ecx
  vostok::render::render_surface_instance **v4; // esi
  signed int v5; // ebx
  vostok::render::enum_render_stage_type v6; // edx
  const vostok::render::render_surface_instance *v7; // ecx
  vostok::render::render_surface_instance *v8; // ebp
  vostok::render::sort_by_ps_predicate v9; // [esp+10h] [ebp-8h] BYREF

  v3 = (const vostok::render::render_surface_instance **)__first;
  v4 = __first + 1;
  if ( __first + 1 != __last )
  {
    v5 = 4;
    while ( 1 )
    {
      v6 = (vostok::render::enum_render_stage_type)*a3;
      v7 = *v3;
      v8 = *v4;
      v9.m_tech_index = (unsigned int)a3[1];
      v9.m_stage_type = v6;
      if ( vostok::render::sort_by_vs_predicate::operator()(&v9, v8, v7) )
      {
        if ( v5 > 0 )
          memmove((unsigned __int8 *)&v4[v5 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v5);
        *__first = v8;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_ps_predicate>(
          v4,
          v8,
          *(vostok::render::sort_by_ps_predicate *)a3);
      }
      ++v4;
      v5 += 4;
      if ( v4 == __last )
        break;
      v3 = (const vostok::render::render_surface_instance **)__first;
    }
  }
}
