vostok::render::culling::portal_sector_system *__thiscall vostok::render::culling::portal_sector_system::`scalar deleting destructor'(
        vostok::render::culling::portal_sector_system *this,
        char a2)
{
  vostok::render::culling::portal_sector_system::~portal_sector_system(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
