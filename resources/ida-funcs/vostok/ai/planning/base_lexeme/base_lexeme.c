void __userpurge vostok::ai::planning::base_lexeme::base_lexeme(
        const vostok::ai::planning::base_lexeme *left@<eax>,
        const vostok::ai::planning::base_lexeme *right@<edx>,
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme::operation_type_enum operation_type,
        unsigned __int8 destroy_manually)
{
  this->__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::base_lexeme::`vftable';
  this->m_value = 1;
  this->m_left.m_lexeme = left;
  if ( left && left->m_destroy_manually )
    ++left->m_counter;
  this->m_right.m_lexeme = right;
  if ( right && right->m_destroy_manually )
    ++right->m_counter;
  this->m_counter = 0;
  this->m_destroy_manually = destroy_manually;
  this->m_operation_type = operation_type;
  vostok::ai::planning::base_lexeme::reset_pointers(this);
}
