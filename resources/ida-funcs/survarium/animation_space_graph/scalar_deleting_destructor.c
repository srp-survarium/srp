survarium::animation_space_graph *__thiscall survarium::animation_space_graph::`scalar deleting destructor'(
        survarium::animation_space_graph *this,
        char a2)
{
  this->__vftable = (survarium::animation_space_graph_vtbl *)&survarium::animation_space_graph::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
