void __thiscall vostok::particle::particle_beam_emitter_instance::~particle_beam_emitter_instance(
        vostok::particle::particle_beam_emitter_instance *this)
{
  this->__vftable = (vostok::particle::particle_beam_emitter_instance_vtbl *)&vostok::particle::particle_beam_emitter_instance::`vftable';
  vostok::particle::particle_beam_emitter_instance::free_dynamic_data(this, (int)this);
  vostok::particle::particle_emitter_instance::~particle_emitter_instance(this);
}
