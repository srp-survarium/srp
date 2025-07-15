Scaleform::GFx::AS3::Tracer *__thiscall Scaleform::GFx::AS3::Tracer::`vector deleting destructor'(
        Scaleform::GFx::AS3::Tracer *this,
        char a2)
{
  Scaleform::GFx::AS3::Tracer::~Tracer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
