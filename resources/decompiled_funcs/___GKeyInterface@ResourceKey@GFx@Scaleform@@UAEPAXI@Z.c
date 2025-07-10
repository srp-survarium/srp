Scaleform::GFx::GFxMovieDataDefFileKeyInterface *__thiscall Scaleform::GFx::ResourceKey::KeyInterface::`scalar deleting destructor'(
        Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::GFxMovieDataDefFileKeyInterface_vtbl *)&Scaleform::GFx::ResourceKey::KeyInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
