char __userpurge Opcode::MeshInterface::SetPointers@<al>(
        const IceMaths::IndexedTriangle *tris@<eax>,
        const IceMaths::Point *verts@<ecx>,
        Opcode::MeshInterface *this)
{
  if ( !tris || !verts )
    return 0;
  this->mTris = tris;
  this->mVerts = verts;
  return 1;
}
