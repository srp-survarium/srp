void __userpurge vostok::particle::particle_domain_complex::load(
        vostok::particle::particle_domain_complex *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *config)
{
  vostok::particle::particle_domain_complex::load_impl<vostok::configs::binary_config_value>(this, a2, config);
}
