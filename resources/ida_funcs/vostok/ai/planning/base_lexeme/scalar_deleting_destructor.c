vostok::ai::planning::base_lexeme *__thiscall vostok::ai::planning::base_lexeme::`scalar deleting destructor'(
        vostok::ai::planning::base_lexeme *this,
        char a2)
{
  vostok::ai::planning::base_lexeme::~base_lexeme(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
