Opcode::Model *__thiscall Opcode::Model::`vector deleting destructor'(Opcode::Model *this, char a2)
{
  Opcode::BaseModel *v3; // ecx

  this->__vftable = (Opcode::Model_vtbl *)&Opcode::Model::`vftable';
  Opcode::BaseModel::ReleaseBase(this);
  this->__vftable = (Opcode::Model_vtbl *)&Opcode::BaseModel::`vftable';
  Opcode::BaseModel::ReleaseBase(v3);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
