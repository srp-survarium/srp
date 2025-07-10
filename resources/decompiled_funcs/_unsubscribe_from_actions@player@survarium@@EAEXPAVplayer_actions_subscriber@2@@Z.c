void __thiscall survarium::player::unsubscribe_from_actions(
        survarium::player *this,
        survarium::player_actions_subscriber *subscriber)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v3; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v5; // edx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v6; // eax
  survarium::player_actions_subscriber *v7; // edi
  void **v8; // ecx

  v3 = *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_10DDC + (_DWORD)this);
  v4 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_10DD8 + (_DWORD)this),
         v3,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&subscriber);
  if ( v4 != v3 )
  {
    v5 = v4;
    v6 = v4 + 1;
    if ( v6 != v3 )
    {
      v7 = subscriber;
      do
      {
        if ( (survarium::player_actions_subscriber *)v6->m_object != v7 )
        {
          v5->m_object = v6->m_object;
          ++v5;
        }
        ++v6;
      }
      while ( v6 != v3 );
    }
    v4 = v5;
  }
  v8 = *(void ***)((char *)&dword_10DDC + (_DWORD)this);
  if ( &v4[1] != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v8 )
  {
    LOBYTE(subscriber) = 0;
    stlp_std::priv::__copy_ptrs<void * *,void * *>((void **)&v4[1].m_object, v8, (void **)&v4->m_object);
  }
  *(int *)((char *)&dword_10DDC + (_DWORD)this) -= 4;
}
