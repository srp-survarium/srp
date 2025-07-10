void __usercall vostok::animation::mixing::animation_lexeme::animation_lexeme(
        vostok::animation::mixing::animation_lexeme *this@<ecx>,
        vostok::animation::mixing::animation_lexeme_parameters *parameters@<eax>)
{
  vostok::animation::mixing::animation_lexeme *v4; // ecx

  vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(this, parameters);
  this->vostok::animation::mixing::base_lexeme::m_buffer = parameters->m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
  this->m_cloned_instance.m_object = 0;
  vostok::animation::mixing::animation_lexeme::cloned_in_buffer(v4, (vostok::animation::mixing::base_lexeme *)this);
}
