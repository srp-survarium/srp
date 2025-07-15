double __thiscall Opcode::AABBTreeBuilder::GetSplittingValue(
        Opcode::AABBTreeBuilder *this,
        const unsigned int *primitives,
        unsigned int nb_prims,
        const IceMaths::AABB *global_box,
        unsigned int axis)
{
  return *(&global_box->mCenter.x + axis);
}
