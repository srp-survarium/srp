void __usercall vostok::render::render_model_cook::render_model_cook(
        vostok::render::render_model_cook *this@<esi>,
        vostok::resources::class_id_enum model_type@<eax>)
{
  this->__vftable = (vostok::render::render_model_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  this->m_cook_users_count.m_count = 0;
  this->m_class_id = model_type;
  this->m_reuse_type = reuse_true;
  this->m_creation_thread_id = -1;
  this->m_allocate_thread_id = GetCurrentThreadId();
  this->m_flags.m_flags = 8;
  this->m_next = 0;
  this->__vftable = (vostok::render::render_model_cook_vtbl *)&vostok::render::render_model_cook::`vftable';
  vostok::resources::resources_manager::register_cook(this);
}
