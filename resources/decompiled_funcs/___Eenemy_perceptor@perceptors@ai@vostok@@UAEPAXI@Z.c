vostok::ai::perceptors::enemy_perceptor *__thiscall vostok::ai::perceptors::enemy_perceptor::`vector deleting destructor'(
        vostok::ai::perceptors::enemy_perceptor *this,
        char a2)
{
  vostok::ai::perceptors::enemy_perceptor::~enemy_perceptor(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
