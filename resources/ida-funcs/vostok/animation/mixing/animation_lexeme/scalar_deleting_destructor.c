vostok::animation::mixing::animation_lexeme *__thiscall vostok::animation::mixing::animation_lexeme::`scalar deleting destructor'(
        vostok::animation::mixing::animation_lexeme *this,
        char a2)
{
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
