void __userpurge vostok::render::res_effect::push_texture_unique(
        vostok::render::res_effect *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_texture *in_texture,
        char *path)
{
  vostok::render::res_texture *v4; // esi
  vostok::render::res_texture *v6; // ecx
  vostok::render::texture_named_instance *if_PAUtexture_named_instance_render_vostok__Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__stlp_std__YAPAUtexture_named_instance_render_vostok__PAU123_0Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__Z; // ebx
  bool v8; // zf
  char *m_buffer; // eax
  char *v10; // ecx
  vostok::render::texture_named_instance *v11; // esi
  int v12; // ebp
  unsigned __int8 *m_begin; // [esp-8h] [ebp-130h]
  vostok::render::res_effect::push_texture_unique::__l2::find_texture_predicate v14; // [esp-4h] [ebp-12Ch]
  unsigned int v15; // [esp-4h] [ebp-12Ch]
  const stlp_std::__false_type *v16; // [esp+0h] [ebp-128h]
  unsigned int v17; // [esp+4h] [ebp-124h]
  bool v18; // [esp+8h] [ebp-120h]
  vostok::render::texture_named_instance **v19; // [esp+10h] [ebp-118h]
  vostok::render::texture_named_instance instance; // [esp+14h] [ebp-114h] BYREF
  _UNKNOWN *retaddr; // [esp+128h] [ebp+0h] BYREF

  v4 = 0;
  if ( in_texture )
  {
    ++in_texture->m_reference_count;
    v4 = in_texture;
  }
  v14.m_texture.m_object = 0;
  if ( v4 )
  {
    v14.m_texture.m_object = v4;
    ++v4->m_reference_count;
  }
  v19 = (vostok::render::texture_named_instance **)(a2 + 264);
  if_PAUtexture_named_instance_render_vostok__Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__stlp_std__YAPAUtexture_named_instance_render_vostok__PAU123_0Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__Z = ___find_if_PAUtexture_named_instance_render_vostok__Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__stlp_std__YAPAUtexture_named_instance_render_vostok__PAU123_0Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__Z(*(vostok::render::texture_named_instance **)(a2 + 264), *(vostok::render::texture_named_instance **)(a2 + 268), v14);
  if ( v4 )
  {
    v8 = v4->m_reference_count-- == 1;
    if ( v8 )
      vostok::render::res_texture::destroy_impl(v6, v4);
  }
  if ( if_PAUtexture_named_instance_render_vostok__Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__stlp_std__YAPAUtexture_named_instance_render_vostok__PAU123_0Ufind_texture_predicate__1__push_texture_unique_res_effect_23_QAEXPAVres_texture_23_PBD_Z__Z == *(vostok::render::texture_named_instance **)(a2 + 268) )
  {
    m_buffer = instance.path.m_buffer;
    instance.path.m_end = instance.path.m_buffer;
    v10 = path;
    instance.path.m_begin = instance.path.m_buffer;
    instance.path.m_max_end = (char *)&retaddr;
    instance.path.m_buffer[0] = 0;
    instance.texture = in_texture;
    if ( instance.path.m_buffer != path )
    {
      instance.path.m_end = instance.path.m_buffer;
      instance.path.m_buffer[0] = 0;
      if ( path )
      {
        if ( *path )
        {
          do
          {
            if ( m_buffer >= instance.path.m_max_end )
              break;
            *m_buffer = *v10;
            m_buffer = instance.path.m_end + 1;
            v8 = *++v10 == 0;
            ++instance.path.m_end;
          }
          while ( !v8 );
        }
        *m_buffer = 0;
      }
    }
    v11 = v19[1];
    if ( v11 == v19[2] )
    {
      stlp_std::priv::_Impl_vector<vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance>>::_M_insert_overflow_aux(
        (stlp_std::priv::_Impl_vector<vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance> > *)&instance,
        v19,
        v11,
        &instance,
        v16,
        v17,
        v18);
    }
    else
    {
      if ( v11 )
      {
        v11->texture = instance.texture;
        v12 = instance.path.m_end - instance.path.m_begin;
        v15 = instance.path.m_end - instance.path.m_begin;
        m_begin = (unsigned __int8 *)instance.path.m_begin;
        v11->path.m_begin = v11->path.m_buffer;
        v11->path.m_end = v11->path.m_buffer;
        v11->path.m_max_end = (char *)&v11[1];
        memcpy((unsigned __int8 *)v11->path.m_buffer, m_begin, v15);
        v11->path.m_end += v12;
        *v11->path.m_end = 0;
      }
      ++v19[1];
    }
  }
}
