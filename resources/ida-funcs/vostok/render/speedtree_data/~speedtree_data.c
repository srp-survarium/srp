void __usercall vostok::render::speedtree_data::~speedtree_data(
        vostok::render::speedtree_data *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<eax>)
{
  vostok::resources::unmanaged_resource *v3; // eax
  vostok::resources::unmanaged_resource **v4; // esi
  int i; // ebx
  int v6; // eax
  vostok::resources::unmanaged_resource **v7; // esi
  int j; // edi
  int v9; // eax

  v3 = a2[356];
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&a2[356]->vostok::resources::unmanaged_intrusive_base, a2[356]);
  v4 = a2 + 11;
  for ( i = 4; i >= 0; --i )
  {
    v6 = (int)*--v4;
    if ( v6 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v4)->vostok::resources::unmanaged_intrusive_base, *v4);
  }
  v7 = a2 + 6;
  for ( j = 4; j >= 0; --j )
  {
    v9 = (int)*--v7;
    if ( v9 )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 208), 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&(*v7)->vostok::resources::unmanaged_intrusive_base, *v7);
    }
  }
}
