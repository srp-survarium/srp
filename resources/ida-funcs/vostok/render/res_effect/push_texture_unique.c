void __thiscall vostok::render::res_effect::push_texture_unique(
        vostok::render::res_effect *this,
        vostok::buffer_vector<vostok::render::texture_named_instance> *in_texture,
        vostok::render::res_texture *path,
        char *a4)
{
  vostok::buffer_vector<vostok::render::texture_named_instance> *v4; // ebx
  vostok::render::texture_named_instance *m_begin; // eax
  vostok::render::res_texture *v6; // ecx
  vostok::render::texture_named_instance *if_PAUtexture_named_instance_render_vostok__Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__priv_stlp_std__YAPAUtexture_named_instance_render_vostok__PAU234_0Ufind_texture_predicate__1__push_texture_unique_res_effect_34_QAEXPAVres_texture_34_PBD_Z_ABUrandom_access_iterator_tag_1__Z; // esi
  vostok::render::res_texture *v8; // eax
  vostok::render::res_texture *m_object; // ecx
  bool v10; // zf
  vostok::render::res_texture *v11; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v12; // [esp-4h] [ebp-C8h] BYREF
  vostok::render::texture_named_instance v13; // [esp+Ch] [ebp-B8h] BYREF
  vostok::render::texture_named_instance *__last; // [esp+120h] [ebp+5Ch] BYREF
  vostok::buffer_vector<vostok::render::texture_named_instance> *v15; // [esp+124h] [ebp+60h]
  vostok::render::texture_named_instance *__first; // [esp+128h] [ebp+64h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v17; // [esp+12Ch] [ebp+68h] BYREF

  v4 = in_texture;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v17,
    path);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_texture,
    &v17);
  __last = v4[22].m_end;
  v15 = v4 + 22;
  m_begin = v4[22].m_begin;
  v12.m_object = v6;
  __first = m_begin;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v12,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_texture);
  if_PAUtexture_named_instance_render_vostok__Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__priv_stlp_std__YAPAUtexture_named_instance_render_vostok__PAU234_0Ufind_texture_predicate__1__push_texture_unique_res_effect_34_QAEXPAVres_texture_34_PBD_Z_ABUrandom_access_iterator_tag_1__Z = _____find_if_PAUtexture_named_instance_render_vostok__Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__priv_stlp_std__YAPAUtexture_named_instance_render_vostok__PAU234_0Ufind_texture_predicate__1__push_texture_unique_res_effect_34_QAEXPAVres_texture_34_PBD_Z_ABUrandom_access_iterator_tag_1__Z(__first, __last, (vostok::render::res_effect::push_texture_unique::__l2::find_texture_predicate)v12.m_object);
  v8 = (vostok::render::res_texture *)in_texture;
  m_object = v12.m_object;
  if ( in_texture )
  {
    v10 = in_texture->m_end-- == (vostok::render::texture_named_instance *)1;
    if ( v10 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)m_object,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v8);
  }
  v11 = v17.m_object;
  if ( v17.m_object )
  {
    v10 = v17.m_object->m_reference_count-- == 1;
    if ( v10 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)m_object,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v11);
  }
  if ( if_PAUtexture_named_instance_render_vostok__Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__priv_stlp_std__YAPAUtexture_named_instance_render_vostok__PAU234_0Ufind_texture_predicate__1__push_texture_unique_res_effect_34_QAEXPAVres_texture_34_PBD_Z_ABUrandom_access_iterator_tag_1__Z == v4[22].m_end )
  {
    v13.path.m_begin = v13.path.m_buffer;
    v13.path.m_end = v13.path.m_buffer;
    v13.path.m_max_end = (char *)&__last;
    v13.texture = path;
    v13.path.m_buffer[0] = 0;
    if ( v13.path.m_buffer != a4 )
    {
      v13.path.m_end = v13.path.m_buffer;
      v13.path.m_buffer[0] = 0;
      vostok::buffer_string::operator+=(&v13.path, a4);
    }
    vostok::buffer_vector<vostok::render::texture_named_instance>::push_back(v15, &v13);
  }
}
