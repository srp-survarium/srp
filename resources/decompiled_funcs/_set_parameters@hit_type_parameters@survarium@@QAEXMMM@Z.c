void __thiscall survarium::hit_type_parameters::set_parameters(
        survarium::hit_type_parameters *this,
        float armor,
        float reduce,
        float absorbtion)
{
  this->m_armor = armor;
  this->m_reduce = reduce;
  this->m_absorption_amount = absorbtion;
}
