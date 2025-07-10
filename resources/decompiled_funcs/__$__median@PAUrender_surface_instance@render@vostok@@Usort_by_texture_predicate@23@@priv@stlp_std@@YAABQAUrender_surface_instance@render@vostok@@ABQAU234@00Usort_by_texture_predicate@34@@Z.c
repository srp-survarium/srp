const vostok::render::render_surface_instance **__cdecl stlp_std::priv::__median<vostok::render::render_surface_instance *,vostok::render::sort_by_texture_predicate>(
        const vostok::render::render_surface_instance **__a,
        const vostok::render::render_surface_instance **__b,
        const vostok::render::render_surface_instance **__c,
        vostok::render::sort_by_texture_predicate __comp)
{
  const vostok::render::render_surface_instance *v4; // esi
  const vostok::render::render_surface_instance *v5; // edi
  bool v6; // al
  const vostok::render::render_surface_instance *v7; // ebx
  const vostok::render::render_surface_instance **result; // eax
  bool v9; // zf
  const vostok::render::render_surface_instance *v10; // [esp-4h] [ebp-14h]

  v4 = *__b;
  v5 = *__a;
  v6 = vostok::render::sort_by_texture_predicate::operator()(&__comp, *__a, *__b);
  v7 = *__c;
  v10 = *__c;
  if ( v6 )
  {
    if ( !vostok::render::sort_by_texture_predicate::operator()(&__comp, v4, v10) )
    {
      if ( vostok::render::sort_by_texture_predicate::operator()(&__comp, v5, v7) )
        return __c;
      return __a;
    }
    return __b;
  }
  if ( vostok::render::sort_by_texture_predicate::operator()(&__comp, v5, v10) )
    return __a;
  v9 = !vostok::render::sort_by_texture_predicate::operator()(&__comp, v4, v7);
  result = __c;
  if ( v9 )
    return __b;
  return result;
}
