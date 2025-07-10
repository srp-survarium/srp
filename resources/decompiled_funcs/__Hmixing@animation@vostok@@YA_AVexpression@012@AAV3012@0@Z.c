vostok::animation::mixing::expression *__cdecl vostok::animation::mixing::operator+(
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::expression *left,
        vostok::animation::mixing::expression *right)
{
  vostok::animation::mixing::expression *v3; // ecx
  vostok::animation::mixing::expression *v4; // ecx
  vostok::animation::mixing::addition_lexeme *v6; // eax
  vostok::animation::mixing::expression *v7; // eax
  vostok::animation::mixing::addition_lexeme *v8; // ecx
  vostok::animation::mixing::addition_lexeme v9; // [esp+24h] [ebp-24h] BYREF

  if ( vostok::animation::mixing::expression::is_empty(v3, left) )
  {
    vostok::animation::mixing::expression::expression(result, right);
    return result;
  }
  else
  {
    if ( vostok::animation::mixing::expression::is_empty(v4, right) )
    {
      vostok::animation::mixing::expression::expression(result, left);
    }
    else
    {
      vostok::animation::mixing::addition_lexeme::addition_lexeme(&v9, left, right);
      v7 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v6);
      vostok::animation::mixing::expression::expression(v7, result);
      vostok::animation::mixing::addition_lexeme::~addition_lexeme(v8, (int)&v9);
    }
    return result;
  }
}
