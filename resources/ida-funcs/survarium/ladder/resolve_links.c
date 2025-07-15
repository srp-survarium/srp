void __thiscall survarium::ladder::resolve_links(
        survarium::ladder *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value cfg)
{
  survarium::usable_object::resolve_links((survarium::usable_object *)this, p, cfg);
  if ( this->m_parent_resources.m_lock )
    (**(void (__thiscall ***)(unsigned int, survarium::base_project *, const void *, _DWORD, const char *, _DWORD, unsigned int, _DWORD))(this->m_parent_resources.m_lock + 4))(
      this->m_parent_resources.m_lock + 4,
      p,
      cfg.data.pointer,
      HIDWORD(cfg.data.max_storage),
      cfg.id.pointer,
      HIDWORD(cfg.id.max_storage),
      cfg.id_crc,
      *(_DWORD *)&cfg.type);
}
