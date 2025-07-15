void __thiscall vostok::sound::sound_rms_cook::delete_resource(
        vostok::sound::sound_rms_cook *this,
        vostok::resources::resource_base *res)
{
  vostok::resources::managed_resource *v2; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v3; // [esp-4h] [ebp-58h] BYREF
  vostok::sound::sound_rms_cook *thisa; // [esp+0h] [ebp-54h]
  vostok::sound::sound_rms *m_data; // [esp+18h] [ebp-3Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v6; // [esp+28h] [ebp-2Ch]
  vostok::resources::managed_resource *object; // [esp+34h] [ebp-20h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> rms; // [esp+44h] [ebp-10h] BYREF
  vostok::sound::sound_rms_pinned pinned_rms; // [esp+48h] [ebp-Ch] BYREF

  thisa = this;
  object = vostok::resources::resource_flags::cast_managed_resource(res);
  rms.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &rms,
    object);
  v3.m_object = v2;
  v6 = &v3;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v3,
    &rms);
  vostok::sound::sound_rms_pinned::sound_rms_pinned(
    (vostok::resources::pinned_ptr_mutable<vostok::sound::sound_rms> *)&pinned_rms,
    v3);
  m_data = (vostok::sound::sound_rms *)pinned_rms.m_data;
  vostok::sound::sound_rms::~sound_rms((vostok::sound::sound_rms *)pinned_rms.m_data);
  vostok::resources::pinned_ptr_base<vostok::sound::sound_rms>::~pinned_ptr_base<vostok::sound::sound_rms>(&pinned_rms);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&rms);
}
