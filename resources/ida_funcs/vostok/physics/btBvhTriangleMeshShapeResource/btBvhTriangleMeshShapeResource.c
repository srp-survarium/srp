void __userpurge vostok::physics::btBvhTriangleMeshShapeResource::btBvhTriangleMeshShapeResource(
        vostok::physics::btBvhTriangleMeshShapeResource *this@<esi>,
        btStridingMeshInterface *meshInterface@<edi>,
        unsigned __int16 *face_data,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *vertices_resource,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *indices_resource)
{
  btTriangleMeshShape::btTriangleMeshShape(this, meshInterface);
  this->m_bvh = 0;
  this->m_triangleInfoMap = 0;
  this->m_useQuantizedAabbCompression = 1;
  this->m_ownsBvh = 0;
  this->m_shapeType = 21;
  this->__vftable = (vostok::physics::btBvhTriangleMeshShapeResource_vtbl *)&vostok::physics::btBvhTriangleMeshShapeResource::`vftable';
  this->m_face_data = face_data;
  this->m_raw_vertices.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->m_raw_vertices,
    vertices_resource);
  this->m_raw_indices.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->m_raw_indices,
    indices_resource);
}
