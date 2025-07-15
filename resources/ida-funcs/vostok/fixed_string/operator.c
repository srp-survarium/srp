const vostok::fixed_string<260> *__thiscall vostok::fixed_string<260>::operator=(
        vostok::fixed_string<260> *this,
        const vostok::fixed_string<260> *src)
{
  if ( src != this )
    vostok::buffer_string::operator=(this, &src->vostok::buffer_string);
  return src;
}
