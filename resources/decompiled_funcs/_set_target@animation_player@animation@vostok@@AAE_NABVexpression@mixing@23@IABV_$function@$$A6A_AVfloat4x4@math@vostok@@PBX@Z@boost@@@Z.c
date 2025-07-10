char __userpurge vostok::animation::animation_player::set_target@<al>(
        const vostok::animation::mixing::expression *expression@<eax>,
        vostok::animation::mixing::n_ary_tree_converter *a2@<ecx>,
        vostok::animation::animation_player *this,
        char *current_time_in_ms,
        boost::function<vostok::math::float4x4 __cdecl(void const *)> *get_transform_functor)
{
  unsigned int m_buffer_size; // esi
  unsigned int v7; // edi
  void *v8; // esp
  vostok::animation::animation_player *v9; // eax
  vostok::animation::mixing::n_ary_tree *v10; // ecx
  boost::function1<vostok::math::float4x4,void const *> **m_animated_objects; // edi
  vostok::animation::mixing::animated_object_holder *v12; // ebx
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  bool v14; // zf
  vostok::animation::animation_player *v16; // ecx
  vostok::animation::mixing::binary_tree_base_node *v17; // ecx
  void *v18; // esp
  unsigned int m_needed_buffer_size; // eax
  unsigned __int8 *next_buffer; // eax
  vostok::animation::mixing::n_ary_tree *v21; // ecx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v22; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v23; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v24; // ecx
  vostok::animation::mixing::n_ary_tree *v25; // ecx
  vostok::animation::mixing::callback_generator_info *v26; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v27; // ecx
  vostok::animation::mixing::n_ary_tree *v28; // ecx
  vostok::animation::mixing::binary_tree_base_node *v29; // ecx
  boost::_bi::bind_t<vostok::math::float4x4,boost::_mfi::cmf1<vostok::math::float4x4,transform_getter,void const *>,boost::_bi::list2<boost::_bi::value<transform_getter *>,boost::arg<1> > > v30; // [esp-8h] [ebp-1B4h]
  unsigned int v31; // [esp-4h] [ebp-1B0h]
  vostok::animation::subscribed_channel *v32[4]; // [esp+0h] [ebp-1ACh] BYREF
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor v33; // [esp+10h] [ebp-19Ch] BYREF
  vostok::math::float4x4 result; // [esp+A4h] [ebp-108h] BYREF
  vostok::animation::mixing::n_ary_tree_converter builder; // [esp+E4h] [ebp-C8h] BYREF
  boost::function<vostok::math::float4x4 __cdecl(void const *)> get_transform_functora; // [esp+118h] [ebp-94h] BYREF
  vostok::animation::mixing::n_ary_tree_comparer comparer; // [esp+13Ch] [ebp-70h] BYREF
  vostok::animation::mixing::n_ary_tree target_tree; // [esp+160h] [ebp-4Ch] BYREF
  vostok::mutable_buffer mixing_buffer; // [esp+190h] [ebp-1Ch] BYREF
  vostok::mutable_buffer buffer; // [esp+198h] [ebp-14h] BYREF
  transform_getter transform_getter_instance; // [esp+1A0h] [ebp-Ch] BYREF
  bool first_time_3; // [esp+1B7h] [ebp+Bh]
  vostok::animation::mixing::animated_object_holder *i; // [esp+1B8h] [ebp+Ch]
  const vostok::animation::mixing::callback_generator_info *generators_head; // [esp+1BCh] [ebp+10h]

  vostok::animation::mixing::n_ary_tree_converter::n_ary_tree_converter(a2, &builder, expression);
  m_buffer_size = builder.m_buffer_size;
  v7 = builder.m_buffer_size;
  first_time_3 = this->m_mixing_tree.m_animations_count == 0;
  if ( this->m_mixing_tree.m_animations_count )
  {
    v8 = alloca(builder.m_buffer_size);
    v9 = (vostok::animation::animation_player *)v32;
  }
  else
  {
    v9 = (vostok::animation::animation_player *)this->m_tree_buffers[1];
    if ( this != (vostok::animation::animation_player *)this->m_current_buffer )
      v9 = this;
    this->m_current_buffer = (char (*)[16384])v9;
  }
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &buffer,
    (unsigned __int8 *)v9,
    m_buffer_size);
  vostok::animation::mixing::n_ary_tree_converter::constructed_n_ary_tree(
    (vostok::animation::mixing::n_ary_tree_converter *)&buffer,
    (vostok::animation::mixing::n_ary_tree_animation_node *)&builder,
    (vostok::mutable_buffer *)&target_tree,
    &buffer,
    current_time_in_ms,
    &this->m_first_subscribed_channel);
  if ( first_time_3 )
  {
    this->m_mixing_tree_buffer_size = v7;
    vostok::animation::mixing::n_ary_tree::operator=(&this->m_mixing_tree, &target_tree);
    m_animated_objects = (boost::function1<vostok::math::float4x4,void const *> **)this->m_mixing_tree.m_animated_objects;
    v12 = (vostok::animation::mixing::animated_object_holder *)&m_animated_objects[34
                                                                                 * this->m_mixing_tree.m_animated_objects_count];
    i = (vostok::animation::mixing::animated_object_holder *)m_animated_objects;
    if ( m_animated_objects != (boost::function1<vostok::math::float4x4,void const *> **)v12 )
    {
      while ( 1 )
      {
        qmemcpy(
          m_animated_objects,
          boost::function1<vostok::math::float4x4,void const *>::operator()(
            m_animated_objects[32],
            get_transform_functor,
            &result,
            m_animated_objects[32]),
          0x40u);
        v10 = 0;
        if ( ++i == v12 )
          break;
        m_animated_objects = (boost::function1<vostok::math::float4x4,void const *> **)i;
      }
    }
    vostok::animation::mixing::n_ary_tree::destroy(v10);
    if ( target_tree.m_reference_counter.m_object )
      --target_tree.m_reference_counter.m_object->m_reference_count;
    m_object = builder.m_root.m_object;
    if ( builder.m_root.m_object )
    {
      v14 = builder.m_root.m_object->m_reference_count-- == 1;
      if ( v14 )
      {
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
          m_object,
          0);
        return 1;
      }
    }
    return 1;
  }
  vostok::animation::mixing::n_ary_tree_comparer::n_ary_tree_comparer(
    &comparer,
    &target_tree,
    &this->m_mixing_tree,
    (unsigned int)current_time_in_ms);
  if ( !comparer.m_equal )
  {
    v18 = alloca(24 * this->m_mixing_tree.m_animations_count);
    m_needed_buffer_size = comparer.m_needed_buffer_size;
    this->m_mixing_tree_buffer_size = comparer.m_needed_buffer_size;
    v31 = m_needed_buffer_size + 128;
    next_buffer = (unsigned __int8 *)vostok::animation::animation_player::get_next_buffer(v16, (char *)this);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &mixing_buffer,
      next_buffer,
      v31);
    vostok::animation::mixing::n_ary_tree::set_objects_transform(v21);
    transform_getter_instance.functor = get_transform_functor;
    v30.l_.a1_.t_ = &transform_getter_instance;
    v30.f_.f_ = (vostok::math::float4x4 *(__thiscall *)(transform_getter *, vostok::math::float4x4 *, const void *))transform_getter::get_transform;
    transform_getter_instance.animation_player = this;
    get_transform_functora.vtable = 0;
    boost::function1<vostok::math::float4x4,void const *>::assign_to<boost::_bi::bind_t<vostok::math::float4x4,boost::_mfi::cmf1<vostok::math::float4x4,transform_getter,void const *>,boost::_bi::list2<boost::_bi::value<transform_getter *>,boost::arg<1>>>>(
      (boost::function1<vostok::math::float4x4,void const *> *)&transform_getter_instance,
      (boost::_bi::bind_t<vostok::math::float4x4,boost::_mfi::cmf1<vostok::math::float4x4,transform_getter,void const *>,boost::_bi::list2<boost::_bi::value<transform_getter *>,boost::arg<1> > > *)&get_transform_functora,
      v30);
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::n_ary_tree_transition_tree_constructor(
      &v33,
      &mixing_buffer,
      &this->m_mixing_tree,
      &target_tree,
      comparer.m_animations_count,
      comparer.m_animated_objects_count,
      (const unsigned int)current_time_in_ms,
      &this->m_first_subscribed_channel,
      &get_transform_functora);
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::computed_tree(
      v22,
      (vostok::animation::mixing::n_ary_tree *)v32[0]);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v23,
      (int *)&v33);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v24,
      (int *)&get_transform_functora);
    generators_head = vostok::animation::mixing::n_ary_tree::generate_animation_lexeme_end_events(
                        &this->m_mixing_tree,
                        (const vostok::animation::mixing::n_ary_tree *)&result.lines[1],
                        (vostok::animation::mixing::callback_generator_info *)v32,
                        (vostok::animation::mixing::callback_generator_info *)this->m_first_subscribed_channel,
                        v32[0]);
    vostok::animation::mixing::n_ary_tree::operator=(
      &this->m_mixing_tree,
      (const vostok::animation::mixing::n_ary_tree *)&result.lines[1]);
    v26 = (vostok::animation::mixing::callback_generator_info *)generators_head;
    if ( generators_head )
    {
      ++this->m_in_tick;
      vostok::animation::mixing::n_ary_tree::dispatch_callbacks(
        generators_head,
        &this->m_first_subscribed_channel,
        (unsigned int)current_time_in_ms,
        &this->m_callbacks_are_actual);
      if ( !--this->m_in_tick && !this->m_callbacks_are_actual )
        vostok::animation::animation_player::compact_callbacks((vostok::animation::animation_player *)0xFFFF, this);
      do
      {
        v27 = &v26->animation.vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>;
        v26 = (vostok::animation::mixing::callback_generator_info *)v26->next;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v27);
      }
      while ( v26 );
    }
    vostok::animation::mixing::n_ary_tree::destroy(v25);
    if ( LODWORD(result.j.x) )
      --*(_DWORD *)LODWORD(result.j.x);
    vostok::animation::mixing::n_ary_tree::destroy(v28);
    if ( target_tree.m_reference_counter.m_object )
      --target_tree.m_reference_counter.m_object->m_reference_count;
    v29 = builder.m_root.m_object;
    if ( builder.m_root.m_object )
    {
      v14 = builder.m_root.m_object->m_reference_count-- == 1;
      if ( v14 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v29->~vostok::animation::mixing::binary_tree_base_node)(
          v29,
          0);
    }
    return 1;
  }
  vostok::animation::mixing::n_ary_tree::destroy((vostok::animation::mixing::n_ary_tree *)v16);
  if ( target_tree.m_reference_counter.m_object )
    --target_tree.m_reference_counter.m_object->m_reference_count;
  v17 = builder.m_root.m_object;
  if ( builder.m_root.m_object )
  {
    v14 = builder.m_root.m_object->m_reference_count-- == 1;
    if ( v14 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v17->~vostok::animation::mixing::binary_tree_base_node)(
        v17,
        0);
  }
  return 0;
}
