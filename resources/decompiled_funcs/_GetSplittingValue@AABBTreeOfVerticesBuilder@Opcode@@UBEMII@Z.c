double __thiscall Opcode::AABBTreeOfVerticesBuilder::GetSplittingValue(
        Opcode::AABBTreeOfVerticesBuilder *this,
        unsigned int index,
        unsigned int axis)
{
  return *(&this->mVertexArray->x + 2 * index + index + axis);
}
