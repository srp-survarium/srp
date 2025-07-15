vostok::sound::sound_world_vtbl *__userpurge vostok::render::grass_world::find_template@<eax>(
        vostok::render::grass_world *this@<ecx>,
        int a2@<eax>,
        const vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *model)
{
  vostok::sound::sound_world *v4; // esi
  vostok::sound::sound_world *v5; // eax

  v4 = boost::get_pointer<vostok::sound::sound_scene>(*(vostok::sound::sound_world **)(a2 + 276));
  v5 = boost::get_pointer<vostok::sound::sound_scene>(*(vostok::sound::sound_world **)(a2 + 280));
  if ( v4 == v5 )
    return 0;
  while ( v4->tick != (void (__thiscall *)(vostok::sound::world *))model->m_object )
  {
    v4 = (vostok::sound::sound_world *)((char *)v4 + 4);
    if ( v4 == v5 )
      return 0;
  }
  return v4->__vftable;
}
