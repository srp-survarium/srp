void __userpurge survarium::bullet_manager::destroy_bullet(
        survarium::bullet_manager *this@<esi>,
        vostok::render::ambient_light ***destroying_bullet_iterator@<eax>,
        bool notification_needed)
{
  vostok::render::ambient_light **v4; // eax
  survarium::bullet *v5; // ebx
  vostok::render::ambient_light **end; // [esp+8h] [ebp-4h] BYREF

  v4 = *destroying_bullet_iterator;
  v5 = (survarium::bullet *)*v4;
  end = v4 + 1;
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
    (vostok::buffer_vector<vostok::render::ambient_light *> *)&this->m_bullets,
    destroying_bullet_iterator,
    &end);
  survarium::bullet_manager::free_bullet(this, v5, notification_needed);
}
