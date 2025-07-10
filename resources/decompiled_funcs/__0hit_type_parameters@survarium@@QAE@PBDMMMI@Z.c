void __thiscall survarium::hit_type_parameters::hit_type_parameters(
        survarium::hit_type_parameters *this,
        const char *type,
        float absorption,
        float armor,
        float reduce,
        unsigned int bdb_count)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->next = 0;
  vostok::fixed_string<16>::fixed_string<16>(&this->m_type, type);
  this->m_absorption_amount = absorption;
  this->m_armor = armor;
  this->m_reduce = reduce;
  this->m_bdb_count = bdb_count;
}
