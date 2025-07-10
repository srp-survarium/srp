void __usercall stlp_std::priv::__partial_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_ps_predicate>(
        vostok::render::render_surface_instance **__first@<eax>,
        vostok::render::render_surface_instance **__middle,
        vostok::render::render_surface_instance **__last,
        vostok::render::render_surface_instance **__formal,
        vostok::render::sort_by_ps_predicate __comp)
{
  const vostok::render::render_surface_instance **v5; // ebx
  int v7; // ebp
  vostok::render::sort_by_ps_predicate v8; // [esp-8h] [ebp-24h]
  vostok::render::render_surface_instance *__val; // [esp+10h] [ebp-Ch]

  v5 = (const vostok::render::render_surface_instance **)__middle;
  v7 = __middle - __first;
  if ( v7 >= 2 )
    stlp_std::__make_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate,vostok::render::render_surface_instance *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      __val = (vostok::render::render_surface_instance *)*v5;
      if ( vostok::render::sort_by_vs_predicate::operator()(
             (vostok::render::sort_by_ps_predicate *)&__formal,
             *v5,
             *__first) )
      {
        v8 = (vostok::render::sort_by_ps_predicate)__PAIR64__(__comp.m_stage_type, (unsigned int)__formal);
        *v5 = *__first;
        stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
          __first,
          0,
          v7,
          __val,
          v8);
      }
      ++v5;
    }
    while ( v5 < (const vostok::render::render_surface_instance **)__last );
  }
  stlp_std::sort_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
    __first,
    __middle,
    (vostok::render::sort_by_ps_predicate)__PAIR64__(__comp.m_stage_type, (unsigned int)__formal));
}
