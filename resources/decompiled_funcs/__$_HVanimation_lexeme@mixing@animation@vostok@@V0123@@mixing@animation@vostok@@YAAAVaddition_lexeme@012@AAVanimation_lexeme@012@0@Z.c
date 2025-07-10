vostok::animation::mixing::addition_lexeme *__cdecl vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme,vostok::animation::mixing::animation_lexeme>(
        vostok::animation::mixing::animation_lexeme *left,
        vostok::animation::mixing::animation_lexeme *right)
{
  vostok::animation::mixing::addition_lexeme *v2; // eax
  vostok::animation::mixing::addition_lexeme *v3; // ecx
  vostok::animation::mixing::addition_lexeme v5; // [esp+18h] [ebp-28h] BYREF
  vostok::animation::mixing::addition_lexeme *v6; // [esp+3Ch] [ebp-4h]

  vostok::animation::mixing::addition_lexeme::addition_lexeme(&v5, left, right);
  v6 = vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v2);
  vostok::animation::mixing::addition_lexeme::~addition_lexeme(v3, (int)&v5);
  return v6;
}
