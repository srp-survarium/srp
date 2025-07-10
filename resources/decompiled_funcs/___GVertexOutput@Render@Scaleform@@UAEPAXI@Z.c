Scaleform::GFx::AS3::ArrayBase *__thiscall Scaleform::Render::VertexOutput::`scalar deleting destructor'(
        Scaleform::GFx::AS3::ArrayBase *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::ArrayBase_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
