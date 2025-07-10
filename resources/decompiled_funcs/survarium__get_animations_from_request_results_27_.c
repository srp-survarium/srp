void __cdecl survarium::get_animations_from_request_results_27_(
        vostok::resources::queries_result *data,
        unsigned int animations_count,
        unsigned int *resource_index,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*result)[27])
{
  survarium::game_camera *v4; // ecx
  vostok::resources::query_result *v5; // eax
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *managed_resource; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v7; // eax
  unsigned int index; // [esp+4h] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v9; // [esp+20h] [ebp-10h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v10; // [esp+24h] [ebp-Ch] BYREF
  char v11; // [esp+2Bh] [ebp-5h]
  unsigned int i; // [esp+2Ch] [ebp-4h]

  v11 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  for ( i = 0; i != animations_count; ++i )
  {
    index = (*resource_index)++;
    v5 = vostok::resources::queries_result::operator[](data, index);
    managed_resource = vostok::resources::query_result_for_user::get_managed_resource(v5, &v10);
    v7 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
           managed_resource,
           &v9);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
      &(*result)[i],
      v7);
    vostok::animation::mixing::animation_interval::~animation_interval(&v9);
    vostok::animation::mixing::animation_interval::~animation_interval(&v10);
  }
}
