Opcode::AABBTreeOfTrianglesBuilder *__thiscall Opcode::AABBTreeBuilder::`scalar deleting destructor'(
        Opcode::AABBTreeOfTrianglesBuilder *this,
        char a2)
{
  this->__vftable = (Opcode::AABBTreeOfTrianglesBuilder_vtbl *)&Opcode::AABBTreeBuilder::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
