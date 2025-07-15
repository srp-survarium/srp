void __thiscall survarium::bullet_manager::add_decal_impl(
        survarium::bullet_manager *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *decal,
        float size,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        const vostok::math::float3 *normal,
        bool is_front_face)
{
  unsigned int m_current_decal_id; // [esp+18h] [ebp-Ch]

  m_current_decal_id = this->m_current_decal_id;
  this->m_current_decal_id = m_current_decal_id + 1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->m_engine->add_decal)(
    this->m_engine,
    decal,
    m_current_decal_id,
    LODWORD(size),
    0.1,
    position,
    direction,
    normal,
    is_front_face);
  if ( this->m_current_decal_id == this->m_max_bullets_decals_count )
    this->m_current_decal_id = 0;
}


void __thiscall survarium::bullet_manager::add_decal_impl(
        survarium::bullet_manager *this,
        survarium::bullet_manager::bullet_functor *const functor)
{
  survarium::bullet_manager::add_decal_impl(
    this,
    &functor->resource,
    functor->size,
    &functor->position,
    &functor->direction,
    &functor->normal,
    functor->is_front_face);
}
