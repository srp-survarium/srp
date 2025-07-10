void __userpurge vostok::collision::resource_guard::resource_guard(
        vostok::collision::resource_guard *this@<esi>,
        const vostok::vectora<unsigned int> *indices@<eax>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> resource,
        Opcode::MeshInterface *mesh)
{
  Opcode::MeshInterface *v4; // ebx
  unsigned int *M_start; // ecx
  const unsigned __int8 *v6; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v7; // [esp-4h] [ebp-Ch] BYREF

  v4 = mesh;
  v7.m_object = (vostok::resources::managed_resource *)&resource;
  this->m_indices = indices;
  this->mesh = v4;
  mesh = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&mesh,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v7.m_object);
  v7.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v7,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&mesh);
  vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
    &this->pinned_data,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v7.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&mesh);
  M_start = this->m_indices->_M_impl._M_start;
  v6 = this->pinned_data.m_data + 36;
  if ( M_start && this->pinned_data.m_data != (const unsigned __int8 *)-36 )
  {
    v4->mTris = (const IceMaths::IndexedTriangle *)M_start;
    v4->mVerts = (const IceMaths::Point *)v6;
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&resource);
}
