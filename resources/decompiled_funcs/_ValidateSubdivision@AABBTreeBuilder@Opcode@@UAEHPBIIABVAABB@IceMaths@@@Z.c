BOOL __thiscall Opcode::AABBTreeBuilder::ValidateSubdivision(
        Opcode::AABBTreeBuilder *this,
        const unsigned int *primitives,
        unsigned int nb_prims,
        const IceMaths::AABB *global_box)
{
  return this->mSettings.mLimit < nb_prims;
}
