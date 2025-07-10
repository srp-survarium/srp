survarium::object_volumetric_sound *__thiscall survarium::object_volumetric_sound::`scalar deleting destructor'(
        survarium::object_volumetric_sound *this,
        char a2)
{
  this->survarium::object_sound::survarium::game_object_static::survarium::game_object_::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::object_volumetric_sound_vtbl *)&survarium::object_volumetric_sound::`vftable'{for `survarium::object_sound'};
  this->survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::object_volumetric_sound::`vftable'{for `survarium::link_resolver'};
  survarium::object_sound::~object_sound(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
