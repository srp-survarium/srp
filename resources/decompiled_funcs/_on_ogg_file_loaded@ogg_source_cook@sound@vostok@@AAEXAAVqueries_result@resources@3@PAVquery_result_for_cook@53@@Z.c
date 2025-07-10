void __thiscall vostok::sound::ogg_source_cook::on_ogg_file_loaded(
        vostok::sound::ogg_source_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v3; // [esp-4h] [ebp-54h] BYREF
  vostok::sound::ogg_source_cook *thisa; // [esp+0h] [ebp-50h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // [esp+30h] [ebp-20h]
  vostok::resources::query_result_for_user *v6; // [esp+34h] [ebp-1Ch]
  char v7; // [esp+4Fh] [ebp-1h]

  thisa = this;
  v7 = 0;
  v3.m_object = (vostok::resources::managed_resource *)this;
  v5 = &v3;
  v6 = vostok::resources::queries_result::operator[](data, 0);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    v5,
    &v6->m_managed_resource);
  vostok::resources::query_result_for_cook::set_managed_resource(parent, v3);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
}
