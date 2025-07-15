vostok::render::stage_volume_fog *__thiscall vostok::render::stage_volume_fog::`scalar deleting destructor'(
        vostok::render::stage_volume_fog *this,
        char a2)
{
  vostok::render::stage_volume_fog::~stage_volume_fog(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
