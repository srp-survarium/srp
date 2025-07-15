survarium::collision_user *__thiscall survarium::collision_user::`scalar deleting destructor'(
        survarium::collision_user *this,
        char a2)
{
  this->__vftable = (survarium::collision_user_vtbl *)&survarium::collision_user::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
