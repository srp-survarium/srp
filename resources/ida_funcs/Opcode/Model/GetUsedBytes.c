unsigned int __thiscall Opcode::Model::GetUsedBytes(Opcode::Model *this)
{
  if ( this->mTree )
    return this->mTree->GetUsedBytes(this->mTree);
  else
    return 0;
}
