void __usercall vostok::animation::mixing::animation_lexeme::animation_lexeme(
        vostok::animation::mixing::animation_lexeme *this@<esi>,
        const vostok::animation::mixing::animation_lexeme *other@<edi>)
{
  vostok::animation::mixing::base_lexeme *v2; // eax
  vostok::animation::mixing::animation_lexeme *m_object; // eax
  vostok::animation::mixing::animation_lexeme *v4; // ecx
  vostok::animation::mixing::animation_lexeme *v5; // eax
  vostok::animation::mixing::animation_lexeme *v6; // ecx

  vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(
    &other->vostok::animation::mixing::binary_tree_animation_node,
    (int)this);
  if ( other )
    v2 = &other->vostok::animation::mixing::base_lexeme;
  else
    v2 = 0;
  this->vostok::animation::mixing::base_lexeme::m_buffer = v2->m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
  this->m_cloned_instance.m_object = 0;
  if ( other->m_cloned_instance.m_object != this )
  {
    m_object = other->m_cloned_instance.m_object;
    v4 = 0;
    if ( m_object )
    {
      v4 = other->m_cloned_instance.m_object;
      ++m_object->m_reference_count;
    }
    v5 = v4;
    v6 = this->m_cloned_instance.m_object;
    this->m_cloned_instance.m_object = v5;
    if ( v6 )
    {
      if ( v6->m_reference_count-- == 1 )
        ((void (__thiscall *)(vostok::animation::mixing::animation_lexeme *, _DWORD))v6->~vostok::animation::mixing::binary_tree_base_node)(
          v6,
          0);
    }
  }
}


void __usercall vostok::animation::mixing::animation_lexeme::animation_lexeme(
        vostok::animation::mixing::animation_lexeme *this@<ecx>,
        const vostok::animation::mixing::animation_lexeme_parameters *parameters@<eax>)
{
  vostok::animation::mixing::animation_lexeme *v4; // ecx

  vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(this, parameters);
  this->vostok::animation::mixing::base_lexeme::m_buffer = parameters->m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
  this->m_cloned_instance.m_object = 0;
  vostok::animation::mixing::animation_lexeme::cloned_in_buffer(v4, this);
}
