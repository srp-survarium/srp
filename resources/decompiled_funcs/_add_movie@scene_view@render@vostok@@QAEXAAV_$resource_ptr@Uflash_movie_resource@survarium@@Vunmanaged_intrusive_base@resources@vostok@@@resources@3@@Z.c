void __usercall vostok::render::scene_view::add_movie(vostok::render::scene_view *this@<ecx>, int a2@<eax>)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *> *v4; // edi
  vostok::render::scene_view_vtbl *v5; // ecx
  const stlp_std::__false_type *v6; // [esp+0h] [ebp-Ch]
  unsigned int v7; // [esp+4h] [ebp-8h]
  bool __comp; // [esp+8h] [ebp-4h]

  v3 = *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 1432);
  v4 = (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *> *)(a2 + 1428);
  if ( v3 == *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 1436) )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
      (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > > *)this,
      v4,
      v3,
      (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this,
      v6,
      v7,
      __comp);
  }
  else
  {
    if ( v3 )
    {
      v3->m_object = 0;
      v5 = this->__vftable;
      if ( v5 )
      {
        v3->m_object = (survarium::flash_movie_resource *)v5;
        _InterlockedExchangeAdd((volatile signed __int32 *)&v5[7].unlink_child_resource, 1u);
      }
    }
    *(_DWORD *)(a2 + 1432) += 4;
  }
  stlp_std::sort<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *,vostok::render::priority_less>(
    (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v4->current,
    *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 1432),
    (vostok::render::priority_less)__comp);
}
