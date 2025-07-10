void __thiscall Opcode::Model::~Model(Opcode::Model *this)
{
  Opcode::BaseModel *v2; // ecx

  this->__vftable = (Opcode::Model_vtbl *)&Opcode::Model::`vftable';
  Opcode::BaseModel::ReleaseBase(this);
  this->__vftable = (Opcode::Model_vtbl *)&Opcode::BaseModel::`vftable';
  Opcode::BaseModel::ReleaseBase(v2);
}
