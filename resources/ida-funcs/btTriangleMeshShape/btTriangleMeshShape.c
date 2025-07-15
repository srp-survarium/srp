void __usercall btTriangleMeshShape::btTriangleMeshShape(
        btTriangleMeshShape *this@<esi>,
        btStridingMeshInterface *meshInterface@<edi>)
{
  btTriangleMeshShape *v2; // ecx

  this->m_userPointer = 0;
  this->m_collisionMargin = 0.0;
  this->__vftable = (btTriangleMeshShape_vtbl *)&btTriangleMeshShape::`vftable';
  this->m_meshInterface = meshInterface;
  this->m_shapeType = 21;
  if ( meshInterface->hasPremadeAabb(meshInterface) )
    meshInterface->getPremadeAabb(meshInterface, &this->m_localAabbMin, &this->m_localAabbMax);
  else
    btTriangleMeshShape::recalcLocalAabb(v2, (float *)this);
}
