Opcode::Model *__thiscall Opcode::Model::`vector deleting destructor'(Opcode::Model *this, char a2)
{
  Opcode::Model::~Model(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
