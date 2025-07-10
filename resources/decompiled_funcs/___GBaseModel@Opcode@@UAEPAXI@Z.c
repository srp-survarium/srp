Opcode::BaseModel *__thiscall Opcode::BaseModel::`scalar deleting destructor'(Opcode::BaseModel *this, char a2)
{
  this->__vftable = (Opcode::BaseModel_vtbl *)&Opcode::BaseModel::`vftable';
  Opcode::BaseModel::ReleaseBase(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
