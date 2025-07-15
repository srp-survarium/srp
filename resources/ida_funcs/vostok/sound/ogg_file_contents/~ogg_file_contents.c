void __thiscall vostok::sound::ogg_file_contents::~ogg_file_contents(vostok::sound::ogg_file_contents *this)
{
  this->__vftable = (vostok::sound::ogg_file_contents_vtbl *)&vostok::sound::ogg_file_contents::`vftable';
  ov_clear(&this->m_ovf);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_raw_file.resource);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
