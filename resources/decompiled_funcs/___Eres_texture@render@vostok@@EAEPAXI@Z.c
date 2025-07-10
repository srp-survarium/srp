vostok::render::res_texture *__thiscall vostok::render::res_texture::`vector deleting destructor'(
        vostok::render::res_texture *this,
        char a2)
{
  vostok::render::res_texture::~res_texture(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
