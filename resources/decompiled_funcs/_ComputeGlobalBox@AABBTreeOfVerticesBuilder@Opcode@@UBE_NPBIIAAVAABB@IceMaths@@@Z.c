char __thiscall Opcode::AABBTreeOfVerticesBuilder::ComputeGlobalBox(
        Opcode::AABBTreeOfVerticesBuilder *this,
        const unsigned int *primitives,
        unsigned int nb_prims,
        IceMaths::AABB *global_box)
{
  unsigned int v4; // esi
  const IceMaths::Point *mVertexArray; // ebp

  if ( !primitives || !nb_prims )
    return 0;
  global_box->mCenter.z = 0.0;
  global_box->mCenter.y = 0.0;
  global_box->mCenter.x = 0.0;
  v4 = 0;
  global_box->mExtents.x = -3.4028235e38;
  global_box->mExtents.y = -3.4028235e38;
  global_box->mExtents.z = -3.4028235e38;
  mVertexArray = this->mVertexArray;
  do
    IceMaths::AABB::Extend((IceMaths::AABB *)&mVertexArray[primitives[v4++]], &global_box->mCenter.x);
  while ( v4 < nb_prims );
  return 1;
}
