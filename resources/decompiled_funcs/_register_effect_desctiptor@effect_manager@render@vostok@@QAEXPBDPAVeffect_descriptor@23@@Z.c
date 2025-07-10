void __thiscall vostok::render::effect_manager::register_effect_desctiptor(
        vostok::render::effect_manager *this,
        vostok::render::effect_manager *name,
        vostok::render::effect_descriptor *dectriptor)
{
  char *m_buffer; // eax
  bool v4; // zf
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> > >,bool> result; // [esp+0h] [ebp-9Ch] BYREF
  stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> __val; // [esp+8h] [ebp-94h] BYREF

  m_buffer = __val.first.m_buffer;
  __val.first.m_begin = __val.first.m_buffer;
  __val.first.m_end = __val.first.m_buffer;
  __val.first.m_max_end = (char *)&__val.second;
  __val.first.m_buffer[0] = 0;
  if ( this )
  {
    if ( this->m_is_effects_query_processing )
    {
      do
      {
        if ( m_buffer >= __val.first.m_max_end )
          break;
        *m_buffer = this->m_is_effects_query_processing;
        m_buffer = __val.first.m_end + 1;
        this = (vostok::render::effect_manager *)((char *)this + 1);
        v4 = !this->m_is_effects_query_processing;
        ++__val.first.m_end;
      }
      while ( !v4 );
    }
    *m_buffer = 0;
  }
  __val.second = dectriptor;
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *)&__val,
    &name->m_effect_descriptors._M_t,
    &result,
    &__val);
}
