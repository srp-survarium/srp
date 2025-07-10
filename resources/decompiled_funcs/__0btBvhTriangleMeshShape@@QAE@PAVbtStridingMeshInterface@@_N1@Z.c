void __usercall btBvhTriangleMeshShape::btBvhTriangleMeshShape(
        btBvhTriangleMeshShape *this@<esi>,
        btStridingMeshInterface *meshInterface@<edi>)
{
  btTriangleMeshShape::btTriangleMeshShape(this, meshInterface);
  this->m_bvh = 0;
  this->m_triangleInfoMap = 0;
  this->m_ownsBvh = 0;
  this->__vftable = (btBvhTriangleMeshShape_vtbl *)&btBvhTriangleMeshShape::`vftable';
  this->m_useQuantizedAabbCompression = 1;
  this->m_shapeType = 21;
}
