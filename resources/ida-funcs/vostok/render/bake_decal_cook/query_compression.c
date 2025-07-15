void __userpurge vostok::render::bake_decal_cook::query_compression(
        const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **result@<eax>,
        vostok::render::result_struct *a2@<ecx>,
        vostok::render::bake_decal_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::render_surface_instance *surface,
        const vostok::render::bake_decal_parameters *parameters)
{
  vostok::render::result_struct *v7; // ecx
  vostok::render::result_struct *v8; // ecx
  vostok::render::result_struct *v9; // ecx
  vostok::render::result_struct *v10; // ecx
  vostok::render::res_texture *m_object; // ebx
  vostok::render::result_struct *v12; // ecx
  vostok::render::res_texture *v13; // edi
  vostok::render::result_struct *v14; // ecx
  vostok::render::result_struct *v15; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *smoothness_texture; // eax
  vostok::render::resource_manager *v17; // ecx
  vostok::render::resource_intrusive_base *v18; // eax
  vostok::render::resource_intrusive_base *v19; // eax
  vostok::render::resource_intrusive_base *v20; // eax
  vostok::render::resource_intrusive_base *v21; // eax
  vostok::memory::doug_lea_allocator *v22; // esi
  char *v23; // eax
  vostok::memory::doug_lea_allocator *v24; // ecx
  char *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // esi
  vostok::render::res_texture *v27; // edi
  char *v28; // eax
  vostok::memory::doug_lea_allocator *v29; // ecx
  char *v30; // eax
  int v31; // ecx
  vostok::render::res_texture *v32; // esi
  char *v33; // ebx
  vostok::fs_new::virtual_path_string *v34; // ecx
  vostok::fs_new::virtual_path_string *v35; // ecx
  vostok::render::texture_converter_params *v36; // ecx
  bool v37; // zf
  char *v38; // edx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v39; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v40; // esi
  int i; // edi
  vostok::fs_new::virtual_path_string v42; // [esp-234h] [ebp-2A0h] BYREF
  vostok::fs_new::virtual_path_string v43; // [esp-120h] [ebp-18Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v44; // [esp-Ch] [ebp-78h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v45; // [esp-8h] [ebp-74h] BYREF
  vostok::render::res_texture *v46; // [esp-4h] [ebp-70h]
  const char *v47; // [esp+0h] [ebp-6Ch]
  const char *v48; // [esp+4h] [ebp-68h]
  unsigned int v49; // [esp+8h] [ebp-64h]
  int v50[4]; // [esp+10h] [ebp-5Ch] BYREF
  void (__thiscall *v51)(vostok::render::bake_decal_cook *, vostok::resources::queries_result *, vostok::render::texture_converter_params *, vostok::render::render_surface_instance *); // [esp+20h] [ebp-4Ch]
  vostok::render::bake_decal_cook *v52; // [esp+24h] [ebp-48h]
  vostok::render::res_texture *v53; // [esp+28h] [ebp-44h]
  vostok::render::render_surface_instance *v54; // [esp+2Ch] [ebp-40h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v55; // [esp+30h] [ebp-3Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v56; // [esp+34h] [ebp-38h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v57; // [esp+38h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v58; // [esp+3Ch] [ebp-30h] BYREF
  void (__thiscall *v59)(vostok::render::bake_decal_cook *, vostok::resources::queries_result *, vostok::render::texture_converter_params *, vostok::render::render_surface_instance *); // [esp+40h] [ebp-2Ch] BYREF
  vostok::render::bake_decal_cook *v60; // [esp+44h] [ebp-28h]
  void (__thiscall *v61)(vostok::render::bake_decal_cook *, vostok::resources::queries_result *, vostok::render::texture_converter_params *, vostok::render::render_surface_instance *); // [esp+48h] [ebp-24h]
  vostok::render::render_surface_instance *v62; // [esp+4Ch] [ebp-20h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v63; // [esp+50h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v64; // [esp+54h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v65; // [esp+58h] [ebp-14h] BYREF
  unsigned int v66; // [esp+5Ch] [ebp-10h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v67; // [esp+60h] [ebp-Ch] BYREF

  vostok::render::result_struct::get_diffuse_texture(a2, result, &v55);
  vostok::render::result_struct::get_normal_texture(v7, (int)result, &v56);
  vostok::render::result_struct::get_fresnel_texture(v8, (int)result, &v57);
  vostok::render::result_struct::get_smoothness_texture(v9, (int)result, &v58);
  m_object = vostok::render::result_struct::get_diffuse_texture(v10, result, &v63)->m_object;
  v13 = vostok::render::result_struct::get_normal_texture(v12, (int)result, &v64)->m_object;
  v66 = (unsigned int)vostok::render::result_struct::get_fresnel_texture(v14, (int)result, &v65)->m_object;
  smoothness_texture = vostok::render::result_struct::get_smoothness_texture(v15, (int)result, &v67);
  v17 = (vostok::render::resource_manager *)((m_object != 0)
                                           + (v13 != 0)
                                           + (v66 != 0)
                                           + (smoothness_texture->m_object != 0));
  v66 = (unsigned int)v17;
  if ( v67.m_object )
  {
    v18 = &v67.m_object->vostok::render::resource_intrusive_base;
    --v67.m_object->m_reference_count;
    if ( !v18->m_reference_count )
      vostok::render::resource_manager::release(
        v17,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v67.m_object);
  }
  if ( v65.m_object )
  {
    v19 = &v65.m_object->vostok::render::resource_intrusive_base;
    --v65.m_object->m_reference_count;
    if ( !v19->m_reference_count )
      vostok::render::resource_manager::release(
        v17,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v65.m_object);
  }
  if ( v64.m_object )
  {
    v20 = &v64.m_object->vostok::render::resource_intrusive_base;
    --v64.m_object->m_reference_count;
    if ( !v20->m_reference_count )
      vostok::render::resource_manager::release(
        v17,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v64.m_object);
  }
  if ( v63.m_object )
  {
    v21 = &v63.m_object->vostok::render::resource_intrusive_base;
    --v63.m_object->m_reference_count;
    if ( !v21->m_reference_count )
      vostok::render::resource_manager::release(
        v17,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v63.m_object);
  }
  v22 = vostok::render::g_allocator;
  v23 = type_info::raw_name(&vostok::render::texture_converter_params `RTTI Type Descriptor');
  v25 = vostok::memory::doug_lea_allocator::malloc_impl(v24, (int)v22, 860 * v66, v23, v47, v48, v49);
  v26 = vostok::render::g_allocator;
  v27 = (vostok::render::res_texture *)v25;
  v64.m_object = (vostok::render::res_texture *)v25;
  v28 = type_info::raw_name(&vostok::resources::creation_request `RTTI Type Descriptor');
  v30 = vostok::memory::doug_lea_allocator::malloc_impl(v29, (int)v26, 16 * v66, v28, v47, v48, v49);
  v67.m_object = 0;
  v32 = (vostok::render::res_texture *)v30;
  v65.m_object = (vostok::render::res_texture *)v30;
  v63.m_object = (vostok::render::res_texture *)v30;
  v33 = &v27[1].m_name.m_string.m_buffer[200];
  do
  {
    if ( *((_DWORD *)&v55.m_object + (int)v67.m_object) )
    {
      v31 = (int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( v33 != (char *)836 )
        {
          v46 = v67.m_object;
          v45.m_object = (vostok::render::res_texture *)(v33 - 836);
          v44.m_object = (vostok::render::res_texture *)(v33 - 836);
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            &v45,
            &v55 + (int)v67.m_object);
          vostok::fs_new::virtual_path_string::virtual_path_string(v34, (int)&v43.m_string.m_end);
          vostok::fs_new::virtual_path_string::virtual_path_string(v35, (int)&v42.m_string.m_end);
          v42.m_string.m_begin = 0;
          vostok::render::texture_converter_params::texture_converter_params(
            v36,
            (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)(v33 - 836),
            0,
            v42,
            v43,
            v44,
            (unsigned int)v45.m_object,
            (int)v46);
          v32 = v63.m_object;
          v27 = v64.m_object;
        }
        v37 = v67.m_object == 0;
        *((_DWORD *)v33 + 3) = 1;
        v33[20] = 0;
        v33[21] = 1;
        v33[22] = v37;
        v38 = "NORMAL_MAP";
        if ( v67.m_object != (vostok::render::res_texture *)1 )
          v38 = "DXT1";
        v31 = *((_DWORD *)v33 - 68);
        if ( (char *)v31 != v38 )
        {
          *((_DWORD *)v33 - 67) = v31;
          *(_BYTE *)v31 = 0;
          vostok::buffer_string::operator+=((vostok::buffer_string *)(v33 - 272), v38);
        }
        if ( v32 )
        {
          v31 = 860;
          v32->__vftable = (vostok::render::res_texture_vtbl *)uri;
          v32->m_reference_count = (unsigned int)(v33 - 836);
          *(_DWORD *)&v32->m_loaded = 860;
          v32->num_mips = 10;
        }
        v32 = (vostok::render::res_texture *)((char *)v32 + 16);
        v63.m_object = v32;
        v33 += 860;
      }
    }
    ++v67.m_object;
  }
  while ( (unsigned int)v67.m_object < 4 );
  v51 = vostok::render::bake_decal_cook::on_texture_converted;
  v52 = this;
  v53 = v27;
  v54 = surface;
  v59 = vostok::render::bake_decal_cook::on_texture_converted;
  v60 = this;
  v61 = (void (__thiscall *)(vostok::render::bake_decal_cook *, vostok::resources::queries_result *, vostok::render::texture_converter_params *, vostok::render::render_surface_instance *))v27;
  v46 = (vostok::render::res_texture *)&v59;
  v62 = surface;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)v31) )
  {
    v50[0] = 0;
  }
  else
  {
    v50[2] = (int)v59;
    v50[3] = (int)v60;
    v51 = v61;
    v52 = (vostok::render::bake_decal_cook *)v62;
    v50[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::bake_decal_cook,vostok::resources::queries_result &,vostok::render::texture_converter_params *,vostok::render::render_surface_instance *>,boost::_bi::list4<boost::_bi::value<vostok::render::bake_decal_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::texture_converter_params *>,boost::_bi::value<vostok::render::render_surface_instance *>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_create_resources(
    (const vostok::resources::creation_request *)v65.m_object,
    v66,
    &vostok::memory::g_mt_allocator,
    0,
    (const vostok::variant<32> **)data->m_parent_query);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v39, v50);
  v40 = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v59;
  for ( i = 3; i >= 0; --i )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(--v40);
}
