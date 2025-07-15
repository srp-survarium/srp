vostok::render::stage_forward *__thiscall vostok::render::stage_forward::`scalar deleting destructor'(
        vostok::render::stage_forward *this,
        char a2)
{
  vostok::render::stage_forward::~stage_forward(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
