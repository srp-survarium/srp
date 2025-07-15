void __usercall vostok::particle::particle_system::particle_system(
        vostok::particle::particle_system *this@<ecx>,
        _DWORD *a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  *a2 = &vostok::particle::particle_system::`vftable';
  a2[66] = 0;
  a2[67] = 0;
}
