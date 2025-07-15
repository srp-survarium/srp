void __thiscall vostok::sound::sound_rms_pinned::sound_rms_pinned(
        vostok::resources::pinned_ptr_mutable<vostok::sound::sound_rms> *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v2; // [esp-4h] [ebp-4Ch] BYREF
  vostok::resources::pinned_ptr_mutable<vostok::sound::sound_rms> *thisa; // [esp+0h] [ebp-48h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v4; // [esp+30h] [ebp-18h]

  thisa = this;
  v2.m_object = (vostok::resources::managed_resource *)this;
  v4 = &v2;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v2,
    &ptr);
  vostok::resources::pinned_ptr_base<vostok::sound::sound_rms>::pinned_ptr_base<vostok::sound::sound_rms>(thisa, v2);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ptr);
}
