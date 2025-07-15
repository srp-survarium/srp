survarium::game_world_object *__thiscall survarium::game_world_object::`vector deleting destructor'(
        survarium::game_world_object *this,
        char a2)
{
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->next);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
