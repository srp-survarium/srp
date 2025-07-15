const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *__fastcall survarium::material_pair::collision_particle(
        survarium::material_pair *this,
        _DWORD *a2)
{
  _DWORD *v2; // eax
  int v3; // ecx

  v2 = a2 + 28;
  if ( a2[28] == (a2[22] - a2[21]) >> 2 )
    *v2 = 0;
  v3 = (*v2)++;
  return (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(a2[21] + 4 * v3);
}
