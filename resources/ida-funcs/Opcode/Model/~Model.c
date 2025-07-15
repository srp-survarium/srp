void __thiscall Opcode::Model::~Model(Opcode::Model *this)
{
  this->__vftable = (Opcode::Model_vtbl *)&Opcode::Model::`vftable';
  Opcode::BaseModel::ReleaseBase(this, (int)this);
  Opcode::BaseModel::~BaseModel(this);
}
