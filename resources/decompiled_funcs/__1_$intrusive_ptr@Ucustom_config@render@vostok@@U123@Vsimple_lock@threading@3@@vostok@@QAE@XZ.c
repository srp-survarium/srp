void __thiscall vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock>::~intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::render::custom_config::destroy(this->m_object, this->m_object);
  }
}
