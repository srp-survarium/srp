vostok::render::stage_visibility *__thiscall vostok::render::stage_visibility::`scalar deleting destructor'(
        vostok::render::stage_visibility *this,
        char a2)
{
  vostok::render::stage_visibility::~stage_visibility(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
