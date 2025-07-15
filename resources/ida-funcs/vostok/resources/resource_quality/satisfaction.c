double __thiscall vostok::resources::resource_quality::satisfaction(
        vostok::resources::resource_quality *this,
        unsigned int quality_level,
        const vostok::resources::resource_base *resource_user,
        unsigned int positional_users_count)
{
  vostok::resources::resource_quality *v5; // ecx
  vostok::threading::simple_lock *m_flags; // ecx
  const vostok::resources::resource_base *v7; // esi
  vostok::resources::cook_base *cook; // eax
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_parent_resources; // esi
  const vostok::threading::simple_lock *v10; // eax
  vostok::resources::resource_link *no_dying; // esi
  double result; // st7
  vostok::threading::simple_lock::mutex_raii v13; // [esp+Ch] [ebp-10h] BYREF
  float v14; // [esp+14h] [ebp-8h]
  float v15; // [esp+28h] [ebp+Ch]

  v5 = (unsigned __int8)((this->m_flags.m_flags & 2) - 2) == 0 ? this : 0;
  if ( v5 )
  {
    ((void (__thiscall *)(vostok::resources::resource_quality *, unsigned int))v5->__vftable[1].~vostok::resources::resource_quality)(
      v5,
      quality_level);
    return result;
  }
  if ( resource_user )
  {
    m_flags = (vostok::threading::simple_lock *)resource_user->m_flags.m_flags;
    LOBYTE(m_flags) = ((unsigned __int8)m_flags & 8) - 8;
    v7 = (unsigned __int8)m_flags == 0 ? resource_user : 0;
    if ( v7 )
    {
      cook = vostok::resources::resources_manager::find_cook(this->m_class_id);
      cook->satisfaction_with(
        cook,
        quality_level,
        (const vostok::math::float4x4 *)&v7[1].m_children_resources.m_last,
        positional_users_count);
      return result;
    }
    p_m_parent_resources = &resource_user->m_parent_resources;
  }
  else
  {
    positional_users_count = vostok::resources::resource_quality::positional_users_count(this, 0);
    p_m_parent_resources = &this->m_parent_resources;
  }
  if ( p_m_parent_resources )
    v10 = &p_m_parent_resources->vostok::threading::simple_lock;
  else
    v10 = 0;
  v13.lock = v10;
  vostok::threading::simple_lock::lock(m_flags, (int)v10);
  v13.locked = 1;
  no_dying = vostok::resources::resource_link_list_front_no_dying(p_m_parent_resources);
  v15 = FLOAT_2048_0;
  if ( !no_dying )
    goto LABEL_16;
  do
  {
    v14 = vostok::resources::resource_quality::satisfaction(
            this,
            quality_level,
            no_dying->resource,
            positional_users_count);
    if ( v14 <= (double)v15 )
      v15 = v14;
    no_dying = vostok::resources::resource_link_list_next_no_dying(no_dying);
  }
  while ( no_dying );
  if ( v15 >= 1024.0 )
LABEL_16:
    v15 = vostok::resources::resource_quality::calculate_best_satisfaction_based_on_size(this);
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v13);
  return v15;
}
