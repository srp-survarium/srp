void __userpurge vostok::render::stage_postprocess::render_models(
        vostok::buffer_vector<vostok::render::render_surface_instance *> *models@<eax>,
        vostok::render::stage_postprocess *this,
        bool foreground)
{
  vostok::render::render_surface_instance *m_begin; // ecx
  vostok::render::render_surface_instance **m_end; // eax
  bool i; // zf
  vostok::render::render_surface_instance *m_object; // ebx
  vostok::render::render_surface *v7; // ecx
  vostok::render::material_effects *material_effects; // esi
  vostok::render::res_pass *v9; // ecx
  vostok::render::res_effect *v10; // eax
  vostok::render::res_pass *v11; // eax
  vostok::render::res_pass *v12; // esi
  _DWORD *m_reference_count; // eax
  vostok::render::res_pass *v14; // edi
  vostok::render::effect_manager *v15; // ecx
  vostok::math::float4x4 *m_transform; // eax
  stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *v17; // edx
  stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *M_right; // ecx
  stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *v19; // esi
  stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *M_parent; // ecx
  stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *v21; // eax
  stlp_std::priv::_Rb_tree_node_base *M_node; // esi
  vostok::math::float4x4 *v23; // eax
  float z; // esi
  vostok::render::backend *v25; // ecx
  vostok::math::float4x4 *v26; // eax
  vostok::render::backend *v27; // ecx
  int v28; // esi
  vostok::render::res_geometry *v29; // ecx
  vostok::render::backend *v30; // ecx
  stlp_std::priv::_Rb_tree_node_base v31; // [esp-4h] [ebp-13Ch]
  vostok::math::float4x4 v32; // [esp+10h] [ebp-128h] BYREF
  vostok::math::float4x4 v33; // [esp+50h] [ebp-E8h] BYREF
  vostok::math::float4x4 v34; // [esp+90h] [ebp-A8h] BYREF
  stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> __val; // [esp+D4h] [ebp-64h] BYREF
  char v36[8]; // [esp+118h] [ebp-20h] BYREF
  vostok::render::render_surface *m_render_surface; // [esp+120h] [ebp-18h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> > > __position; // [esp+124h] [ebp-14h] BYREF
  vostok::render::render_surface_instance **v39; // [esp+128h] [ebp-10h]
  vostok::render::render_surface_instance *v40; // [esp+12Ch] [ebp-Ch]
  int v41; // [esp+130h] [ebp-8h]
  char v42; // [esp+137h] [ebp-1h]

  m_begin = (vostok::render::render_surface_instance *)models->m_begin;
  m_end = models->m_end;
  v41 = 0;
  v39 = m_end;
  for ( i = m_begin == (vostok::render::render_surface_instance *)m_end;
        ;
        i = &v40->m_override_normal_texture == (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v39 )
  {
    v40 = m_begin;
    if ( i )
      break;
    m_object = (vostok::render::render_surface_instance *)m_begin->m_override_diffuse_texture.m_object;
    if ( vostok::render::render_surface_instance::is_foreground(
           m_begin,
           (int)m_begin->m_override_diffuse_texture.m_object) != foreground )
      goto LABEL_36;
    m_render_surface = m_object->m_render_surface;
    material_effects = vostok::render::render_surface::get_material_effects(v7, (int)m_render_surface);
    vostok::render::renderer_context::set_w(m_object->m_transform, this->m_context);
    v10 = material_effects->m_effects[1].m_object;
    v10->m_cur_technique = 7;
    v11 = (vostok::render::res_pass *)v10->m_techniques.m_begin[7].m_object;
    v12 = 0;
    if ( v11 )
    {
      v12 = v11;
      ++v11->m_reference_count;
    }
    m_reference_count = (_DWORD *)v12->m_vs.m_object->m_reference_count;
    v14 = 0;
    if ( m_reference_count )
    {
      v14 = (vostok::render::res_pass *)v12->m_vs.m_object->m_reference_count;
      ++*m_reference_count;
    }
    vostok::render::res_pass::apply(v9, (int)v14);
    if ( v14 )
    {
      if ( !--v14->m_reference_count )
        vostok::render::effect_manager::delete_pass(
          v15,
          (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
          v14);
    }
    if ( !--v12->m_reference_count )
      vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v12);
    m_transform = m_object->m_transform;
    qmemcpy(&v34, m_transform, sizeof(v34));
    v17 = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)((char *)&loc_26388 + (_DWORD)this);
    qmemcpy(&v32, m_transform, sizeof(v32));
    M_right = *(stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > **)((char *)&loc_26388 + (_DWORD)this + 4);
    v19 = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)((char *)&loc_26388 + (_DWORD)this);
    if ( M_right )
    {
      do
      {
        if ( M_right->_M_node_count < (unsigned int)m_object )
        {
          M_right = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)M_right->_M_header._M_data._M_right;
        }
        else
        {
          v19 = M_right;
          M_right = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)M_right->_M_header._M_data._M_left;
        }
      }
      while ( M_right );
      if ( v19 == v17 )
        goto LABEL_34;
      if ( (unsigned int)m_object < v19->_M_node_count )
        v19 = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)((char *)&loc_26388 + (_DWORD)this);
    }
    if ( v19 != v17 )
    {
      qmemcpy(&v32, &v19->_M_key_compare, sizeof(v32));
      M_parent = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)v17->_M_header._M_data._M_parent;
      v21 = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)((char *)&loc_26388 + (_DWORD)this);
      while ( M_parent )
      {
        if ( M_parent->_M_node_count < (unsigned int)m_object )
        {
          M_parent = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)M_parent->_M_header._M_data._M_right;
        }
        else
        {
          v21 = M_parent;
          M_parent = (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)M_parent->_M_header._M_data._M_left;
        }
      }
      M_node = (stlp_std::priv::_Rb_tree_node_base *)v21;
      if ( v21 == v17 || (v41 |= 1u, v42 = 0, (unsigned int)m_object < v21->_M_node_count) )
        v42 = 1;
      if ( (v41 & 1) != 0 )
        v41 &= ~1u;
      if ( v42 )
      {
        __val.first = m_object;
        qmemcpy(&__val.second, &v33, sizeof(__val.second));
        stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4>>>::insert_unique(
          v17,
          &__val,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> > >)&__position,
          v21);
        M_node = __position._M_node;
      }
      qmemcpy(&M_node[1]._M_parent, &v34, 0x40u);
      goto LABEL_35;
    }
LABEL_34:
    __val.first = m_object;
    *(_DWORD *)&v31._M_color = &__val;
    qmemcpy(&__val.second, m_transform, sizeof(__val.second));
    stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4>>>::insert_unique(
      0,
      (int)v36,
      v17,
      v31);
LABEL_35:
    vostok::math::float4x4::try_invert(&v34, &v34);
    vostok::math::mul4x3(&this->m_prev_view_matrix, &v32, &v33);
    v23 = vostok::math::transpose(&v33, &__val.second);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v25,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      this->m_prev_world_view_matrix_parameter,
      (const vostok::math::float3 *)v23);
    v26 = vostok::math::transpose(&v34, &v33);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v27,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      this->m_inverse_world_matrix_parameter,
      (const vostok::math::float3 *)v26);
    m_object->m_parent->set_constants(m_object->m_parent, 0);
    v28 = (int)m_render_surface;
    vostok::render::res_geometry::apply(v29, (int)m_render_surface->m_render_geometry.geom.m_object);
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      3 * *(_DWORD *)(v28 + 24),
      v30,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      0,
      0);
LABEL_36:
    m_begin = (vostok::render::render_surface_instance *)&v40->m_override_normal_texture;
  }
}
