void __thiscall vostok::render::scene::remove_model(
        vostok::render::scene *this,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a3)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v3; // ebx
  vostok::render::scene *v4; // ecx
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > *v5; // ecx
  char *v6; // esi
  char **v7; // ebx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v8; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp-4h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = v;
  v = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>((char *)v[2284894].m_object, (int *)&a3, (char *)v[2284895].m_object);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v9,
    &a3);
  vostok::render::scene::remove_streamable_texture_instance(v4, (int)v3, v9);
  a3.m_object->__vftable[2].~vostok::particle::particle_system_instance(a3.m_object);
  (*(void (__thiscall **)(_DWORD, vostok::particle::particle_emitter_instance **))(**(_DWORD **)((char *)&dword_8B9654
                                                                                               + (_DWORD)v3)
                                                                                 + 4))(
    *(int *)((char *)&dword_8B9654 + (_DWORD)v3),
    &a3.m_object->m_lods[0].m_emitter_instance_list.m_last);
  v10 = v + 1;
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>>::erase(
    v5,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&v3[2284894],
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&v,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&v10);
  v6 = *(char **)((char *)&vostok::memory::s_resources.m_buffer[4183] + (_DWORD)v3);
  v7 = (char **)((char *)&vostok::memory::s_resources.m_buffer[4182] + (_DWORD)v3);
  v8 = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(*v7, (int *)&a3, v6);
  v10 = v8;
  if ( v8 != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v6 )
  {
    v = v8 + 1;
    vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>>::erase(
      (vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > *)v9.m_object,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)v7,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&v10,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&v);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
}
