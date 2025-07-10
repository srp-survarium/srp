Scaleform::GFx::FontResourceCreator *__thiscall Scaleform::GFx::FontResourceCreator::`scalar deleting destructor'(
        Scaleform::GFx::FontResourceCreator *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::FontResourceCreator_vtbl *)&Scaleform::GFx::ResourceData::DataInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
