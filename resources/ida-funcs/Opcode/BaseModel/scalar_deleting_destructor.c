Opcode::BaseModel *__thiscall Opcode::BaseModel::`scalar deleting destructor'(Opcode::BaseModel *this, char a2)
{
  Opcode::BaseModel::~BaseModel(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
