void __usercall survarium::animations_selector::reset_animation_controller(
        survarium::animations_selector *this@<esi>,
        vostok::animation::subscribed_channel **time_in_ms@<edi>)
{
  void *v2; // esp
  survarium::base_animation_controller *m_current_controller; // ecx
  survarium::base_animation_controller *m_target_controller; // eax
  bool v5; // zf
  survarium::base_animation_controller *v6; // ecx
  const vostok::animation::mixing::expression *v7; // eax
  vostok::animation::subscribed_channel **m_target_controller_parameters; // [esp-4004h] [ebp-401Ch]
  unsigned __int8 v9; // [esp-4000h] [ebp-4018h] BYREF
  vostok::mutable_buffer v10; // [esp+8h] [ebp-10h] BYREF
  vostok::animation::mixing::expression v11; // [esp+10h] [ebp-8h] BYREF

  v2 = alloca(0x4000);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &v10,
    &v9,
    0x4000u);
  m_current_controller = this->m_current_controller;
  m_target_controller = this->m_target_controller;
  if ( m_current_controller != m_target_controller )
  {
    if ( m_current_controller )
    {
      m_current_controller->try_finalize(m_current_controller, &v11, m_target_controller, &v10);
      if ( v11.m_node.m_object )
      {
        if ( v11.m_lexeme )
        {
          survarium::animations_selector::set_animation_player_target(&v11, this, time_in_ms);
          goto LABEL_10;
        }
        v5 = v11.m_node.m_object->m_reference_count-- == 1;
        if ( v5 )
          ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v11.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
            v11.m_node.m_object,
            0);
      }
    }
    v6 = this->m_target_controller;
    this->m_current_controller = v6;
    v6->initialize(v6);
  }
  m_target_controller_parameters = (vostok::animation::subscribed_channel **)this->m_target_controller_parameters;
  ((void (__thiscall *)(survarium::base_animation_controller *))this->m_current_controller->set_target)(this->m_current_controller);
  this->m_target_controller_parameters->reset(this->m_target_controller_parameters);
  v7 = (const vostok::animation::mixing::expression *)((int (__thiscall *)(survarium::base_animation_controller *, vostok::animation::mixing::expression *, vostok::mutable_buffer *, vostok::animation::subscribed_channel **))this->m_current_controller->selected_animations)(
                                                        this->m_current_controller,
                                                        &v11,
                                                        &v10,
                                                        time_in_ms);
  survarium::animations_selector::set_animation_player_target(v7, this, m_target_controller_parameters);
LABEL_10:
  if ( v11.m_node.m_object )
  {
    v5 = v11.m_node.m_object->m_reference_count-- == 1;
    if ( v5 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v11.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v11.m_node.m_object,
        0);
  }
}
