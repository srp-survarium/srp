void __thiscall vostok::ui::ui_window::remove_child(vostok::ui::ui_window *this, vostok::ui::window *w)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  vostok::ui::window *v5; // esi
  vostok::memory::base_allocator *m_allocator; // ebx
  _BYTE *v7; // edi

  M_finish = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this->m_children._M_impl._M_finish;
  v4 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this->m_children._M_impl._M_start,
         M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&w);
  if ( &v4[1] != M_finish )
    stlp_std::priv::__copy_ptrs<void * *,void * *>(
      (void **)&v4[1].m_object,
      (void **)&M_finish->m_object,
      (void **)&v4->m_object);
  v5 = w;
  --this->m_children._M_impl._M_finish;
  if ( v5->get_orphan(v5) )
  {
    m_allocator = this->m_allocator;
    v7 = __RTCastToVoid((void **)&v5->__vftable);
    ((void (__thiscall *)(vostok::ui::window *, _DWORD))v5->~vostok::ui::window)(v5, 0);
    m_allocator->call_free(m_allocator, v7);
  }
  else
  {
    v5->set_parent(v5, 0);
  }
}
