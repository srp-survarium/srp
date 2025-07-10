vostok::sound::ogg_file_contents_cook *__thiscall vostok::sound::ogg_file_contents_cook::`vector deleting destructor'(
        vostok::sound::ogg_file_contents_cook *this,
        char a2)
{
  vostok::sound::ogg_file_contents_cook::~ogg_file_contents_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
