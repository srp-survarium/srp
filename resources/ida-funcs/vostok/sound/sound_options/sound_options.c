void __usercall vostok::sound::sound_options::sound_options(
        vostok::sound::sound_options *this@<ecx>,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__that@<eax>)
{
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this,
    __that);
  this->fixed_spl = *(float *)&__that[1].m_object;
  this->volume_k = *(float *)&__that[2].m_object;
  this->lp_filter_k = *(float *)&__that[3].m_object;
  *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->pan_3d = __that[4];
}
