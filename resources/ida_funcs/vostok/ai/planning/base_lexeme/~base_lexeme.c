void __thiscall vostok::ai::planning::base_lexeme::~base_lexeme(vostok::ai::planning::base_lexeme *this)
{
  this->__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::base_lexeme::`vftable';
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&this->m_right);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&this->m_left);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_value);
}
