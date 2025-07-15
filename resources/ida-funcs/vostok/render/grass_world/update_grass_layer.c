void __userpurge vostok::render::grass_world::update_grass_layer(
        unsigned int layer_data@<eax>,
        vostok::render::grass_world *this,
        vostok::render::grass_layer_desc *desc,
        bool is_set,
        int do_populate,
        bool from_cook)
{
  vostok::render::grass_layer_desc *v6; // ebx
  int v8; // ecx
  unsigned int v9; // edi
  void *v10; // esp
  unsigned __int8 v11; // cl
  int v12; // eax
  vostok::resources::request *m_begin; // edx
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::grass_world,vostok::resources::queries_result &,vostok::render::grass_layer_desc *,vostok::render::grass_layer_data *,bool>,boost::_bi::list5<boost::_bi::value<vostok::render::grass_world *>,boost::arg<1>,boost::_bi::value<vostok::render::grass_layer_desc *>,boost::_bi::value<vostok::render::grass_layer_data *>,boost::_bi::value<bool> > > *v14; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::grass_world,vostok::resources::queries_result &,vostok::render::grass_layer_desc *,vostok::render::grass_layer_data *,bool>,boost::_bi::list5<boost::_bi::value<vostok::render::grass_world *>,boost::arg<1>,boost::_bi::value<vostok::render::grass_layer_desc *>,boost::_bi::value<vostok::render::grass_layer_data *>,boost::_bi::value<bool> > > *v15; // eax
  void (__thiscall *__ptr64 f)(vostok::render::grass_world *, vostok::resources::queries_result *, vostok::render::grass_layer_desc *, vostok::render::grass_layer_data *, bool); // xmm0_8
  __int64 v17; // xmm2_8
  void (__cdecl *v18)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v19; // ecx
  const stlp_std::__true_type *v20; // edi
  float v21; // xmm2_4
  unsigned int v22; // xmm0_4
  unsigned int v23; // xmm1_4
  bool v24; // zf
  _BYTE v25[28]; // [esp-18h] [ebp-8Ch] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+Ch] [ebp-68h] BYREF
  char v27; // [esp+2Ch] [ebp-48h] BYREF
  char v28; // [esp+44h] [ebp-30h] BYREF
  vostok::math::float2 cell_pos_lt; // [esp+5Ch] [ebp-18h] BYREF
  vostok::math::float2 cell_pos_rb; // [esp+64h] [ebp-10h] BYREF
  vostok::buffer_vector<vostok::resources::request> r; // [esp+6Ch] [ebp-8h] BYREF
  int savedregs; // [esp+74h] [ebp+0h] BYREF
  int x; // [esp+84h] [ebp+10h]
  float from_cooka; // [esp+8Ch] [ebp+18h]

  v6 = desc;
  if ( is_set )
  {
    v8 = (char *)desc->models_list.m_end - (char *)desc->models_list.m_begin;
    v9 = v8 / 280;
    v10 = alloca(8 * (v8 / 280));
    r.m_begin = (vostok::resources::request *)&v25[24];
    r.m_end = (vostok::resources::request *)&v25[24];
    vostok::buffer_vector<vostok::resources::request>::resize(v8, v8 / 280, &r);
    v11 = 0;
    if ( v9 )
    {
      v12 = 0;
      do
      {
        m_begin = r.m_begin;
        r.m_begin[v12].path = v6->models_list.m_begin[v12].name.m_begin;
        v6 = desc;
        ++v11;
        m_begin[v12].id = grass_render_model_class;
        v12 = v11;
      }
      while ( v11 < v9 );
    }
    *(_DWORD *)&v25[20] = do_populate;
    *(_DWORD *)&v25[16] = layer_data;
    *(_DWORD *)&v25[12] = v6;
    *(_DWORD *)&v25[8] = (unsigned __int8)1_70;
    *(_DWORD *)&v25[4] = 0;
    if ( from_cook )
    {
      *(_DWORD *)v25 = vostok::render::grass_world::grass_layer_resources_ready_from_cook;
      v14 = (boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::grass_world,vostok::resources::queries_result &,vostok::render::grass_layer_desc *,vostok::render::grass_layer_data *,bool>,boost::_bi::list5<boost::_bi::value<vostok::render::grass_world *>,boost::arg<1>,boost::_bi::value<vostok::render::grass_layer_desc *>,boost::_bi::value<vostok::render::grass_layer_data *>,boost::_bi::value<bool> > > *)&v28;
    }
    else
    {
      *(_DWORD *)v25 = vostok::render::grass_world::grass_layer_resources_ready;
      v14 = (boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::grass_world,vostok::resources::queries_result &,vostok::render::grass_layer_desc *,vostok::render::grass_layer_data *,bool>,boost::_bi::list5<boost::_bi::value<vostok::render::grass_world *>,boost::arg<1>,boost::_bi::value<vostok::render::grass_layer_desc *>,boost::_bi::value<vostok::render::grass_layer_data *>,boost::_bi::value<bool> > > *)&v27;
    }
    v15 = boost::bind<void,vostok::render::grass_world,vostok::resources::queries_result &,vostok::render::grass_layer_desc *,vostok::render::grass_layer_data *,bool,vostok::render::grass_world *,boost::arg<1>,vostok::render::grass_layer_desc *,vostok::render::grass_layer_data *,bool>(
            this,
            v14,
            *(void (__thiscall *__ptr64 *)(vostok::render::grass_world *, vostok::resources::queries_result *, vostok::render::grass_layer_desc *, vostok::render::grass_layer_data *, bool))v25,
            (boost::arg<1>)v25[8],
            *(vostok::render::grass_layer_desc **)&v25[12],
            *(vostok::render::grass_layer_data **)&v25[16],
            v25[20]);
    f = v15->f_.f_;
    v17 = *(_QWORD *)&v15->l_.a4_.t_;
    *(_DWORD *)&v25[4] = HIDWORD(v15->f_.f_);
    *(boost::_bi::storage3<boost::_bi::value<vostok::render::grass_world *>,boost::arg<1>,boost::_bi::value<vostok::render::grass_layer_desc *> > *)&v25[8] = v15->l_.boost::_bi::storage3<boost::_bi::value<vostok::render::grass_world *>,boost::arg<1>,boost::_bi::value<vostok::render::grass_layer_desc *> >;
    callback.vtable = 0;
    *(_QWORD *)&v25[16] = v17;
    if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *,survarium::inventory_cooker_data *,survarium::player_parameters_cooker_data *>,boost::_bi::list5<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *>,boost::_bi::value<survarium::inventory_cooker_data *>,boost::_bi::value<survarium::player_parameters_cooker_data *>>>>(
           &callback.functor,
           (boost::detail::function::basic_vtable1<void,survarium::game_object_ &> *)f,
           *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,survarium::game_object_ &,survarium::simple_game_project *,vostok::resources::query_result_for_cook *>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<survarium::simple_game_project *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > *)&v25[4]) )
    {
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::grass_world,vostok::resources::queries_result &,vostok::render::grass_layer_desc *,vostok::render::grass_layer_data *,bool>,boost::_bi::list5<boost::_bi::value<vostok::render::grass_world *>,boost::arg<1>,boost::_bi::value<vostok::render::grass_layer_desc *>,boost::_bi::value<vostok::render::grass_layer_data *>,boost::_bi::value<bool>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    else
    {
      callback.vtable = 0;
    }
    vostok::resources::query_resources(
      r.m_begin,
      v9,
      &callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      0,
      0,
      assert_on_fail_true);
    if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
    {
      v18 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v18 )
        v18(&callback.functor, &callback.functor, 2);
    }
  }
  else
  {
    v19 = 0;
    for ( x = 0; (unsigned __int16)v19 < *(_WORD *)(layer_data + 8); x = v19 )
    {
      v20 = 0;
      if ( *(_WORD *)(layer_data + 10) )
      {
        from_cooka = (float)(unsigned __int16)v19;
        do
        {
          v21 = *(float *)(layer_data + 12);
          *(float *)&v22 = (float)(v21 * from_cooka) + *(float *)layer_data;
          *(float *)&v23 = (float)((float)(unsigned __int16)v20 * v21) + *(float *)(layer_data + 4);
          *(float *)&r.m_begin = v21 + *(float *)&v22;
          cell_pos_rb.x = v21 + *(float *)&v22;
          *(float *)&r.m_end = v21 + *(float *)&v23;
          cell_pos_rb.y = v21 + *(float *)&v23;
          v24 = *(_BYTE *)((unsigned __int16)v19
                         + (unsigned __int16)v20 * *(unsigned __int16 *)(layer_data + 8)
                         + *(_DWORD *)(layer_data + 20)) == 0;
          cell_pos_lt = (vostok::math::float2)__PAIR64__(v23, v22);
          if ( !v24 )
          {
            vostok::render::grass_world::remove_layer_instances(
              this,
              (bool)&savedregs,
              v20,
              layer_data,
              this,
              (const vostok::math::float2 *)desc->id,
              &cell_pos_lt,
              &cell_pos_rb);
            v19 = x;
          }
          ++v20;
        }
        while ( (unsigned __int16)v20 < *(_WORD *)(layer_data + 10) );
      }
      ++v19;
    }
    if ( (_BYTE)do_populate )
      this->m_need_populate = 1;
  }
}
