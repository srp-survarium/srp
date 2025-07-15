vostok::render::stage_shadow_direct *__thiscall vostok::render::stage_shadow_direct::`scalar deleting destructor'(
        vostok::render::stage_shadow_direct *this,
        char a2)
{
  vostok::render::stage_shadow_direct::~stage_shadow_direct(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
