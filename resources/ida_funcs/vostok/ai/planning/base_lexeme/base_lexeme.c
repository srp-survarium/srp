void __thiscall vostok::ai::planning::base_lexeme::base_lexeme(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme::operation_type_enum operation_type,
        const vostok::ai::planning::base_lexeme *left,
        const vostok::ai::planning::base_lexeme *right,
        unsigned __int8 destroy_manually)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_value);
  this->__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::base_lexeme::`vftable';
  this->m_value = 1;
  vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(&this->m_left, left);
  vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(&this->m_right, right);
  this->m_counter = 0;
  this->m_destroy_manually = destroy_manually;
  this->m_operation_type = operation_type;
  vostok::ai::planning::base_lexeme::reset_pointers(this);
}


void __thiscall vostok::ai::planning::base_lexeme::base_lexeme(
        vostok::ai::planning::base_lexeme *this,
        unsigned __int8 destroy_manually)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_value);
  this->__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::base_lexeme::`vftable';
  this->m_value = 1;
  vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(&this->m_left, 0);
  vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(&this->m_right, 0);
  this->m_counter = 0;
  this->m_destroy_manually = destroy_manually;
  this->m_operation_type = 2;
  vostok::ai::planning::base_lexeme::reset_pointers(this);
}
