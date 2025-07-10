void __thiscall vostok::buffer_vector<vostok::animation::mixing::animation_interval>::~buffer_vector<vostok::animation::mixing::animation_interval>(
        vostok::buffer_vector<vostok::animation::mixing::animation_interval> *this)
{
  vostok::animation::mixing::animation_interval *i; // [esp+8h] [ebp-8h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    vostok::animation::mixing::animation_interval::`scalar deleting destructor'(i, &i->m_animation, 0);
  this->m_end = this->m_begin;
}
