vostok::render::culling::portal_sector_structure *__thiscall vostok::render::culling::portal_sector_structure::`scalar deleting destructor'(
        vostok::render::culling::portal_sector_structure *this,
        char a2)
{
  vostok::render::culling::portal_sector_structure::~portal_sector_structure(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
