void __thiscall vostok::sound::ogg_sound::~ogg_sound(vostok::sound::ogg_sound *this)
{
  this->__vftable = (vostok::sound::ogg_sound_vtbl *)&vostok::sound::ogg_sound::`vftable';
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_sound_rms);
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ogg_file_contents);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
