survarium::rifle_scope *__thiscall vostok::render::skeleton_model_instance::`vector deleting destructor'(
        survarium::rifle_scope *this,
        char a2)
{
  vostok::render::static_model_instance::~static_model_instance(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
