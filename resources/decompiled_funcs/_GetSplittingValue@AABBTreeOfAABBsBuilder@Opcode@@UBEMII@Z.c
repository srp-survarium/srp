double __thiscall Opcode::AABBTreeOfAABBsBuilder::GetSplittingValue(
        Opcode::AABBTreeOfAABBsBuilder *this,
        unsigned int index,
        unsigned int axis)
{
  return *(&this->mAABBArray[index].mCenter.x + axis);
}
