void __thiscall vostok::configs::binary_config_value::fix_up(
        vostok::configs::binary_config_value *this,
        unsigned int offset)
{
  vostok::platform_pointer_selector<char const ,1>::helper *p_id; // edi
  vostok::animation::mixing::animation_interval *v4; // eax
  int type; // eax
  int count; // ebp
  int v7; // edi

  p_id = &this->id;
  if ( vostok::animation::mixing::animation_interval::animation((vostok::animation::mixing::animation_interval *)&this->id)->m_animation.m_object )
  {
    v4 = vostok::animation::mixing::animation_interval::animation((vostok::animation::mixing::animation_interval *)p_id);
    v4->m_animation.m_object = (vostok::resources::managed_resource *)((char *)v4->m_animation.m_object + offset);
  }
  type = this->type;
  if ( (unsigned int)type > 2 )
  {
    this->data.pointer = (char *)this->data.pointer + offset;
    if ( type <= 4 )
    {
      count = this->count;
      if ( this->count )
      {
        v7 = 0;
        do
        {
          vostok::configs::binary_config_value::fix_up(
            (vostok::configs::binary_config_value *)((char *)this->data.pointer + v7),
            offset);
          v7 += 24;
          --count;
        }
        while ( count );
      }
    }
  }
}
