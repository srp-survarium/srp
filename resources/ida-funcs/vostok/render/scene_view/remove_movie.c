void __userpurge vostok::render::scene_view::remove_movie(
        vostok::render::scene_view *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *movie)
{
  int v3; // esi
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **v4; // ebx
  int v5; // eax
  int v6; // ecx
  survarium::flash_movie_resource *m_object; // edx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // [esp+10h] [ebp-4h] BYREF

  v3 = *(int *)((char *)&dword_10D20 + a2);
  v4 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)((char *)&dword_10D1C + a2);
  v5 = *(int *)((char *)&dword_10D1C + a2);
  v6 = (v3 - v5) >> 4;
  if ( v6 <= 0 )
  {
LABEL_8:
    if ( (v3 - v5) >> 2 != 1 )
    {
      if ( (v3 - v5) >> 2 != 2 )
      {
        v6 = ((v3 - v5) >> 2) - 3;
        if ( (v3 - v5) >> 2 != 3 )
          goto LABEL_16;
        v6 = *(_DWORD *)v5;
        if ( *(survarium::flash_movie_resource **)v5 == movie->m_object )
          goto LABEL_17;
        v5 += 4;
      }
      v6 = *(_DWORD *)v5;
      if ( *(survarium::flash_movie_resource **)v5 == movie->m_object )
        goto LABEL_17;
      v5 += 4;
    }
    v6 = *(_DWORD *)v5;
    if ( *(survarium::flash_movie_resource **)v5 == movie->m_object )
      goto LABEL_17;
LABEL_16:
    v5 = v3;
    goto LABEL_17;
  }
  m_object = movie->m_object;
  while ( *(survarium::flash_movie_resource **)v5 != m_object )
  {
    v5 += 4;
    if ( *(survarium::flash_movie_resource **)v5 == m_object )
      break;
    v5 += 4;
    if ( *(survarium::flash_movie_resource **)v5 == m_object )
      break;
    v5 += 4;
    if ( *(survarium::flash_movie_resource **)v5 == m_object )
      break;
    v5 += 4;
    if ( --v6 <= 0 )
      goto LABEL_8;
  }
LABEL_17:
  v8 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v5;
  movie = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)(v5 + 4);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>>::erase(
    (vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > *)v6,
    v4,
    &v8,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&movie);
}
