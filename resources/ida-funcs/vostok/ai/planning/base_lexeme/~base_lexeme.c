void __thiscall vostok::ai::planning::base_lexeme::~base_lexeme(vostok::ai::planning::base_lexeme *this)
{
  vostok::ai::planning::base_lexeme_ptr *v2; // ecx

  this->__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::base_lexeme::`vftable';
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(
    (vostok::ai::planning::base_lexeme_ptr *)this,
    (int *)&this->m_right);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(v2, (int *)&this->m_left);
}
