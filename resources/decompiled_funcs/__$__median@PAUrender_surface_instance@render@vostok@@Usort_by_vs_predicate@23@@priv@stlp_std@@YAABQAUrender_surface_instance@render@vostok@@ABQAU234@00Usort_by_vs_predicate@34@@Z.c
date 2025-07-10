const vostok::render::render_surface_instance **__cdecl stlp_std::priv::__median<vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        const vostok::render::render_surface_instance **__a,
        const vostok::render::render_surface_instance **__b,
        const vostok::render::render_surface_instance **__c,
        vostok::render::sort_by_ps_predicate __comp)
{
  const vostok::render::render_surface_instance *v4; // ebx
  const vostok::render::render_surface_instance *v5; // esi
  const vostok::render::render_surface_instance *v6; // ebp
  const vostok::render::render_surface_instance **result; // eax
  const vostok::render::render_surface_instance *v8; // ebp
  bool v9; // zf

  v4 = *__a;
  v5 = *__b;
  if ( vostok::render::sort_by_vs_predicate::operator()(&__comp, *__a, *__b) )
  {
    v6 = *__c;
    if ( !vostok::render::sort_by_vs_predicate::operator()(&__comp, v5, *__c) )
    {
      if ( vostok::render::sort_by_vs_predicate::operator()(&__comp, v4, v6) )
        return __c;
      return __a;
    }
    return __b;
  }
  v8 = *__c;
  if ( vostok::render::sort_by_vs_predicate::operator()(&__comp, v4, *__c) )
    return __a;
  v9 = !vostok::render::sort_by_vs_predicate::operator()(&__comp, v5, v8);
  result = __c;
  if ( v9 )
    return __b;
  return result;
}
