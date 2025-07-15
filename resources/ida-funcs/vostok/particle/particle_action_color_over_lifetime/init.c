void __userpurge vostok::particle::particle_action_color_over_lifetime::init(
        vostok::particle::particle_action_color_over_lifetime *this@<ecx>,
        float a2@<xmm0>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time_delta)
{
  vostok::particle::particle_emitter_instance::get_linear_emitter_time((vostok::particle::particle_emitter_instance *)this);
  P->target_color_y_position = a2;
}
