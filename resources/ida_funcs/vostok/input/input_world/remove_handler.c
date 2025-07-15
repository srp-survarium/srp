void __thiscall vostok::input::input_world::remove_handler(
        vostok::input::input_world *this,
        vostok::input::handler *handler)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v4; // eax

  M_finish = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this->m_handlers._M_impl._M_finish;
  v4 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this->m_handlers._M_impl._M_start,
         M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&handler);
  if ( &v4[1] != M_finish )
  {
    LOBYTE(handler) = 0;
    stlp_std::priv::__copy_ptrs<void * *,void * *>(
      (void **)&v4[1].m_object,
      (void **)&M_finish->m_object,
      (void **)&v4->m_object);
  }
  --this->m_handlers._M_impl._M_finish;
}
