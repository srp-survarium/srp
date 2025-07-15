void __thiscall vostok::engine::engine_world::logic_finalize_modules(vostok::engine::engine_world *this)
{
  this->on_application_deactivate(&this->vostok::editor::engine);
  this->m_engine_user_module_proxy->destroy_world(this->m_engine_user_module_proxy, &this->m_engine_user_world);
}
