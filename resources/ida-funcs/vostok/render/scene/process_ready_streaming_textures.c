void __thiscall vostok::render::scene::process_ready_streaming_textures(vostok::render::scene *this, int a2)
{
  int *v2; // edi
  int v3; // eax
  vostok::render::streaming_ready_texture *v4; // ebx
  LARGE_INTEGER QPC; // rax
  vostok::timing::timer *v6; // ecx
  const char *m_begin; // eax
  double elapsed_sec; // st7
  vostok::render::res_texture *v9; // ecx
  vostok::render::requested_streamable_texture *requested_texture; // eax
  vostok::buffer_vector<vostok::render::requested_streamable_texture> *v11; // ecx
  int v12; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v13; // [esp-10h] [ebp-54h] BYREF
  const char *v14; // [esp-Ch] [ebp-50h]
  unsigned int num_mips; // [esp-8h] [ebp-4Ch]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v16; // [esp-4h] [ebp-48h] BYREF
  LARGE_INTEGER v17[3]; // [esp+10h] [ebp-34h] BYREF
  vostok::render::streaming_ready_texture *v18; // [esp+2Ch] [ebp-18h] BYREF
  vostok::render::requested_streamable_texture *begin; // [esp+30h] [ebp-14h] BYREF
  vostok::render::requested_streamable_texture *end; // [esp+34h] [ebp-10h] BYREF
  unsigned int v21; // [esp+38h] [ebp-Ch]
  float v22; // [esp+3Ch] [ebp-8h]

  v2 = (int *)((char *)&loc_12E16C + a2);
  if ( (*(_DWORD *)((char *)&loc_12E170 + a2) - *(_DWORD *)((char *)&loc_12E16C + a2)) / 288 )
  {
    v21 = 0;
    vostok::timing::timer::timer((vostok::timing::timer *)0x120, v17);
    v3 = *v2;
    v22 = 0.0;
    if ( v3 != v2[1] )
    {
      do
      {
        if ( v21 >= 4 || v22 > 2.0 )
          break;
        v18 = *(vostok::render::streaming_ready_texture **)((char *)&loc_12E16C + a2);
        v4 = v18;
        QPC = vostok::timing::get_QPC();
        v6 = 0;
        v17[1] = QPC;
        v17[0].QuadPart = 0;
        if ( v4->data.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          m_begin = v4->name.m_begin;
          v16.m_object = 0;
          num_mips = v4->num_mips;
          v14 = m_begin;
          v13.m_object = 0;
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
            &v13,
            &v4->data);
          vostok::render::resource_manager::on_texture_loaded_res(
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v13,
            v14,
            num_mips,
            (vostok::resources::managed_resource *)v16.m_object);
        }
        elapsed_sec = vostok::timing::timer::get_elapsed_sec(v6, (int)v17);
        v16.m_object = v9;
        v22 = elapsed_sec * 1000.0 + v22;
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v16,
          &v4->texture);
        requested_texture = stlp_std::find_if<vostok::render::requested_streamable_texture *,vostok::render::find_requested_texture_predicate>(
                              *(vostok::render::requested_streamable_texture **)((char *)&dword_E8160 + a2),
                              *(vostok::render::requested_streamable_texture **)((char *)&dword_E8164 + a2),
                              (vostok::render::find_requested_texture_predicate)v16.m_object);
        begin = requested_texture;
        if ( requested_texture != *(vostok::render::requested_streamable_texture **)((char *)&dword_E8164 + a2) )
        {
          end = requested_texture + 1;
          vostok::buffer_vector<vostok::render::requested_streamable_texture>::erase(
            v11,
            (int *)((char *)&dword_E8160 + a2),
            &begin,
            (const vostok::render::requested_streamable_texture **)&end);
        }
        begin = (vostok::render::requested_streamable_texture *)&v4[1];
        vostok::buffer_vector<vostok::render::streaming_ready_texture>::erase(
          (vostok::buffer_vector<vostok::render::streaming_ready_texture> *)v11,
          (vostok::render::streaming_ready_texture *const *)((char *)&loc_12E16C + a2),
          (vostok::fixed_string<260> **)&v18,
          (vostok::render::streaming_ready_texture **)&begin);
        v12 = *(_DWORD *)((char *)&loc_12E16C + a2);
        ++v21;
      }
      while ( v12 != *(_DWORD *)((char *)&loc_12E16C + a2 + 4) );
    }
  }
}
