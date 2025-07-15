unsigned int __thiscall btCollisionWorld::RayResultCallback::getShapeId(
        btCollisionWorld::RayResultCallback *this,
        unsigned int local_shape_id)
{
  unsigned int result; // eax

  result = this->m_shape_id;
  if ( result == -1 )
    return local_shape_id;
  return result;
}
