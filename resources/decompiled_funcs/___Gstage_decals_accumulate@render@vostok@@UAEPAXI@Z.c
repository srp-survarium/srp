vostok::render::stage_decals_accumulate *__thiscall vostok::render::stage_decals_accumulate::`scalar deleting destructor'(
        vostok::render::stage_decals_accumulate *this,
        char a2)
{
  vostok::render::stage_decals_accumulate::~stage_decals_accumulate(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
