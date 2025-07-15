void __thiscall vostok::sound::sound_emitter::sound_emitter(vostok::sound::sound_emitter *this)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (vostok::sound::sound_emitter_vtbl *)&vostok::sound::sound_emitter::`vftable';
  this->m_old_address = 0;
}
