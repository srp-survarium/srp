vostok::sound::sound_environment *__thiscall vostok::sound::sound_scene::get_current_environment(
        vostok::sound::sound_scene *this)
{
  vostok::vectora_allocator<void const *> __a; // [esp+B8h] [ebp-58h] BYREF
  vostok::resources::unmanaged_resource *m_object; // [esp+BCh] [ebp-54h]
  vostok::vectora_allocator<vostok::collision::object const *> allocator; // [esp+C0h] [ebp-50h] BYREF
  vostok::sound::sound_environment *v6; // [esp+C4h] [ebp-4Ch]
  vostok::sound::sound_environment *m_default_environment; // [esp+C8h] [ebp-48h]
  vostok::math::float3 result; // [esp+CCh] [ebp-44h] BYREF
  vostok::math::float3 radius; // [esp+D8h] [ebp-38h] BYREF
  vostok::math::aabb aabb; // [esp+E4h] [ebp-2Ch] BYREF
  vostok::sound::sound_environment *test; // [esp+FCh] [ebp-14h]
  vostok::vectora<vostok::collision::object const *> query_result; // [esp+100h] [ebp-10h] BYREF

  m_object = vostok::sound::g_allocator.m_object;
  allocator.m_allocator = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
  Scaleform::Render::Color::Color(&__a, &allocator);
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
    &query_result._M_impl,
    &__a);
  vostok::math::half3_pod::operator vostok::math::float3(&this->m_list_position.m_data.m_val, &result);
  radius.x = FLOAT_1_0;
  radius.y = FLOAT_1_0;
  radius.z = FLOAT_1_0;
  vostok::math::create_aabb_center_radius(&aabb, &result, &radius);
  this->m_environments_tree->aabb_query(this->m_environments_tree, 1u, &aabb, &query_result);
  if ( query_result._M_impl._M_start == query_result._M_impl._M_finish )
  {
    m_default_environment = this->m_default_environment;
    stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>((vostok::vectora<vostok::resources::request> *)&query_result);
    return m_default_environment;
  }
  else
  {
    test = (vostok::sound::sound_environment *)*((_DWORD *)*query_result._M_impl._M_start + 9);
    v6 = test;
    stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>((vostok::vectora<vostok::resources::request> *)&query_result);
    return v6;
  }
}
