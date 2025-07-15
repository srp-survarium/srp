char __userpurge vostok::animation::animation_player::set_target@<al>(
        vostok::animation::animation_player *this@<ecx>,
        float a2@<xmm4>,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> expression,
        vostok::animation::mixing::expression *current_time_in_ms,
        boost::function<vostok::math::float4x4 __cdecl(void const *)> *get_transform_functor,
        float animations_count)
{
  int m_object; // ebx
  vostok::animation::mixing::n_ary_tree_converter *v7; // ecx
  unsigned int m_buffer_size; // edi
  bool v9; // zf
  void *v10; // esp
  int *v11; // eax
  boost::function<vostok::math::float4x4 __cdecl(void const *)> *m_reference_count; // esi
  boost::function<vostok::math::float4x4 __cdecl(void const *)> *v13; // ebx
  boost::function1<vostok::math::float4x4,void const *> *v14; // ecx
  vostok::math::float4x4 *v15; // eax
  boost::function<vostok::math::float4x4 __cdecl(void const *)> *v16; // edi
  char v17; // bl
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v19; // ecx
  const vostok::animation::mixing::n_ary_tree **v21; // eax
  void *v22; // esp
  char *v23; // eax
  int *v24; // eax
  vostok::animation::mixing::n_ary_tree *v25; // ecx
  float x; // esi
  const vostok::animation::mixing::n_ary_tree **v27; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v28; // ecx
  int v29; // eax
  const vostok::animation::mixing::n_ary_tree *v30; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v31; // ecx
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v32; // esi
  const vostok::animation::mixing::n_ary_tree **v33; // eax
  vostok::animation::mixing::n_ary_tree_intrusive_base *v34; // edi
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v35; // ecx
  vostok::animation::animation_player *v36; // ecx
  vostok::animation::mixing::n_ary_tree_intrusive_base *v37; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v38; // ecx
  boost::_bi::bind_t<vostok::math::float4x4,boost::_mfi::cmf1<vostok::math::float4x4,transform_getter,void const *>,boost::_bi::list2<boost::_bi::value<transform_getter *>,boost::arg<1> > > v39; // [esp-8h] [ebp-1A8h]
  int v40[4]; // [esp+0h] [ebp-1A0h] BYREF
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor v41; // [esp+10h] [ebp-190h] BYREF
  vostok::animation::mixing::n_ary_tree_converter v42; // [esp+A0h] [ebp-100h] BYREF
  vostok::math::float4x4 result; // [esp+118h] [ebp-88h] BYREF
  boost::function<vostok::math::float4x4 __cdecl(void const *)> get_transform_functora; // [esp+158h] [ebp-48h] BYREF
  vostok::mutable_buffer v45; // [esp+17Ch] [ebp-24h] BYREF
  bool is_final_tree[4]; // [esp+184h] [ebp-1Ch] BYREF
  unsigned int v47; // [esp+188h] [ebp-18h]
  _DWORD v48[2]; // [esp+18Ch] [ebp-14h] BYREF
  vostok::animation::mixing::callback_generator_info *callback_generators_buffer_begin; // [esp+194h] [ebp-Ch]
  vostok::mutable_buffer buffer; // [esp+198h] [ebp-8h] BYREF

  m_object = (int)expression.m_object;
  vostok::animation::mixing::n_ary_tree_converter::n_ary_tree_converter(
    &v42,
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)((char *)&_sbh_sizeHeaderList
                                                                                           + (unsigned int)expression.m_object),
    current_time_in_ms,
    (const boost::function<unsigned char __cdecl(void const *)> *)&byte_10040[(unsigned int)expression.m_object],
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&expression.m_object[16392]);
  m_buffer_size = v42.m_buffer_size;
  v9 = *(_DWORD *)(m_object + 65728) == 0;
  current_time_in_ms = (vostok::animation::mixing::expression *)(m_object + 65728);
  HIBYTE(expression.m_object) = v9;
  if ( v9 )
  {
    v7 = (vostok::animation::mixing::n_ary_tree_converter *)(m_object + 65732);
    v11 = (int *)(m_object + 0x8000);
    if ( m_object != *(_DWORD *)(m_object + 65732) )
      v11 = (int *)m_object;
    v7->m_animation_resolver.vtable = (boost::detail::function::vtable_base *)v11;
  }
  else
  {
    v10 = alloca(v42.m_buffer_size);
    v11 = v40;
  }
  *(_DWORD *)is_final_tree = v11;
  v47 = m_buffer_size;
  vostok::animation::mixing::n_ary_tree_converter::constructed_n_ary_tree(
    v7,
    (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&v42,
    (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&buffer,
    (vostok::animation::mixing::n_ary_tree_base_node **)is_final_tree,
    (unsigned int)get_transform_functor);
  if ( HIBYTE(expression.m_object) )
  {
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 65728),
      (vostok::animation::mixing::n_ary_tree_intrusive_base *)buffer.m_data);
    m_reference_count = (boost::function<vostok::math::float4x4 __cdecl(void const *)> *)vostok::animation::tree(
                                                                                           (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 65728),
                                                                                           &expression)->m_object[6].m_reference_count;
    get_transform_functor = m_reference_count;
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&expression);
    v13 = (boost::function<vostok::math::float4x4 __cdecl(void const *)> *)((char *)m_reference_count
                                                                          + 136
                                                                          * vostok::animation::tree(
                                                                              (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)current_time_in_ms,
                                                                              (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&current_time_in_ms)->m_object[9].m_reference_count);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&current_time_in_ms);
    if ( m_reference_count != v13 )
    {
      while ( 1 )
      {
        v15 = boost::function1<vostok::math::float4x4,void const *>::operator()(
                v14,
                (_DWORD *)LODWORD(animations_count),
                &result,
                m_reference_count[4].vtable);
        v16 = get_transform_functor;
        get_transform_functor = (boost::function<vostok::math::float4x4 __cdecl(void const *)> *)((char *)get_transform_functor
                                                                                                + 136);
        qmemcpy(v16, v15, 0x40u);
        v14 = 0;
        if ( get_transform_functor == v13 )
          break;
        m_reference_count = get_transform_functor;
      }
    }
  }
  else
  {
    v21 = (const vostok::animation::mixing::n_ary_tree **)vostok::animation::tree(
                                                            (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 65728),
                                                            &expression);
    vostok::animation::mixing::n_ary_tree_comparer::n_ary_tree_comparer(
      (vostok::animation::mixing::n_ary_tree_comparer *)&result.lines[1].elements[2],
      (const vostok::animation::mixing::n_ary_tree *)buffer.m_data,
      (const boost::function<unsigned char __cdecl(void const *)> *)&byte_10040[m_object],
      *v21,
      (unsigned int)get_transform_functor);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&expression);
    if ( LOBYTE(result.lines[3].elements[3]) )
    {
      v17 = 0;
      goto LABEL_12;
    }
    v22 = alloca(
            24
          * vostok::animation::tree(
              (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)current_time_in_ms,
              &expression)->m_object[8].m_reference_count);
    callback_generators_buffer_begin = (vostok::animation::mixing::callback_generator_info *)v40;
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&expression);
    v23 = (char *)(m_object + 0x8000);
    if ( m_object != *(_DWORD *)(m_object + 65732) )
      v23 = (char *)m_object;
    *(_DWORD *)(m_object + 65732) = v23;
    v45.m_data = v23;
    v45.m_size = LODWORD(result.c.y) + 128;
    v24 = (int *)vostok::animation::tree(
                   (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)current_time_in_ms,
                   (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&buffer.m_size);
    vostok::animation::mixing::n_ary_tree::set_objects_transform(v25, a2, *v24);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&buffer.m_size);
    *(float *)&v48[1] = animations_count;
    v39.l_.a1_.t_ = (transform_getter *)v48;
    v39.f_.f_ = (vostok::math::float4x4 *(__thiscall *)(transform_getter *, vostok::math::float4x4 *, const void *))transform_getter::get_transform;
    v48[0] = m_object;
    boost::function<vostok::math::float4x4 __cdecl (void const *)>::function<vostok::math::float4x4 __cdecl (void const *)>(
      (boost::function<vostok::math::float4x4 __cdecl(void const *)> *)transform_getter::get_transform,
      (boost::_bi::bind_t<vostok::math::float4x4,boost::_mfi::cmf1<vostok::math::float4x4,transform_getter,void const *>,boost::_bi::list2<boost::_bi::value<transform_getter *>,boost::arg<1> > > *)&get_transform_functora,
      v39,
      v40[0]);
    x = result.c.x;
    animations_count = result.k.w;
    v27 = (const vostok::animation::mixing::n_ary_tree **)vostok::animation::tree(
                                                            (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)current_time_in_ms,
                                                            (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&buffer.m_size);
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::n_ary_tree_transition_tree_constructor(
      &v41,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&get_transform_functora,
      &v45,
      *v27,
      (const vostok::animation::mixing::n_ary_tree *)buffer.m_data,
      LODWORD(animations_count),
      LODWORD(x),
      (unsigned int)get_transform_functor,
      (const boost::function<unsigned char __cdecl(void const *)> *)&byte_10040[m_object]);
    v30 = *(const vostok::animation::mixing::n_ary_tree **)(v29 + 84);
    animations_count = 0.0;
    if ( v30 )
    {
      vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&animations_count);
      ++v30->m_reference_count;
      animations_count = *(float *)&v30;
    }
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v28,
      (int *)&v41);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&buffer.m_size);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v31,
      (int *)&get_transform_functora);
    v32 = (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)current_time_in_ms;
    vostok::animation::tree(
      (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)current_time_in_ms,
      (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&buffer.m_size);
    v33 = (const vostok::animation::mixing::n_ary_tree **)vostok::animation::tree(
                                                            v32,
                                                            (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&current_time_in_ms);
    v34 = (vostok::animation::mixing::n_ary_tree_intrusive_base *)LODWORD(animations_count);
    expression.m_object = (vostok::animation::mixing::n_ary_tree_intrusive_base *)vostok::animation::mixing::n_ary_tree::generate_animation_lexeme_end_events(
                                                                                    *v33,
                                                                                    (const boost::function<unsigned char __cdecl(void const *)> *)&byte_10040[m_object],
                                                                                    (const vostok::animation::mixing::n_ary_tree *)LODWORD(animations_count),
                                                                                    callback_generators_buffer_begin,
                                                                                    *(vostok::animation::mixing::callback_generator_info **)(m_object + 65736));
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&current_time_in_ms);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&buffer.m_size);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v32,
      v34);
    if ( expression.m_object )
    {
      ++*(_WORD *)(m_object + 65748);
      vostok::animation::mixing::n_ary_tree::dispatch_callbacks(
        (const stlp_std::random_access_iterator_tag *)expression.m_object,
        v35,
        (vostok::animation::subscribed_channel **)(m_object + 65736),
        (unsigned int)get_transform_functor,
        (vostok::resources::pinned_ptr_const<unsigned char> *)(m_object + 65750));
      if ( !--*(_WORD *)(m_object + 65748) && !*(_BYTE *)(m_object + 65750) )
        vostok::animation::animation_player::compact_callbacks(v36, m_object);
      v37 = expression.m_object;
      do
      {
        v38 = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v37;
        v37 = (vostok::animation::mixing::n_ary_tree_intrusive_base *)v37[2].m_reference_count;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v38);
      }
      while ( v37 );
    }
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&animations_count);
  }
  v17 = 1;
LABEL_12:
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&buffer);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v42.m_root);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v18,
    (int *)&v42.m_time_calculator_resolver);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v19,
    (int *)&v42);
  return v17;
}
