void __usercall vostok::sound::sound_scene::stop(
        vostok::sound::sound_scene *this@<ecx>,
        vostok::sound::sound_scene *a2@<edi>)
{
  vostok::sound::sound_instance_proxy_internal *i; // esi

  for ( i = a2->m_active_proxies.m_first; i; i = i->m_next_for_sound_world )
    vostok::sound::sound_scene::stop_propagate_sound(a2, i);
}
