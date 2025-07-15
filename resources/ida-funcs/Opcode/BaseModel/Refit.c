int __thiscall Opcode::BaseModel::Refit(Opcode::BaseModel *this)
{
  return ((int (__thiscall *)(Opcode::AABBOptimizedTree *, const Opcode::MeshInterface *))this->mTree->Refit)(
           this->mTree,
           this->mIMesh);
}
