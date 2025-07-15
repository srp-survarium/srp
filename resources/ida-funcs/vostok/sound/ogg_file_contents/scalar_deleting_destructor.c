vostok::sound::ogg_file_contents *__thiscall vostok::sound::ogg_file_contents::`scalar deleting destructor'(
        vostok::sound::ogg_file_contents *this,
        char a2)
{
  vostok::sound::ogg_file_contents::~ogg_file_contents(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
