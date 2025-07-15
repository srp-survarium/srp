void __thiscall survarium::options_tab::apply(
        survarium::options_tab *this,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *movie,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *moviea)
{
  bool v3; // zf
  int v4; // ecx
  survarium::flash_movie_resource *m_object; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  vostok::console_commands::console_command *v7; // eax
  survarium::options_tab *v8; // ecx
  vostok::render::scene_renderer *v9; // [esp-8h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+0h] [ebp-14h] BYREF
  bool v11; // [esp+4h] [ebp-10h]
  bool v12; // [esp+8h] [ebp-Ch]
  volatile int *v13; // [esp+Ch] [ebp-8h]
  unsigned __int8 v14; // [esp+13h] [ebp-1h]

  v3 = LOBYTE(movie[1].m_object) == 0;
  v14 = 0;
  if ( !v3 )
  {
    do
    {
      v4 = *((_DWORD *)&movie->m_object->__vftable + v14);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 16))(v4);
      ++v14;
    }
    while ( v14 < LOBYTE(movie[1].m_object) );
  }
  if ( movie[2].m_object == (survarium::flash_movie_resource *)2 )
  {
    m_object = movie[3].m_object;
    v10.m_object = (vostok::particle::particle_system_instance_impl *)this;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v10,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_current_satisfaction);
    v6 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)*(&movie[3].m_object[51].m_reconstruction_size + 1);
    v9 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + v6[40].m_object->m_fat_it.m_type);
    vostok::render::scene_renderer::end_render_options_changing(v9, (int)v9, v6 + 1, v10, v11, v12, v13);
  }
  v7 = vostok::console_commands::find("cfg_save_user");
  v7->execute(v7, uri);
  survarium::options_tab::initialize_data(v8, (int)movie, moviea);
}
