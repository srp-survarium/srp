void __usercall survarium::player_creation_params::~player_creation_params(
        survarium::player_creation_params *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  vostok::resources::unmanaged_resource *v2; // eax
  vostok::resources::unmanaged_resource *v3; // eax
  vostok::resources::unmanaged_resource *v4; // eax

  v2 = a2[78];
  if ( v2 )
  {
    this = (survarium::player_creation_params *)_InterlockedExchangeAdd(&v2->m_reference_count, 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(&a2[78]->vostok::resources::unmanaged_intrusive_base, a2[78]);
  }
  v3 = a2[75];
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&a2[75]->vostok::resources::unmanaged_intrusive_base, a2[75]);
  v4 = a2[74];
  if ( v4 )
  {
    this = (survarium::player_creation_params *)_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(&a2[74]->vostok::resources::unmanaged_intrusive_base, a2[74]);
  }
  survarium::base_player_creation_params::~base_player_creation_params(this, (int)a2);
}
