const vostok::fixed_string<260> *__thiscall vostok::fixed_string<260>::operator=(
        vostok::fixed_string<260> *this,
        vostok::fixed_string<260> *src)
{
  if ( this != src )
    vostok::buffer_string::operator=((vostok::fixed_string<32> *)src, (vostok::fixed_string<32> *)this);
  return this;
}
